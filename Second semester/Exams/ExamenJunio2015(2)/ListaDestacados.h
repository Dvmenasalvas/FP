#include "ListaJugadores.h"

const int CAP = 2;

struct tElemento {
	tJugador* jugador;
	bool todasGanadas;
};

struct tListaDestacados {
	tElemento* destacados;
	int tam = 0, capacidad;
};

tListaDestacados destacados(tListaJugadores const & jugadores);
void insertar(tListaDestacados & lista, tElemento const & elemento);
void mostrar(tListaDestacados const & lista);
tJugador* todasGanadas(tListaDestacados const & destacados);
tJugador* todasGanadasAux(tListaDestacados const & destacados,int ini, int fin);