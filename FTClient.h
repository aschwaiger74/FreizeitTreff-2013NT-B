#pragma once
#include <string>
#include "Socket.hpp"

using namespace std;

class FTClient
{
private:
	string server;
	int port;
	Socket* clientSocket;
public:
	FTClient(string server, int port);
	string login(string benname, string passwort); //wird in der Klausur nicht gefordert.
	string logout(); //wird in der Klausur nicht gefordert.
	string anzeigenAlleAktionen(); //wird in der Klausur nicht gefordert.
	string anzeigenMeineTermine(); //wird in der Klausur nicht gefordert.
	string anmeldenFuerAktion(int anr); //wird in der Klausur nicht gefordert.
	string eintragenInWarteliste(int anr);
	string abmeldenVonAktion(int anr); //wird in der Klausur nicht gefordert.
	string anbietenAktion(string aktionDaten); //wird in der Klausur nicht gefordert.
	~FTClient();
};

