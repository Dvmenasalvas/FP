#include "ListaEmpleados.h"

bool buscar(tListaEmpleados const & lista, std::string dni, int & pos) {
	return buscarAux(lista, dni, pos, 0, lista.tam);
}
bool buscarAux(tListaEmpleados const & lista, std::string dni, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) {
		pos = ini; encontrado = false;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (dni < lista.empleados[med]->dni) encontrado = buscarAux(lista, dni, pos, ini, med);
		else if (lista.empleados[med]->dni < dni) encontrado = buscarAux(lista, dni, pos, med + 1, fin);
		else {
			encontrado = true;
			pos = med;
		}
	}
	return encontrado;
}
void insertar(tListaEmpleados & lista, tEmpleado const & empleado) {
	int pos;
	buscar(lista, empleado.dni, pos);
	for (int i = lista.tam; i > pos; i--)
		lista.empleados[i] = lista.empleados[i - 1];
	lista.empleados[pos] = new tEmpleado;
	*lista.empleados[pos] = empleado;
	lista.tam++;
}
void cargar(tListaEmpleados & lista) {
	std::ifstream archivo;
	archivo.open(EMPLEADOS);
	if (archivo.is_open()) {
		tEmpleado nuevo;
		cargar(nuevo, archivo);
		while (nuevo.dni != "XXX") {
			insertar(lista, nuevo);
			cargar(nuevo, archivo);
		}
		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << EMPLEADOS << "." << '\n';
}
void mostrar(tListaEmpleados const & lista) {
	for (int i = 0; i < lista.tam; i++)
		mostrar(*lista.empleados[i]);
}
void procesarVacaciones(tListaEmpleados & lista) {
	std::ifstream archivo;
	archivo.open(VACACIONES);
	if (archivo.is_open()) {
		std::string dni;
		archivo >> dni;
		while (dni != "XXX") {
			int dia, mes, pos;
			archivo >> dia >> mes;
			if (buscar(lista, dni, pos))
				lista.empleados[pos]->calendario[mes][dia] = true;
			archivo >> dni;
		}
		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << VACACIONES << "." << '\n';
}
void mostrarEmpleadosSinMitad(tListaEmpleados const & lista) {
	for (int i = 0; i < lista.tam; i++)
		if (!tieneMitadVacaciones(lista.empleados[i]->calendario))
			mostrar(*lista.empleados[i]);
}