#include "FTServerThread.h"
#include "Mitglied.h"
#include "Socket.hpp"
#include "FTServer.h"

FTServerThread::FTServerThread(Socket* clientSocket, FTServer* fts)
{
	mitglied = new Mitglied();
	this->clientSocket = clientSocket;
	ftserver = fts;
}

void FTServerThread::run()
{
	string ben, pw,tmp;
	tmp = clientSocket->readLine();
	ben =tmp.substr(0, tmp.find(";"));
	pw= tmp.substr(tmp.find(";")+1);
	mitglied = ftserver->findeMitglied(ben, pw);
	if (mitglied != NULL) 
	{
		clientSocket->write("OK \n");
	}
	else 
	{
		clientSocket->write("NOK Mitglied existiert nicht.\n");
		return;
	}
	string anf = clientSocket->readLine();
	while (anf != "quit") 
	{
		if (anf.find("eintragenInWarteliste")) 
		{
			string anrs = anf.substr(22, anf.find(";"));   
			int anr = stoi(anrs);
			Aktion* a = nullptr;
			a = ftserver->findeAktion(anr);
			if (a != nullptr) 
			{
				mitglied->eintragenInWarteliste(a); 
				a->eintragenInWarteliste(mitglied);
				clientSocket->write("OK\n");
			}
			else 
			{
				clientSocket->write("NOK Aktion existiert nicht. \n");
			}

		}
		else 
		{
			clientSocket->write("NOK Unbekanntes Kommando\n");
		}
		anf = clientSocket->readLine();
	}
	clientSocket->write("OK bye\n");
	clientSocket->close();
}

FTServerThread::~FTServerThread()
{

}
