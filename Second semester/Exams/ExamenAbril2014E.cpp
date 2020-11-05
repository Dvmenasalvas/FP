#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string AESPECIALIDADES = "especialidades.txt";
const int ESP = 15;
const string ACONSULTAS = "consultas.txt";
const int CONS = 500;

struct tEspecialidad {
	int codigo;
	string nombre;
};

typedef tEspecialidad tEspecialidades[ESP];

struct tLEspecialidades {
	tEspecialidades esp;
	int cont;
};

struct tFecha {
	int dia;
	int mes;
	int año;
};

struct tConsulta {
	int codigo;
	tFecha fecha;
	int consultas;
};

typedef tConsulta tConsultas[CONS];

struct tLConsultas {
	tConsultas consultas;
	int cont;
};

bool leerEspecialidades(tLEspecialidades & lEspecialidades) {
	ifstream archivo;
	archivo.open(AESPECIALIDADES);
	bool exito = false;
	if (archivo.is_open()) {
		exito = true;
		lEspecialidades.cont = 0;
		while (lEspecialidades.cont < ESP && lEspecialidades.esp[lEspecialidades.cont].codigo != -1) {
			archivo >> lEspecialidades.esp[lEspecialidades.cont].codigo;
			if (lEspecialidades.esp[lEspecialidades.cont].codigo != -1) {
				getline(archivo, lEspecialidades.esp[lEspecialidades.cont].nombre);
				lEspecialidades.cont++;
			}
		}
		archivo.close();
	}
	else cout << "No se ha podido abrir el archivo " << AESPECIALIDADES << '\n';
	return exito;
}

bool leerConsultas(tLConsultas & lConsultas) {
	ifstream archivo;
	archivo.open(ACONSULTAS);
	char aux;
	bool exito = false;
	if (archivo.is_open()) {
		exito = true;
		lConsultas.cont = 0;
		while (lConsultas.cont < CONS && lConsultas.consultas[lConsultas.cont].codigo != -1) {
			archivo >> lConsultas.consultas[lConsultas.cont].codigo;
			if (lConsultas.consultas[lConsultas.cont].codigo != -1) {
				archivo >> lConsultas.consultas[lConsultas.cont].fecha.año;
				archivo.get(aux);
				archivo >> lConsultas.consultas[lConsultas.cont].fecha.mes;
				archivo.get(aux);
				archivo >> lConsultas.consultas[lConsultas.cont].fecha.dia;
				archivo >> lConsultas.consultas[lConsultas.cont].consultas;
				lConsultas.cont++;
			}
		}
		archivo.close();
	}
	else cout << "No se ha podido abrir el archivo " << ACONSULTAS << '\n';
	return exito;
}

bool ordenado(tConsulta a, tConsulta b) {
	bool ordenado = false;
	if (a.fecha.año < b.fecha.año) ordenado = true;
	if (a.fecha.año == b.fecha.año) {
		if (a.fecha.mes < b.fecha.mes) ordenado = true;
		if (a.fecha.mes == b.fecha.mes)
			if (a.fecha.dia < b.fecha.dia) ordenado = true;
	}
	return ordenado;
}

void ordenar(tLConsultas & lConsultas) {
	int pos;
	for (int i = 0; i < lConsultas.cont; i++) {
		pos = i;
		for (int j = i + 1; j < lConsultas.cont; j++) {
			if (ordenado(lConsultas.consultas[j], lConsultas.consultas[pos]))pos = j;
		}
		if (pos != i) {
			tConsulta actual = lConsultas.consultas[i];
			lConsultas.consultas[i] = lConsultas.consultas[pos];
			lConsultas.consultas[pos] = actual;
		}
	}
}	

void buscar(tLEspecialidades const& lEspecialidades, int codigo, int &indice) {
	int ini = 0, fin = lEspecialidades.cont;
	int medio;
	bool encontrado = false;
	while (!encontrado && ini != fin) {
		medio = (fin + ini - 1) / 2;
		if (codigo < lEspecialidades.esp[medio].codigo) fin = medio;
		else if (lEspecialidades.esp[medio].codigo < codigo) ini = medio + 1;
		else encontrado = true;
	}
	if (encontrado) indice = medio;
	else indice = -1;
}

void mostrar(tLConsultas const& lConsultas, tLEspecialidades const& lEspecialidades) {
	int pos;
	for (int i = 0; i < lConsultas.cont; i++) {
		buscar(lEspecialidades, lConsultas.consultas[i].codigo, pos);
		cout << lConsultas.consultas[i].fecha.año << "/" << lConsultas.consultas[i].fecha.mes << "/" << lConsultas.consultas[i].fecha.dia << " ";
		if (pos == -1) {
			cout << "ERROR: ¡¡¡especialidad inexistente!!!";
		}
		else {
			cout << lEspecialidades.esp[pos].nombre << " " << lConsultas.consultas[i].consultas;
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	tLConsultas lConsultas;
	tLEspecialidades lEspecialidades;
	leerConsultas(lConsultas);
	leerEspecialidades(lEspecialidades);
	mostrar(lConsultas, lEspecialidades);
	ordenar(lConsultas);
	mostrar(lConsultas, lEspecialidades);
	system("pause");
	return 0;
}