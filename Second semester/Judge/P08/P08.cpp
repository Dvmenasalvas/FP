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

const int incF[] = {1, 0, -1, 0};
const int incC[] = {0,1,0,-1};

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(tMatriz const& matriz, int & fila, int & suma) {
	suma = 0;
	fila = 0;
	int sumaAux;

	for (int i = 0; i < matriz.filas; i++) {
		sumaAux = 0;
		sumaAux += matriz.elementos[i][i]; //Principal
		if (i > 0) {
			sumaAux += matriz.elementos[i + incF[2]][i + incC[2]]; //Arriba
			sumaAux += matriz.elementos[i + incF[3]][i + incC[3]]; //Izquierda
		}
		if (i < matriz.filas - 1) {
			sumaAux += matriz.elementos[i + incF[1]][i + incC[1]]; //Derecha
			sumaAux += matriz.elementos[i + incF[0]][i + incC[0]]; //Abajo
		}
		if (sumaAux > suma) {
			suma = sumaAux;
			fila = i;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer un dato de la entrada
	tMatriz matriz;
	int fila, suma;

	cin >> matriz;

	if (!std::cin)
		return false;

	resolver(matriz, fila, suma);

    // escribir sol
	cout << fila << " " << suma << '\n';

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