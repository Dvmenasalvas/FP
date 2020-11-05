//Daniel Valverde Menasalvas y Eloy Mosig García 
//Grupo Doble Grado en Informática y Matemáticas
//Práctica 3
#include "sokoban.h"

void colorFondo(int	color)	{
	HANDLE	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void dibujaCasilla(tCasilla casilla) {
	switch (casilla) {
	case Libre:
		colorFondo(15);
		std::cout << "  ";
		break;
	case Muro:
		colorFondo(0);
		std::cout << "  ";
		break;
	case DestinoL:
		colorFondo(7);
		std::cout << "  ";
		break;
	case DestinoC:
		colorFondo(8);
		std::cout << "  ";
		break;
	case DestinoJ:
		colorFondo(4);
		std::cout << "  ";
		break;
	case Jugador:
		colorFondo(12);
		std::cout << "  ";
		break;
	case Caja:
		colorFondo(6);
		std::cout << "  ";
		break;
	}
	colorFondo(0);
}
