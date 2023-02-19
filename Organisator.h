#pragma once
#include <iostream>
#include <string>
#include "Mitglied.h"
using namespace std;


class Mitglied;
class Aktion;
class Organisator : public Mitglied
{
private:
	static double honorar;
	List<Aktion*> meineAktionen;
public:
	Organisator();
	Organisator(string name, string vorname);
	void hinzufuegenAktion(Aktion* a);
	bool abmeldenVonAktion(Aktion* a);
	void anbietenAktion(Aktion* a); // fehlt
	double berechneZahlung(int jahr, int monat);
	~Organisator();
};

