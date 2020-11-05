#include "DateList.h"

tDateList newList() {
	tDateList list;
	list.capacidad = CAP_INI;
	list.tam = 0;
	list.lista = new tDate[CAP_INI];
	return list;
}
void insert(tDateList & list, tDate const & date) {
	if (list.tam >= list.capacidad) {
		tDate* aux;
		list.capacidad += 10;
		aux = new tDate[list.capacidad];
		for (int i = 0; i < list.tam; i++)
			aux[i] = list.lista[i];
		delete[] list.lista;
		list.lista = aux;
	}
	int i = list.tam;
	while (i > 0 && date.rate < list.lista[i - 1].rate) {
		list.lista[i] = list.lista[i - 1];
		i--;
	}
	list.lista[i] = date;
	list.tam++;
}
void display(tDateList const & list) {
	std::cout << "Date List..." << '\n';
	for (int i = 0; i < list.tam; i++) {
		std::cout << "--------------------------------------------------" << '\n';
		display(*list.lista[i].a);
		display(*list.lista[i].b);
		std::cout << "Date in " << list.lista[i].place << ". Rating: " << list.lista[i].rate << '\n';
	}
}
void free(tDateList const & dates, tClientList const & clients) {
	free(clients);
	delete[] dates.lista;
}