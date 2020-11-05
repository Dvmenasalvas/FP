#include "ListaClientes.h"

bool encuentra(tListaClientes const & lista, std::string NIF, int & pos) {
	return encuentraAux(lista, NIF, pos, 0, lista.tam);
}

bool encuentraAux(tListaClientes const & lista, std::string NIF, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) {
		encontrado = false;
		pos = ini;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (NIF < lista.clientes[med]->NIF) encontrado = encuentraAux(lista, NIF, pos, ini, med);
		else if (lista.clientes[med]->NIF < NIF) encontrado = encuentraAux(lista, NIF, pos, med + 1, fin);
		else {
			encontrado = true;
			pos = med;
		}
	}
	return encontrado;
}
float totalVentas(tListaClientes const & lista) {
	float total = 0;
	for (int i = 0; i < lista.tam; i++)
		total += totalVentas(lista.clientes[i]->ventas);
	return total;
}
void insertaCliente(tListaClientes & lista, std::string NIF, tProducto const & producto) {
	if (lista.tam < CLIENT_MAX) {
		int pos;
		if (!encuentra(lista, NIF, pos)) {
			for (int i = lista.tam; i > pos; i--)
				lista.clientes[i] = lista.clientes[i - 1];
			lista.clientes[pos] = new tCliente;
			lista.clientes[pos]->NIF = NIF;
			inicializa(lista.clientes[pos]->ventas);
			insertaProd(lista.clientes[pos]->ventas, producto);
			lista.tam++;
		}
	}
}
void carga(tListaClientes & lista) {
	std::ifstream archivo;
	archivo.open(DATOS);
	if (archivo.is_open()) {
		std::string NIF;
		tProducto producto;
		archivo >> NIF;
		while (NIF != "XXX") {
			int pos;
			archivo >> producto.codigo >> producto.precio >> producto.unidades;
			if (encuentra(lista, NIF, pos)) insertaProd(lista.clientes[pos]->ventas, producto);
			else insertaCliente(lista, NIF, producto);
			archivo >> NIF;
		}
		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << DATOS << '\n';
}
void muestra(tListaClientes const & lista) {
	for (int i = 0; i < lista.tam; i++) {
		std::cout << "------------------------" << '\n';
		std::cout << "Cliente: " << lista.clientes[i]->NIF << '\n';
		muestra(lista.clientes[i]->ventas);
	}
	std::cout << "Total venta: " << totalVentas(lista) << " $" << '\n';
}
void destruye(tListaClientes const & lista) {
	for (int i = 0; i < lista.tam; i++) {
		destruye(lista.clientes[i]->ventas);
		delete lista.clientes[i];
	}
}