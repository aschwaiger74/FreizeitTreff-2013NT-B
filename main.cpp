#include <iostream>
#include "List.h"
#include "Aktion.h"
#include "Mitglied.h"
#include "Organisator.h"
#include "FTServer.h"

using namespace std;

int main()
{
	Organisator* peterOrg = new Organisator("Peter", "Mueller");
	Aktion* aktFuss = new Aktion("02.03.2022", "15:00","Fussball",50,2,peterOrg);
	Aktion* aktKino = new Aktion("02.03.2023", "20:00", "Kino", 20, 3, peterOrg);
	Mitglied* antonM = new Mitglied("Anton", "Mitglied-1");
	Mitglied* beaM = new Mitglied("Bea", "Mitglied-2");
	Mitglied* cesarM = new Mitglied("Cesar", "Mitgleid-3");

	cout << "Test: Zuviele Anmeldungen" << endl;
	cout << "Anmeldung Anton: " << aktFuss->anmelden(antonM) << endl;
	cout << "Anmeldung Bea: " << aktFuss->anmelden(beaM) << endl;
	for (int i = 0; i < aktFuss->getTeilnehmer().size(); i++) { cout << "Teilnehmer der Aktion: " << aktFuss->getTeilnehmer().get(i)->getName() << endl; }

	cout << "\nTest: Warteschleife" << endl;
	aktFuss->eintragenInWarteliste(antonM);
	aktFuss->eintragenInWarteliste(beaM);
	for (int i = 0; i < aktFuss->getWarteliste().size(); i++) { cout << "Warteliste der Aktion: " << aktFuss->getWarteliste().get(i)->getName() << endl; }
	aktFuss->eintragenInWarteliste(beaM);


	//cout << "Klasse Aktion Test: \n\n";

	//cout <<"Uwe: "<<akt->anmelden(mit)<<"	"<<mit->anmeldenFuerAktion(akt)<<endl;
	//cout <<"Thorge: "<<akt->anmelden(mit1)<<"	"<<mit1->anmeldenFuerAktion(akt) <<endl;
	//cout <<"Joscha: "<<akt->anmelden(mit2)<<"	"<<mit2->anmeldenFuerAktion(akt)<<endl;
	//cout << "Ausgebucht: " << akt->istAusgebucht()<< endl;
	//cout << "Teilnehmer: " << akt->istTeilnehmer(mit1)<<endl;
	//akt->eintragenInWarteliste(mit2);
	//cout << "Warteliste: " << akt->istAufWarteliste(mit2) << endl;
	//akt->abmelden(mit);
	//cout << "Abmelden funktioniert: " << akt->istTeilnehmer(mit2) << endl;
	//Aktion* akt1 = new Aktion("02.03.2022", "16:00", "Basketball", 25, 2, org);
	//cout << "\nKlasse Mitglied Test: \n\n";
	//
	//mit1->anmeldenFuerAktion(akt1)<<akt1->anmelden(mit1);
	//cout << "Angemeldet Thorge: " << akt1->istTeilnehmer(mit1)<<endl;
	//cout <<"Zahlung: "<<mit1->berechneZahlung(2022, 3)<<" Richtig, weil 2 Aktionen stattfinden 50+25+10 und mit1 in diesen beiden angemeldet wurde"<<endl;
	//mit1->eintragenInWarteliste(akt1);
	//cout << "Eintragen in Warteliste Thorge: " << mit1->getmeineWarteliste().contains(akt1)<<endl;
	//cout << "Abmelden Thorge: " << mit1->abmeldenVonAktion(akt)<<endl;
	//cout << "Zahlung nach Abmeldung: " << mit1->berechneZahlung(2022, 3);
	//cout << "\nKlasse Organisator Test: \n\n";
	//cout <<"Zahlung: "<< org->berechneZahlung(2022,3)<<"	bedeutet er macht 70 Euro plus mit seinen Aktionen. ";

	system("pause");
	return 0;
}