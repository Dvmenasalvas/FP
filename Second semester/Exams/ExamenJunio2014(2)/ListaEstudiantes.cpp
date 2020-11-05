#include "ListaEstudiantes.h" 

bool encuentra(tListaEstudiantes const & lista, std::string NIF, int & pos) {
	return encuentraAux(lista, NIF, pos, 0, lista.tam);
}
bool encuentraAux(tListaEstudiantes const & lista, std::string NIF, int & pos, int ini, int fin) {
	bool encontrado;
	if (ini == fin) {
		encontrado = false;
		pos = ini;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (NIF < lista.estudiantes[med]->NIF) encontrado = encuentraAux(lista, NIF, pos, ini, med);
		else if (lista.estudiantes[med]->NIF < NIF) encontrado = encuentraAux(lista, NIF, pos, med + 1, fin);
		else {
			encontrado = true;
			pos = med;
		}
	}
	return encontrado;
}
void insertaEstudiante(tListaEstudiantes & lista, std::string NIF, tLibro const & libro) {
	if (lista.tam < MAX_EST) {
		int pos;
		encuentra(lista, NIF, pos);
		for (int i = lista.tam; i > pos; i--)
			lista.estudiantes[i] = lista.estudiantes[i - 1];
		lista.estudiantes[pos] = new tEstudiante;
		lista.estudiantes[pos]->NIF = NIF;
		lista.estudiantes[pos]->libros.tam = 0;
		insertaLibro(lista.estudiantes[pos]->libros, libro);
		lista.tam++;
	}
}
void carga(tListaEstudiantes & lista) {
	std::ifstream archivo;
	archivo.open(DATOS);
	if (archivo.is_open()) {
		std::string NIF;
		archivo >> NIF;
		while (NIF != "XXX") {
			tLibro libro;
			int pos;
			archivo >> libro.codigo >> libro.fecha >> libro.diasPrestamo;
			if (encuentra(lista, NIF, pos)) insertaLibro(lista.estudiantes[pos]->libros, libro);
			else insertaEstudiante(lista, NIF, libro);
			archivo >> NIF;
		}
		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << DATOS << '\n';
}
void muestra(tListaEstudiantes const & lista) {
	for (int i = 0; i < lista.tam; i++) {
		std::cout << "------------------------" << '\n';
		std::cout << "Estudiante: " << lista.estudiantes[i]->NIF << '\n';
		muestra(lista.estudiantes[i]->libros, 0);
	}
}

void destruye(tListaEstudiantes const & lista) {
	for (int i = 0; i < lista.tam; i++) {
		destruye(lista.estudiantes[i]->libros);
		delete lista.estudiantes[i];
	}
}