//Hecho por Eloy Mósig García y Daniel Valverde Menasalvas del 1º del Doble Grado en Matemáticas e Ingeniería informática
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <cmath>
#include <fstream>
#include <locale>

const int MAX_PROD = 25, PROD_NULO = 0, CENTINELA = -1;
typedef int tArray[MAX_PROD];

//Métodos de manejo de filas
void mostrarFila(const tArray fila, int tam); // Dada una fila, la muestra en pantalla siguiendo el formato del final de la segunda página.
bool esPosValida(int tam, int pos); // Devuelve si la posición pos es válida en la fila de tamaño tam.
bool estaVacia(const tArray fila, int pos); //Devuelve si la posición pos está vacía.
bool filaOrdenada(const tArray fila, int tam); // Devuelve si los materiales en la fila están ordenados de menor a mayor, ignorando los huecos que los separen.

//Métodos de manejo de ficheros
void leerFilaFich(ifstream &fich, tArray fila, int &tam); //Dado el fichero de lectura abierto fich, carga su contenido en la fila.
void escribirFilaFich(ofstream &fich, const tArray fila, int tam); //Dado el fichero de escritura abierto fich, guarda en dicho fichero el contenido de la fila.

//Métodos de manejo de grúa
bool esPosibleGrua1Entre(const tArray fila, int tam, int posIni, int posSoltar); //(Versión 1, no se usa) Devuelve cierto si posIni y posSoltar son posiciones válidas de la fila y además es posible dejar caer el contenido de la fila situado en posIni en su posición posSoltar.
bool grua1Elemento(tArray fila, int tam, int posIni, int posSoltar); //(Versión 1, no se usa) Si es posible, realiza el movimiento de la grúa entre las posiciones posIni y posSoltar.Devuelve si el movimiento se ha realizado
bool sonPosicionesPosiblesGrua(int tam, int posIni, int posFin, int posSoltar); // Devuelve si el segmento a levantar no tiene su extremo derecho antes que el izquierdo y si todas las posiciones involucradas son válidas en la fila de tamaño tam.Fíjate en que, para comprobar lo segundo, te basta con comprobarlo para los cuatro extremos involucrados.
bool esPosibleGrua(const tArray fila, int tam, int posIni, int posFin, int posSoltar); //Devuelve si es posible realizar el movimiento de la grúa, es decir, si es posible dejar caer todos los materiales de la fila desde posIni hasta posFin a partir de la posición posSoltar.Recuerda que cada material no puede caer encima de otro material, sino que debe caer sobre un hueco libre.Pero fíjate también en que el segmento a levantar no solapa consigo mismo : si tomamos la segunda fila que se muestra en la página 1 y dejamos caer los materiales 2, 3 y 4 una posición a la derecha de donde están, el 2 no solapará con el 3 al caer, pues el 3 ya no estará allí.
bool grua(tArray fila, int tam, int posIni, int posFin, int posSoltar); //Primero se comprueba si el movimiento es posible tal y como descubre la función anterior.Si es así, realiza el movimiento de la grúa de la siguiente manera : se ponen en un array auxiliar los elementos a levantar, se ponen huecos en sus correspondientes posiciones de la fila, y después se sueltan los elementos del array auxiliar en la fila, a partir de la posición a soltar.Recuerda que los materiales anteriores que ya estuvieran en la zona de caída(no levantados ahora) se respetan.

//Métodos de manejo de excavadora
int posHuecoLibreDir(const tArray fila, int tam, int posIni, int direccion); //Devuelve la posición del primer hueco libre de la fila si, comenzando por posIni, vamos avanzando paso a paso hacia la derecha.Si no hay ninguno, devolverá el valor tam.
bool excavadora1Dir(tArray fila, int tam, int posIni, int direccion); //(Versión 1, se usa) Desplaza la pala de la excavadora desde posIni una posición hacia la derecha, empujando desde su posición todos los elementos adyacentes(es decir, no separados por huecos) hacia la derecha, y así, eliminando el primer hueco libre que haya en tal dirección.Recuerda que los materiales empujados no atraviesan los muros del final de la fila.Devuelve un booleano indicando si el desplazamiento ha podido ser realizado.Se considera así si la posición inicial es correcta, aunque no realice ninguna modificación visible sobre la fila
bool excavadora(tArray fila, int tam, int posIni, int numDespla, int direccion); // Primero se comprueba si el movimiento es posible, es decir, si la posición desde la que empezar a empujar es válida.Si es así, se lleva a cabo el movimiento de la excavadora : la excavadora se sitúa en la posición posIni y se mueve numDespla posiciones hacia la dirección direccion empujando los materiales que encuentre a su camino.La implementación se hará en pasadas sucesivas de 1 desplazamiento de toda la hilera de materiales empujados en cada una, ocupando un nuevo hueco en cada uno.Fíjate en que la hilera empujada podría hacerse cada vez más grande a lo largo de las pasadas.

