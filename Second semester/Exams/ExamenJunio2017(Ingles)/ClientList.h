#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX_CLIENT = 50;
const std::string CLIENTS = "clients.txt";

struct tClient {
	std::string login;
	std::string regDate;
	int age;
	std::string city;
};

void display(tClient const & client);

struct tClientList {
	tClient* clients[MAX_CLIENT];
	int tam;
};

void load(tClientList & list);
void show(tClientList const & list, int ini);
void free(tClientList const & list);

#endif