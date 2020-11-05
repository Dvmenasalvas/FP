#include "ClientList.h"

void display(tClient const & client) {
	std::cout << std::setw(15) << std::left << client.login << std::setw(11) << std::left << client.regDate << client.age << " years " << client.city << '\n';
}
void load(tClientList & list) {
	std::ifstream archivo;
	archivo.open(CLIENTS);
	if (archivo.is_open()) {
		tClient client;
		archivo >> client.login;
		while (client.login != "XXX") {
			archivo >> client.regDate >> client.age >> client.city;
			list.clients[list.tam] = new tClient;
			*list.clients[list.tam] = client;
			list.tam++;
			archivo >> client.login;
		}
		archivo.close();
	}
	else std::cout << "No se ha podido abrir el archivo " << CLIENTS;
}
void show(tClientList const & list, int ini) {
	if (ini < list.tam) {
		std::cout << ini + 1 << ": ";
		display(*list.clients[ini]);
		show(list, ini + 1);
	}
}

void free(tClientList const & list) {
	for (int i = 0; i < list.tam; i++)
		delete list.clients[i];
}