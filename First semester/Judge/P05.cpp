#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int anio;
		cin >> anio;
		while ( (anio < 1582) || (anio > 10000)) {
			cin >> anio;
		}
				if ((anio % 4) == 0){
					if ((anio % 100) == 0) {
						if ((anio % 400) == 0) {
							cout << "SI" << endl;
						} else cout << "NO" << endl;
					} else cout << "SI" << endl;
				} else cout << "NO" << endl;
			}
	return 0;

}