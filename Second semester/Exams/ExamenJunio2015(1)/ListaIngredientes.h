#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int TAM = 50;
const string ARCHIVO = "ingredientes.txt";

struct tIngrediente {
	string nombre;
	int calorias;
};

struct tListaIngredientes {
	tIngrediente * elementos[TAM];
	int tam = 0;
};

void inserta(tListaIngredientes & lista, tIngrediente const & nuevo);
void carga(tListaIngredientes & lista);
int selecIngred(tListaIngredientes const & lista);
bool busca(tListaIngredientes const & lista, string nombre, int & pos);
bool buscaAux(tListaIngredientes const & lista, string nombre, int & pos, int ini, int fin);
int pedirInt();