#include "ListaEnunciados.h"
#include <stdlib.h>
#include <time.h>


const std::string SALIDA = "examen.txt";
const int CAP_INI = 3;

enum tResultado { correcta, incorrecta, pendiente };

struct tPregunta {
	std::string identificador;
	int respuesta;
	tResultado resultado;
};

struct tExamen {
	tPregunta* preguntas;
	int tam, capacidad, aciertos;
};

tExamen iniciar();
tPregunta nuevaPregunta(tListaEnunciados const & enunciados, tExamen const & examen);
void insertar(tExamen & examen, tPregunta const & pregunta);
void mostrar(tExamen const & examen, tListaEnunciados const & enunciados);
void guardar(tExamen const & examen);
void guardarPreguntas(tExamen const & examen, std::ofstream & archivo, int ini, int fin);
int pedirEntero();