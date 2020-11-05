#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int TAM = 20;
typedef int tArray[TAM];

string esTriangular(int n);
bool esCreciente(tArray numeros);

int main() {
	tArray numeros;
	ifstream archivo;
	archivo.open("secuencia.txt");
	if (archivo.is_open()) {
		for (int i = 0; i < TAM; i++) {
			archivo >> numeros[i];
		}
		for (int i = 0; i < TAM; i++) {
			cout << "Posicion" << setw(3) << i + 1 << ":";
			cout << setw(5) << numeros[i] << " - " << esTriangular(numeros[i]);
			cout << "  es triangular" << endl;
		}

		cout << endl;
		if (esCreciente(numeros)) cout << "La secuencia es creciente." << endl;
		else cout << "La secuencia no es creciente." << endl;
	}
	else {
		cout << "No se ha podido abrir el archivo";
	}

	system("pause");
	return 0;
}

string esTriangular(int n) {
	int i = 1, suma = 0;
	bool triangular = false;
	string salida;
	while ((!triangular) && (suma <= n)) {
		if (suma == n) {
			triangular = true;
		}
		else {
			suma += i;
			i++;
		}
	}
	if (triangular) {
		salida = "SI";
	}
	else salida = "NO";

	return salida;
}

bool esCreciente(tArray numeros) {
	int i = 1;
	bool creciente = true;
	while (creciente && (i < TAM)) {
		if (numeros[i] < numeros[i - 1]) {
			creciente = false;
		}
		else i++;
	}
	return creciente;
}