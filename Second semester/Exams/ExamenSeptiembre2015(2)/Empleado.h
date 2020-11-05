#include "Calendario.h"
#include <fstream>
#include <iostream>
#include <iomanip>

struct tEmpleado {
	std::string dni, nombre, apellido1, apellido2;
	tCalendario calendario;
};

void cargar(tEmpleado & empleado, std::istream & archivo);
void reservarVacacines(tEmpleado & empleado, int mes, int dia);
void mostrar(tEmpleado const & empleado);