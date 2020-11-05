#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int Tam = 100000;

int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		typedef int tPesos[Tam];
		tPesos pesos;
		int pNinio, c = 0, afines = 0;
		double media = 0;
		bool sigue = true;
		
		cin >> pNinio;
		while (pNinio < 10 || pNinio > 25) cin >> pNinio;
		
		while (sigue && (c < 100000)) {
			cin >> pesos[c];
			if (pesos[c] == 0) sigue = false;
			else {
				while (pesos[c] < 10 || pesos[c] > 25) cin >> pesos[c];
				c++;
			}
		}
		for (int a = 0; a < c; a++) {
			media += pesos[a];
		}
		media /= c;
		if (pNinio >= media) {
			cout << "MAYOR" << " ";
			for (int a = 0; a < c; a++) {
				if (pesos[a] >= media) afines++;
			}
			cout << afines << endl;
		}
		else {
			cout << "MENOR" << " ";
			for (int a = 0; a < c; a++) {
				if (pesos[a] < media) afines++;
			}
			cout << afines << endl;
		}
		

	}
	return 0;

}