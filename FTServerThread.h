#pragma once
#include "Thread.h" 

class FTServer;
class Socket;
class Mitglied;

class FTServerThread : public CThread 
{
private:
	Socket* clientSocket;
	Mitglied* mitglied;
	FTServer* ftserver;
public:
	FTServerThread(Socket* clientSocket, FTServer* fts);
	void run();
	~FTServerThread();
};