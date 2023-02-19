#pragma once
#include "ServerSocket.hpp"
#include "List.h"
#include "Aktion.h"
#include "Mitglied.h"
#include "FTServerThread.h"

class FTServer
{
private:
	int port;
	ServerSocket* serversocket;
	List<Mitglied*> mitglieder;
	List<Aktion*> aktionen;
public:
	FTServer(int port);
	void starten();
	Mitglied* findeMitglied(string benname, string pw);
	Aktion* findeAktion(int anr);
	void berechneZahlungen(int jahr, int monat);
	~FTServer();
};

