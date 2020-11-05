#include "Jugador.h"
#include <fstream>

const int MAX = 50;

struct tListaJugadores {
	tJugador * jugadores[MAX];
	int tam = 0;
};

bool cargar(std::string nomArchivo, tListaJugadores & lista);
void actualizar(tListaJugadores & maestra, tListaJugadores const & actualizaciones);
bool buscar(tListaJugadores const & lista, std::string buscado, int & pos);
bool buscarAux(tListaJugadores const & lista, std::string buscado, int & pos, int ini, int fin);
void mostrar(tListaJugadores const & lista);