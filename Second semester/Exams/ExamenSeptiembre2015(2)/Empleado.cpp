#include "Empleado.h"

void cargar(tEmpleado & empleado, std::istream & archivo) {
	archivo >> empleado.dni >> empleado.nombre >> empleado.apellido1 >> empleado.apellido2;
	inicializar(empleado.calendario);
}
void reservarVacacines(tEmpleado & empleado, int mes, int dia) {
	empleado.calendario[mes][dia] = true;
}
void mostrar(tEmpleado const & empleado) {
	std::cout << empleado.dni << "  " << std::setw(10) << std::left << empleado.nombre << std::setw(10) << std::left << empleado.apellido1 << std::setw(15) << std::left << empleado.apellido2 << std::setw(3) << std::right << numDiasVacaciones(empleado.calendario) << " días de vacaciones" << '\n';
}