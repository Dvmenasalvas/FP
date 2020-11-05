#include "ListaEnunciados.h"

bool insertar(tListaEnunciados & lista, tEnunciado const & enunciado) {
	int pos;
	bool insertado = false;
	if (!buscar(lista, enunciado.identificador, pos) && lista.tam < MAX_PREG) {
		insertado = true;
		for (int i = lista.tam; i > pos; i--)
			lista.enunciados[i] = lista.enunciados[i - 1];
		lista.enunciados[pos] = new tEnunciado;
		*lista.enunciados[pos] = enunciado;
		lista.tam++;
	}
	return insertado;
}

bool buscar(tListaEnunciados const & lista, std::string buscado, int & pos) {
	return buscarAux(lista, buscado, pos, 0, lista.tam);
}
bool buscarAux(tListaEnunciados const & lista, std::string buscado, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) {
		encontrado = false; pos = ini;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (buscado < lista.enunciados[med]->identificador) encontrado = buscarAux(lista, buscado, pos, ini, med);
		else if (lista.enunciados[med]->identificador < buscado) encontrado = buscarAux(lista, buscado, pos, med + 1, fin);
		else {
			encontrado = true;
			pos = med;
		}
	}
	return encontrado;
}
void cargar(tListaEnunciados & lista) {
	std::ifstream archivo;
	archivo.open(ENTRADA);
	if (archivo.is_open()) {
		tEnunciado nuevo;
		archivo >> nuevo.identificador;
		while (nuevo.identificador != "XXX") {
			archivo.ignore(1000, '\n');
			std::getline(archivo, nuevo.texto);
			archivo >> nuevo.solucion;
			insertar(lista, nuevo);
			archivo >> nuevo.identificador;
		}
		archivo.close();
	}	
	else std::cout << "No se ha podido abrir el archivo " << ENTRADA << "." << '\n';

}