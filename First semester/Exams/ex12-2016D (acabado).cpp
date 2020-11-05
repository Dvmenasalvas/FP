#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int CENTINELA = -1;
const int TAM = 50;
typedef int tArray[TAM];

int leerNumero();
int leerEdad();
int numCifras(int n);
bool leerFichero(int n, tArray numeros, int &cont);
void calcularExtremos(int num, int& primeras, int&ultimas);
int sumar(const tArray numeros, int cont);
int queComprar(int n, int edad, const tArray numeros, int cont);
void escribirFichero(int n, int edad, int cont, int elegido, const tArray numeros, bool abierto);

int main() {
	int n = leerNumero(), edad = leerEdad(), cont, elegido;
	bool abierto;
	tArray numeros;

	abierto = leerFichero(n, numeros, cont);
	elegido = queComprar(n, edad, numeros, cont);
	escribirFichero(n, edad, cont, elegido, numeros, abierto);

	system("pause");
	return 0;
}

int leerNumero() {
	int n;
	cout << "Introduzca su numero de cifras preferido: ";
	cin >> n;
	while (n < 4) {
		cout << "El numero ha de ser mayor o igual que 4: ";
		cin >> n;
	}
	return n;
}
int leerEdad() {
	int edad;
	cout << "Introduzca su edad: ";
	cin >> edad;
	while ((edad < 10) || (edad > 99)) {
		cout << "La edad no puede ser menor de 10 ni mayor a 99: ";
		cin >> edad;
	}
	return edad;
}

int numCifras(int n) {
	int i = 0;
	while (n > 0) {
		n = n / 10;
		i++;
	}
	return i;
}

bool leerFichero(int n, tArray numeros, int &cont) {
	ifstream fichero;
	cont = 0;
	bool abierto, encontrado = false;
	int num;
	fichero.open("entrada.txt");
	if (fichero.is_open()) {
		abierto = true;
		while (!encontrado) {
			fichero >> num;
			if (num == CENTINELA) {
				encontrado = true;
			}
			else {
				if (numCifras(num) == n) {
					numeros[cont] = num;
					cont++;
				}
			}
		}
		fichero.close();
	}
	else abierto = false;
	return abierto;
}

void calcularExtremos(int num, int& primeras, int&ultimas) {
	bool mayor100 = true;

	ultimas = num % 100;
	while (mayor100) {
		if (num < 100) {
			mayor100 = false;
		}
		else {
			num /= 10;
		}
	}
	primeras = num;
}

int sumar(const tArray numeros, int cont) {
	int suma = 0;
	for (int i = 0; i < cont; i += 2) {
		suma += numeros[i];
	}
	return suma;
}

int queComprar(int n, int edad, const tArray numeros, int cont) {
	int primeras, ultimas, i = 0, elegido;
	bool encontrado = false;
	while (!encontrado && (i < cont)) {
		calcularExtremos(numeros[i], primeras, ultimas);
		if (primeras == edad) {
			encontrado = true;
			elegido = ultimas;
		}
		else i++;
	}
	if (!encontrado) {
		calcularExtremos(sumar(numeros, cont), primeras, ultimas);
		elegido = ultimas;
	}
	return elegido;
}

void escribirFichero(int n, int edad, int cont, int elegido, const tArray numeros, bool abierto) {
	ofstream fichero;
	fichero.open("salida.txt");
	if (!abierto || (cont == 0)) {
		fichero << "-1";
	}
	else {
		fichero << n << endl;
		fichero << edad << endl;
		fichero << cont << endl;
		for (int i = 0; i < cont; i++) {
			fichero << numeros[i] << " ";
		}
		fichero << endl;
		fichero << elegido;
		cout << "Se escribio en el fichero correctamente" << endl;
	}
	fichero.close();
}