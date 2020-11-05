#ifndef DATELIST_H
#define DATELIST_H
#include "ClientList.h"
#include "checkML.h"

const int CAP_INI = 10;

struct tDate {
	tClient* a, *b;
	std::string place;
	int rate;
};

struct tDateList {
	tDate* lista;
	int tam, capacidad;
};

tDateList newList();
void insert(tDateList & list, tDate const & date);
void display(tDateList const & list);
void free(tDateList const & dates, tClientList const & clients);
#endif