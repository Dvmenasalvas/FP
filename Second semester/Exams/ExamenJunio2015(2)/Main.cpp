#include "ListaDestacados.h"

const std::string LINI = "jugadores.txt";
const std::string LACT = "actualiza.txt";

int main() {
	tListaJugadores maestra, actualizacion;
	cargar(LINI, maestra);
	cargar(LACT, actualizacion);

	actualizar(maestra, actualizacion);
	mostrar(maestra);

	tListaDestacados listaDestacados = destacados(maestra);
	mostrar(listaDestacados);

	tJugador* ganador = todasGanadas(listaDestacados);
	if (ganador != nullptr) mostrar(*ganador);

	for (int i = 0; i < maestra.tam; i++)
		delete maestra.jugadores[i];
	for (int i = 0; i < actualizacion.tam; i++)
		delete actualizacion.jugadores[i];
	delete[] listaDestacados.destacados;

	system("pause");

	return 0;
}