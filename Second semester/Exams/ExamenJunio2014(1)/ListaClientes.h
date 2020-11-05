#include "ListaProductos.h"
#include <fstream>

const int CLIENT_MAX = 100;
const std::string DATOS = "datos.txt";

struct tCliente {
	std::string NIF;
	tListaProd ventas;
};

struct tListaClientes {
	tCliente* clientes[CLIENT_MAX];
	int tam;
};

bool encuentra(tListaClientes const & lista, std::string NIF, int & pos);
bool encuentraAux(tListaClientes const & lista, std::string NIF, int & pos, int ini, int fin);
float totalVentas(tListaClientes const & lista);
void insertaCliente(tListaClientes & lista, std::string NIF, tProducto const & producto);
void carga(tListaClientes & lista);
void muestra(tListaClientes const & lista);
void destruye(tListaClientes const & lista);