//Métodos del menú
int menu(); //Muestra el menú de opciones, solicita al usuario su respuesta, y devuelve la opción escogida cuando el usuario haya respondido una opción válida.
bool ejecutarLeerFichero(tArray fila, int &tam); // Pide al usuario el nombre del fichero del que cargará su fila.Si existe, carga la fila, y si no, la fila se inicializa como vacía(asigna el valor 0 a tam).Debe informar al usuario sobre si ha logrado realizar la carga, así como mostrar la fila leída.
void ejecutarGuardarFichero(const tArray fila, int tam); // Pide al usuario el nombre del fichero en el que se guardará la fila.Si logra abrirlo, guarda en el fichero la fila, usando el formato visto antes.Debe informar al usuario sobre si ha logrado realizar el guardado.
bool ejecutarGrua(tArray fila, int tam); //En esta versión, pregunta al usuario qué posición quiere levantar y en qué posición quiere dejarlo caer.Si es posible, realizará el movimiento.Si el movimiento no fue posible, informará al usuario de ello.Se mostrará cómo queda la fila tras el movimiento.
bool ejecutarExcavadora(tArray fila, int tam); // Pregunta al usuario desde qué posición empujará la excavadora.Entonces lo hace, o bien indica que no lo ha hecho(porque la posición desde la que pidió empujar es inválida).Muestra cómo queda la fila tras el movimiento.
void ejecutarOpc(int opc, tArray fila, int &tam, int &intentos); // Dada la opción escogida por el usuario en el menú, la ejecuta.
void pedirEntero(int &n); //Pide un entero en caso de que no se introduzca tal.

int main() {
	setlocale(LC_ALL, "spanish");
	system("chcp 1252");
	tArray fila;
	int tam = 0, opc, intentos = 0;
	do {
		opc = menu();
		if (opc != 0) {
			if ((tam != 0) || (opc == 1)) ejecutarOpc(opc, fila, tam, intentos);
			if (tam == 0) cout << "No hay ninguna fila cargada." << endl << endl;
			else {
				mostrarFila(fila, tam);
				if (filaOrdenada(fila, tam)) cout << "La fila está ordenada." << endl;
				else cout << "La fila no está ordenada." << endl;
				cout << "Has utilizado " << intentos << " movimientos." << endl << endl;
			}
		}
	} while (opc != 0);
	return 0;
}


//Métodos de manejo de filas
void mostrarFila(const tArray fila, int tam) {
	cout << "|";
	for (int i = 0; i < tam; i++) {
		if (estaVacia(fila, i)) {
			cout << "  |";
		}
		else {
			cout << setw(2) << fila[i] << "|";
		}
	}
	cout << endl;
	cout << "-";
	for (int i = 0; i < tam; i++) {
		cout << "---";
	}
	cout << endl;
	cout << "|";
	for (int i = 0; i < tam; i++) {
		cout << setw(2) << i << "|";
	}
	cout << endl;
}

bool esPosValida(int tam, int pos) {
	bool valida;
	if ((pos < tam) && (pos >= 0)) {
		valida = true;
	}
	else {
		valida = false;
	}
	return valida;
}

bool estaVacia(const tArray fila, int pos) {
	bool vacia;
	if (fila[pos] == PROD_NULO) {
		vacia = true;
	}
	else {
		vacia = false;
	}
	return vacia;
}

bool filaOrdenada(const tArray fila, int tam){
	bool orden = true;
	int actual = 0, i = 0;

	while ((i < tam) && orden) {
		if (fila[i] != PROD_NULO) {
			if (fila[i] >= actual) actual = fila[i];
			else orden = false;
		}
		i++;
	}
	return orden;
}

