#include "FTClient.h"
#include <iostream>
using namespace std;

FTClient::FTClient(string server, int port)
{
	this->server = server;
	this->port = port;
	clientSocket = new Socket(server, port);

}

string FTClient::login(string benname, string passwort)
{
	return string();
}

string FTClient::logout()
{
	return string();
}

string FTClient::anzeigenAlleAktionen()
{
	return string();
}

string FTClient::anzeigenMeineTermine()
{
	return string();
}

string FTClient::anmeldenFuerAktion(int anr)
{
	return string();
}

string FTClient::eintragenInWarteliste(int anr)
{
	while (clientSocket->connect() == 0) 
	{
		cout << "Warte auf Verbindung mit dem Server." << endl;
		Sleep(500);
	}
	cout << "Verbunden mit dem Server." << endl;
	clientSocket->write("Peter;123");
	if (clientSocket->readLine() == "OK \n") 
	{
		clientSocket->write("eintragenInWarteliste123;");
		if (clientSocket->readLine() == "OK\n") 
		{
			clientSocket->write("quit");
			if (clientSocket->readLine() == "OK bye\n") 
			{
				clientSocket->close();
				return "Erfolgreiche Kommunikation\n";
			}
			else 
			{
				clientSocket->close();
				return "Fehler beim Lesen von quit\n";
			}
		}
		else 
		{
			clientSocket->close();
			return "Fehler beim Lesen von eintragenInWarteliste\n";
		}
	}
	else 
	{
		clientSocket->close();
		return "Fehler beim finden des Mitglieds\n";
	}
}

string FTClient::abmeldenVonAktion(int anr)
{
	return string();
}

string FTClient::anbietenAktion(string aktionDaten)
{
	return string();
}

FTClient::~FTClient()
{
}
