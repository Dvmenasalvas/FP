#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int TAM = 100;
typedef int tArray[TAM];

int sumar(const tArray numeros, int inf, int sup);
void rellenar(tArray numeros, int n, int x);
int primeroMayor(const tArray numeros, int m, int n);
void escribir(const tArray numeros, int n, string nombre);

int main() {
	tArray numeros;
	int n, x, m;
	cout << "¿Cuantos numeros va a tener la secuencia?";
	cin >> n;
	if (n > TAM) n = TAM;
	cout << "¿Cuantos numeros vas a querer sumar de una?";
	cin >> x;

	rellenar(numeros, n, x);

	cout << "Numero para comparar: ";
	cin >> m;
	cout << "El primero que se pasa de " << m << " es el " << primeroMayor(numeros, m, n) << endl;

	escribir(numeros, n, "polla.txt");

	system("pause");
	return 0;
}

int sumar(const tArray numeros, int inf, int sup) {
	int suma = 0;
	if (inf < 0) inf = 0;
	if (sup < 0) sup = 0;
	for (int i = inf; i <= sup; i++) {
		suma = suma + numeros[i];
	}
	return suma;
}

void rellenar(tArray numeros, int n, int x) {
	int a = 0;
	numeros[a] = 1;
	a++;
	while (a < n) {
		if (a < x) {
			numeros[a] = sumar(numeros, 0, a - 1);
			a++;
		}
		else {
			numeros[a] = sumar(numeros, a - x, a - 1);
			a++;
		}
	}
}

int primeroMayor(const tArray numeros, int m, int n) {
	bool encontrado = false;
	int i = 0, y;
	while ((!encontrado) && (i < n)) {
		if (numeros[i] > m) {
			encontrado = true;
			y = numeros[i];
		}
		else {
			i++;
		}
	}
	if (!encontrado) {
		y = numeros[i - 1];
	}
	return y;
}

void escribir(const tArray numeros, int n, string nombre) {
	ofstream archivo;
	archivo.open(nombre);
	for (int i = 0; i < n; i++) {
		archivo << numeros[i] << " ";
	}
	archivo.close();
	cout << "Se ha escrito la secuencia en el archivo: " << nombre << endl;
}