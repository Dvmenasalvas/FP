#include "ListaJugadores.h"


bool cargar(std::string nomArchivo, tListaJugadores & lista) {
	bool encontrado = false;
	std::ifstream archivo;
	archivo.open(nomArchivo);
	if (archivo.is_open()) {
		encontrado = true;
		archivo >> lista.tam;
		for (int i = 0; i < lista.tam; i++) {
			lista.jugadores[i] = new tJugador;
			archivo >> lista.jugadores[i]->nombre >> lista.jugadores[i]->partidas >> lista.jugadores[i]->ganadas >> lista.jugadores[i]->maxp;
		}
		archivo.close();
	}
	else {
		std::cout << "No se ha podido abrir el archivo " << nomArchivo << "." << '\n';
	}
	return encontrado;
}
void actualizar(tListaJugadores & maestra, tListaJugadores const & actualizaciones) {
	int posMaestra;
	for (int i = 0; i < actualizaciones.tam; i++) {
		buscar(maestra, actualizaciones.jugadores[i]->nombre, posMaestra);
		maestra.jugadores[posMaestra]->partidas += actualizaciones.jugadores[i]->partidas;
		maestra.jugadores[posMaestra]->ganadas += actualizaciones.jugadores[i]->ganadas;
		if(actualizaciones.jugadores[i]->maxp > maestra.jugadores[posMaestra]->maxp)
			maestra.jugadores[posMaestra]->maxp = actualizaciones.jugadores[i]->maxp;
	}
}

bool buscar(tListaJugadores const & lista, std::string buscado, int & pos) {
	return buscarAux(lista, buscado, pos, 0, lista.tam);
}

bool buscarAux(tListaJugadores const & lista, std::string buscado, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) {
		encontrado = false;
		pos = ini;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (buscado < lista.jugadores[med]->nombre)
			encontrado = buscarAux(lista, buscado, pos, ini, med);
		else if(lista.jugadores[med]->nombre < buscado)
			encontrado = buscarAux(lista, buscado, pos, med + 1, fin);
		else {
			encontrado = true;
			pos = med;
		}
	}
	return encontrado;
}

void mostrar(tListaJugadores const & lista) {
	if (lista.tam > 0) {
		std::cout << std::setw(10) << std::left << "Nombre" << std::setw(8) << std::right << "Partidas" << std::setw(8) << std::right << "Ganadas" << std::setw(8) << std::right << "Puntos" << '\n';
		for (int i = 0; i < lista.tam; i++) {
			mostrar(*lista.jugadores[i]);
		}
		std::cout << '\n';
	}
}