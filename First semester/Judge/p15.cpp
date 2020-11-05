#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#include <iomanip>


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i)
	{
		int n, suma = 0;
		cin >> n;
		for (int a = 1; a <= n; a++) {
			suma = 0;
			for (int b = 0; b < n; b++) {
				suma += a + (a * b);
				cout << setw(5) << a + (a * b);
			}
			cout << setw(6) << suma << endl;
		}
	}
	return 0;

}