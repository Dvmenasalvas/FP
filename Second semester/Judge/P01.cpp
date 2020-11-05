// Grupo Doble Grado Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX_LIN = 500;

struct tMatriz {
	int numFilas, numColum;
	double elementos[MAX_LIN][MAX_LIN];
};

struct tPos {
	int fila = 0, columna = 0;
};




// función que resuelve el problema
// comentario sobre el coste, O(f(N
double resolver(tPos &pos, tMatriz const& matriz) {
	double altMax = matriz.elementos[0][0];

	for (int i = 0; i < matriz.numFilas; i++) {
		for (int j = 0; j < matriz.numColum; j++) {
			if (matriz.elementos[i][j] > altMax) {
				altMax = matriz.elementos[i][j];
				pos.fila = i;
				pos.columna = j;
			}
		}
	}

	return altMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	tMatriz matriz;
	tPos pos;

	std::cin >> matriz.numFilas;

	if (!std::cin)
		return false;

	std::cin >> matriz.numColum;

	for (int i = 0; i < matriz.numFilas; i++) {
		for (int j = 0; j < matriz.numColum; j++) {
			std::cin >> matriz.elementos[i][j];
		}
	}

	double altMax = resolver(pos, matriz);

	std::cout << altMax << " " << pos.fila << " " << pos.columna << '\n';


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("/Users/daniv/OneDrive/Documentos/numeros.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}