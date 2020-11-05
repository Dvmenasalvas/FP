//Daniel Valverde Menasalvas y Eloy Mosig García 
//Grupo Doble Grado en Informática y Matemáticas
//Práctica 3
#include "juego.h"

//V1
void dibujar(tJuego const& juego){
	system("cls");
	std::cout << "Fichero: " << juego.nFichero << "      Nivel: " << juego.nivel << '\n';
	
	for (int i = 0; i < juego.sokoban.nfilas; i++){
		for (int j = 0; j < juego.sokoban.ncolumnas; j++){
			dibujaCasilla(juego.sokoban.tablero[i][j]);
		}
		std::cout << '\n';
	}

	std::cout << "Numero de movimientos: " << juego.numMovimientos << '\n';

	if (bloqueado(juego)) std::cout << "Una o más cajas están bloqueadas, es imposible llegar a una solución del nivel." << '\n';

	if (juego.sokoban.cajas == juego.sokoban.colocadas) std::cout << "¡Enhorabuena, has completado el nivel!" << '\n';
}

void inicializa(tJuego &juego) {
	juego.numMovimientos = 0;

	juego.sokoban.cajas = 0;
	juego.sokoban.colocadas = 0;
	juego.sokoban.ncolumnas = 0;
	juego.sokoban.nfilas = 0;

	juego.historia.actual = 0;
	juego.historia.cont = 0;


	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++){
			juego.sokoban.tablero[i][j] = Libre;
		}
	}
}

bool cargarJuego(tJuego & juego) {
	std::ifstream archivo;
	std::string leer;
	bool encontrado = false;

	std::cout << "Inserte el nombre del fichero que contiene los niveles: ";
	std::cin >> juego.nFichero;
	std::cout << "Inserte el nivel deseado: ";
	std::cin >> juego.nivel;

	archivo.open(juego.nFichero);
	if (archivo.is_open()){
		inicializa(juego);
		encontrado = cargarNivel(archivo, juego);

		if (!encontrado){
			std::cout << "No se ha encontrado el nivel pedido." << '\n';
		}

		archivo.close();
	}
	else std::cout << "No se ha encontrado el archivo pedido." << '\n';
	
	return encontrado;
}

bool cargarNivel(std::ifstream &archivo, tJuego& juego) {
	std::string nNivel, linea;
	bool encontrado = true;

	nNivel = "Level " + std::to_string(juego.nivel);	

	while ((linea != nNivel) && (!archivo.eof())) {
		std::getline(archivo, linea);
	}

	if (archivo.eof()) encontrado = false;
	else {
		while (linea != "" && !archivo.eof()) {
			std::getline(archivo, linea);
			for (int j = 0; j < linea.length(); j++) {
				switch (linea[j]) {
				case '#':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = Muro;
					break;
				case ' ':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = Libre;
					break;
				case '.':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = DestinoL;
					break;
				case '$':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = Caja;
					juego.sokoban.cajas++;
					break;
				case '@':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = Jugador;
					juego.sokoban.fila = juego.sokoban.nfilas;
					juego.sokoban.columna = j;
					break;
				case '*':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = DestinoC;
					juego.sokoban.cajas++;
					juego.sokoban.colocadas++;
					break;
				case '+':
					juego.sokoban.tablero[juego.sokoban.nfilas][j] = DestinoJ;
					juego.sokoban.fila = juego.sokoban.nfilas;
					juego.sokoban.columna = j;
					break;
				}
			}
				if (linea.length() > juego.sokoban.ncolumnas) juego.sokoban.ncolumnas = linea.length();
				if(linea.length() != 0) juego.sokoban.nfilas++;
		}
	}

	return encontrado;
}

//V2
bool bloqueado(tJuego const & juego) {
	int cajas = 0, i = 0, j = 0;
	bool bloq = false;

	while ((i < juego.sokoban.nfilas) && !bloq){
		j = 0;
		while ((j < juego.sokoban.ncolumnas) && !bloq) {
			if (juego.sokoban.tablero[i][j] == Caja) {
				if (((juego.sokoban.tablero[i + 1][j] == Muro) || (juego.sokoban.tablero[i - 1][j] == Muro)) && ((juego.sokoban.tablero[i][j + 1] == Muro) || (juego.sokoban.tablero[i][j - 1] == Muro)))
					bloq = true;
			}
			j++; 
		}
		i++;
	}

	return bloq;
}

