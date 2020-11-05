#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		int D, d, c, r;
		cin >> D >> d;
		if (d == 0) cout << "DIV0" << endl;
		else {
			r = D % d;
			if ((D < 0) && (r != 0)) {
					if (d > 0) {
						c = D / d -1;
						r = D % d + d;
					} else {
						c = D / d + 1;
						r = D % d - d;
					}
			} else {
				c = D / d;
				r = D % d;
			}
			cout << c << " " << r << endl;
		}
	}
	return 0;
}