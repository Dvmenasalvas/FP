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

void escribirDiagonal(tMatriz & z, int vertical, int horizontal, int f, int c, int d) {
	int i = 0;
	while ((f + i*vertical >= 0) && (f + i*vertical < z.filas) && (c + i*horizontal >= 0) && (c + i*horizontal < z.columnas)) {
		z.elementos[f + i*vertical][c + i*horizontal] = d;
		i++;
	}
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(tMatriz  &z, int num) {
	string op;
	int longitud;

	for (int i = 0; i < num; i++) {
		cin >> op;
		longitud = op.length(); //Aprovechamos la longitud del string para poder hacer un switch

		int a, b, f;
		switch (longitud) {
		case 5: //filas
			cin >> a >> b;
			a--;
			b--;
			for (int i = 0; i < z.columnas; i++) {
				int c = z.elementos[a][i];
				z.elementos[a][i] = z.elementos[b][i];
				z.elementos[b][i] = c;
			}
			break;
		case 8: //columnas
			if (op == "columnas") { //columnas
				cin >> a >> b;
				a--;
				b--;
				for (int i = 0; i < z.filas; i++) {
					int c = z.elementos[i][a];
					z.elementos[i][a] = z.elementos[i][b];
					z.elementos[i][b] = c;
				}
			}
			else {
				int aux;
				cin >> c;

				if (c >= 0) {
					c--;
					aux = z.elementos[z.filas - 1][c];
					for (int i = z.columnas - 2; i >= 0; i--) {
						z.elementos[f][i + 1] = z.elementos[f][i];
					}
					z.elementos[f][0] = aux;
				}
				else {
					c = -c;
					c--;
					aux = z.elementos[f][0];
					for (int i = 0; i < z.columnas - 1; i++) {
						z.elementos[f][i] = z.elementos[f][i + 1];
					}
					z.elementos[f][z.columnas - 1] = aux;
				}
			}
			break;
		case 4: //cruz
			int c, d;
			cin >> f >> c >> d;
			f--;
			c--;
			escribirDiagonal(z, -1, -1, f, c, d); //Arriba izquierda
			escribirDiagonal(z, -1, 1, f, c, d);  //Arriba derecha
			escribirDiagonal(z, 1, -1, f, c, d);  //Abajo izquierda
			escribirDiagonal(z, 1, 1, f, c, d);   //Abajo derecha
			break;
		case 9: //rotarFila
			int aux;
			cin >> f;

			if (f >= 0) {
				f--;
				aux = z.elementos[f][z.columnas - 1];
				for (int i = z.columnas - 2; i >= 0; i--) {
					z.elementos[f][i + 1] = z.elementos[f][i];
				}
				z.elementos[f][0] = aux;
			}
			else {
				f = -f;
				f--;
				aux = z.elementos[f][0];
				for (int i = 0; i < z.columnas - 1; i++) {
					z.elementos[f][i] = z.elementos[f][i + 1];
				}
				z.elementos[f][z.columnas - 1] = aux;
			}
			break;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer un dato de la entrada
	tMatriz z;
	int num;

	cin >> z;

	if ((z.filas == 0) || (z.columnas == 0))
        return false;
    
	cin >> num;

	resolver(z,num);
    
	cout << z << "---" << '\n';

    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("/Users/daniv/pruebaP5.txt");
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