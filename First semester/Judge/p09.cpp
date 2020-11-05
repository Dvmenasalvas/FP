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
		string palabra;
		cin >> palabra;
		while(palabra.length() > 100) {
			cin >> palabra;
		}
		for(int i = 0; i < palabra.length(); i++){
			if(isupper(palabra.at(i))) palabra.at(i) = tolower(palabra.at(i));
		}
		cout << palabra << endl;
	}
	return 0;

}