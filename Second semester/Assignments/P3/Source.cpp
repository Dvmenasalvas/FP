//Daniel Valverde Menasalvas y Eloy Mosig García 
//Grupo Doble Grado en Informática y Matemáticas
//Práctica 3
#include "juego.h"
#include <conio.h>

enum tTecla {Arriba, Abajo, Derecha, Izquierda, Salir, Nada, Deshacer}; //Tipos de teclas a leer

tTecla leerTecla() {
	tTecla tecla;

	std::cin.sync();
	int dir = _getch(); //tipo int
	if (dir == 0xe0) dir = _getch();

	switch (dir) {
	case 27:
		tecla = Salir;
		break;
	case 72:
		tecla = Arriba;
		break;
	case 80:
		tecla = Abajo;
		break;
	case 77:
		tecla = Derecha;
		break;
	case 75:
		tecla = Izquierda;
		break;
	case 100:
	case 68:
		tecla = Deshacer;
		break;
	default:
		tecla = Nada;
	}

	return tecla;
}



void mover(int vertical, int horizontal, tJuego &juego) {
	switch (juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal]) {
	case Libre:
	case DestinoL:
		guardarTablero(juego);  //Si nos movemos hacia una casilla vacia, podemos hacer el movimiento, guardamos el tablero, incrementamos numMovimientos y procedemos
		juego.numMovimientos++;
		if (juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] == DestinoL)
			juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] = DestinoJ;
		else
			juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] = Jugador;

		if (juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] == DestinoJ)
			juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] = DestinoL;
		else
			juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] = Libre;
		juego.sokoban.fila += vertical;
		juego.sokoban.columna += horizontal;
		break;
	case Caja:
	case DestinoC:
		if ((juego.sokoban.tablero[juego.sokoban.fila + (vertical * 2)][juego.sokoban.columna + (horizontal * 2)] == Libre) || (juego.sokoban.tablero[juego.sokoban.fila + (vertical * 2)][juego.sokoban.columna + (horizontal * 2)] == DestinoL)) {
			guardarTablero(juego); //Si nos movemos hacia una caja(o destino caja) y la casilla siguiente es un libre(o Dlibre) podemos hacer el movimiento, guardamos el tablero, incrementamos numMovimientos y procedemos
			juego.numMovimientos++;

			if (juego.sokoban.tablero[juego.sokoban.fila + (vertical * 2)][juego.sokoban.columna + (horizontal * 2)] == DestinoL) {
				juego.sokoban.tablero[juego.sokoban.fila + (vertical * 2)][juego.sokoban.columna + (horizontal * 2)] = DestinoC;
				juego.sokoban.colocadas++;
			}
			else
				juego.sokoban.tablero[juego.sokoban.fila + (vertical * 2)][juego.sokoban.columna + (horizontal * 2)] = Caja;

			if (juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] == DestinoC) {
				juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] = DestinoJ;
				juego.sokoban.colocadas--;
			}
			else
				juego.sokoban.tablero[juego.sokoban.fila + vertical][juego.sokoban.columna + horizontal] = Jugador;

			if (juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] == DestinoJ)
				juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] = DestinoL;
			else
				juego.sokoban.tablero[juego.sokoban.fila][juego.sokoban.columna] = Libre;
			juego.sokoban.fila += vertical;
			juego.sokoban.columna += horizontal;
		}
		break;
	}
}

void hacerMovimiento(tJuego &juego, tTecla tecla) {
	switch (tecla) {
	case Arriba:
		mover(-1, 0, juego);
		break;
	case Abajo:
		mover(1, 0, juego);
		break;
	case Derecha:
		mover(0, 1, juego);
		break;
	case Izquierda:
		mover(0, -1, juego);
		break;
	case Deshacer:
		deshacerMovimiento(juego);
		break;
	}
}

int menu() {
	int op;
	do {
		std::cout << "1. Jugar partida" << '\n';
		std::cout << "2. Mostrar exitos" << '\n';
		std::cout << "0. Salir" << '\n';
		std::cout << "Elija su opcion: ";
		std::cin >> op;
		while (std::cin.fail()) { //Comprobamos que se inserte un entero
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Por favor, inserte un entero: ";
			std::cin >> op;
		}
		std::cin.ignore(10000, '\n');
	} while ((op < 0) || (op > 2));

	return op;
}

int main() {
	tJuego juego;
	int op;
	tInfo info;

	std::cout << "¡Bienvenido a sokoban!" << '\n';
	std::cout << "Por favor, introduzca su nombre: ";
	std::cin >> info.nombre;

	leerInfo(info);

	do {
		op = menu();
		switch (op) {
		case 1:
			tTecla tecla;
			if (cargarJuego(juego)) {
				dibujar(juego);
				do {
					tecla = leerTecla();
					if ((tecla != Nada) && (tecla != Salir)) {
						hacerMovimiento(juego, tecla); 
						dibujar(juego);
					}
				} while (tecla != Salir && juego.sokoban.cajas != juego.sokoban.colocadas);
				if (tecla == Salir) system("cls");
				if (juego.sokoban.cajas == juego.sokoban.colocadas) actualizarInfo(info, juego);
			}
			break;
		case 2:
			mostrarInfo(info);
		}
		std::cout << '\n';
	} while (op != 0);
	
	guardarInfo(info);

	return 0;
}