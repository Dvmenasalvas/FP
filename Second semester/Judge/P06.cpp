// Grupo doble grado matemáticas e informática. Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "matriz.h"

const int NUM = 9;

typedef bool tNumeros[NUM];
typedef tNumeros tArea[NUM];

void inicializa(tArea &area) {
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			area[i][j] = false;
		}
	}
}	
// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(tMatriz const &sudoku) {
	bool correcto = true;
	tArea filas, columnas, regiones;
	inicializa(filas);
	inicializa(columnas);
	inicializa(regiones);


	//Recogemos los datos del sudoku
	for (int i = 0; i < sudoku.filas; i++) { //filas
		for (int j = 0; j < sudoku.columnas; j++) { //columnas
			filas[i][sudoku.elementos[i][j] - 1] = true;
			columnas[j][sudoku.elementos[i][j] - 1] = true;
			
			if (i < 3) {
				if (j < 3) regiones[0][sudoku.elementos[i][j] - 1] = true; //Las regiones las numeramos de izquierda a derecha y de arriba a abajo empezando por arriba a la izquierda(0)
				else if(j < 6) regiones[1][sudoku.elementos[i][j] - 1] = true;
				else regiones[2][sudoku.elementos[i][j] - 1] = true;
			}
			else if (i < 6) {
				if (j < 3) regiones[3][sudoku.elementos[i][j] - 1] = true; //Las regiones las numeramos de izquierda a derecha y de arriba a abajo empezando por arriba a la izquierda(0)
				else if (j < 6) regiones[4][sudoku.elementos[i][j] - 1] = true;
				else regiones[5][sudoku.elementos[i][j] - 1] = true;
			}
			else {
				if (j < 3) regiones[6][sudoku.elementos[i][j] - 1] = true; //Las regiones las numeramos de izquierda a derecha y de arriba a abajo empezando por arriba a la izquierda(0)
				else if (j < 6) regiones[7][sudoku.elementos[i][j] - 1] = true;
				else regiones[8][sudoku.elementos[i][j] - 1] = true;
			}
		}
	}

	//Comprobamos por filas, columnas y regiones a la vez
	for (int i = 0; i < NUM; i++) { //Diferentes filas, columnas o regiones
		for (int j = 0; j < NUM; j++) { //Diferentes numeros en cada área
			if (!filas[i][j]) correcto = false;
			if (!columnas[i][j]) correcto = false;
			if (!regiones[i][j]) correcto = false;
		}
	}

	return correcto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	tMatriz sudoku;
	sudoku.columnas = NUM;
	sudoku.filas = NUM;
	// leer los datos de la entrada
	std::cin >> sudoku;

	bool sol = resolver(sudoku);
	// escribir sol
	if (sol) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/daniv/sudoku.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}