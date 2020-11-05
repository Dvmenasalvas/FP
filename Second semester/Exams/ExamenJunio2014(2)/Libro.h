#include <string>
#include <iostream>
#include <iomanip>

struct tLibro {
	int codigo;
	std::string fecha;
	int diasPrestamo;
};

void muestra(tLibro const & libro);