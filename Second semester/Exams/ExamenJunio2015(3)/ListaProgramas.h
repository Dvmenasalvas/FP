#include "Programa.h"

const int MAX = 20;
const std::string ARCHIVO = "programas.txt";

struct tListaProgramas {
	tPrograma* programas[MAX];
	int tam = 0;
};

void insertar(tListaProgramas & lista, tPrograma const & programa);
bool buscar(tListaProgramas const & lista, tPrograma const & programa, int & pos);
bool buscarAux(tListaProgramas const & lista, tPrograma const & programa, int & pos, int ini, int fin);
void cargar(tListaProgramas & lista);
tPrograma* selecPrograma(tListaProgramas const & lista);
int pedirEntero();
void destruir(tListaProgramas const & lista);