#include "Componente.h"

const int CAP_INI = 2;

struct tReceta {
	tComponente* componentes;
	int tam, capacidad;
	string nombre;
};

tReceta crea();
void inserta(tReceta & receta, tComponente const & componente);
void muestra(tReceta const & receta);
