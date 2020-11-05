//Hecho por Eloy Mosig Garcia y Daniel Valverde Menasalvas

#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <locale>

int solicitaAnyo();										 //solicita, valida y devuelve un año introducido por el usuario a través de teclado. Debe ser 1900 o posterior.
int solicitaMes();										 //solicita, valida y devuelve un mes introducido por el usuario a través de teclado.
int solicitaDia(int mes, int anyo); 					 //solicita, valida y devuelve un día introducido por el usuario, correcto para el mes y el año proporcionados.
long int diasTranscurridos(int dia, int mes, int anyo);  //devuelve el número de días transcurridos desde el 1/enero/1900 hasta la fecha dia/mes/anyo.
long int diaAnyosCompletos(int anyo); 					 //devuelve el número de días que han transcurrido desde el 1/enero/1900 hasta el 1/enero/anyo.
int diasEsteAnyo(int dia, int mes, int anyo); 			 //devuelve el número de días transcurridos desde la fecha 1/enero/anyo hasta la fecha dia/mes/anyo
int contarBisiestos(int anyoInicio, int anyoFinal);		 //devuelve el número de años bisiestos existentes en el intervalo [anyoInicio, anyoFinal]
int diasMes(int mes, int anyo); 						 //devuelve el número de días del mes y año dado, teniendo en cuenta en el caso de ser el mes de febrero si el año es bisiesto o no
bool esBisiesto(int anyo);								 //devuelve un valor booleano que indica si el año anyo es o no bisiesto.
int diaSemana(long int numDias);						 //devuelve una representación entera del día de la semana que es después de haber transcurrido numDias días desde el 1/enero/1900 (0 si es lunes, 1 si es martes,…, 6 si es domingo).
string nombreDia(int representacionDia);				 //recibe un entero que representa un día de la semana (0 si es lunes, 1 si es martes,…, 6 si es domingo) y devuelve una cadena con el nombre del día.
string nombreMes(int mes);								 //recibe un entero que representa un mes del año (1 si es enero, 2 si es febrero,..., 12 si es diciembre) y devuelve una cadena con el nombre del mes.
int menu(); 											 //muestra por pantalla un menú con las distintas opciones y solicita, valida y devuelve la opción elegida.
string diaDeLaSemana(int dia, int mes, int anyo);		 //devuelve una cadena con el nombre del día de la semana en que cae la fecha dia/mes/anyo
int primerDomingoMes(int mes, int anyo); 				 //devuelve el día del mes que corresponde al primer domingo del mes/anyo dados
int domingosAnyo(int anyo);								 //muestra por pantalla los domingos del año anyo y devuelve el número de domingos mostrados.
bool puentes();											 // localiza los posibles puentes asociados a las fiestas de un año, guardadas en el archivo fiestas.txt, y guarda en el archivo puentes.txt aquellas fiestas que dan lugar a puente de acuerdo con el criterio y formato indicado anteriormente en el enunciado de la práctica.
int compruebaEntero(int num);							 //comprueba que el numero introducido es un entero

const int AnyoIni = 1900;
const int DiasAnyo = 365;

int main () {
	setlocale(LC_ALL, "spanish");  
	system("chcp 1252"); // Permite el uso de ñ y tildes
	int op;
	while(op != 0) {
		op = menu();
		int dia, mes, anyo;
		switch (op) {
		case 4: 
			puentes();
			break;
		case 3: 
			int anyo;
			anyo = solicitaAnyo();
			domingosAnyo(anyo);
			break;
		case 2: 
			mes = 1;
			anyo = solicitaAnyo();
			cout << "El primer domingo del año " << anyo << " es el día: " << primerDomingoMes(mes, anyo) << " de enero." << endl;
			break;
		case 1: 
			anyo = solicitaAnyo();
			mes = solicitaMes();
			dia = solicitaDia(mes, anyo);
			cout << "El día " << dia << " de " << nombreMes(mes) << " de " << anyo << " fue " << diaDeLaSemana(dia, mes, anyo) << endl;
			break;
		case 0: 
			break;
		}
	}
	return 0;
}

int solicitaAnyo() {
	int anyo;
	cout << "Introduzca año: ";
	cin >> anyo;
	anyo = compruebaEntero (anyo);
	while (anyo < AnyoIni) { // Comprobamos que el año no es menor que 1900. Si lo es, lo pedimos de nuevo
		cout << "Valor no válido. Inserte un año posterior a 1900: ";
		cin >> anyo;
		anyo = compruebaEntero (anyo);
	}
	return anyo;
}

