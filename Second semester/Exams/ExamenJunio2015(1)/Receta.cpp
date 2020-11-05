#include "Receta.h"

tReceta crea() {
	tReceta receta;
	receta.capacidad = CAP_INI;
	receta.tam = 0;
	receta.componentes = new tComponente[CAP_INI];
	return receta;
}

void inserta(tReceta & receta, tComponente const & componente) {
	if (receta.tam >= receta.capacidad) {
		tComponente * aux;
		receta.capacidad = receta.capacidad * 2;
		aux = new tComponente[receta.capacidad];
		for (int i = 0; i < receta.tam; i++)
			aux[i] = receta.componentes[i];
		delete[] receta.componentes;
		receta.componentes = aux;
	}
	receta.componentes[receta.tam] = componente;
	receta.tam++;
}
void muestra(tReceta const & receta) {
	int calorias = 0;
	cout << "Receta: " << receta.nombre << '\n';
	for (int i = 0; i < receta.tam; i++) {
		muestra(receta.componentes[i]);
		cout << '\n';
		calorias += receta.componentes[i].gramos * receta.componentes[i].ingrediente->calorias;
	}
	cout << "Total de calorías = " << calorias << '\n' << '\n';
}