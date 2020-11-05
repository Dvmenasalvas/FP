#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "checkML.h"
using namespace std; 

const int MAX_TAM = 200;

struct tMatriz{
	double elementos[MAX_TAM][MAX_TAM];
	int lado;
};

struct tVector {
	double elementos[MAX_TAM];
	int tam;
};

tMatriz matrizConstante(double x, int n);
tVector operator*(tVector const & v, tMatriz const & m);
tVector operator*(double x, tVector const & m);
tVector operator+(tVector const& m1, tVector const & m2);
double operator*(tVector const& m1, tVector const & m2);
void normalizaL(tMatriz & L, tVector & a);

#endif