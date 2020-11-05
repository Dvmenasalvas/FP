#include "Examen.h"

int menu() {
	int op;
	do {
		std::cout << "1. Nueva pregunta" << '\n';
		std::cout << "2. Mostrar examen" << '\n';
		std::cout << "3. Salir" << '\n';
		std::cout << "Elija una opcion: ";
		op = pedirEntero();
	} while (op <= 0 || op > 3);
	return op;
}

int main() {
	tListaEnunciados enunciados;
	enunciados.tam = 0;
	cargar(enunciados);
	tExamen examen = iniciar();
	int op;
	do {
		op = menu();
		std::cout << '\n';
		switch (op) {
		case 1:
			if (examen.tam == enunciados.tam) std::cout << "Se han usado todos los enunciados disponibles en este examen." << '\n';
			else insertar(examen, nuevaPregunta(enunciados, examen));
			break;
		case 2:
			mostrar(examen, enunciados);
			break;
		}
		std::cout << '\n';

	} while (op != 3);

	guardar(examen);
	
	for (int i = 0; i < enunciados.tam; i++)
		delete enunciados.enunciados[i];
	delete[] examen.preguntas;

	return 0;
}