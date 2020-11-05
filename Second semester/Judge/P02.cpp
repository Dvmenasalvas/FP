// Grupo Doble Grado, Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_LIN = 500;

struct tMatriz {
	int numFilas, numColum;
	int elementos[MAX_LIN][MAX_LIN];
};

tMatriz operator* (tMatriz const& a, tMatriz const& b) {
	tMatriz c;
	int sum;
	c.numFilas = a.numFilas;
	c.numColum = b.numColum;

	for (int i = 0; i < c.numFilas; i++) {
		for (int j = 0; j < c.numColum; j++) {
			sum = 0;
			for (int k = 0; k < a.numColum; k++) {
				sum += a.elementos[i][k] * b.elementos[k][j];
			}
			c.elementos[i][j] = sum;
		}
	}
	return c;
}

istream& operator >> (istream & in, tMatriz & m) {
	in >> m.numFilas >> m.numColum;
	for (int i = 0; i < m.numFilas; i++) {
		for (int j = 0; j < m.numColum; j++) {
			in >> m.elementos[i][j];
		}
	}
	return in;
}

ostream& operator<< (ostream & out, tMatriz const& m) {
	for (int i = 0; i < m.numFilas; i++) {
		for (int j = 0; j < m.numColum; j++) {
			out << m.elementos[i][j] << " ";
		}
		out << '\n';
	}
	return out;
}


// función que resuelve el problema
// comentario sobre el coste, O(f(N
tMatriz resolver(tMatriz const& a, tMatriz const& b) {
	tMatriz c = a * b;

	return c;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	tMatriz a, b, c;

	std::cin >> a;

	if (!std::cin)
		return false;

	std::cin >> b;



	c = resolver(a, b);

	std::cout << c << '\n';


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
	#ifndef DOMJUDGE
	std::ifstream in("/Users/daniv/OneDrive/Documentos/numeros.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif
	*/

	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	*/
	return 0;
}