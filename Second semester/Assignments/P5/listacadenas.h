#ifndef LISTACADENAS_H
#define	LISTACADENAS_H
#include <iostream>
#include <fstream>
#include <string>
#include "checkML.h"

const int TAMINI = 3;


template <typename T>
struct tListaCadenas {
	int tam = 0, capacidad = TAMINI;
	T* elementos;
};

template <typename T>
void inicializar(tListaCadenas<T> & lista) {
	lista.elementos = new T[TAMINI];
}

template <typename T> 
void insertar(tListaCadenas<T> & l, T const & s) { //Añade un elemento al vector e incrementa su tamaño en uno
	if (l.tam >= l.capacidad) {
		l.capacidad = (l.capacidad * 3) / 2 + 1;
		T* nuevo = new T[l.capacidad];
		for (int i = 0; i < l.tam; i++)
			nuevo[i] = l.elementos[i];
		delete[] l.elementos;
		l.elementos = nuevo;
	}
	l.elementos[l.tam] = s;
	l.tam++;
}

template <typename T>
bool buscar(tListaCadenas<T> const & l, T const & s, int & pos)  { //Busca un elemento en la lista y devuelve su posicion y si lo ha encontrado o no
	bool encontrado = false;
	int i = 0;
	while (!encontrado && i < l.tam) {
		if (l.elementos[i] == s) encontrado = true;
		else i++;
	}
	if (encontrado) pos = i;

	return encontrado;
}

template <typename T>
void operator<<(std::istream & archivo, tListaCadenas<T> const & l) { //Saca todos lo elementos del vector por el buffer que pasemos como argumento
	for (int i = 0; i < l.tam; i++) archivo << l.elementos[i] << " ";
}

template <typename T>
void ordenar(tListaCadenas<T> & l){ //Ordena el vector mediante insercion
	for (int i = 1; i < l.tam; i++) {
		int j = i;
		while ((l.elementos[i] > l.elementos[j - 1]) && j > 0)
			j--;
		if (j != i){
			T actual = l.elementos[i];
			for (int t = i; t > j; t--) {
				l.elementos[t] = l.elementos[t - 1];
			}
			l.elementos[j] = actual;
		}
	}
}

#endif