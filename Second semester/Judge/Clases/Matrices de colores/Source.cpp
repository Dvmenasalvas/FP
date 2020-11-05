#include "Matriz.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
using namespace std;

enum tTecla {derecha, izquierda, arriba, abajo, Salir, Nada};


tTecla leerTecla() {
	int dir;
	tTecla sal = Nada;
	cin.sync();
	dir = _getch(); //	dir:	tipo	int
	if (dir == 0xe0)	{
		dir = _getch();
	}
	switch (dir) {
	case 77: sal = derecha;
		break;
	case 75: sal = izquierda;
		break;
	case 72: sal = arriba;
		break;
	case 80: sal = abajo;
		break;
	case 27: sal = Salir;
	}

	return sal;
}

int main() {
	ifstream archivo;
	tMatriz a, b;
	tTecla dir = Nada;
	archivo.open("archivo.txt");
	if (archivo.is_open()) {
		archivo >> a;
	}
	archivo.close();

	cout << a << '\n';

	while (dir != Salir) {
		dir = leerTecla();
		switch (dir) {
		case derecha:
			a = girarDerecha(a);
			cout << a << '\n';
			break;
		case abajo:
		case arriba:
			a = girar180(a);
			cout << a << '\n';
			break;
		case izquierda:
			a = girarIzquierda(a);
			cout << a << '\n';
			break;
		}
	}

	
	return 0;
}