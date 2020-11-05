#include "Programa.h"

bool cargar(std::istream & archivo, tPrograma & programa) {
	std::getline(archivo, programa.nombre);
	archivo >> programa.hora;
	archivo >> programa.duracion;
	archivo.ignore(1000000, '\n');
	return "XXX" != programa.nombre;
}

void mostrar(tPrograma const & programa) {
	std::cout << programa.nombre << ". " << programa.hora << ". Duración " << programa.duracion << " minutos" << '\n';
}
void mostrarFecha(tPrograma const & programa) {
	std::cout << programa.hora << '\n';
}