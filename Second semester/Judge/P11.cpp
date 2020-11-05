// Grupo del doble grado, Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

const int maxC = 7;
const int maxF = 6;
const int incC[] = {-1, 1, -1 , 1, -1, 1, 0, 0};
const int incF[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

typedef int tTablero[maxF][maxC];

bool cuatroRaya(tTablero const & tablero, int columna, int fila) {
	int cont, i = 0, j, c, f;
	bool fallo, encontrado = false;
	while (!encontrado && i < 8) {
		cont = 1;
		fallo = false;
		j = 1;
		while (!fallo && j < 4) {
			f = fila + incF[i] * j;
			c = columna + incC[i] * j;
			if (f >= 0 && c >= 0 && f < maxF && c < maxC && tablero[fila][columna] == tablero[f][c])
				cont++;
			else fallo = true;
			j++;
		}
		//Lado contrario
		if (cont == 4) encontrado = true;
		fallo = false;
		j = 1;
		while (!fallo && j < 4 && !encontrado) {
			f = fila + incF[i + 1] * j;
			c = columna + incC[i + 1] * j;
			if (f >= 0 && c >= 0 && f < maxF && c < maxC && tablero[fila][columna] == tablero[f][c]) {
				cont++;
				if (cont == 4) encontrado = true;
			}
			else fallo = true;
			j++;
		}
		i += 2;
	}
	return encontrado;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
string resolver(int fichas) {
	int columnas[maxC];
	for (int i = 0; i < maxC; i++) columnas[i] = 0;
	tTablero tablero;
	int columna, fila, ganador;
	bool fin = false;
	string resultado;
	for (int i = 0; i < fichas; i++) {
		cin >> columna;
		if (!fin) {
			fila = columnas[columna];
			columnas[columna]++;
			tablero[fila][columna] = i % 2;
		}
		if (cuatroRaya(tablero, columna, fila) && !fin) {
			fin = true;
			ganador = i % 2;
		}
	}
	if (fin)
		if (ganador == 0) resultado = "Gana A";
		else resultado = "Gana B";
	else resultado = "Empate";
	
	return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer un dato de la entrada
	int fichas;
	cin >> fichas;

	if (fichas == 0)
		return false;

	// lectura del resto de los datos de la entrada

	string resultado = resolver(fichas);

	// escribir sol

	cout << resultado << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/daniv/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}