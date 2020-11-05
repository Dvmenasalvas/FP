// Grupo doble grado, Daniel Valverde Menasalvas
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


// función que resuelve el problema
// comentario sobre el coste, O(f(N))
tMatriz resolver(int giros, tMatriz const& a) {
	int giro;
	tMatriz b = a;
	for (int i = 0; i < giros; i++) {
		cin >> giro;
		switch (giro) {
		case 90:
			b = girar90(b);
			break;
		case 180:
			b = girar180(b);
			break;
		case 270:
			b = girar270(b);
			break;
		}
	}
	return b;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	tMatriz a;
	int giros;

	cin >> a;

	if (!std::cin)
		return false;

	cin >> giros;

	tMatriz sol = resolver(giros, a);

	cout << sol << '\n';


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/usuario_local/Documents/visual studio 2013/Projects/Project2/archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;
	system("pause");

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}