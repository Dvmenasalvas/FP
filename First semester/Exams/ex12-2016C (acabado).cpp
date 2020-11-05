#include <iostream>
#include <string>
#include <fstream>
using namespace std;


const int NUMCODIGOS = 10;
typedef int tSecuencia[NUMCODIGOS];

void cargar(ifstream &archivo, tSecuencia secuencia, string nombre);
bool comparar(tSecuencia clave, tSecuencia intento);

int main() {
	ifstream archivo;
	tSecuencia clave, intento;
	cargar(archivo, clave, "codigos.txt");
	cargar(archivo, intento, "acceso.txt");

	if (comparar(clave, intento)) {
		cout << "La clave es correcta, el acceso ha sido permitido." << endl;
	}
	else {
		cout << "La clave es incorrecta, intentelo de nuevo." << endl;
	}

	system("pause");
	return 0;
}

void cargar(ifstream &archivo, tSecuencia secuencia, string nombre) {
	archivo.open(nombre);
	if (archivo.is_open()) {
		for (int i = 0; i < NUMCODIGOS; i++) {
			archivo >> secuencia[i];
		}
		archivo.close();
		cout << "El archivo " << nombre << " ha sido cargado correctamente." << endl;
	}
	else {
		cout << "Error no se ha podido abrir el archivo " << nombre << endl;
	}
}

bool comparar(tSecuencia clave, tSecuencia intento) {
	bool acceso = true;
	for (int i = 0; i < NUMCODIGOS; i++) {
		if (clave[i] != intento[i]) {
			acceso = false;
		}
	}
	return acceso;
}