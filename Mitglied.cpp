#include "Mitglied.h"

double Mitglied::mtlBeitrag = 10;

Mitglied::Mitglied()
{
	name = "";
	vorname = "";
	benutzername = "";
	passwort = "";
}

Mitglied::Mitglied(string name, string vorname)
{
	this->name = name;
	this->vorname = vorname;
	benutzername = "";
	passwort = "";
}

bool Mitglied::anmeldenFuerAktion(Aktion* a) //muss immer mit anmelden funktion von Aktion ausgeführt werden.
{
	if (meineTermine.contains(a)) //falls schon drinne
	{
		return true;
	}
	if (meineWarteliste.contains(a)) //wenn er schon in der Warteschlange ist wird er daraus entfernt und angemeldet
	{
		meineWarteliste.remove(a);
		meineTermine.add(a);
		return true;
	}
	meineTermine.add(a);
	return true;
}

void Mitglied::eintragenInWarteliste(Aktion* a)
{
	if (!meineTermine.contains(a))
	{
		meineWarteliste.add(a);
	}
}

bool Mitglied::abmeldenVonAktion(Aktion* a)
{
	if (meineTermine.remove(a))
	{	
		if (meineWarteliste.size() > 0)
		{
			meineTermine.add(meineWarteliste.remove(0));
		}
		return true;
	}
	return meineWarteliste.remove(a);
}

double Mitglied::berechneZahlung(int jahr, int monat)
{
	double zahlung = mtlBeitrag;
	for (int i = 0;i < meineTermine.size();i++)
	{
		int m = 0;
		int	j = 0;
		string datum = meineTermine.get(i)->getDatum();
		m = stoi(datum.substr(3, datum.find("."))); //datum hat immer 2 stellen im monat&tag .split() funktion von String simuliert
		j = stoi(datum.substr(6));
		if (m == monat && j == jahr)
		{
			zahlung = zahlung + meineTermine.get(i)->getKosten();
		}
	}
	return zahlung;
}

string Mitglied::getName()
{
	return name;
}

string Mitglied::getBenutzername()
{
	return benutzername;
}

string Mitglied::getPasswort()
{
	return passwort;
}

List<Aktion*> Mitglied::getMeineWarteliste()
{
	return meineWarteliste;
}

List<Aktion*> Mitglied::getMeineTermine()
{
	return meineTermine;
}

Mitglied::~Mitglied()
{
}
