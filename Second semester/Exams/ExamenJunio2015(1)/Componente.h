#include "ListaIngredientes.h"
#include <iomanip>

struct tComponente {
	tIngrediente* ingrediente;
	int gramos;
};

tComponente leeComponente(tListaIngredientes const & lista);
void muestra(tComponente const & componente);