void guardarTablero(tJuego & juego) {
	juego.historia.actual++;
	if (juego.historia.actual == MAXH) juego.historia.actual = 0;
	juego.historia.tableros[juego.historia.actual] = juego.sokoban;
	if (juego.historia.cont < MAXH) juego.historia.cont++;
}

bool deshacerMovimiento(tJuego &juego) {
	bool posible = false;

	if (juego.historia.cont > 0) {
		posible = true;
		juego.historia.cont--;
		if (juego.historia.actual < 0) juego.historia.actual = MAXH - 1;
		juego.sokoban = juego.historia.tableros[juego.historia.actual];
		juego.historia.actual--;
		juego.numMovimientos--;
	}

	return posible;
}

//V3
void leerInfo(tInfo &info) {
	std::ifstream archivo;
	archivo.open(info.nombre + ".txt");
	info.partidas = 0;
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			archivo >> info.exitos[info.partidas].nFichero;
			if (!archivo.eof()) { //Comprobamos que la linea no es vacia(por ejemplo, por que acabe con un salto de linea)
				archivo >> info.exitos[info.partidas].nivel >> info.exitos[info.partidas].numMovimientos;
				info.partidas++;
			}
		}
		archivo.close();
	}

}

bool operator == (tPartida const& a, tPartida const& b) {
	return a.nFichero == b.nFichero && a.nivel == b.nivel;
}

bool operator < (tPartida const& a, tPartida const& b) {
	bool menor = false;
	if (a.nFichero < b.nFichero) menor = true;
	else if (a.nFichero == b.nFichero && a.nivel < b.nivel) menor = true;
	return menor;
}

void actualizarInfo(tInfo& info, tJuego const &juego) {
	int ini = 0, fin = info.partidas, mitad;
	bool encontrado = false;
	tPartida partida;

	partida.nFichero = juego.nFichero;
	partida.nivel = juego.nivel;
	partida.numMovimientos = juego.numMovimientos;

	while (ini < fin && !encontrado){ //Busqueda binaria
		mitad = (ini + fin - 1) / 2;
		if (partida < info.exitos[mitad]) fin = mitad;
		else if (info.exitos[mitad] < partida) ini = mitad + 1;
		else encontrado = true;
	}
	if (!encontrado) { //Si ese nivel no ha sido superado con anterioridad
		info.partidas++;
		for (int j = info.partidas - 1; j > ini; j--) { //Hacemos hueco
			info.exitos[j] = info.exitos[j - 1];
		}
		info.exitos[ini] = partida; //Insertamos
	}
	else { //Si ya ha sido superado, actualizamos solo si esta vez se ha mejorado el numero de movimientos
		if (info.exitos[mitad].numMovimientos > partida.numMovimientos) 
			info.exitos[mitad].numMovimientos = partida.numMovimientos;
	}	
}

void guardarInfo(tInfo const& info) {
	std::ofstream archivo;
	archivo.open(info.nombre + ".txt");
	if (archivo.is_open()) {
		for (int i = 0; i < info.partidas; i++) {
			archivo << info.exitos[i].nFichero << " " << info.exitos[i].nivel << " " << info.exitos[i].numMovimientos;
			if (i != info.partidas - 1) archivo << '\n'; //Evitamos que el fichero acabe con un salto de linea, ya que nos puede dar problemas
		}
		archivo.close();
	}
}

void mostrarInfo(tInfo const& info) {
	if (info.partidas == 0) std::cout << "¡Aun no has completado ningun nivel!" << '\n';
	else {
		std::cout << "Niveles superados por " << info.nombre << ":" << '\n';
		std::cout << std::setw(20) << "Nombre del fichero" << std::setw(10) << "Nivel" << std::setw(25) << "Numero de movimientos" << '\n';
		for (int i = 0; i < info.partidas; i++) {
			std::cout << std::setw(20) << info.exitos[i].nFichero << std::setw(10) << info.exitos[i].nivel << std::setw(25) << info.exitos[i].numMovimientos << '\n';
		}
	}
}