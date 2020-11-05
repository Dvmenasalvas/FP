#ifndef	matriz_h
#define	matriz_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <Windows.h>
using namespace std; 

const int TAM = 100;

struct tMatriz{
	int elementos[TAM][TAM];
	int columnas, filas;
};

istream& operator>> (istream& in, tMatriz & matriz);
ostream& operator<< (ostream& out, tMatriz const& matriz);
tMatriz operator* (tMatriz const& a, tMatriz const& b);
void colorFondo(int	color);
tMatriz girarDerecha(tMatriz const& a);
tMatriz girar180(tMatriz const& a);
tMatriz girarIzquierda(tMatriz const& a);

#endif