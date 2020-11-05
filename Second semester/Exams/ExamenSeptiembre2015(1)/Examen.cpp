#include "Examen.h"


tExamen iniciar() {
	tExamen examen;
	examen.aciertos = 0;
	examen.capacidad = CAP_INI;
	examen.tam = 0;
	examen.preguntas = new tPregunta[examen.capacidad];
	return examen;
}
tPregunta nuevaPregunta(tListaEnunciados const & enunciados, tExamen const & examen) {
	tPregunta nueva;
	if (enunciados.tam > 0) {
		srand(time(NULL));
		bool encontrado = true;
		int pos;
		while (encontrado) {
			pos = rand() % enunciados.tam;
			encontrado = false;
			int i = 0;
			while (i < examen.tam && !encontrado) {
				encontrado = examen.preguntas[i].identificador == enunciados.enunciados[pos]->identificador;
				i++;
			}
		}
		nueva.identificador = enunciados.enunciados[pos]->identificador;
		std::cout << enunciados.enunciados[pos]->texto << '\n';
		std::cin >> nueva.respuesta;
		if (nueva.respuesta == enunciados.enunciados[pos]->solucion) nueva.resultado = correcta;
		else nueva.resultado = incorrecta;
	}
	else std::cout << "No hay ningun enunciado disponible." << '\n';

	return nueva;
}
void insertar(tExamen & examen, tPregunta const & pregunta) {
	if (examen.tam >= examen.capacidad) {
		examen.capacidad *= 2;
		tPregunta* aux = new tPregunta[examen.capacidad];
		for (int i = 0; i < examen.tam; i++)
			aux[i] = examen.preguntas[i];
		delete[] examen.preguntas;
		examen.preguntas = aux;
	}
	examen.preguntas[examen.tam] = pregunta;
	examen.tam++;
	if (pregunta.resultado == correcta) examen.aciertos++;
}
void mostrar(tExamen const & examen, tListaEnunciados const & enunciados) {
	std::cout << "Preguntas: " << examen.tam << '\n';
	for (int i = 0; i < examen.tam; i++) {
		int pos;
		buscar(enunciados, examen.preguntas[i].identificador, pos);
		std::cout << i + 1 << ".- " << enunciados.enunciados[pos]->texto << '\n';
		std::cout << examen.preguntas[i].respuesta << " (";
		switch (examen.preguntas[i].resultado) {
		case 1:
			std::cout << "incorrecta";
			break;
		case 0:
			std::cout << "correcta";
			break;
		case 2:
			std::cout << "pendiente";
			break;
		}
		std:: cout << ")" << '\n';
	}
	std::cout << "Aciertos: " << examen.aciertos << '\n';
}

void guardar(tExamen const & examen) {
	std::ofstream archivo;
	archivo.open(SALIDA);
	if (archivo.is_open()) {
		archivo << examen.tam << '\n';
		if (examen.tam > 0) {
			guardarPreguntas(examen, archivo, 0, examen.tam);
		}
		archivo.close();
	}
	else std::cout << "Hubo un problema escribiendo el archivo " << SALIDA << "." << '\n';

}

void guardarPreguntas(tExamen const & examen,std::ofstream & archivo, int ini, int fin) {
	if (ini == fin - 1) archivo << examen.preguntas[ini].identificador << " " << examen.preguntas[ini].respuesta << " " << examen.preguntas[ini].resultado << '\n';
	else {
		archivo << examen.preguntas[ini].identificador << " " << examen.preguntas[ini].respuesta << " " << examen.preguntas[ini].resultado << '\n';
		guardarPreguntas(examen, archivo, ini + 1, fin);
	}
}

int pedirEntero() {
	int entero;
	std::cin >> entero;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> entero;
	}
	std::cin.ignore(10000, '\n');
	return entero;
}