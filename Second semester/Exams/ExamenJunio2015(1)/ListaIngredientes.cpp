#include "ListaIngredientes.h"


void inserta(tListaIngredientes & lista, tIngrediente const & nuevo) {
	int pos;
	if (!busca(lista, nuevo.nombre, pos)) {
		for (int i = lista.tam; i > pos; i--)
			lista.elementos[i] = lista.elementos[i - 1];
		lista.elementos[pos] = new tIngrediente;
		lista.elementos[pos]->calorias = nuevo.calorias;
		lista.elementos[pos]->nombre = nuevo.nombre;
		lista.tam++;
	}
}

void carga(tListaIngredientes & lista) {
	ifstream archivo;
	archivo.open(ARCHIVO);
	if (archivo.is_open()) {
		tIngrediente nuevo;
		archivo >> nuevo.calorias;
		while (nuevo.calorias != -1) {
			getline(archivo, nuevo.nombre);
			inserta(lista, nuevo);
			archivo >> nuevo.calorias;
		}
		archivo.close();
	}
	else cout << "No se ha podido cargar una lista de ingredientes de " << ARCHIVO << '\n';
}

int selecIngred(tListaIngredientes const & lista) {
	int op;
	cout << "Lista de ingredientes:" << '\n';
	for (int i = 0; i < lista.tam; i++)
		cout << i + 1 << ". " << lista.elementos[i]->nombre << '\n';
	cout << '\n';

	do {
		cout << "Elija su ingrediente: ";
		op = pedirInt();
	} while (op <= 0 || op > lista.tam);

	return op - 1;
}

bool busca(tListaIngredientes const & lista, string nombre, int & pos) {
	return buscaAux(lista, nombre, pos, 0, lista.tam);
}

bool buscaAux(tListaIngredientes const & lista, string nombre,int & pos, int ini, int fin) {
	if (ini == fin) {
		pos = ini; return false;
	}
	else {
		int med = (ini + fin - 1) / 2;
		if (nombre < lista.elementos[med]->nombre)
			return buscaAux(lista, nombre, pos, ini, med);
		else if (lista.elementos[med]->nombre < nombre)
			return buscaAux(lista, nombre, pos, med + 1, fin);
		else {
			pos = med;
			return true;
		}
	}
}

int pedirInt() {
	int entero;
	cin >> entero;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> entero;
	}
	cin.ignore(10000, '\n');
	return entero;
}