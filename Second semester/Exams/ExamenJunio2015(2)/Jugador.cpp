#include "Jugador.h" 

void mostrar(tJugador const & jugador) {
	std::cout << std::setw(10) << std::left << jugador.nombre << std::setw(8) << std::right << jugador.partidas << std::setw(8) << std::right << jugador.ganadas << std::setw(8) << std::right << jugador.maxp << '\n';
}