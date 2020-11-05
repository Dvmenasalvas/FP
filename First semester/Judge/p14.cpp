#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


bool casoDePrueba() {
	int numero, suma = 0, i = 1;
	cin >> numero;

	if (numero == 0)
		return false;
	else {
		while (suma < numero) {
			suma += i;
			i++;
		}
		if (suma == numero) cout << numero << endl;
		return true;
	}
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}