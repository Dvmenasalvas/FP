#ifndef CLAVEVALOR_H
#define CLAVEVALOR_H

#include "listacadenas.h"
#include <string>
#include <iostream>
#include <fstream>

const int TAMCV = 200;

struct tClaveValor {
	std::string clave;
	tListaCadenas<std::string> valor;
};

struct tIndicePalabras{
	tClaveValor elementos[TAMCV];
	int tam;
};

bool busquedaBinaria(tIndicePalabras const& l, std::string const& s, int & pos);
void insertarOrdenado(tIndicePalabras & idx, std::string const& palabra, std::string const& nombreArchivo);

#endif