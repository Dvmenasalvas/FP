#include <string>

const int MESES = 12;
const int DIAS = 31;

typedef bool tCalendario[MESES][DIAS];

void inicializar(tCalendario calendario);
int numDiasVacaciones(tCalendario const & calendario);
bool tieneMitadVacaciones(tCalendario const & calendario);