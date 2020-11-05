#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

const int PROD = 100;
const string ARCHINVENT = "inventario.txt";
const string AMODIFICACIONES = "modificaciones.txt";

//V1
struct tProducto {
	size_t codigo;
	string nombre;
	size_t unidades;
};

struct tInventario {
	tProducto productos[PROD];
	int cont = 0;
};

//V2

struct tModificacion {
	size_t codigo;
	char operacion;
	size_t unidades;
};


//V1
void cargarInventario(tInventario &inventario) {
	ifstream archivo;
	archivo.open(ARCHINVENT);
	if (archivo.is_open()) {
		int i = 0;
		while (i < PROD && inventario.productos[i].codigo != -1) {
			archivo >> inventario.productos[i].codigo;
			if (inventario.productos[i].codigo != -1) {
				archivo >> inventario.productos[i].nombre >> inventario.productos[i].unidades;
				i++;
			}
		}
		inventario.cont = i;
		archivo.close();
	}
	else cout << "No se ha encontrado el archivo " << ARCHINVENT << '\n';
}

void mostrarInventario(tInventario const &inventario) {
	for (int i = 0; i < inventario.cont; i++) {
		cout << setw(6) << inventario.productos[i].codigo << " " << setw(30) << left << inventario.productos[i].nombre << setw(3) << right << inventario.productos[i].unidades << " unidades" << '\n';
	}
	cout << '\n';
}

void ordenarInventario(tInventario &inventario) {
	bool cambio = true;
	while (cambio) {
		cambio = false;
		for (int i = inventario.cont - 1; i > 0; i--) {
			if (inventario.productos[i].codigo < inventario.productos[i - 1].codigo) {
				cambio = true;
				tProducto actual = inventario.productos[i];
				inventario.productos[i] = inventario.productos[i - 1];
				inventario.productos[i - 1] = actual;
			}
		}
	}
}

//V2
void eliminarProducto(tInventario &inventario, int pos) {
	for (int i = pos; i < inventario.cont - 1; i++) {
		inventario.productos[i] = inventario.productos[i + 1];
	}
	inventario.cont--;
}

bool buscarProducto(tInventario const& inventario, int cBuscado, int &pos) {
	int ini = 0, fin = inventario.cont;
	int mitad = 0;
	bool encontrado = false;
	while (!encontrado && ini < fin) {
		mitad = (ini + fin - 1) / 2;
		if (cBuscado < inventario.productos[mitad].codigo) fin = mitad;
		else if (cBuscado > inventario.productos[mitad].codigo)ini = mitad + 1;
		else encontrado = true;
	}
	if (encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}

void procesarModificaciones(tInventario &inventario) {
	tModificacion modificacion;
	ifstream archivo;
	int pos;
	archivo.open(AMODIFICACIONES);
	if (archivo.is_open()) {
		modificacion.codigo = 0;
		while (modificacion.codigo != -1) {
			archivo >> modificacion.codigo;
			if (modificacion.codigo != -1) {
				archivo >> modificacion.operacion >> modificacion.unidades;
				if (buscarProducto(inventario, modificacion.codigo, pos)) {
					if (modificacion.operacion == 'V') {
						inventario.productos[pos].unidades -= modificacion.unidades;
						if (inventario.productos[pos].unidades < 1) eliminarProducto(inventario, pos);
					}
					else inventario.productos[pos].unidades += modificacion.unidades;
				}	
			}
		}
		archivo.close();
	}
	else cout << "No se ha encontrado el archivo " << AMODIFICACIONES << '\n';
}

int main() {
	tInventario inventario;
	cargarInventario(inventario);
	mostrarInventario(inventario);
	ordenarInventario(inventario);
	mostrarInventario(inventario);
	procesarModificaciones(inventario);
	mostrarInventario(inventario);
	system("pause");
	return 0;
}