int solicitaMes()	{
	int mes;
	cout << "Introduzca mes: "; 
	cin >> mes;
	mes = compruebaEntero (mes);
	while ((mes > 12) || (mes < 1)) { // Comprobamos que el mes es un entero entre 1 y 12. Si no lo es, lo pedimos de nuevo
		cout << "Valor no válido. Inserte un mes comprendido entre 1 y 12: ";
		cin >> mes; 
		mes = compruebaEntero (mes);
	}
	return mes;
}

int solicitaDia(int mes, int anyo){
	int dia;
	cout << "Introduzca día: ";
	cin >> dia;
	dia = compruebaEntero (dia); 
	while ((dia < 1) || (dia > diasMes(mes, anyo))){ //Comprobamos que el dia introducido es valido para el mes dado, si no lo es, lo pedimos otra vez
		cout << "El día no es válido para el mes dado. Introduzca un valor válido: ";
		cin >> dia;
		dia = compruebaEntero (dia);
	}

	return dia;
}

long int diasTranscurridos(int dia, int mes, int anyo){
	long int ndias;
	ndias = diaAnyosCompletos(anyo) + diasEsteAnyo(dia, mes, anyo); // Sumamos los dias desde el 01/01/1900 hasta el uno de enero de este anyo con los dias que han pasado este anyo
	return ndias;
}

long int diaAnyosCompletos(int anyo) {
	long int ndias;
	ndias = (anyo - AnyoIni) * DiasAnyo + contarBisiestos(AnyoIni, anyo); // Sumamos los 365 dias de cada año mas 1 por cada bisiesto
	return ndias;
}

int diasEsteAnyo(int dia, int mes, int anyo) {
	int ndias = dia - 1; //Sumamos los dias que han pasado este mes sin contar el dia actual
	mes--;
	while (mes > 0) { //Sumamos los dias de los meses anteriores al mes actual
		ndias = ndias + diasMes (mes, anyo);
		mes--;
	}
	return ndias;
}

int contarBisiestos(int anyoInicio, int anyoFinal) {
	int bisiestos, restaf, restai, bisiestof, bisiestoi; //Cogeremos como anyo de referencia el 1600 porque es menor a cualquier anyo valido y es multiplo de 400, lo que facilita los calculos
	restaf = anyoFinal - 1600 - 1; //Años que han pasado desde el 1600 al anyoFinal, sin contar este último
	restai = anyoInicio - 1600 - 1; //Años que han pasado desde el 1600 al anyoInicio, sin contar este último
	bisiestof = 97 * (restaf / 400) + 24 * ((restaf % 400) / 100) + (((restaf % 400) % 100) / 4); // Bisiestos desde 1600 hasta anyoFinal
	bisiestoi = 97 * (restai / 400) + 24 * ((restai % 400) / 100) + (((restai % 400) % 100) / 4); // Bisiestos desde 1600 hasta anyoInicio
	bisiestos = bisiestof - bisiestoi; //Bisiestos entre anyoInicio(contandolo) y anyoFinal(sin contarlo)
	return bisiestos;
}

int diasMes(int mes, int anyo) {
	int diasm;
	if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) diasm = 30;
	else {
		if (mes == 2) {
			if (esBisiesto(anyo)) diasm = 29; //Si es febrero, comprobamos si el anyo es bisiesto
			else diasm = 28;
		}
		else diasm = 31;
	}
	return diasm;
}

bool esBisiesto(int anyo) {
	if ((anyo % 400) == 0) return true; // Si es multiplo de 400, es bisiesto
	else {
		if (((anyo % 4) == 0) && ((anyo % 100) != 0)) return true; // Si es multiplo de 4 y no lo es de 100, tambien es bisiesto
		else return false;
	}

}

int diaSemana(long int numDias) {
	int ndiasemana = numDias % 7; 
	return ndiasemana;
}

string nombreDia(int representacionDia) {
	string diaSemana;
	switch (representacionDia) {
	case 6: diaSemana = "domingo";
		break;
	case 5: diaSemana = "sábado";
		break;
	case 4: diaSemana = "viernes";
		break;
	case 3: diaSemana = "jueves";
		break;
	case 2: diaSemana = "miércoles";
		break;
	case 1: diaSemana = "martes";
		break;
	case 0: diaSemana = "lunes";
		break;
	}
	return diaSemana;
}

