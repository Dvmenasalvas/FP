//Daniel Valverde Menasalvas y Eloy Mosig García 
//Grupo Doble Grado en Informática y Matemáticas
//Práctica 3
#ifndef	sokoban_h
#define	sokoban_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <Windows.h>

const int MAX = 50;

enum tCasilla{ Libre, Muro, DestinoL, DestinoC, DestinoJ, Jugador, Caja }; //Tipos de casillas

typedef tCasilla tTablero[MAX][MAX]; //Matriz del tablero con su tam maximo

struct tSokoban{   //Struct del sokoban(tablero)
	tTablero tablero;
	int nfilas, ncolumnas;
	int fila, columna;
	int cajas, colocadas;
};

void colorFondo(int	color); //Cambia el color de fondo al indicado
void dibujaCasilla(tCasilla casilla); //Dibuja la casilla que se le pase por argumento

#endif