#include "ListaLibros.h"

void insertaLibro(tListaLibros & lista, tLibro const & libro) {
	if (lista.tam < MAX_LIBROS) {
		int i = lista.tam;
		while (i > 0 && libro.fecha < lista.libros[i - 1]->fecha) {
			lista.libros[i] = lista.libros[i - 1];
			i--;
		}
		lista.libros[i] = new tLibro;
		*lista.libros[i] = libro;
		lista.tam++;
	}
}
void muestra(tListaLibros const & lista, int pos) {
	if (pos < lista.tam) {
		muestra(*lista.libros[pos]);
		muestra(lista, pos + 1);
	}
}
void destruye(tListaLibros const & lista) {
	for (int i = 0; i < lista.tam; i++)
		delete lista.libros[i];
}