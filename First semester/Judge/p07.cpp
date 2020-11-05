#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int p1, p2, a1, a2, ancho, alto, azulejos;
		bool maquina;
		maquina = 0;
		
		cin >> p1;
		while ((p1 < 100) || (p1 > 1000)) cin >> p1;
		cin >> p2;
		while ((p2 < 50) || (p2 > 300)) cin >> p2;
		cin >> a1;
		while ((a1 < 1) || (a1 > 50)) cin >> a1;
		cin >> a2;
		while ((a2 < 1) || (a2 > 50)) cin >> a2;
		
		ancho = p1 / a1;
		if ((p1 % a1) != 0) {
			ancho++;
			maquina = 1;
		}
		alto = p2 / a2;
		if ((p2 % a2) != 0) {
			alto++;
			maquina = 1;
		}
		
		azulejos = ancho * alto;
		if (maquina) {
			cout << azulejos << " NECESITA COMPRAR MAQUINA" << endl;
		} else {
			cout << azulejos << endl;
		}
	}
	return 0;
}