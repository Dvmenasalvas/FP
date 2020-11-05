#include "matriz.h"

tMatriz matrizConstante(double x, int n) { //Crea una matriz constante cuadrada de x con tamaño n
	tMatriz matriz;
	matriz.lado = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matriz.elementos[i][j] = x;

	return matriz;
}
tVector operator*(tVector const & v, tMatriz const & m) { //Multiplica vector y matriz
	tVector solucion;
	solucion.tam = v.tam;
	for (int i = 0; i < v.tam; i++) solucion.elementos[i] = 0;

	for (int j = 0; j < m.lado; j++)
		for (int i = 0; i < m.lado; i++)
			solucion.elementos[j] += (v.elementos[i] * m.elementos[i][j]);

	return solucion;
}

tVector operator*(double x, tVector const & m) { //Multiplica un numero y un vector
	tVector solucion;
	solucion.tam = m.tam;
	for (int i = 0; i < m.tam; i++) solucion.elementos[i] = m.elementos[i] * x;

	return solucion;
}

tVector operator+(tVector const& m1, tVector const & m2) { //Suma dos vectores
	tVector solucion;
	solucion.tam = m1.tam;
	for (int i = 0; i < solucion.tam; i++) solucion.elementos[i] = m1.elementos[i] + m2.elementos[i];

	return solucion;
}

double operator*(tVector const& m1, tVector const & m2){ //Multiplica dos vectores
	double resultado = 0;
	for (int i = 0; i < m1.tam; i++)
		resultado += m1.elementos[i] * m2.elementos[i];
	return resultado;
}

void normalizaL(tMatriz & L, tVector & a) { //Normaliza la matriz L y, a la vez, define su vector asociado 'a'
	int suma;
	a.tam = L.lado;
	for (int i = 0; i < L.lado; i++) {
		suma = 0;
		for (int j = 0; j < L.lado; j++)
			suma += L.elementos[i][j];
		if (suma > 0) {
			a.elementos[i] = 0;
			for (int j = 0; j < L.lado; j++)
				L.elementos[i][j] /= suma;
		}
		else a.elementos[i] = 1;
	}
}
