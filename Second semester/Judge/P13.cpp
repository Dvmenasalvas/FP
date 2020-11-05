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
int resolver(int a, int b) {
	int resultado;
	if (b == 0) resultado = 0;
	else if (b == 1) resultado = a;
	else if (b % 2 == 0) resultado = resolver(2 * a, b / 2);
	else resultado = resolver(2 * a, b / 2) + a;

	return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer un dato de la entrada
	int a, b;

	cin >> a;

	if (!std::cin)
		return false;

	// lectura del resto de los datos de la entrada

	cin >> b;
	cout << resolver(a, b) << '\n';

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