string nombreMes(int mes) {
	string nmes;
	switch (mes) {
	case 1: nmes = "enero";
		break;
	case 2: nmes = "febrero";
		break;
	case 3: nmes = "marzo";
		break;
	case 4: nmes = "abril";
		break;
	case 5: nmes = "mayo";
		break;
	case 6: nmes = "junio";
		break;
	case 7: nmes = "julio";
		break;
	case 8: nmes = "agosto";
		break;
	case 9: nmes = "septiembre";
		break;
	case 10: nmes = "octubre";
		break;
	case 11: nmes = "noviembre";
		break;
	case 12: nmes = "diciembre";
		break;
	}
	return nmes;
}

int menu() {
	int op = -1;
	while ((op < 0) || (op > 4)) {
		cout << "1 - Calcular el día de la semana para una fecha dada" << endl;
		cout << "2 - Obtener la fecha correspondiente al primer domingo de un año" << endl;
		cout << "3 - Obtener los domingos de un año" << endl;
		cout << "4 - Obtener los posibles puentes de un año" << endl;
		cout << "0 - Salir" << endl;
		cout << "Opción: ";
		cin >> op;
		op = compruebaEntero (op);
		if((op < 0) || (op > 4)) cout << "¡Opción no válida!" << endl;
	}
	return op;
}

string diaDeLaSemana(int dia, int mes, int anyo){
	string dSemana;
	dSemana = nombreDia(diaSemana(diasTranscurridos(dia, mes, anyo)));
	return dSemana;
}

int primerDomingoMes(int mes, int anyo) {
	int domingo;
	domingo = 7 - diaSemana(diasTranscurridos(1, mes, anyo)); //Obtenemos los dias que han pasado desde un lunes al primer día del mes dado, obtenemos el dia de la semana correspondiente para ese dia y lo restamos a 7 para obtener la fecha del primer domingo
	return domingo;
}

int domingosAnyo(int anyo) {
	int dia, mes = 1, domingos = 1;
	bool primera = true;
	dia = primerDomingoMes(mes, anyo);
	cout << "Domingos de " << anyo << endl;
	cout << dia << " de " << nombreMes(mes) << endl; // Damos el primer domingo del año
	while(mes < 13){ // Un bucle nos da todos los domingos, comprobando que el mes y el dia son validos
		domingos++;
		dia = dia + 7;
		if(dia > diasMes(mes, anyo)){ // Si el dia no es valido para el mes dado, pasamos al mes siguiente
			dia = dia - diasMes(mes, anyo);
			mes++;
		}
		if(mes < 13) cout << dia << " de " << nombreMes(mes) << endl;
	}
	cout << "Número total de domingos: " << domingos << endl;
	return domingos;
	}

bool puentes() {
	ifstream fiestas;
	fiestas.open("fiestas.txt");
	ofstream puentes;
	puentes.open("puentes.txt");
	int dia, mes, anyo, dsemana;
	bool final = true; // Variable de control del bucle
	if (fiestas.is_open()) {
		fiestas >> anyo;
		puentes << anyo << endl;
		while (final) {
			fiestas >> dia >> mes;
			if ((dia == 0) && (mes == 0)) { // El centinela en fiestas.txt es el valor 0 0
				final = false;
				puentes << "0 0 XXX" << endl; // Marcamos el final de la escritura en puentes.txt
			}
			else {
				if (!(dia < 1) && !(dia > diasMes(mes, anyo))){
					dsemana = diaSemana(diasTranscurridos(dia, mes, anyo)); //Obtenemos el día de la semana para la fiesta en cuestión
					if ((dsemana == 1) || (dsemana == 3)) { // Si es martes o jueves lo escribimos en puentes.txt
					puentes << dia << " " << mes << " " << nombreDia(dsemana) << endl;
					}
				}
			}
		}
		fiestas.close();
		puentes.close();
		cout << "El archivo puentes.txt ha sido creado con éxito" << endl;
	} else cout << "No se ha podido abrir el archivo fiestas.txt" << endl;
	return true;
}

int compruebaEntero(int num) {
	// comprobamos que el numero insertado es un entero y, si no lo es, lo indicamos y pedimos otro
	while (cin.fail()) 
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Valor no válido. El valor introducido ha de ser un entero: ";
		cin >> num;
	}	
	cin.ignore(10000, '\n');
	return num;
}