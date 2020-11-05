#ifndef CLAVEVALOR_H
#define CLAVEVALOR_H

#include "listacadenas.h"
#include <string>
#include <iostream>
#include <fstream>

struct tClaveValor {
	std::string clave;
	tListaCadenas<std::string> valor;
};

struct tIndicePalabras{
	tClaveValor* elementos;
	int tam = 0, capacidad = TAMINI;
};

bool busquedaBinaria(tIndicePalabras const& l, std::string const& s, int & pos);
void insertarOrdenado(tIndicePalabras & idx, std::string const& palabra, std::string const& nombreArchivo);


#endif