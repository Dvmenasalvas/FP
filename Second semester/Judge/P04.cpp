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
using namespace std;

struct tValores{
	int max, min;
};

typedef tValores tArray[TAM];


// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(tMatriz a) {
	bool sol = false;
	tArray filas, columnas;

	//Recorremos por filas
	for (int i = 0; i < a.filas; ++i) {
		filas[i].max = a.elementos[i][0];
		filas[i].min = a.elementos[i][0];
		for (int j = 0; j < a.columnas; ++j) {
			if (a.elementos[i][j] > filas[i].max) 
				filas[i].max = a.elementos[i][j];

			if (a.elementos[i][j] < filas[i].min)
				filas[i].min = a.elementos[i][j];
		}
	}

	//Recorremos por columnas
	for (int j = 0; j < a.columnas; ++j) {
		columnas[j].max = a.elementos[0][j];
		columnas[j].min = a.elementos[0][j];
		for (int i = 0; i < a.filas; ++i) {
			if (a.elementos[i][j] > columnas[j].max)
				columnas[j].max = a.elementos[i][j];

			if (a.elementos[i][j] < columnas[j].min)
				columnas[j].min = a.elementos[i][j];
		}
	}

	//Recorremos matriz buscando puntos de silla
	int i = 0, j = 0;
	while (i < a.filas && !sol) {
		j = 0;
		while (j < a.columnas && !sol) {
			if (filas[i].max == columnas[j].min || filas[i].min == columnas[j].max)
				sol = true;
			j++;
		}
		i++;
	}



	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer un dato de la entrada
	tMatriz a;

	cin >> a;

	if ((a.filas == 0) || (a.columnas == 0))
        return false;
    
    
    bool sol = resolver(a);
    
	if (sol) cout << "SI" << '\n';
	else cout << "NO" << '\n';

    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("/Users/daniv/pruebaP4.txt");
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