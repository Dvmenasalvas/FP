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
		long long int n, suma = 0;
		cin >> n;
		while(n < 0) {
			cin >> n;
		}
		while((n > 0) || (suma >= 10)) {
			suma = suma + (n % 10);
			n = n / 10;
			if ((n == 0) && (suma >= 10)) {
				n = suma;
				suma = 0;
			}
		}
		cout << suma << endl;
	}
	return 0;

}