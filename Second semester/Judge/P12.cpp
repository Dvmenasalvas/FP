// Grupo del doble grado, Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(int l) {
	if (l < 1) return 0;
	else if (l == 1) return 4;
	else return 4 * resolver(l / 2);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer un dato de la entrada
	int l;

	cin >> l;

	if (!cin) 
		return false;

	// lectura del resto de los datos de la entrada

	cout << resolver(l) << '\n';

	// escribir sol


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
	return 0;
#endif
}

