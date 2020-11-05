#include "Libro.h"

void muestra(tLibro const & libro) {
	std::cout << std::setw(15) << std::left << libro.codigo << "-   " << libro.fecha << " -" << std::setw(7) << std::right << libro.diasPrestamo << '\n';
}