//Hecho por Daniel Valverde Menasalvas. Doble Grado Matemáticas e Informática

#include <iostream>
#include <fstream>
#include <string>
#include "indices.h"
using namespace std;

const double c = 0.85;

void ordenarTotales(tListaCadenas<string> & totales, tVector & X){ //Ordena los vectores X y totales, fijandose solo en los elementos de X
	for (int i = 1; i < X.tam; i++) {
		int j = i;
		while ((X.elementos[i] < X.elementos[j - 1]) && j > 0) 
			j--;
		if (j != i){
			float actual = X.elementos[i];
			string sactual = totales.elementos[i];
			for (int t = i; t > j; t--) {
				X.elementos[t] = X.elementos[t - 1];
				totales.elementos[t] = totales.elementos[t - 1];
			}
			X.elementos[j] = actual;
			totales.elementos[j] = sactual;
		}
	}
}

void mostrarPalabra(const tIndicePalabras & tabla, const tListaCadenas<string> & totales, const tVector & X) { //Mientras no se introduzca fin, muestra los archivos en los que aparece cada palabra introducida ordenados en funcion de su pageRank
	string entrada;
	int pos;
	cout << "Introduzca una palabra ('fin' para terminar): " << '\n';
	cin >> entrada;
	std::transform(entrada.begin(), entrada.end(), entrada.begin(), std::tolower);
	while (entrada != "fin") {
		if (busquedaBinaria(tabla, entrada, pos)) {
			tListaCadenas<int> orden; //Lista que usaremos para mostrar los archivos ordenados por orden de relevancia
			orden.tam = 0;
			for (int i = 0; i < tabla.elementos[pos].valor.tam; i++) { //Metemos las posiciones en totales de los archivos que queremos mostrar en orden
				buscar(totales, tabla.elementos[pos].valor.elementos[i], orden.elementos[orden.tam]);
				orden.tam++;
			}
			ordenar(orden);
			for (int i = 0; i < orden.tam; i++){ //Mostramos los archivos de orden ordenados por su relevancia
				cout << "Encontrada en '" << totales.elementos[orden.elementos[i]] << "' ";
				cout << "(relevancia " << X.elementos[orden.elementos[i]] << ")" << '\n';
			}
		}
		else cout << "Palabra no encontrada. " << '\n';
		cout <<'\n' << "Introduzca una palabra ('fin' para terminar): " << '\n';
		cin >> entrada;
		std::transform(entrada.begin(), entrada.end(), entrada.begin(), std::tolower);
	}
}

bool cercanos(tVector const & a, tVector const & b) { //Calcula si el vector X1 y X2 estan lo suficientemente cerca (para asegurar que la sucesion converge lo suficiente)
	int i = 0;
	while (((1 - a.elementos[i] / b.elementos[i]) < 0.00001) && i < a.tam){
		i++;
	}

	return i == a.tam;
}

void calcularPR(tMatriz & L, tVector & X1) { //Calcula y devuelve el PG en X1, a partir de L
	tVector a, e, X2;
	normalizaL(L,a);
	e.tam = L.lado;
	for (int i = 0; i < e.tam; i++) e.elementos[i] = 1;
	float n = 1.0 / float(L.lado);
	X1.tam = L.lado;
	X2.tam = L.lado;
	for (int i = 0; i < e.tam; i++) X1.elementos[i] = n;
	do{
		X2 = (c * X1 * L) + ((c * X1 * a) + 1 - c) * (1.0 / float(L.lado)) * e;
		X1 = (c * X2 * L) + ((c * X2 * a) + 1 - c) * (1.0 / float(L.lado)) * e;
	} while (!cercanos(X1, X2));
}

int main(){
	tIndicePalabras tabla;
	tListaCadenas<std::string> totales;
	tMatriz L;
	string entrada;
	cout << "Buscador de Daniel Valverde Menasalvas" << '\n' << '\n' << '\n';
	cout << "Por favor, introduzca el nombre del fichero raiz a partir del que se creara el indice(sin la extension): ";
	cin >> entrada;
	
	if (crearTabla(tabla, totales, entrada, L)){
		cout << "Creando tablas... ";
		tVector X;
		calcularPR(L, X);
		ordenarTotales(totales, X);

		cout << "[CORRECTO]" << '\n';
		cout << "La información ha sido cargada. Puede empezar a hacer busquedas." << '\n' << '\n';

		mostrarPalabra(tabla, totales, X);
	}
	else cout << "No se ha podido encontrar el archivo pedido." << '\n';
	cout << "Gracias por usar el buscador.";

	return 0;
}