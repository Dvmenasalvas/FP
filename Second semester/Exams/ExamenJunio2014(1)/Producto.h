#include <string>
#include <iostream>
#include <iomanip>


struct tProducto {
	int codigo;
	float precio;
	int unidades;
};

void muestra(tProducto const & producto);
float totalVenta(tProducto const & producto);