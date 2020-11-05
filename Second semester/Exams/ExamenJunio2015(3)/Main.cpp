#include "Grabaciones.h"

int menu() {
	int op;
	do {
		std::cout << "1. Programar una grabacion nueva." << '\n';
		std::cout << "2. Mostrar las grabaciones programadas hasta ahora." << '\n';
		std::cout << "3. Salir" << '\n';
		std::cout << "Elija su opcion: ";
		op = pedirEntero();
	} while (op <= 0 || op > 3);
	
	return op;
}

int main() {
	tListaProgramas programas;
	programas.tam = 0;
	cargar(programas);

	tGrabaciones grabaciones = crear();
	int op;
	do {
		op = menu();
		switch (op) {
		case 1:
			tGrabacion nueva;
			nueva.programa = selecPrograma(programas);
			if (nueva.programa != nullptr) {
				if (insertar(grabaciones, nueva)) std::cout << "La grabación ha sido programada con exito. " << '\n';
				else std::cout << "No se ha podido programar la grabacion." << '\n';
			}
			break;
		case 2:
			mostrar(grabaciones);
			break;
		}
		std::cout << '\n';
	} while (op != 3);

	return 0;
}