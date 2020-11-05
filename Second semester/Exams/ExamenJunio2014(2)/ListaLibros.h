#include "Libro.h"

const int MAX_LIBROS = 20;

struct tListaLibros {
	tLibro* libros[MAX_LIBROS];
	int tam;
};

void insertaLibro(tListaLibros & lista, tLibro const & libro);
void muestra(tListaLibros const & lista, int pos);
void destruye(tListaLibros const & lista);