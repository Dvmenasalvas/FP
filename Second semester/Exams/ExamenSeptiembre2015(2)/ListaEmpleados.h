#include "Empleado.h"


const int MAX_EMP = 100;
const std::string EMPLEADOS = "empleados.txt";
const std::string VACACIONES = "vacaciones.txt";

struct tListaEmpleados {
	tEmpleado* empleados[MAX_EMP];
	int tam = 0;
};

bool buscar(tListaEmpleados const & lista, std::string dni, int & pos);
bool buscarAux(tListaEmpleados const & lista, std::string dni, int & pos, int ini, int fin);
void insertar(tListaEmpleados & lista, tEmpleado const & empleado);
void cargar(tListaEmpleados & lista);
void mostrar(tListaEmpleados const & lista);
void procesarVacaciones(tListaEmpleados & lista);
void mostrarEmpleadosSinMitad(tListaEmpleados const & lista);