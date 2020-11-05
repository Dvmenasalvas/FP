#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int ancho1, largo1, alto1, ancho2, largo2, alto2, cajas;
		cin >> ancho1;
		while ( (ancho1 <= 0) || (ancho1 > 3)) {
			cin >> ancho1;
		}
		cin >> alto1;
		while ( (alto1 <= 0) || (alto1 > 3)){
			cin >> alto1;
		}
		cin >> largo1;
		while ( (largo1 <= 0) || (largo1 > 10) ) {
			cin >> largo1;
		}

		cin >> ancho2;
		while ( (ancho2 < 10) || (ancho2 > 100) ) {
			cin >> ancho2;
		}
		cin >> alto2;
		while ( (alto2 < 10) || (alto2 > 100) ) {
			cin >> alto2;
		}
		cin >> largo2;
		while ( (largo2 < 10) || (largo2 > 100) ) {
			cin >> largo2;
		}
		
		
		ancho1 = ancho1 * 100;
		largo1 = largo1 * 100;
		alto1 = alto1 * 100;

		cajas = (ancho1 / ancho2) * (largo1 / largo2) * (alto1 / alto2);
		cout << cajas << endl;
	}
	return 0;

}