#ifndef INDICES_H
#define INDICES_H

#include "matriz.h"
#include "listacadenas.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include "clavevalor.h"

bool crearTabla(tIndicePalabras & tabla, tListaCadenas<std::string> & totales, tMatriz & L);
void quitarFin(std::string & palabra);


#endif
