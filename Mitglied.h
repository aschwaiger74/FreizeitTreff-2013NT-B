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
	bool anmeldenFuerAktion(Aktion* a); //muss immer mit anmelden funktion von Aktion ausgef�hrt werden.
	void eintragenInWarteliste(Aktion* a);
	bool abmeldenVonAktion(Aktion* a);
	double berechneZahlung(int jahr, int monat);
	string getName();
	string getBenutzername();
	string getPasswort();
	List<Aktion*> getMeineWarteliste();
	List<Aktion*> getMeineTermine();
	~Mitglied();
};

