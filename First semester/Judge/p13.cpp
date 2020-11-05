#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool casoDePrueba() {
	string palabra;
	bool sigue = true;
	cin >> palabra;
	if (palabra == "XXX")
		return false;
	else {
		int a = 1;
		while (sigue && (a < palabra.length())) {
			if (palabra[a] == palabra[a - 1]) {
				cout << a - 1 << endl;
				sigue = false;
			}
			a++;
		}
		if (sigue) cout << "NO" << endl;
		return true;
	}
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}
