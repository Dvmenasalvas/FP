#include "clavevalor.h"


bool busquedaBinaria(tIndicePalabras const& l, std::string const& s, int & pos) { //Hace una busqueda binaria para buscar una palabra en la tabla y devuelve si la ha encontrado o no
	int ini = 0, fin = l.tam, medio;
	bool encontrado = false;
	while (ini < fin && !encontrado) {
		medio = (ini + fin - 1) / 2;
		if (s < l.elementos[medio].clave) fin = medio;
		else if (l.elementos[medio].clave < s) ini = medio + 1;
		else encontrado = true;
	}
	if (encontrado) pos = medio;
	else pos = ini;

	return encontrado;
}

void insertarOrdenado(tIndicePalabras & idx, std::string const& palabra, std::string const& nombreArchivo) { //Inserta en la tabla un nombre de archivo asociado a una palabra de forma ordenada
	int pos, aux;
	if (busquedaBinaria(idx, palabra, pos)) {
		if(!buscar(idx.elementos[pos].valor, nombreArchivo,aux))
			insertar(idx.elementos[pos].valor, nombreArchivo);
	}
	else {
		if (idx.tam < TAMCV) {
			for (int i = idx.tam; i > pos; i--)
				idx.elementos[i] = idx.elementos[i - 1];
			idx.elementos[pos].clave = palabra;
			idx.tam++;
			idx.elementos[pos].valor.elementos[0] = nombreArchivo;
			idx.elementos[pos].valor.tam = 1;
		}
	}
}
