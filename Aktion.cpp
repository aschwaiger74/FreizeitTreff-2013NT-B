#include "Aktion.h"
#include "Organisator.h"

int Aktion::anrzaehler = 0;

Aktion::Aktion()
{
	anr = anrzaehler++;
	plaetze = 0;
	datum = "";
	beginn = "";
	titel = "";
	veranstalter = nullptr;
	kosten = 0;
}

Aktion::Aktion(string datum, string beginn, string titel, double kosten, int plaetze, Organisator* org)
{
	anr = anrzaehler++;
	this->datum = datum;
	this->beginn = beginn;
	this->titel = titel;
	this->kosten = kosten;
	this->plaetze = plaetze;
	veranstalter = org;	// Aktion weiß, wer der Organisator ist
	veranstalter->hinzufuegenAktion(this);  // Der Organisator hat eine Liste mit allen Aktionen.
	teilnehmer.add(org); // Der Organisator ist immer auch Teilnehmer seiner Aktion. 
}

bool Aktion::anmelden(Mitglied* m) //muss immer mit anmeldenFuerAktion funktion von Mitglied ausgeführt werden.
{
	if (teilnehmer.size() < plaetze) //plaetze frei
	{
		if(this->istTeilnehmer(m)) //falls m schon angemeldet ist
			{
				return true;
			}
		teilnehmer.add(m); 
		return true;
	}
	return false;
}

void Aktion::eintragenInWarteliste(Mitglied* m)
{
	if (this->istTeilnehmer(m)) //falls m schon ein teilnehmer ist 
	{
		return;
	}
	if (this->istAufWarteliste(m)) //falls m schon auf der warteliste steht 

	{
		return;
	}
	warteliste.add(m);
}

bool Aktion::abmelden(Mitglied* m)
{
	if (teilnehmer.remove(m))
	{
		if (warteliste.size() > 0)
		{
			teilnehmer.add(warteliste.remove(0)); //damit die Reihenfolge der Warteschlange berücksichtigt wird
		}
		return true;
	}
	return warteliste.remove(m);
}

bool Aktion::istTeilnehmer(Mitglied* m)
{
	return teilnehmer.contains(m);
}

bool Aktion::istAufWarteliste(Mitglied* m)
{
	return warteliste.contains(m);
}

bool Aktion::istAusgebucht()
{
	if (teilnehmer.size() >= plaetze) return true;
	return false;
}

string Aktion::getDatum()
{
	return datum;
}

double Aktion::getKosten()
{
	return kosten;
}

int Aktion::getAnr()
{
	return anr;
}

List<Mitglied*> Aktion::getTeilnehmer()
{
	return teilnehmer;
}

List<Mitglied*> Aktion::getWarteliste()
{
	return warteliste;
}

Organisator* Aktion::getVeranstalter()
{
	return veranstalter;
}

Aktion::~Aktion()
{
}
