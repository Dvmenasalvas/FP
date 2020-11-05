#include "Calendario.h"

void inicializar(tCalendario calendario) {
	for (int i = 0; i < MESES; i++)
		for (int j = 0; j < DIAS; j++)
			calendario[i][j] = false;
}
int numDiasVacaciones(tCalendario const & calendario) {
	int vacaciones = 0;
	for (int i = 0; i < MESES; i++)
		for (int j = 0; j < DIAS; j++)
			if (calendario[i][j]) vacaciones++;
	return vacaciones;
}
bool tieneMitadVacaciones(tCalendario const & calendario) {
	int vacaciones = 0, i = 0;
	while (vacaciones < 10 && i < MESES) {
		int j = 0;
		while (vacaciones < 10 && j < DIAS) {
			if (calendario[i][j]) vacaciones++;
			j++;
		}
		i++;
	}
	return vacaciones >= 10;
}