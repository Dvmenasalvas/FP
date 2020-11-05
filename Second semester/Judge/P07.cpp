// Grupo Doble Grado, Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include "matriz.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

struct tPos {
	int fila, columna;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
tPos resolver(tMatriz const& imagen, tMatriz const& patron) {
	bool encontrado = false;
	tPos pos;
	int i = 0, j, x = 0, y;

	while (i < imagen.filas - (patron.filas - 1) && !encontrado) {
		j = 0;
		while (j < imagen.columnas - (patron.columnas - 1) && !encontrado) {
			if (imagen.elementos[i][j] == patron.elementos[0][0]) {
				pos.fila = i;
				pos.columna = j;
				encontrado = true;
				x = 0;
				while (encontrado && x < patron.filas) {
					y = 0;
					while (encontrado && y < patron.columnas) {
						if (imagen.elementos[i + x][j + y] != patron.elementos[x][y]) encontrado = false;
						y++;
					}
					x++;
				}

			}
			j++;
		}
		i++;
	}

	if (!encontrado) {
		pos.fila = -1;
		pos.columna = -1;
	}

	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer un dato de la entrada
	tMatriz imagen, patron;
	tPos pos;

	cin >> imagen;

	if (!std::cin)
		return false;

	cin >> patron;

	pos = resolver(imagen, patron);

    // escribir sol
	if (pos.fila == -1 && pos.columna == -1) cout << "NO" << '\n';
	else cout << pos.fila << " " << pos.columna << '\n';
    
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
     system("PAUSE");
     #endif
    
    return 0;
}