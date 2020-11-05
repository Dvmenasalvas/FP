#include <string>
#include <iostream>
#include <fstream>


struct tPrograma {
	std::string nombre;
	int hora, duracion;
};

bool cargar(std::istream & archivo, tPrograma & programa);
void mostrar(tPrograma const & programa);
void mostrarFecha(tPrograma const & programa);