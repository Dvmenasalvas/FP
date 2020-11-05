#include <string>
#include <fstream>
#include <iostream>

const int MAX_PREG = 50;
const std::string ENTRADA = "enunciados.txt";

struct tEnunciado {
	std::string identificador;
	std::string texto;
	int solucion;
};

struct tListaEnunciados {
	tEnunciado* enunciados[MAX_PREG];
	int tam;
};

bool insertar(tListaEnunciados & lista, tEnunciado const & enunciado);
bool buscar(tListaEnunciados const & lista, std::string buscado, int & pos);
bool buscarAux(tListaEnunciados const & lista, std::string buscado, int & pos, int ini, int fin);
void cargar(tListaEnunciados & lista);