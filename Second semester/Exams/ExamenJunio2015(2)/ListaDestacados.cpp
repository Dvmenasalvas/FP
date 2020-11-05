#include "ListaDestacados.h"

tListaDestacados destacados(tListaJugadores const & jugadores) {
	tListaDestacados destacados;
	destacados.capacidad = CAP;
	destacados.tam = 0;
	destacados.destacados = new tElemento[destacados.capacidad];
	for (int i = 0; i < jugadores.tam; i++) {
		if (jugadores.jugadores[i]->ganadas > (jugadores.jugadores[i]->partidas - jugadores.jugadores[i]->ganadas)) {
			tElemento nuevo;
			nuevo.jugador = jugadores.jugadores[i];
			nuevo.todasGanadas = jugadores.jugadores[i]->ganadas == jugadores.jugadores[i]->partidas;
			insertar(destacados, nuevo);
		}
	}
	return destacados;
}

void insertar(tListaDestacados & lista, tElemento const & elemento) {
	if (lista.tam >= lista.capacidad) {
		lista.capacidad = lista.capacidad * 2;
		tElemento * aux = new tElemento[lista.capacidad];
		for (int i = 0; i < lista.tam; i++)
			aux[i] = lista.destacados[i];
		delete[] lista.destacados;
		lista.destacados = aux;
	}
	lista.destacados[lista.tam] = elemento;
	lista.tam++;
}

void mostrar(tListaDestacados const & lista) {
	if (lista.tam > 0) {
		std::cout << std::setw(10) << std::left << "Nombre" << std::setw(8) << std::right << "Partidas" << std::setw(8) << std::right << "Ganadas" << std::setw(8) << std::right << "Puntos" << '\n';
		for (int i = 0; i < lista.tam; i++) {
			mostrar(*lista.destacados[i].jugador);
		}
		std::cout << '\n';
	}
}

tJugador* todasGanadas(tListaDestacados const & destacados) {
	return todasGanadasAux(destacados, 0, destacados.tam);
}
tJugador* todasGanadasAux(tListaDestacados const & destacados, int ini, int fin) {
	if (ini >= fin) return nullptr;
	else if (destacados.destacados[ini].todasGanadas) return destacados.destacados[ini].jugador;
	else return todasGanadasAux(destacados, ini + 1, fin);
}