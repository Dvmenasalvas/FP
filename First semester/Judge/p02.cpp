#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int n1, n2, suma = 0;
		cin >> n1;
		if (n1 < 0) n1 = 0;
		if (n1 > 10000) n1 = 10000;
		cin >> n2;
		if (n2 < n1) n2 = n1;
		while (n1 <= n2) {
				suma += n1;
				n1++;
		}
		cout << suma << endl;
		
	}
	return 0;

}