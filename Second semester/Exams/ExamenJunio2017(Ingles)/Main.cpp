#include "DateList.h"

int pedirEntero() {
	int entero;
	std::cin >> entero;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> entero;
	}
	std::cin.ignore(10000, '\n');
	return entero;
}

int menu() {
	int op;
	do {
		std::cout << "1. Display Client List" << '\n';
		std::cout << "2. New Date" << '\n';
		std::cout << "3. Display Dates" << '\n';
		std::cout << "0. Exit" << '\n';
		std::cout << "Elige una opcion: ";
		op = pedirEntero();
	} while (op < 0 || op > 3);
	return op;
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tClientList clients;
	clients.tam = 0;
	load(clients);

	tDateList dates = newList();
	int op;
	do {
		std::cout << '\n';
		op = menu();
		tDate date;
		switch (op) {
		case 1:
			if (clients.tam <= 0) std::cout << "No ha ningun cliente en la lista." << '\n';
			else show(clients, 0);
			break;
		case 2:
			if (clients.tam <= 0) std::cout << "No ha ningun cliente en la lista." << '\n';
			else {
				int a, b;
				std::cout << "Date between two clients. Choose two numbers separated by a space..." << '\n';
				show(clients, 0);
				do {
					std::cout << "First client: ";
					a = pedirEntero();
				} while (a <= 0 || a > clients.tam);
				do{
					std::cout << "Second client: ";
					b = pedirEntero();
				} while (b <= 0 || b > clients.tam);
				date.a = clients.clients[a - 1];
				date.b = clients.clients[b - 1];
				std::cout << "Date's place: ";
				std::cin >> date.place;
				std::cout << "Date's rating (between 0 and 5): ";
				do {
					date.rate = pedirEntero();
				} while (date.rate < 0 || date.rate > 5);
				insert(dates, date);
			}
			break;
		case 3:
			if (dates.tam <= 0) std::cout << "No hay ninguna cita." << '\n';
			else display(dates);
			break;
		}
	} while (op != 0);

	free(dates, clients);
	return 0;
}