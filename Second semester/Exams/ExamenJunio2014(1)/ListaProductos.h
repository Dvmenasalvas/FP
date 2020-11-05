#include "Producto.h"

const int CAP_INI = 2;
const int CAP_MAX = 200;

struct tListaProd {
	tProducto* productos;
	int tam, capacidad;
};

void insertaProd(tListaProd & lista, tProducto const & producto);
void muestra(tListaProd const & lista);
float totalVentas(tListaProd const & lista);
void destruye(tListaProd const & lista);
void inicializa(tListaProd & lista);