//Métodos de manejo de ficheros
void leerFilaFich(ifstream &fich, tArray fila, int &tam) {
	tam = 0;
	bool encontrado = false;
	while (!encontrado && (tam < MAX_PROD)) {
		fich >> fila[tam];
		if (fila[tam] == CENTINELA) {
			encontrado = true;
		}
		else {
			tam++;
		}
	}
}

void escribirFilaFich(ofstream &fich, const tArray fila, int tam) {
	for (int i = 0; i < tam; i++) {
		fich << fila[i] << " ";
	}
	fich << CENTINELA;
}


//Métodos de manejo de grúa
bool esPosibleGrua1Entre(const tArray fila, int tam, int posIni, int posSoltar) { //Versión 1
	bool posible = false;
	if (esPosValida(tam, posIni) && esPosValida(tam, posSoltar)) {
		if (estaVacia(fila, posSoltar) && !estaVacia(fila, posIni)) {
			posible = true;
		}
	}
	return posible;

}

bool grua1Elemento(tArray fila, int tam, int posIni, int posSoltar) { //Versión 1
	bool realizado = false;
	if (esPosibleGrua1Entre(fila, tam, posIni, posSoltar)) {
		realizado = true;
		fila[posSoltar] = fila[posIni];
		fila[posIni] = PROD_NULO;
	}
	return realizado;
}

bool sonPosicionesPosiblesGrua(int tam, int posIni, int posFin, int posSoltar) {
	bool posible = true;
	int posExtremoSoltar = posSoltar + posFin - posIni;

	if (posIni > posFin) posible = false;
	if (!esPosValida(tam, posIni)) posible = false;
	if (!esPosValida(tam, posFin)) posible = false;
	if (!esPosValida(tam, posSoltar)) posible = false;
	if (!esPosValida(tam, posExtremoSoltar)) posible = false;
	return posible;
}

bool esPosibleGrua(const tArray fila, int tam, int posIni, int posFin, int posSoltar) {
	bool posible = true;
	int posDejar;
	if (!sonPosicionesPosiblesGrua(tam, posIni, posFin, posSoltar)) {
		posible = false;
	}
	else {
		for (int i = posIni; i <= posFin; i++) {
			if (!estaVacia(fila, i)) {
				posDejar = posSoltar + i - posIni;
				if ((posDejar < posIni) || (posDejar > posFin)) {
					if (!estaVacia(fila, posDejar)) posible = false;
				}
			}
		}
	}
	return posible;
}

bool grua(tArray fila, int tam, int posIni, int posFin, int posSoltar) {
	bool posible = esPosibleGrua(fila, tam, posIni, posFin, posSoltar);
	int posDejar = posSoltar + posFin - posIni;
	if (posible) {
		tArray aux;
		for (int i = posIni; i <= posFin; i++) {
			aux[i - posIni] = fila[i];
			fila[i] = PROD_NULO;
		}
		for (int i = posSoltar; i <= posDejar; i++) {
			if (fila[i] == PROD_NULO) {
				fila[i] = aux[i - posSoltar];
			}
		}

	}
	return posible;
}

//Métodos de manejo de excavadora
int posHuecoLibreDir(const tArray fila, int tam, int posIni, int direccion) {
	int pos, posibleHueco = posIni + direccion;
	bool encontrado = false;
	while ((posibleHueco >= 0) && (posibleHueco < tam) && !encontrado) {
		if (fila[posibleHueco] == PROD_NULO) {
			pos = posibleHueco;
			encontrado = true;
		}
		else posibleHueco += direccion;
	}
	if (!encontrado) pos = tam;
	return pos;
}

bool excavadora1Dir(tArray fila, int tam, int posIni, int direccion) { //Versión 1
	bool posible = false;
	int hueco = posHuecoLibreDir(fila, tam, posIni, direccion);
	if ((posIni >= 0) && (posIni < tam) && (fila[posIni] != PROD_NULO) && (hueco < tam)) {
		posible = true;
		while (hueco != posIni) {
			fila[hueco] = fila[hueco - direccion];
			fila[hueco - direccion] = PROD_NULO;
			hueco -= direccion;
		}
	}
	return posible;
}

bool excavadora(tArray fila, int tam, int posIni, int numDespla, int direccion) {
	bool posible = false, fin = false;
	int posActual, i = numDespla;
	if (esPosValida(tam, posIni)) {
		posible = true;
		posActual = posIni;
		while ((i > 0) && !fin) {
			if (fila[posActual] != PROD_NULO) {
				fin = !excavadora1Dir(fila, tam, posActual, direccion);
			}
			i--;
			posActual += direccion;
		}

	}
	return posible;
}

