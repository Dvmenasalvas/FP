//Daniel Valverde Menasalvas y Eloy Mosig García 
//Grupo Doble Grado en Informática y Matemáticas
//Práctica 3
#ifndef	juego_h
#define	juego_h
#include "sokoban.h"

const int MAXH = 10;
const int MAXE = 100;

//V2
struct tHistoria {
	tSokoban tableros[MAXH]; //Array de mov guardados
	int cont = 0;   //Cantidad de movimientos guardados
	int actual = 0; //Posicion en el array de la ultima historia guardada
};

struct tJuego{ //Struct que guardara toda la informacion del juego
	tSokoban sokoban;
	int numMovimientos;
	std::string nFichero;
	int nivel;
	tHistoria historia;
};

//V3
struct tPartida {  //Struct que guarda una partida superada
	std::string nFichero;
	int nivel;
	int numMovimientos;
};

typedef tPartida tExitos[MAXE];  //Array de partidas superadas

struct tInfo {  //Struct que guarda las partidas superadas con el nombre del usuario
	std::string nombre;
	tExitos exitos;
	int partidas = 0;
};
//V1
void dibujar(tJuego const& juego); //Dibuja el tablero actual del sokoban en pantalla
void inicializa(tJuego &juego); //Prepara el juego para cargar un nivel nuevo
bool cargarJuego(tJuego & juego); //Carga una nueva partida
bool cargarNivel(std::ifstream &archivo, tJuego& juego); //Lee el fichero para obtener las caracteristicas del nivel
//V2
bool bloqueado(tJuego const & juego); //Comprueba si alguna caja ha quedado bloqueada en una esquina
void guardarTablero(tJuego & juego); //Guarda el tablero en la historia(antes de realizar un movimiento)
bool deshacerMovimiento(tJuego &juego); //Deja el juego como estaba hace un movimiento(solo se puede hacer un numero MAXH de veces)
//V3
void leerInfo(tInfo &info); //Lee la info de un usuario de su fichero
bool operator == (tPartida const& a, tPartida const& b); //Sobrecarga de los operadores == y < para el tipo tPartida, util en las siguientes funciones
bool operator < (tPartida const& a, tPartida const& b);
void actualizarInfo(tInfo& info, tJuego const &juego); //Tras completar un nivel, añadimos a la info del jugador ese exito
void guardarInfo(tInfo const& info); //Guardamos la info del jugador en su fichero(al cerrar el programa)
void mostrarInfo(tInfo const& info); //Muestra los exitos del jugador por pantalla
#endif