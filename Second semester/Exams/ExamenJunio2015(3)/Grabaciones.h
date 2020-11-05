#include "ListaProgramas.h"

const int CAP = 20;

struct tGrabacion {
	tPrograma* programa;
	bool grabado;
};

struct tGrabaciones {
	tGrabacion* grabaciones;
	int tam = 0, capacidad = CAP;
};

tGrabaciones crear();
bool solapan(tGrabacion const & a, tGrabacion const & b);
bool insertar(tGrabaciones & lista, tGrabacion const & grabacion);
void mostrar(tGrabaciones const & lista);
void destruir(tGrabaciones const & grabaciones);