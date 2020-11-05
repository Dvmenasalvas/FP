#include "Producto.h"

void muestra(tProducto const & producto) {
		std::cout << std::setw(10) << std::left << producto.codigo << "-" << std::setw(6) << std::right << producto.unidades << " x" << std::setw(11) << std::right << std::fixed << std::setprecision(2)  << producto.precio << " $ =" << std::setw(12) << std::right << std::fixed << std::setprecision(2) << totalVenta(producto) << " $" << '\n';
}
		
float totalVenta(tProducto const & producto) {
	return producto.precio * producto.unidades;
}