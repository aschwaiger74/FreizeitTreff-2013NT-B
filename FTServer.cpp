#include "FTServer.h"

FTServer::FTServer(int port)
{
	this->port = port;
	serversocket = new ServerSocket(port);
}

void FTServer::starten()
{
	Socket* workSocket;
	workSocket = serversocket->accept();
	/*FTServerThread* go = new FTServerThread(workSocket, this);*/
	/*go->run();*/
}

Mitglied* FTServer::findeMitglied(string benname, string pw)
{
	for (int i = 0; i < mitglieder.size(); i++)
	{
		if (mitglieder.get(i)->getbenutzername() == benname && mitglieder.get(i)->getpasswort() == pw) 
		{
			return mitglieder.get(i);
		}
	}
	return nullptr;
}

Aktion* FTServer::findeAktion(int anr)
{
	for (int i = 0; i < aktionen.size(); i++)
	{
		if (aktionen.get(i)->getanr() == anr) 
		{
			return aktionen.get(i);
		}
	}
	return nullptr;
}

void FTServer::berechneZahlungen(int jahr, int monat)
{
	double zahlungsbetrag = 0;
	for (int i = 0; i < mitglieder.size(); i++) 
	{
		zahlungsbetrag=mitglieder.get(i)->berechneZahlung(jahr, monat)+zahlungsbetrag;
	}
	cout << "Zahlungsbetrag: " << zahlungsbetrag <<endl;
}

FTServer::~FTServer()
{
}
