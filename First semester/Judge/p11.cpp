#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int longitud = -1, pares = 0;
		while ((longitud < 0)||(longitud > 10000)) cin >> longitud;
		const int Dim = 10000;
		typedef int tNum[Dim];
		tNum array;
		for (int i = 0; i < longitud; i++) {
			cin >> array[i];
			if (array[i] % 2 == 0) pares++;
		}
			cout << pares << endl;
	}
	return 0;

}