#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
	unsigned int numCasos, i;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		string palabra;
		char c;
		bool a = 0,e = 0,i = 0,o = 0,u = 0;
		cin >> palabra;
		while(palabra.size() > 30) {
			cin >> palabra;
		}
		for (int y = 0; y < palabra.length(); y++) {
			c = palabra.at(y);
			if(c == 'a') a = true;
			if(c == 'e') e = true;
			if(c == 'i') i = true;
			if(c == 'o') o = true;
			if(c == 'u') u = true;
			}
		
		if (a && e && i && o && u) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	return 0;

}