#include "ListaClientes.h"

int main() {
	tListaClientes clientes;
	clientes.tam = 0;
	carga(clientes);
	muestra(clientes);
	destruye(clientes);

	system("pause");

	return 0;
}