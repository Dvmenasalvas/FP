#include "indices.h"

void quitarFin(std::string & palabra) { //Quita el .txt a los nombres de archivo(si es que lo tiene) para que se pueda hacer referencia a estos con o sin extension
	bool fallo = false;
	std::string fin = ".txt";
	int i = 0;
	while (!fallo && i < 4) {
		if (palabra[palabra.length() - 1 - i] != fin[fin.length() - 1 - i]) fallo = true;
		i++;
	}
	if (!fallo) palabra.erase(palabra.length() - 4, 4);
}


bool crearTabla(tIndicePalabras & tabla, tListaCadenas<std::string> & totales, tMatriz & L) { //Crea una tabla definiendo a la vez su vector totales y su matriz L correspondiente a partir de un archivo inicial
	string entrada;
	cout << "Por favor, introduzca el nombre del fichero raiz a partir del que se creara el indice(sin la extension): ";
	cin >> entrada;

	//Inicializamos tabla
	tabla.tam = 0;
	bool encontrado = true;

	tListaCadenas<std::string> visitados, noVisitados;
	inicializar(visitados);
	inicializar(noVisitados);
	int i = 0, j = 0;
	noVisitados.tam = 0;
	totales.tam = 0;
	insertar(noVisitados, entrada);
	insertar(totales, entrada);
	visitados.tam = 0;
	L.lado = 1;
	L.elementos[0][0] = 0;

	while (noVisitados.tam > 0 && encontrado) {
		insertar(visitados, noVisitados.elementos[noVisitados.tam - 1]);
		noVisitados.tam--;
		
		buscar(totales, visitados.elementos[visitados.tam - 1], i);

		std::ifstream archivo;
		archivo.open(visitados.elementos[visitados.tam - 1] + ".txt");
		if (archivo.is_open()) {
			std::stringstream stream;
			std::string palabra;
			while (!archivo.eof()) {
				std::getline(archivo, palabra);
				stream = std::stringstream(palabra);
				stream >> palabra;
				while (stream) {
					while (!std::isalnum(palabra[palabra.length() - 1]))
						palabra.pop_back();
					if (palabra[0] == '<') {
						palabra.erase(0, 1);
						quitarFin(palabra);
						if (buscar(totales, palabra, j)) {
							if (i != j) L.elementos[i][j] = 1;
						}
						else {
							insertar(noVisitados, palabra);
							insertar(totales, palabra);
							L.lado++;
							for (int t = 0; t < L.lado; t++) {
								L.elementos[t][L.lado - 1] = 0;
								L.elementos[L.lado - 1][t] = 0;
							}
							L.elementos[i][L.lado - 1] = 1;
						}
					}
					else {
						std::transform(palabra.begin(), palabra.end(), palabra.begin(), std::tolower);
						insertarOrdenado(tabla, palabra, visitados.elementos[visitados.tam - 1]);
					}
					stream >> palabra;
				}
			}
			archivo.close();
		}
		else encontrado = false;
	}
	delete[] visitados.elementos;
	visitados.elementos = nullptr;
	delete[] noVisitados.elementos;
	noVisitados.elementos = nullptr;
	return encontrado;
}