#include "ListaProgramas.h"

void insertar(tListaProgramas & lista, tPrograma const & programa) {
	int pos;
	buscar(lista, programa, pos);
	for (int i = lista.tam; i > pos; i--)
		lista.programas[i] = lista.programas[i - 1];
	lista.programas[pos] = new tPrograma;
	*lista.programas[pos] = programa;
	lista.tam++;
}

bool buscar(tListaProgramas const & lista, tPrograma const & programa, int & pos) {
	return buscarAux(lista, programa, pos, 0, lista.tam);
}

bool buscarAux(tListaProgramas const & lista, tPrograma const & programa, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) { pos = ini; encontrado = false; }
	else {
		int med = (ini + fin - 1) / 2;
		if (lista.programas[med]->nombre < programa.nombre) encontrado = buscarAux(lista, programa, pos, med + 1, fin);
		else if (programa.nombre < lista.programas[med]->nombre) encontrado = buscarAux(lista, programa, pos, 0, med);
		else { pos = med; encontrado = true; }
	}
	return encontrado;
}

void cargar(tListaProgramas & lista) {
	std::ifstream archivo;
	archivo.open(ARCHIVO);
	if (archivo.is_open()) {
		tPrograma programa;
		while (cargar(archivo, programa))
			insertar(lista, programa);

		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << ARCHIVO << '\n';
}
tPrograma* selecPrograma(tListaProgramas const & lista) {
	if (lista.tam > 0) {
		int op;
		for (int i = 0; i < lista.tam; i++)
			std::cout << i + 1 << ". " << lista.programas[i]->nombre << '\n';
		do {
			std::cout << "Elija un programa: ";
			op = pedirEntero();
		} while (op <= 0 || op > lista.tam);
		return lista.programas[op - 1];
	}
	else {
		std::cout << "No hay ningun programa en la lista." << '\n';
		return nullptr;
	}
}

int pedirEntero() {
	int entero;
	std::cin >> entero;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> entero;
	}
	std::cin.ignore(10000, '\n');
	return entero;
}

void destruir(tListaProgramas const & lista) {
	for (int i = 0; i < lista.tam; i++)
		delete lista.programas[i];
}
