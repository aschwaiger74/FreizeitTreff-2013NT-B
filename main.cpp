#include <iostream>
#include "List.h"
#include "Aktion.h"
#include "Mitglied.h"
#include "Organisator.h"
#include "FTServer.h"
#include "FTClient.h"
using namespace std;

int main()
{
	cout << "(1) Server -- () Client" << endl;
	int wahl = 0;
	cin >> wahl;
	if (wahl == 1) {
		FTServer fts(54321);
		fts.starten();

	}
	else 
	{
		FTClient ftc("127.0.0.1", 54321);
		ftc.login("Peter", "Peter");
	}

	Organisator* peterOrg = new Organisator("Peter", "Mueller");
	Aktion* aktFuss = new Aktion("02.03.2022", "15:00","Fussball",50,2,peterOrg);
	Aktion* aktKino = new Aktion("02.03.2022", "20:00", "Kino", 20, 3, peterOrg);
	Mitglied* antonM = new Mitglied("Anton", "Mitglied-1");
	Mitglied* beaM = new Mitglied("Bea", "Mitglied-2");
	Mitglied* cesarM = new Mitglied("Cesar", "Mitgleid-3");

	cout << "Test: Zuviele Anmeldungen" << endl;
	cout << "MethodenTest - istAusgebucht() " << aktFuss->istAusgebucht() << endl;
	cout << "Anmeldung Anton by Aktion: " << aktFuss->anmelden(antonM) << " Anmeldung Anton by Mitglieder: " << antonM->anmeldenFuerAktion(aktFuss) << endl;
	cout << "MethodenTest - istAusgebucht() " << aktFuss->istAusgebucht() << endl;
	cout << "Anmeldung Bea: " << aktFuss->anmelden(beaM) << " FEHLER! DA BEA GLAUBT, DASS SIE ANGEMELDET IST Anmeldung Bea by Mitglieder: " << beaM->anmeldenFuerAktion(aktFuss) << endl;
	for (int i = 0; i < aktFuss->getTeilnehmer().size(); i++) { cout << "Teilnehmer der Aktion: " << aktFuss->getTeilnehmer().get(i)->getName() << endl; }

	cout << "\nTest: Warteschleife" << endl;
	aktFuss->eintragenInWarteliste(antonM);
	aktFuss->eintragenInWarteliste(beaM);
	for (int i = 0; i < aktFuss->getWarteliste().size(); i++) { cout << "Warteliste der Aktion: " << aktFuss->getWarteliste().get(i)->getName() << endl; }
	aktFuss->eintragenInWarteliste(beaM);

	cout << "\nTest: Zahlungen" << endl;
	cout << "10 Mitglied, da keine Teilnahme an einer Aktion. Name: " << cesarM->getName() << " Zahlung: " << cesarM->berechneZahlung(2022, 03) << endl;
	cout << "10 + 50, da Teilnahme an einer Aktion. Name: " << antonM->getName() << " Zahlung: " << antonM->berechneZahlung(2022, 03) << endl;
	cout << "FEHLER! Bea glaubt, sie könnte teilnehmen. 10 Zahlung, da keine Teilnahme an einer Aktion. Name: " << beaM->getName() << " Zahlung: " << beaM->berechneZahlung(2022, 03) << endl;
	cout << "RICHTIG, da 10 -40 Fussball - 40Kino Name: " << peterOrg->getName() << " Zahlung: " << peterOrg->berechneZahlung(2022, 03) << endl;

	system("pause");
	return 0;
}