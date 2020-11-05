/*
 * Crear objetos funcion
 *
 *  Practica FP 2016/17
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream> // string streams para la lectura genérica de datos del fichero
#include <functional>
#include <string>
using namespace std;

struct	ComparaParImpar	{
	bool	operator()	(int	n1, int	n2)	{
		if (abs(n1) % 2 == 0 && abs(n2) % 2 == 1)	//par	- impar
			return	true;
		else	if (abs(n1) % 2 == 0)	//Los	dos	son	pares
			return	n1	<	n2;
		else	if (abs(n2) % 2 == 0)	//	impar- par
			return	false;
		else	//	Los	dos	impares
			return	n1	>	n2;
	}
};

std::string	aMinusculas(std::string	const&	Palabra)
{
	string nueva = Palabra;
	int lenght = Palabra.length();
	for (int i = 0; i < lenght; i++) {
		nueva[i] = tolower(Palabra[i]);
	}
	return nueva;
}


struct	ComparaString	{
	bool	operator()	(string	s1, string s2)	{
		string ss1 = aMinusculas(s1);
		string ss2 = aMinusculas(s2);
		return ss1 > ss2;
	}
};

template	<typename	T, typename	Comp = std::less<T>>
// Algoritmo de ordenación por insercion
void ordenarInsercion(std::vector<T>	&	array, Comp	ord =
	Comp()) {
    size_t N = array.size();
    // parte ordenada array[0..i), parte por procesar array[i..N)
    for (size_t i = 1; i < N; ++i) { // desde el segundo hasta el último
        // parte ordenada array[0..i)
        T elemento = array[i];  // elemento a insertar
        size_t j = i; // desplazar los mayores de la parte ordenada
        while (j > 0 && ord(elemento, array[j - 1])) {
            array[j] = array[j - 1];
            --j;
        }
        if (j != i) array[j] = elemento; // colocar en el hueco
    } // parte ordenada array[0..N)
}



int main() {
    
    std::ifstream entrada;
    entrada.open("PruebaString.txt");
    if (!entrada.is_open()) std::cout << "No se encuentra el fichero\n";
    else {
        // lectura de todos los casos de prueba del fichero
        while (!entrada.eof()) {
            std::string auxs;
            std::stringstream ss;
            std::getline(entrada,auxs); // Lee los datos del vector en un string
            ss << auxs; // Transforma el string en un stringstream
            std::vector<string> v;
            string n; // variable para leer los datos del vector
            ss >> n;  // lee un valor
            while (ss) {  // mientras existen datos en el stringstream
                v.push_back(n);
                ss >> n;
            }
            ordenarInsercion(v, ComparaString());
            for (string n : v) std::cout << n << ' ';
            std::cout << '\n';
            v.clear();
        }
    }
	system("pause");
        return 0;
    }

