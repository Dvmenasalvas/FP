#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int insectos, aracnidos, crustaceos, escolopendras, anillos, patas;
		cin >> insectos >> aracnidos >> crustaceos >> escolopendras >> anillos;

		patas = insectos * 6 + aracnidos * 8 + crustaceos * 10 + escolopendras * anillos * 2;
		cout << patas << endl;
	}
	return 0;

}