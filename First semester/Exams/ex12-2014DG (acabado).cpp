#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int CENTINELA = -1, TAM = 50;
typedef  int tArray[TAM];

int sigS(int n);
bool comprobarS(ifstream &ent, int &n);
void generar(tArray secuencia, int k);
void mostrar(const tArray secuencia);

int main() {
	tArray secuencia;
	int k, n;
	string nombre;
	//Comprobar
	ifstream archivo;
	cout << "Nombre de archivo:";
	cin >> nombre;
	archivo.open(nombre);
	if (archivo.is_open()) {
		archivo >> k;
		cout << "Secuencia a partir del " << k << ": ";
		if (comprobarS(archivo, k)){
			cout << "OK" << endl;
		}
		else {
			cout << "el " << k << " rompe la secuencia" << endl;
		}
	}
	else cout << "No se ha podido abrir el archivo" << endl;

	//Generar y mostrar
	cout << endl << "Introduce un entero positivo: ";
	cin >> n;
	generar(secuencia, n);
	cout << "Sucesion generada a partir de " << n << ":" << endl;
	mostrar(secuencia);

	system("pause");
	return 0;
}

int sigS(int n) {
	int m;
	if ((n % 2) == 0) {
		m = n / 2;
	}
	else {
		m = 3 * n + 1;
	}
	return m;
}

bool comprobarS(ifstream &ent, int &n) {
	int m = n, x;
	bool encontrado = false, serie;
	while (!encontrado) {
		ent >> x;
		if (x == CENTINELA){
			encontrado = true;
			serie = true;
		}
		else {
			if (sigS(m) != x) {
				n = x;
				serie = false;
				encontrado = true;
			}
			else m = sigS(m);
		}
	}
	return serie;
}

void generar(tArray secuencia, int k) {
	bool fin = false;
	int i = 0;
	while ((!fin) && (i < TAM)) {
		if (k != 1) {
			secuencia[i] = k;
			k = sigS(k);
			i++;
		}
		else {
			fin = true;
			secuencia[i] = k;
			i++;
		}
	}
}

void mostrar(const tArray secuencia) {
	bool encontrado = false;
	int i = 0;
	while ((!encontrado) && (i < TAM)) {
		if (secuencia[i] == 1) {
			encontrado = true;
			cout << "1" << endl;
		}
		else {
			if (i == (TAM - 1)) {
				cout << secuencia[i] << endl;
			}
			else {
				cout << secuencia[i] << ", ";
				i++;
			}
		}
	}
}