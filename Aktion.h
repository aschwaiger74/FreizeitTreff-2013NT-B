#pragma once
#include <iostream>
#include <string>

#include "List.h"
using namespace std;

class Mitglied;
class Organisator;

class Aktion
{
private:
	static int anrzaehler;
	int anr;
	int plaetze;
	string datum; // muss immer 2 stellen im monat&tag haben also z.b bei februar 02.02.2022...
	string beginn;
	string titel;
	double kosten;
	Organisator* veranstalter;
	List<Mitglied*> teilnehmer;
	List<Mitglied*> warteliste;
public:
	Aktion();
	Aktion(string datum, string beginn, string titel, double kosten, int plaetze, Organisator* org);
	bool anmelden(Mitglied* m); //muss immer mit anmeldenFuerAktion funktion von Mitglied ausgeführt werden.
	void eintragenInWarteliste(Mitglied* m);
	bool abmelden(Mitglied* m);
	bool istTeilnehmer(Mitglied* m);
	bool istAufWarteliste(Mitglied* m);
	bool istAusgebucht();
	string getDatum();
	double getKosten();
	int getAnr();
	List<Mitglied*> getTeilnehmer();
	List<Mitglied*> getWarteliste();
	Organisator* getVeranstalter();
	~Aktion();
};

