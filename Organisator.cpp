#include "Organisator.h"


double Organisator::honorar = 40;

Organisator::Organisator() : Mitglied()
{

}

Organisator::Organisator(string name, string vorname) : Mitglied(name, vorname)
{
}

void Organisator::hinzufuegenAktion(Aktion* a)
{
	meineAktionen.add(a);
}

bool Organisator::abmeldenVonAktion(Aktion* a)
{
	bool ergebnis = false;
	for (int i = 0;i < meineAktionen.size();i++)
	{
		ergebnis = this->abmeldenVonAktion(a);
	}
	return ergebnis;
}

double Organisator::berechneZahlung(int jahr, int monat)
{
	int anz = 0;
	for (int i = 0;i < meineAktionen.size();i++)
	{
		int m;
		int j;
		string datum = meineAktionen.get(i)->getDatum();
		m = stoi(datum.substr(3, datum.find("."))); //datum hat immer 2 stellen im monat&tag .split() funktion von String simuliert
		j = stoi(datum.substr(6));
		if (m == monat && j == jahr)
		{
			anz++;
		}
	}
	return Mitglied::berechneZahlung(jahr, monat) - honorar * anz;
}

Organisator::~Organisator()
{
}
