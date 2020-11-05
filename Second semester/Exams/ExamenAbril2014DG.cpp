#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int N = 10;
const string ASOPA = "sopa.txt";
const string PATRON = "rock";

typedef char tSopa[N][N];

bool cargarSopa(tSopa &sopa) {
	ifstream archivo;
	archivo.open(ASOPA);
	bool exito = false;
	if (archivo.is_open()) {
		exito = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				archivo >> sopa[i][j];
		archivo.close();
	}
	else cout << "No se ha encontrado el archivo " << ASOPA << '\n';
	return exito;
}

void mostrarSopa(tSopa const& sopa) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sopa[i][j] << " ";
		}
		cout << '\n';
	}
}

bool patronDerecha(tSopa const& sopa,int i, int j) {
	bool exito = false;
	if ((N - j) >= PATRON.length()) {
		int t = 0;
		exito = true;
		while (exito && t < PATRON.length()) {
			if (PATRON[t] != sopa[i][j + t]) exito = false;
			t++;
		}
	}
	return exito;
}

bool patronArribaDerecha(tSopa const& sopa, int i, int j) {
	bool exito = false;
	if ((N - j) >= PATRON.length() && (i + 1) >= PATRON.length()) {
		int t = 0;
		exito = true;
		while (exito && t < PATRON.length()) {
			if (PATRON[t] != sopa[i - t][j + t]) exito = false;
			t++;
		}
	}
	return exito;
}

int aparicionesTotales(tSopa const& sopa) {
	int apariciones = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - (PATRON.length() - 1); j++) {
			if (patronDerecha(sopa, i, j)) apariciones++;
			if (patronArribaDerecha(sopa, i, j)) apariciones++;
		}
	}
	return apariciones;
}

int main() {
	tSopa sopa;
	cargarSopa(sopa);
	mostrarSopa(sopa);
	cout << aparicionesTotales(sopa);
	system("pause");
	return 0;
}