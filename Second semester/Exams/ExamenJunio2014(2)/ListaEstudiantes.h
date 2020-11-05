#include "ListaLibros.h"
#include "fstream"

const int MAX_EST = 300;
const std::string DATOS = "datos.txt";

struct tEstudiante {
	std::string NIF;
	tListaLibros libros;
};

struct tListaEstudiantes {
	tEstudiante* estudiantes[MAX_EST];
	int tam;
};

bool encuentra(tListaEstudiantes const & lista, std::string NIF, int & pos);
bool encuentraAux(tListaEstudiantes const & lista, std::string NIF, int & pos, int ini, int fin);
void insertaEstudiante(tListaEstudiantes & lista, std::string NIF, tLibro const & libro);
void carga(tListaEstudiantes & lista);
void muestra(tListaEstudiantes const & lista);
void destruye(tListaEstudiantes const & lista);