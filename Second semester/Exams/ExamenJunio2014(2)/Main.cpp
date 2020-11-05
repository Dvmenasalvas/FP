#include "ListaEstudiantes.h"

int main() {
	tListaEstudiantes lista;
	lista.tam = 0;
	carga(lista);
	muestra(lista);
	destruye(lista);

	system("pause");

	return 0;
}