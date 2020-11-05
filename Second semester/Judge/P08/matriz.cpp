#include "matriz.h"

istream& operator>> (istream& in, tMatriz & matriz) {
	in >> matriz.filas;

	for (int i = 0; i < matriz.filas; i++) { //Diagonal principal
			in >> matriz.elementos[i][i];
	}
	for (int i = 0; i < matriz.filas - 1; i++) { //Diagonal de arriba
		in >> matriz.elementos[i][i + 1];
	}
	for (int i = 0; i < matriz.filas - 1; i++) { //Diagonal de abajo
		in >> matriz.elementos[i + 1][i];
	}


	return in;
}

ostream& operator<< (ostream& out, tMatriz const& matriz) {
	for (int i = 0; i < matriz.filas; i++) {
		for (int j = 0; j < matriz.columnas; j++) {
			out << matriz.elementos[i][j] << " ";
		}
		out << '\n';
	}

	return out;
}

tMatriz operator* (tMatriz const& a, tMatriz const& b) {
	tMatriz c;
	int suma = 0;
	c.filas = a.filas;
	c.columnas = b.columnas;

	for (int i = 0; i < c.filas; i++) {
		for (int j = 0; j < c.columnas; j++) {
			for (int n = 0; n < a.columnas; n++) {
				suma += a.elementos[i][n] * b.elementos[n][j];
			}
			c.elementos[i][j] = suma;
			suma = 0;
		}
	}
	return c;
}

tMatriz girar90(tMatriz const& a) {
	tMatriz b;
	b.filas = a.columnas;
	b.columnas = a.filas;

	for (int i = 0; i < b.filas; i++) {
		for (int j = 0; j < b.columnas; j++) {
			b.elementos[i][j] = a.elementos[b.columnas - 1 - j][i];
		}
	}

	return b;
}

tMatriz girar180(tMatriz const& a) {
	tMatriz b;
	b.filas = a.filas;
	b.columnas = a.columnas;

	for (int i = 0; i < b.filas; i++) {
		for (int j = 0; j < b.columnas; j++) {
			b.elementos[i][j] = a.elementos[b.filas - 1 - i][b.columnas - 1 - j];
		}
	}

	return b;
}

tMatriz girar270(tMatriz const& a) {
	tMatriz b;
	b.filas = a.columnas;
	b.columnas = a.filas;

	for (int i = 0; i < b.filas; i++) {
		for (int j = 0; j < b.columnas; j++) {
			b.elementos[i][j] = a.elementos[j][b.filas - 1 - i];
		}
	}

	return b;
}