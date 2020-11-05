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
void resolver(vector<int> &vector, int ini, int fin) {
	if (ini < fin) {
		int aux = vector[ini];
		vector[ini] = vector[fin - 1];
		vector[fin - 1] = aux;
		resolver(vector, ini + 1, fin - 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer un dato de la entrada
	int size, entrada;
	vector<int> vector;
	cin >> size;

	if (!std::cin)
		return false;
	
	// lectura del resto de los datos de la entrada

	for (int i = 0; i < size; i++) {
		cin >> entrada;
		vector.push_back(entrada);
	}

	resolver(vector, 0, vector.size());

	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";

	cout << '\n';

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

