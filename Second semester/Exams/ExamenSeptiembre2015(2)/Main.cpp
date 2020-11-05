#include "ListaEmpleados.h"
using namespace std;

int pedirEntero() {
	int entero;
	cin >> entero;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> entero;
	}
	cin.ignore(10000, '\n');
	
	return entero;
}

int menu() {
	int op;
	do {
		cout << "1.- Datos de la plantilla" << '\n';
		cout << "2.- Empleados con menos de la mitad de las vacaciones disfrutadas" << '\n';
		cout << "0.- Salir" << '\n';
		cout << "Elija una opcion: ";
		op = pedirEntero();
		cout << '\n';
	} while (op < 0 || op > 2);

	return op;
}	


int main() {
	tListaEmpleados lista;
	lista.tam = 0;
	cargar(lista);
	procesarVacaciones(lista);
	int op;
	do {
		op = menu();
		switch (op) {
		case 1:
			mostrar(lista);
			break;
		case 2:
			mostrarEmpleadosSinMitad(lista);
			break;
		}
		cout << '\n';
	} while (op != 0);

	return 0;
}