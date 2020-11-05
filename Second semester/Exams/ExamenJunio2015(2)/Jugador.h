#include <string>
#include <iostream>
#include <iomanip>

struct tJugador {
	std::string nombre;
	int partidas, ganadas, maxp;
};

void mostrar(tJugador const & jugador);