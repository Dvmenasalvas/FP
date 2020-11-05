#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		string a, b, c;
		cin >> a >> b >> c;
		if (a < b) {
			if (a < c) {
				cout << a << ",";
				if (b < c) cout << b << "," << c << endl;
				else cout << c << "," << b << endl;
			}
			else cout << c << "," << a << "," << b << endl;
		}
		else {
			if (b < c) {
				cout << b << ",";
				if (c < a) cout << c << "," << a << endl;
				else cout << a << "," << c << endl;
			}
			else cout << c << "," << b << "," << a << endl;
		}
	}
	return 0;

}