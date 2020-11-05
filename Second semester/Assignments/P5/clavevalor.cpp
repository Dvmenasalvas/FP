#include "clavevalor.h"

bool bBinariaAux(tIndicePalabras const& l, std::string const& buscado, int ini, int fin, int & pos){
	bool enc;
	if (ini == fin) { pos = ini; enc = false; }
	else {
		int mitad = (ini + fin - 1) / 2;
		if (buscado < l.elementos[mitad].clave)
			enc = bBinariaAux(l, buscado, ini, mitad, pos);
		else if (l.elementos[mitad].clave < buscado)
			enc = bBinariaAux(l, buscado, mitad + 1, fin, pos);
		else { pos = mitad; enc = true; }
	}
	return enc;
}

bool busquedaBinaria(tIndicePalabras const& l, std::string const& s, int & pos) { //Hace una busqueda binaria para buscar una palabra en la tabla y devuelve si la ha encontrado o no
	return bBinariaAux(l, s, 0, l.tam, pos);
}

void insertarOrdenado(tIndicePalabras & idx, std::string const& palabra, std::string const& nombreArchivo) { //Inserta en la tabla un nombre de archivo asociado a una palabra de forma ordenada
	int pos, aux;
	if (busquedaBinaria(idx, palabra, pos)) {
		if(!buscar(idx.elementos[pos].valor, nombreArchivo,aux))
			insertar(idx.elementos[pos].valor, nombreArchivo);
	}
	else {
		if (idx.tam >= idx.capacidad) {
			idx.capacidad = (idx.capacidad * 3) / 2 + 1;
			tClaveValor* nuevo = new tClaveValor[idx.capacidad];
			for (int i = 0; i < idx.tam; i++)
				nuevo[i] = idx.elementos[i];
			delete[] idx.elementos;
			idx.elementos = nuevo;
		}
		for (int i = idx.tam; i > pos; i--)
			idx.elementos[i] = idx.elementos[i - 1];
		idx.elementos[pos].clave = palabra;
		idx.tam++;
		inicializar(idx.elementos[pos].valor);
		idx.elementos[pos].valor.elementos[0] = nombreArchivo;
		idx.elementos[pos].valor.tam = 1;
	}
}
