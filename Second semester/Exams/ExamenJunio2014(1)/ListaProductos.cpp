#include "ListaProductos.h"

void insertaProd(tListaProd & lista, tProducto const & producto) {
	bool llena = false;
	if (lista.tam >= lista.capacidad) {
		if (lista.capacidad < CAP_MAX) {
			lista.capacidad *= 2;
			if (lista.capacidad > CAP_MAX) lista.capacidad = CAP_MAX;
			tProducto* aux = new tProducto[lista.capacidad];
			for (int i = 0; i < lista.tam; i++)
				aux[i] = lista.productos[i];
			destruye(lista);
			lista.productos = aux;
		}
		else llena = true;
	}
	if (!llena) {
		lista.productos[lista.tam] = producto;
		lista.tam++;
	}
}

void muestra(tListaProd const & lista) {
	for (int i = 0; i < lista.tam; i++)
		muestra(lista.productos[i]);
}

float totalVentas(tListaProd const & lista){
	float total = 0;
	for (int i = 0; i < lista.tam; i++)
		total += totalVenta(lista.productos[i]);
	return total;
}

void destruye(tListaProd const & lista) {
	delete[] lista.productos;
}

void inicializa(tListaProd & lista) {
	lista.tam = 0;
	lista.capacidad = CAP_INI;
	lista.productos = new tProducto[lista.capacidad];
}