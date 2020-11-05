#include "Receta.h"

int menu() {
	int op;
	do {
		cout << "1. Añadir ingrediente a la receta." << '\n';
		cout << "2. Mostrar estado actual de la receta." << '\n';
		cout << "0. Salir" << '\n';
		cout << "Elija su opcion: ";
		op = pedirInt();

	} while (op < 0 || op > 2);
	return op;
}

int main() {
	tListaIngredientes lista;
	carga(lista);

	tReceta receta = crea();
	
	int op = menu();
	while (op != 0) {
		cout << '\n';
		switch (op) {
		case 1:
			inserta(receta, leeComponente(lista));
			break;
		case 2:
			muestra(receta);
			break;
		}
		cout << '\n';
		op = menu();
	}
		
	return 0;
}