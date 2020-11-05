// Grupo doble grado, Daniel Valverde Menasalvas
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

const int TAM = 50;
const int FOT = 200;

struct tFoto {
	string titulo;
	string tema;
	int matriz[TAM][TAM];
};

struct ordenTitulo {
	bool operator()(tFoto* a, tFoto* b) {
		return a->titulo < b->titulo;
	}
};

struct ordenTema {
	bool operator()(tFoto* a, tFoto* b) {
		return a->tema < b->tema;
	}
};

template <typename T, typename Comp = std::less<T>>
void ordenarInsercion(std::vector<T> & array, Comp ord = Comp()) {
	size_t N = array.size();
	// parte ordenada array[0..i), parte por procesar array[i..N)
	for (size_t i = 1; i < N; ++i) { // desde el segundo hasta el último
									 // parte ordenada array[0..i)
		T elemento = array[i];  // elemento a insertar
		size_t j = i; // desplazar los mayores de la parte ordenada
		while (j > 0 && ord(elemento, array[j - 1])) {
			array[j] = array[j - 1];
			--j;
		}
		if (j != i) array[j] = elemento; // colocar en el hueco
	} // parte ordenada array[0..N)
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(vector<tFoto*> &titulos, vector<tFoto*> &temas) {
	ordenarInsercion(titulos, ordenTitulo());
	ordenarInsercion(temas, ordenTitulo());
	ordenarInsercion(temas, ordenTema());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer un dato de la entrada
	vector<tFoto*> titulos;
	vector<tFoto*> temas;
	int fotos;
	string entrada;


	cin >> fotos;

	if (fotos == 0)
		return false;

	getline(cin, entrada);
	for (int i = 0; i < fotos; i++){
		titulos.push_back(new tFoto);
		temas.push_back(titulos[i]);
		getline(cin, titulos[i]->titulo);
	}
	for(int i = 0; i < fotos; i++)
		getline(cin, titulos[i]->tema);

	for (int i = 0; i < TAM; i++)
		for (int j = 0; j < TAM; j++)
			for (int t = 0; t < titulos.size(); t++)
				titulos[t]->matriz[i][j] = 3;

	resolver(titulos, temas);
    
	for (int i = 0; i < titulos.size(); i++)
		cout << titulos[i]->titulo << '\n';

	cout << '\n';

	for (int i = 0; i < temas.size(); i++) {
		cout << temas[i]->tema << " - " << temas[i]->titulo << '\n';
		delete temas[i];
	}
    
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
