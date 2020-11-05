#include "Grabaciones.h"

tGrabaciones crear() {
	tGrabaciones lista;
	lista.grabaciones = new tGrabacion[CAP];
	return lista;
}

bool solapan(tGrabacion const & a, tGrabacion const & b) {
	return a.programa->hora == b.programa->hora;
}

bool insertar(tGrabaciones & lista, tGrabacion const & grabacion) {
	bool exito = true;
	int i = 0;
	while (exito && i < lista.tam) {
		if (solapan(grabacion, lista.grabaciones[i])) exito = false;
		i++;
	}
	if (lista.capacidad <= lista.tam) exito = false;
	if (exito) {
		lista.grabaciones[lista.tam] = grabacion;
		lista.tam++;
	}
	return exito;
}
void mostrar(tGrabaciones const & lista) {
	if (lista.tam <= 0) std::cout << "No hay ninguna grabacion programada. " << '\n';
	else {
		for (int i = 0; i < lista.tam; i++)
			mostrar(*lista.grabaciones[i].programa);
		std::cout << '\n';
	}
}
void destruir(tGrabaciones const & grabaciones) {
	delete[] grabaciones.grabaciones;
}