//Métodos del menú
int menu() {
	int op;
	cout << "1.- Cargar fila de fichero" << endl
		<< "2.- Guarda fila en fichero" << endl
		<< "3.- Usar grúa" << endl
		<< "4.- Usar excavadora" << endl
		<< "0.- Salir" << endl;
	cout << "Inserte su opción: ";
	pedirEntero(op);
	while ((op < 0) || (op > 4)) {
		cout << "Inserte una opción válida: ";
		pedirEntero(op);
	}
	cout << endl;
	return op;
}

bool ejecutarLeerFichero(tArray fila, int &tam) {
	string nombre;
	ifstream fichero;
	bool posible = false;
	cout << "Inserte el nombre del fichero que contiene la fila: ";
	cin >> nombre;
	fichero.open(nombre);
	if (fichero.is_open()) {
		leerFilaFich(fichero, fila, tam);
		cout << "La fila ha sido cargada correctamente:" << endl;
		posible = true;
	}
	else {
		tam = 0;
		cout << "No se ha podido cargar la fila." << endl;
	}
	cout << endl;
	return posible;
}

void ejecutarGuardarFichero(const tArray fila, int tam) {
	string nombre;
	ofstream fichero;
	cout << "Escriba el nombre del fichero donde se quiere guardar la fila: ";
	cin >> nombre;
	fichero.open(nombre);
	if (fichero.is_open()) {
		escribirFilaFich(fichero, fila, tam);
		cout << "La fila se ha guardado correctamente en el fichero." << nombre << endl;
	}
	else {
		cout << "No se ha podido guardar la fila en el fichero." << endl;
	}
	cout << endl;
}

bool ejecutarGrua(tArray fila, int tam) {
	int posIni, posSoltar = 0, posFin = 0;
	bool posible;

	cout << "Indique el inicio de la fila que quiere levantar: ";
	pedirEntero(posIni);
	if (esPosValida(tam, posIni)){
		cout << "Indique el final de la fila que quiere levantar: ";
		pedirEntero(posFin);
		if (esPosValida(tam, posFin) && (posFin >= posIni)){
			cout << "Indique la posicion donde quiere dejar el objeto: ";
			pedirEntero(posSoltar);
		}
	}
	posible = grua(fila, tam, posIni, posFin, posSoltar);
	if (posible) {
		cout << "El movimiento se ha realizado correctamente: " << endl;
	}
	else {
		cout << "No se ha podido realizar el movimiento pedido." << endl;
	}
	cout << endl;
	return posible;
}

bool ejecutarExcavadora(tArray fila, int tam) {
	int posIni, direccion, numDespla = 0;
	string dir;
	bool posible;

	cout << "Indique la posicion desde la que quiere que la excavadora empuje: ";
	pedirEntero(posIni);
	if (esPosValida(tam, posIni)){
		cout << "Indique la direccion de empuje (d, i): ";
		cin >> dir;
		while ((dir != "d") && (dir != "i")){
			cin.ignore(10000, '\n');
			cout << "Introduzca una dirección válida (d, i): ";
			cin >> dir;
		}
		if (dir == "d") direccion = 1;
		else direccion = -1;

		cout << "Indique el número de desplazamientos deseado: ";
		pedirEntero(numDespla);
		while (numDespla < 0) {
			cout << "Indique un número de desplazamientos válido: ";
			pedirEntero(numDespla);
		}
	}
	posible = excavadora(fila, tam, posIni, numDespla, direccion);
	if (posible) {
		cout << "El movimiento se ha realizado correctamente: " << endl;
	}
	else {
		cout << "No se ha podido realizar el movimiento pedido." << endl;
	}
	cout << endl;
	return posible;
}

void ejecutarOpc(int opc, tArray fila, int &tam, int &intentos) {
	switch (opc) {
	case 1:
		if (ejecutarLeerFichero(fila, tam)) intentos = 0;
		break;
	case 2:
		ejecutarGuardarFichero(fila, tam);
		break;
	case 3:
		if (ejecutarGrua(fila, tam)) intentos++;
		break;
	case 4:
		if (ejecutarExcavadora(fila, tam)) intentos++;
		break;
	}
}

void pedirEntero(int &n){
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "El valor debe de ser entero: ";
		cin >> n;
	}
	cin.ignore(10000, '\n');
}