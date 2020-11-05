#include "Componente.h";

tComponente leeComponente(tListaIngredientes  const & lista) {
	tComponente componente;
	int op = selecIngred(lista), gramos;
	componente.ingrediente = lista.elementos[op];
	cout << "Inserte los gramos necesarios del ingrediente: ";
	gramos = pedirInt();
	componente.gramos = gramos;
	return componente;
}

void muestra(tComponente const & componente) {
	cout << "     " << setw(4) << right << componente.gramos << " gr. de " << componente.ingrediente->nombre;
}