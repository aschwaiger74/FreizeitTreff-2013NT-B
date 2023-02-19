#pragma once
#include <iostream>
#include <string>
#include "Aktion.h"
#include "List.h"
using namespace std;

class Aktion;
class Mitglied
{
protected:
	string name;
	string vorname;
	string benutzername;
	string passwort;
	static double mtlBeitrag;
	List <Aktion*> meineWarteliste;
	List <Aktion*> meineTermine;
public:
	Mitglied();
	Mitglied(string name, string vorname);
	bool anmeldenFuerAktion(Aktion* a); //muss immer mit anmelden funktion von Aktion ausgeführt werden.
	void eintragenInWarteliste(Aktion* a);
	bool abmeldenVonAktion(Aktion* a);
	double berechneZahlung(int jahr, int monat);
	string getname();
	string getbenutzername();
	string getpasswort();
	List<Aktion*> getmeineWarteliste();
	List<Aktion*> getmeineTermine();
	~Mitglied();
};

