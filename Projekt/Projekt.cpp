#include <iostream>
#include "Artikl.h"
#include "Racun.h"
#include "Stavka.h"
#include "Kupac.h"
#include "Osoba.h"
#include "Statistika.h"
#include "top10.h"
#include "top10kolicina.h"
#include "top10racun.h"
#include <vector>
#include <iterator>
#include<string>
#include "tinyxml2.h"
#include "TextTable.h"
#include <stdlib.h>
#include <set>

using namespace std;
using namespace tinyxml2;

/*
* ---------------------------------
*
* Funkcija za izlazak iz programa
*
* ---------------------------------
*/
static void Izlazak()
{
	exit(0);
}
/*
* ------------------------------------
*
* Funkcija za ispis zglavnog izbornika
*
* ------------------------------------
*/
static void DajIzbornik()
{
	cout << "1) Kreiraj racun" << endl;
	cout << "2) Dodavanje/Azuriranje/Brisanje kupca" << endl;
	cout << "3) Pregled racuna kupaca" << endl;
	cout << "4) Storniranje racuna" << endl;
	cout << "5) Pregled storniranih racuna" << endl;
	cout << "6) Statistika" << endl;
	cout << "7) Izlazak iz programa" << endl;
	cout << "Odabir: ";
}
/*
void UcitajRacuneiStavke()
{
	vector<Stavka*> vStavke;
	vStavke.clear();
	XMLDocument stavke;
	stavke.LoadFile("stavke.xml");
	XMLElement* pStavka = stavke.FirstChildElement("dataset");
	XMLElement* pChildStavka;
	set<Stavka*> sStavke;
	for (pChildStavka = pStavka->FirstChildElement("Stavka"); pChildStavka != NULL; pChildStavka = pChildStavka->NextSiblingElement())
	{
		int nId = stoi(pChildStavka->Attribute("ID"));
		double dKolicina = stod(pChildStavka->Attribute("kolicina"));
		string sBrojRacuna = pChildStavka->Attribute("brojRacuna");
		float fUkupnaCijena = stof(pChildStavka->Attribute("ukupanIznos"));
		string sSifra = pChildStavka->Attribute("sifra");
		string sNaziv = pChildStavka->Attribute("naziv");
		float fCijena = stof(pChildStavka->Attribute("cijena"));
		vStavke.push_back(new Stavka(nId, sSifra, sNaziv, fCijena, dKolicina, sBrojRacuna, fUkupnaCijena));
		sStavke.insert(new Stavka(nId, sSifra, sNaziv, fCijena, dKolicina, sBrojRacuna, fUkupnaCijena));
	}

	vector<Racun*> vRacuni;
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRacun = racuni.FirstChildElement("dataset");
	XMLElement* pChildRacun;
	for (pChildRacun = pRacun->FirstChildElement("Racun"); pChildRacun != NULL; pChildRacun = pChildRacun->NextSiblingElement())
	{
		int nId = stoi(pChildRacun->Attribute("ID"));
		string sBrojRacuna2 = pChildRacun->Attribute("brojRacuna");
		string sSifraKupca = pChildRacun->Attribute("sifraKupca");
		float fCijena2 = stof(pChildRacun->Attribute("ukupanIznos"));
		string sDatum = pChildRacun->Attribute("datum");
		string sStornirano = pChildRacun->Attribute("stornirano");
		vRacuni.push_back(new Racun(vStavke, nId, sBrojRacuna2, sSifraKupca, fCijena2, sDatum, sStornirano));
	}
}

vector<Racun*> DajVektorRacun()
{
	vector<Racun*> vRacuni;
	vector<Stavka*> vPrivremeni;
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRacun = racuni.FirstChildElement("dataset");
	XMLElement* pChildRacun;
	for (pChildRacun = pRacun->FirstChildElement("Racun"); pChildRacun != NULL; pChildRacun = pChildRacun->NextSiblingElement())
	{
		int nId = stoi(pChildRacun->Attribute("ID"));
		string sBrojRacuna2 = pChildRacun->Attribute("brojRacuna");
		string sSifraKupca = pChildRacun->Attribute("sifraKupca");
		float fCijena2 = stof(pChildRacun->Attribute("ukupanIznos"));
		string sDatum = pChildRacun->Attribute("datum");
		string sStornirano = pChildRacun->Attribute("stornirano");
		vRacuni.push_back(new Racun(vPrivremeni, nId, sBrojRacuna2, sSifraKupca, fCijena2, sDatum, sStornirano));
	}

	return vRacuni;
}
vector<Stavka*> DajVektorStavka()
{
	vector<Stavka*> vStavke;
	vStavke.clear();
	XMLDocument stavke;
	stavke.LoadFile("stavke.xml");
	XMLElement* pStavka = stavke.FirstChildElement("dataset");
	XMLElement* pChildStavka;
	for (pChildStavka = pStavka->FirstChildElement("Stavka"); pChildStavka != NULL; pChildStavka = pChildStavka->NextSiblingElement())
	{
		int nId = stoi(pChildStavka->Attribute("ID"));
		double dKolicina = stod(pChildStavka->Attribute("kolicina"));
		string sBrojRacuna = pChildStavka->Attribute("brojRacuna");
		float fUkupnaCijena = stof(pChildStavka->Attribute("ukupanIznos"));
		string sSifra = pChildStavka->Attribute("sifra");
		string sNaziv = pChildStavka->Attribute("naziv");
		float fCijena = stof(pChildStavka->Attribute("cijena"));
		vStavke.push_back(new Stavka(nId, sSifra, sNaziv, fCijena, dKolicina, sBrojRacuna, fUkupnaCijena));
	}
	return vStavke;
}

Racun* PronadiRacunPoId(int nId)
{
	Racun* oRacun = nullptr;
	vector<Racun*> vRacuni = DajVektorRacun();
	for (int i = 0; i < vRacuni.size(); i++)
	{
		if (vRacuni[i]->m_nId == nId)
		{
			oRacun = vRacuni[i];
		}
	}
	return oRacun;
}

Stavka* PronadiStavkuPoId(int nId)
{
	Stavka* oStavka = nullptr;
	vector<Stavka*> vStavke = DajVektorStavka();
	for (int i = 0; i < vStavke.size(); i++)
	{
		if (vStavke[i]->m_nId == nId)
		{
			oStavka = vStavke[i];
		}
	}
	return oStavka;
}
*/
/*
* ----------------------------------------------
*
* Funkcija za upis sadrzaja vektora u racuni.xml
*
* ----------------------------------------------
*/
static void XML(vector<Racun*>vRacuni)
{
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRootRacuni = racuni.FirstChildElement("dataset");
	vector<Racun*>::iterator iRacun;

	for (iRacun = vRacuni.begin(); iRacun != vRacuni.end(); ++iRacun)
	{
		XMLElement* nodeRacuni = pRootRacuni->InsertNewChildElement("Racun");
		nodeRacuni->SetAttribute("ID", (*iRacun)->DajId());
		nodeRacuni->SetAttribute("brojRacuna", (*iRacun)->DajBrojRacuna().data());
		nodeRacuni->SetAttribute("sifraKupca", (*iRacun)->DajSifruKupca().data());
		nodeRacuni->SetAttribute("ukupanIznos", (*iRacun)->DajUkupanIznos());
		nodeRacuni->SetAttribute("datum", (*iRacun)->DajDatum().data());
		nodeRacuni->SetAttribute("stornirano", (*iRacun)->Stornirano().data());
		pRootRacuni->LinkEndChild(nodeRacuni);
		racuni.SaveFile("racuni.xml");
	}
}
/*
* ----------------------------------------------
*
* Funkcija za upis sadrzaja vektora u kupac.xml
*
* ----------------------------------------------
*/
static void XML2(vector<Kupac*>vKupci)
{
	XMLDocument oXMLDocumentKupac;
	oXMLDocumentKupac.LoadFile("kupci.xml");
	XMLElement* pRootKupac = oXMLDocumentKupac.FirstChildElement("dataset");
	vector<Kupac*>::iterator iKup;

	for (iKup = vKupci.begin(); iKup != vKupci.end(); ++iKup)
	{
		XMLElement* nodeKupci = pRootKupac->InsertNewChildElement("Kupac");
		nodeKupci->SetAttribute("ime", (*iKup)->DajIme().data());
		nodeKupci->SetAttribute("prezime", (*iKup)->DajPrezime().data());
		nodeKupci->SetAttribute("grad", (*iKup)->DajGrad().data());
		nodeKupci->SetAttribute("adresa", (*iKup)->DajAdresu().data());
		nodeKupci->SetAttribute("sifraKupca", (*iKup)->DajSifruKupca().data());
		nodeKupci->SetAttribute("sifraBrojila", (*iKup)->DajSifruBrojila().data());
		pRootKupac->LinkEndChild(nodeKupci);
		oXMLDocumentKupac.SaveFile("kupci.xml");
	}
}
/*
* ----------------------------------------------
*
* Funkcija za upis sadrzaja vektora u stavke.xml
*
* ----------------------------------------------
*/
static void XML3(vector<Stavka*>vStavka)
{
	XMLDocument stavke;
	stavke.LoadFile("stavke.xml");
	XMLElement* pRootStavka = stavke.FirstChildElement("dataset");
	vector<Stavka*>::iterator iStav;

	for (iStav = vStavka.begin(); iStav != vStavka.end(); ++iStav)
	{
		XMLElement* nodeStavke = pRootStavka->InsertNewChildElement("Stavka");
		nodeStavke->SetAttribute("ID", (*iStav)->DajID());
		nodeStavke->SetAttribute("sifra", (*iStav)->DajSifru().data());
		nodeStavke->SetAttribute("naziv", (*iStav)->DajNaziv().data());
		nodeStavke->SetAttribute("cijena", (*iStav)->DajCijenu());
		nodeStavke->SetAttribute("kolicina", (*iStav)->DajKolicinu());
		nodeStavke->SetAttribute("brojRacuna", (*iStav)->DajBrojRacuna().data());
		nodeStavke->SetAttribute("ukupanIznos", (*iStav)->DajUkupnuCijenu());
		pRootStavka->LinkEndChild(nodeStavke);
		stavke.SaveFile("stavke.xml");
	}
}
/*
* ----------------------------------------------
*
* Funkcija za kreiranje racuna kupaca
*
* ----------------------------------------------
*/
static void KreiranjeRacuna(vector<Kupac*>vKupci, vector<Artikl*> vArtikli, vector<Racun*>vRacuni, vector<Stavka*> vStavke)
{
	system("CLS");
	float ukupnacijena = 0;
	float pojedinacnacijena = 0;
	string naziv2;
	string sifraArtikla;
	int brojac = 1;
	vector<Kupac*>::iterator iKup;
	vector<Artikl*>::iterator iArt;
	TextTable t('-', '|', '+');
	t.add("Rb.r");
	t.add("Ime");
	t.add("Prezime");
	t.add("Grad");
	t.add("Adresa");
	t.add("Sifra kupca");
	t.add("Sifra brojila");
	t.endOfRow();
	for (iKup = vKupci.begin(); iKup != vKupci.end(); iKup++)
	{
		t.add(to_string(brojac));
		t.add((*iKup)->DajIme());
		t.add((*iKup)->DajPrezime());
		t.add((*iKup)->DajGrad());
		t.add((*iKup)->DajAdresu());
		t.add((*iKup)->DajSifruKupca());
		t.add((*iKup)->DajSifruBrojila());
		t.endOfRow();
		brojac += 1;
	}

	cout << t;

	cout << "Unesite sifru zeljenog kupca -> ";
	string sifra;
	cin >> sifra;
	cout << endl;

	system("CLS");

	t.add("Ime");
	t.add("Prezime");
	t.add("Grad");
	t.add("Adresa");
	t.add("Sifra kupca");
	t.add("Sifra brojila");
	t.endOfRow();

	TextTable t2('-', '|', '+');
	t2.add("Rb.r");
	t2.add("Sifra artikla");
	t2.add("Naziv artikla");
	t2.add("Pojedinacna cijena");
	t2.endOfRow();


	for (iKup = vKupci.begin(); iKup != vKupci.end(); iKup++)
	{
		if (sifra == (*iKup)->DajSifruKupca() || sifra == (*iKup)->DajSifruBrojila())
		{
			t.add((*iKup)->DajIme());
			t.add((*iKup)->DajPrezime());
			t.add((*iKup)->DajGrad());
			t.add((*iKup)->DajAdresu());
			t.add((*iKup)->DajSifruKupca());
			t.add((*iKup)->DajSifruBrojila());
			t.endOfRow();
			sifra = (*iKup)->DajSifruKupca();
			cout << endl;
			system("CLS");
			for (iArt = vArtikli.begin(); iArt != vArtikli.end(); iArt++)
			{
				t2.add(to_string(brojac));
				t2.add((*iArt)->DajSifru());
				t2.add((*iArt)->DajNaziv());
				t2.add(to_string((*iArt)->Cijena()));
				t2.endOfRow();
				brojac += 1;
			}

			cout << t2;
			cout << endl;
			cout << "Unesite sifru zeljenog artikla ->" << endl;
			cin >> sifraArtikla;
			
			system("CLS");
			for (iArt = vArtikli.begin(); iArt != vArtikli.end(); iArt++)
			{
				if (sifraArtikla == (*iArt)->DajSifru())
				{
					ukupnacijena = (*iArt)->UkupnaCijena();
					naziv2 = (*iArt)->DajNaziv();
					pojedinacnacijena = (*iArt)->Cijena();
				}
			}
		}
	}
	vector<Racun*>::iterator iRac;
	povratak:
	cout << "Unesite id: ";
	int id;
	cin >> id;
	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); iRac++)
	{
		if ((*iRac)->DajId() == id)
		{
			cout << "Uneseni ID vec postoji! Unesite novi. " << endl;
			goto povratak;
		}
	}

	povratak2:

	string brojRacuna;
	cout << "Unesite broj racuna: ";
	cin >> brojRacuna;

	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); iRac++)
	{
		if ((*iRac)->DajBrojRacuna() == brojRacuna)
		{
			cout << "Uneseni racun vec postoji! Unesite novi. " << endl;
			goto povratak2;
		}
	}

	string datum;
	cout << "Unesite datum [DD.MM.YYYY]: ";
	cin >> datum;

	string stornirano = "ne";

	float kolicina = ukupnacijena / pojedinacnacijena;

	XMLDocument racuni2;
	racuni2.LoadFile("racuni.xml");
	XMLElement* pRootRacun2 = racuni2.FirstChildElement("dataset")->FirstChildElement("Racun");
	XMLElement* pChildRacun;
	pChildRacun = racuni2.FirstChildElement("dataset");
	if (pChildRacun->FirstChildElement("Racun"))
	{
		pChildRacun->DeleteChildren();

		racuni2.SaveFile("racuni.xml");
	}
	
	XML(vRacuni);
		
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRootRacuni = racuni.FirstChildElement("dataset");
	XMLElement* nodeRacuni = pRootRacuni->InsertNewChildElement("Racun");
	nodeRacuni->SetAttribute("ID", id);
	nodeRacuni->SetAttribute("brojRacuna", brojRacuna.data());
	nodeRacuni->SetAttribute("sifraKupca", sifra.data());
	nodeRacuni->SetAttribute("ukupanIznos", ukupnacijena);
	nodeRacuni->SetAttribute("datum", datum.data());
	nodeRacuni->SetAttribute("stornirano", stornirano.data());
	racuni.SaveFile("racuni.xml");

	cout << "Racun je kreiran " << endl;

	XMLDocument stavke;
	stavke.LoadFile("stavke.xml");
	XMLElement* pRootStavka = stavke.FirstChildElement("dataset")->FirstChildElement("Stavka");
	XMLElement* pChildStavka;
	pChildStavka = stavke.FirstChildElement("dataset");
	if (pChildStavka->FirstChildElement("Stavka"))
	{
		pChildStavka->DeleteChildren();

		stavke.SaveFile("stavke.xml");
	}

	XML3(vStavke);

	XMLDocument stavke2;
	stavke2.LoadFile("stavke.xml");
	XMLElement* pRootStavke = stavke2.FirstChildElement("dataset");
	XMLElement* nodeStavke = pRootStavke->InsertNewChildElement("Stavka");
	nodeStavke->SetAttribute("ID", id);
	nodeStavke->SetAttribute("sifra", sifraArtikla.data());
	nodeStavke->SetAttribute("naziv", naziv2.data());
	nodeStavke->SetAttribute("cijena", pojedinacnacijena);
	nodeStavke->SetAttribute("kolicina", kolicina);
	nodeStavke->SetAttribute("brojRacuna", brojRacuna.data());
	nodeStavke->SetAttribute("ukupanIznos", ukupnacijena);
	stavke2.SaveFile("stavke.xml");

	XMLDocument zapis;
	zapis.LoadFile("zapis.xml");
	XMLElement* pRootZapis = zapis.FirstChildElement("dataset");
	XMLElement* nodeZapis = pRootZapis->InsertNewChildElement("Zapis");
	nodeZapis->SetAttribute("ID_racun", id);
	nodeZapis->SetAttribute("ID_stavka", id);
	zapis.SaveFile("zapis.xml");


	system("pause");

}
/*
* ----------------------------------------------
*
* Funkcija za dodavanje novih kupaca
*
* ----------------------------------------------
*/
static void DodavanjeKupca(vector<Kupac*> vKupci)
{
	system("CLS");
	cout << "DODAVANJE KUPCA" << endl;
	cout << "Unesite ime novog kupca:" << endl;
	string ime;
	cin >> ime;
	cout << "Unesite prezime novog kupca:" << endl;
	string prezime;
	cin >> prezime;
	cout << "Unesite ime grada u kojem kupac zivi:" << endl;
	string grad;
	cin >> grad;
	cout << "Unesite adresu stanovanja:" << endl;
	string adresa;
	cin.ignore();
	getline(cin, adresa);
	cout << "Unesite sifru novog kupca: " << endl;
	string sifraKupca;
	cin >> sifraKupca;
	cout << "Unesite sifru brojila: " << endl;
	string sifraBrojila;
	cin >> sifraBrojila;

	XMLDocument kupci;
	kupci.LoadFile("kupci.xml");
	XMLElement* pRootKupac = kupci.FirstChildElement("dataset")->FirstChildElement("Kupac");
	XMLElement* pChildKupac1;
	pChildKupac1 = kupci.FirstChildElement("dataset");
	if (pChildKupac1->FirstChildElement("Kupac"))
	{
		pChildKupac1->DeleteChildren();

		kupci.SaveFile("kupci.xml");
	}

	XML2(vKupci);

	XMLDocument oXmlDocumentKupci;
	oXmlDocumentKupci.LoadFile("kupci.xml");
	XMLElement* pKupac = oXmlDocumentKupci.FirstChildElement("dataset")->InsertNewChildElement("Kupac");
	XMLElement* pChildKupac = pKupac;
	pChildKupac->SetAttribute("ime", ime.data());
	pChildKupac->SetAttribute("prezime", prezime.data());
	pChildKupac->SetAttribute("grad", grad.data());
	pChildKupac->SetAttribute("adresa", adresa.data());
	pChildKupac->SetAttribute("sifraKupca", sifraKupca.data());
	pChildKupac->SetAttribute("sifraBrojila", sifraBrojila.data());
	oXmlDocumentKupci.SaveFile("kupci.xml");
	cout << "Kupac je uspjesno dodan!" << endl;
	system("pause");
}
/*
* ----------------------------------------------
*
* Funkcija za azuriranje postojecih kupaca
*
* ----------------------------------------------
*/
static void AzuriranjeKupca(vector<Kupac*> vKupci) 
{
	temp2:
	system("CLS");
	int brojac = 1;
	vector<Kupac*>::iterator iKup;
	TextTable t('-', '|', '+');
	t.add("Rb.r");
	t.add("Ime");
	t.add("Prezime");
	t.add("Grad");
	t.add("Adresa");
	t.add("Sifra kupca");
	t.add("Sifra brojila");
	t.endOfRow();
	for (iKup = vKupci.begin(); iKup != vKupci.end(); iKup++)
	{
		t.add(to_string(brojac));
		t.add((*iKup)->DajIme());
		t.add((*iKup)->DajPrezime());
		t.add((*iKup)->DajGrad());
		t.add((*iKup)->DajAdresu());
		t.add((*iKup)->DajSifruKupca());
		t.add((*iKup)->DajSifruBrojila());
		t.endOfRow();
		brojac += 1;
	}
	cout << t;
	cout << "Unesite sifru kupca koji zelite azurirati: " << endl;
	string sifra;
	cin >> sifra;
	temp:
	system("CLS");
	cout << "Koji podatak zelite azurirati: " << endl;
	cout << "1) Ime" << endl;
	cout << "2) Prezime" << endl;
	cout << "3) Grad" << endl;
	cout << "4) Adresa" << endl;
	cout << "5) Sifru kupca" << endl;
	cout << "6) Sifru brojila" << endl;
	cout << "7) Povratak na listu kupaca" << endl;
	cout << "8) Povratak u glavni izbornik" << endl;
	int odabir;
	cin >> odabir;
	if (odabir == 1)
	{
		cout << "Unesite novo ime kupca: " << endl;
		string ime;
		cin >> ime;
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("ime", ime.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
		
	}
	else if (odabir == 2)
	{
		cout << "Unesite novo prezime kupca: " << endl;
		string prezime;
		cin >> prezime;
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("prezime", prezime.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
	}
	else if (odabir == 3)
	{
		cout << "Unesite grad kupca: " << endl;
		string grad;
		cin >> grad;
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("grad", grad.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
	}
	else if (odabir == 4)
	{
		cout << "Unesite novu adresu kupca: " << endl;
		string adresa;
		cin.ignore();
		getline(cin, adresa);
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("adresa", adresa.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
	}
	else if (odabir == 5)
	{
		cout << "Unesite novu sifru kupca: " << endl;
		string sifraKupca;
		cin >> sifraKupca;
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("sifraBrojila", sifraKupca.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
	}
	else if (odabir == 6)
	{
		cout << "Unesite novu sifru brojila: " << endl;
		string sifraBrojila;
		cin >> sifraBrojila;
		XMLDocument kupci;
		kupci.LoadFile("kupci.xml");
		XMLElement* pKupac = kupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			if (pChildKupac->Attribute("sifraKupca") == sifra || pChildKupac->Attribute("sifraBrojila") == sifra)
			{
				pChildKupac->SetAttribute("ime", sifraBrojila.data());
			}
		}
		kupci.SaveFile("kupci.xml");
		cout << "Kupac je azuriran!" << endl;
		system("pause");
		goto temp;
	}
	else if (odabir == 7)
	{
		goto temp2;
	}
	else if (odabir == 8)
	{
		DajIzbornik();
	}
}
/*
* ----------------------------------------------
*
* Funkcija za brisanje postojecih kupaca
*
* ----------------------------------------------
*/
static void BrisanjeKupca(vector<Kupac*> vKupci, int i) 
{
	system("CLS");
		int brojac = 1;
		vector<Kupac*>::iterator iKup;
		TextTable t('-', '|', '+');
		t.add("Rb.r");
		t.add("Ime");
		t.add("Prezime");
		t.add("Grad");
		t.add("Adresa");
		t.add("Sifra kupca");
		t.add("Sifra brojila");
		t.endOfRow();
		for (iKup = vKupci.begin(); iKup != vKupci.end(); iKup++)
		{
			t.add(to_string(brojac));
			t.add((*iKup)->DajIme());
			t.add((*iKup)->DajPrezime());
			t.add((*iKup)->DajGrad());
			t.add((*iKup)->DajAdresu());
			t.add((*iKup)->DajSifruKupca());
			t.add((*iKup)->DajSifruBrojila());
			t.endOfRow();
			brojac += 1;
		}
		cout << t;
		cout << "Unesite redni broj kupca kojeg zelite obrisati: " << endl;
		cin >> i;
		XMLDocument oXmlDocumentKupci;
		oXmlDocumentKupci.LoadFile("kupci.xml");
		XMLElement* pKupac = oXmlDocumentKupci.FirstChildElement("dataset");
		XMLElement* pChildKupac;
		int brojac2 = 0;
		for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
		{
			brojac2++;
			if (brojac2 == i)
			{
				pKupac->DeleteChild(pChildKupac);
				oXmlDocumentKupci.SaveFile("kupci.xml");
				break;
			}
		}
		cout << "Kupac je izbrisan" << endl;
		system("pause");
}
/*
* -----------------------------------------------------------
*
* Funkcija za pregled nestorniranih racuna za odabranog kupca
*
* -----------------------------------------------------------
*/
static void PregledRacunaKupaca(vector<Racun*> vRacuni, vector<Kupac*>vKupci)
{
	system("CLS");
	int brojac = 1;
	vector<Kupac*>::iterator iKup;
	TextTable t2('-', '|', '+');
	t2.add("ID");
	t2.add("Ime");
	t2.add("Prezime");
	t2.add("Grad");
	t2.add("Adresa");
	t2.add("Sifra kupca");
	t2.add("Sifra brojila");
	t2.endOfRow();
	for (iKup = vKupci.begin(); iKup != vKupci.end(); iKup++)
	{
		t2.add(to_string(brojac));
		t2.add((*iKup)->DajIme());
		t2.add((*iKup)->DajPrezime());
		t2.add((*iKup)->DajGrad());
		t2.add((*iKup)->DajAdresu());
		t2.add((*iKup)->DajSifruKupca());
		t2.add((*iKup)->DajSifruBrojila());
		t2.endOfRow();
		brojac += 1;
	}

	cout << t2;

	cout << "Unesite redni broj kupca za kojeg zelite vidjeti izdane racune: ";
	string sifra;
	cin >> sifra;
	cout << endl;


	system("CLS");
	vector<Racun*>::iterator iRac;
	TextTable t('-', '|', '+');
	t.add("ID");
	t.add("Naziv");
	t.add("Broj racuna");
	t.add("Sifra kupca");
	t.add("Kolicina");
	t.add("Cijena");
	t.add("Ukupan iznos");
	t.add("Datum");
	t.endOfRow();

	int brojac2 = 1;
	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); iRac++)
	{
		if ((*iRac)->Stornirano() == "ne")
		{
			for (int i = 0; i < (*iRac)->m_pStavka.size(); i++)
			{
				if ((*iRac)->DajBrojRacuna() == (*iRac)->m_pStavka[i]->DajBrojRacuna() && (*iRac)->DajSifruKupca() == sifra)
				{
					t.add(to_string((*iRac)->DajId()));
					t.add((*iRac)->m_pStavka[i]->DajNaziv());
					t.add((*iRac)->DajBrojRacuna());
					t.add((*iRac)->DajSifruKupca());
					t.add(to_string((*iRac)->m_pStavka[i]->DajKolicinu()));
					t.add(to_string((*iRac)->m_pStavka[i]->DajCijenu()));
					t.add(to_string((*iRac)->DajUkupanIznos()));
					t.add((*iRac)->DajDatum());
					t.endOfRow();
					brojac2++;
				}
			}
		}
	}
	cout << t;
	system("pause");
}
/*
* ----------------------------------------------
*
* Funkcija za storniranje racuna kupaca
*
* ----------------------------------------------
*/
static void StorniranjeRacuna(vector<Racun*>vRacuni)
{
	system("CLS");
	vector<Racun*>::iterator iRac;
	TextTable t('-', '|', '+');
	t.add("ID");
	t.add("Naziv");
	t.add("Broj racuna");
	t.add("Sifra kupca");
	t.add("Kolicina");
	t.add("Cijena");
	t.add("Ukupan iznos");
	t.add("Datum");
	t.endOfRow();
	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); iRac++)
	{
		if ((*iRac)->Stornirano() == "ne")
		{
			for (int i = 0; i < (*iRac)->m_pStavka.size(); ++i)
			{
				if ((*iRac)->DajBrojRacuna() == (*iRac)->m_pStavka[i]->DajBrojRacuna())
				{
					t.add(to_string((*iRac)->DajId()));
					t.add((*iRac)->m_pStavka[i]->DajNaziv());
					t.add((*iRac)->DajBrojRacuna());
					t.add((*iRac)->DajSifruKupca());
					t.add(to_string((*iRac)->m_pStavka[i]->DajKolicinu()));
					t.add(to_string((*iRac)->m_pStavka[i]->DajCijenu()));
					t.add(to_string((*iRac)->DajUkupanIznos()));
					t.add((*iRac)->DajDatum());
					t.endOfRow();
				}
			}
		}
	}
	cout << t;
	cout << "Unesite broj racuna koji zelite stornirati: " << endl;
	string brojRacuna;
	cin >> brojRacuna;
	string stornirano = "da";
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRacun = racuni.FirstChildElement("dataset");
	XMLElement* pChildRacun;
	for (pChildRacun = pRacun->FirstChildElement("Racun"); pChildRacun != NULL; pChildRacun = pChildRacun->NextSiblingElement())
	{
		if (pChildRacun->Attribute("brojRacuna") == brojRacuna)
		{
			pChildRacun->SetAttribute("stornirano", stornirano.data());
		}
	}
	racuni.SaveFile("racuni.xml");
	cout << "Racun je storniran! " << endl;
	system("pause");
}
/*
* ----------------------------------------------
*
* Funkcija za pregled storniranih racuna kupaca
*
* ----------------------------------------------
*/
static void PregledStorniranihRacuna(vector<Racun*> vRacuni)
{
	system("CLS");
	vector<Racun*>::iterator iRac;
	int brojac;
	TextTable t('-', '|', '+');
	t.add("ID");
	t.add("Naziv");
	t.add("Broj racuna");
	t.add("Sifra kupca");
	t.add("Kolicina");
	t.add("Cijena");
	t.add("Ukupan iznos");
	t.add("Datum");
	t.endOfRow();
	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); iRac++)
	{
		if ((*iRac)->Stornirano() == "da")
		{
			for (int i = 0; i < (*iRac)->m_pStavka.size(); ++i)
			{
				if ((*iRac)->DajBrojRacuna() == (*iRac)->m_pStavka[i]->DajBrojRacuna())
				{
					t.add(to_string((*iRac)->DajId()));
					t.add((*iRac)->m_pStavka[i]->DajNaziv());
					t.add((*iRac)->DajBrojRacuna());
					t.add((*iRac)->DajSifruKupca());
					t.add(to_string((*iRac)->m_pStavka[i]->DajKolicinu()));
					t.add(to_string((*iRac)->m_pStavka[i]->DajCijenu()));
					t.add(to_string((*iRac)->DajUkupanIznos()));
					t.add((*iRac)->DajDatum());
					t.endOfRow();
				}
			}
		}
	}
	cout << t;
	system("pause");
}
/*
* ------------------------------------------------
*
* Funkcija za pregled statistike prodanih kolicina
*
* ------------------------------------------------
*/
static void StatistikaKolicina(vector<Stavka*>sStavke)
{
	
	vector<Stavka*>::iterator iStav;
	double kolicinaNiska = 0;
	double kolicinaVisoka = 0;
	double kolicinaTip1 = 0;
	double kolicinaTip2 = 0;
	string naziv1;
	string naziv2;
	string naziv3;
	string naziv4;
	for (iStav = sStavke.begin(); iStav != sStavke.end(); ++iStav)
	{
		if ((*iStav)->DajNaziv() == "niska tarifa")
		{
			kolicinaNiska += (*iStav)->DajKolicinu();
			naziv1 = (*iStav)->DajNaziv();
		}
		if ((*iStav)->DajNaziv() == "visoka tarifa")
		{
			kolicinaVisoka += (*iStav)->DajKolicinu();
			naziv2 = (*iStav)->DajNaziv();
		}
		if ((*iStav)->DajNaziv() == "industrijska potrosnja tip 1")
		{
			kolicinaTip1 += (*iStav)->DajKolicinu();
			naziv3 = (*iStav)->DajNaziv();
		}
		if ((*iStav)->DajNaziv() == "industrijska potrosnja tip 2")
		{
			kolicinaTip2 += (*iStav)->DajKolicinu();
			naziv4 = (*iStav)->DajNaziv();
		}
	}

	Statistika s1(naziv1, kolicinaNiska);
	Statistika s2(naziv2, kolicinaVisoka);
	Statistika s3(naziv3, kolicinaTip1);
	Statistika s4(naziv4, kolicinaTip2);

	set<Statistika> sStat;
	sStat.clear();
	sStat.insert(s1);
	sStat.insert(s2);
	sStat.insert(s3);
	sStat.insert(s4);
	set<Statistika>::iterator iStat;
	TextTable t('-', '|', '+');
	t.add("Naziv");
	t.add("Ukupna prodana kolicina");
	t.endOfRow();

	for (iStat = sStat.begin(); iStat != sStat.end(); ++iStat)
	{
		t.add(iStat->DajNaziv());
		t.add(to_string(iStat->DajKolicinu()));
		t.endOfRow();
	}
	cout << t;
	system("pause");
}
/*
* ----------------------------------------------------------
*
* Funkcija za pregled top 10 kupaca po kolicini niske tarife
*
* ----------------------------------------------------------
*/
static void topdesetniska(vector <Racun*>vRacuni)
{
	vector<Racun*>::iterator iRac;
	set<top10> sTop;
	set<top10>::iterator iTop;
	int objekti = 1;
	int brojac2 = 1;
	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); ++iRac)
	{
		for (int j = 0; j < (*iRac)->m_pStavka.size(); ++j)
		{
			if ((*iRac)->DajBrojRacuna() == (*iRac)->m_pStavka[j]->DajBrojRacuna())
			{
				if ((*iRac)->m_pStavka[j]->DajNaziv() == "niska tarifa")
				{
					top10 objekti((*iRac)->DajBrojRacuna(), (*iRac)->DajSifruKupca(), (*iRac)->m_pStavka[j]->DajKolicinu(), (*iRac)->DajUkupanIznos());
					sTop.insert(objekti);
					if (brojac2 == 10)
					{
						break;
					}
					brojac2++;
				}
			}
		}
	}

	TextTable t('-', '|', '+');
	t.add("Broj Racuna");
	t.add("Sifra Kupca");
	t.add("Kolicina");
	t.add("Ukupan Iznos");
	t.endOfRow();

	for (iTop = sTop.begin(); iTop != sTop.end(); ++iTop)
	{
		t.add(iTop->DajBrojRacuna());
		t.add(iTop->DajSifruKupca());
		t.add(to_string(iTop->DajKolicinu()));
		t.add(to_string(iTop->DajUkupanIznos()));
		t.endOfRow();
	}
	cout << t;

	system("pause");

}
/*
* ---------------------------------------------
*
* Funkcija za pregled top 10 kupaca po kolicini 
*
* ---------------------------------------------
*/
static void topDesetkolicina(vector<Racun*> vRacuni)
{
	vector<Racun*>::iterator iRac;
	set<top10kolicina> sTop2;
	set<top10kolicina>::iterator iTop2;
	int objekti = 1;
	int brojac2 = 1;
	TextTable t('-', '|', '+');
	t.add("Broj Racuna");
	t.add("Sifra Kupca");
	t.add("Kolicina");
	t.endOfRow();

	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); ++iRac)
	{
		for (int j = 0; j < (*iRac)->m_pStavka.size(); ++j)
		{
			if ((*iRac)->DajBrojRacuna() == (*iRac)->m_pStavka[j]->DajBrojRacuna())
			{
				top10kolicina objekti((*iRac)->DajBrojRacuna(), (*iRac)->DajSifruKupca(), (*iRac)->m_pStavka[j]->DajKolicinu());
				sTop2.insert(objekti);
				
				
			}
		}
	}

	for (iTop2 = sTop2.begin(); iTop2 != sTop2.end(); ++iTop2)
	{
		t.add(iTop2->DajBrojRacuna2());
		t.add(iTop2->DajSifruKupca2());
		t.add(to_string(iTop2->DajKolicinu2()));
		t.endOfRow();
		if (brojac2 == 10)
		{
			break;
		}
		brojac2++;
	}

	cout << t;
	system("pause");
}
/*
* ----------------------------------------------------------
*
* Funkcija za pregled top 10 kupaca po velicini racuna
*
* ----------------------------------------------------------
*/
static void topDesetracun(vector<Racun*> vRacuni)
{
	vector<Racun*>::iterator iRac;
	set<top10racun> sTop3;
	set<top10racun>::iterator iTop3;
	int objekti = 1;
	int brojac2 = 1;
	TextTable t('-', '|', '+');
	t.add("Broj Racuna");
	t.add("Sifra Kupca");
	t.add("Ukupan Iznos");
	t.endOfRow();

	for (iRac = vRacuni.begin(); iRac != vRacuni.end(); ++iRac)
	{
			top10racun objekti((*iRac)->DajBrojRacuna(), (*iRac)->DajSifruKupca(), (*iRac)->DajUkupanIznos());
			sTop3.insert(objekti);
			if (brojac2 == 10)
			{
				break;
			}
			brojac2++;
	}

	for (iTop3 = sTop3.begin(); iTop3 != sTop3.end(); ++iTop3)
	{
		t.add(iTop3->DajBrojRacuna2());
		t.add(iTop3->DajSifruKupca2());
		t.add(to_string(iTop3->DajUkupanIznos2()));
		t.endOfRow();
	}

	cout << t;
	system("pause");
}
 /*
 * ---------------------------------------------------------
 *
 * Funckija za odabir jedne od ponudenih opcija iz izbornika
 *
 * ---------------------------------------------------------
 */
static void Odabir(vector<Kupac*>vKupci, vector<Artikl*> vArtikli, vector<Racun*> vRacuni, vector<Stavka*> vStavke)
{
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		KreiranjeRacuna(vKupci, vArtikli, vRacuni, vStavke);
		break;
	case 2:
		system("CLS");
		cout << "Odabir: " << endl;
		cout << "1) Dodavanje kupca" << endl;
		cout << "2) Azuriranje kupca" << endl;
		cout << "3) Brisanje kupca" << endl;
		cout << "4) Povratak u glavni izbornik" << endl;
		int odabir;
		cin >> odabir;
		if (odabir == 1)
		{
			DodavanjeKupca(vKupci);
		}
		else if (odabir == 2)
		{
			AzuriranjeKupca(vKupci);
		}
		else if (odabir == 3)
		{
			BrisanjeKupca(vKupci, i);
		}
		else if (odabir == 4)
		{
			DajIzbornik();
		}
		break;
	case 3:
		PregledRacunaKupaca(vRacuni, vKupci);
		break;
	case 4:
		StorniranjeRacuna(vRacuni);
		break;
	case 5:
		PregledStorniranihRacuna(vRacuni);
		break;
	case 6:
		povratak2:
		system("CLS");
		cout << "Odabir: " << endl;
		cout << "1) Statistika prodanih tarifa" << endl;
		cout << "2) TOP 10 kupaca" << endl;
		cout << "3) Povratak u glavni izbornik" << endl;
		int odabir2;
		cin >> odabir2;
		if (odabir2 == 1)
		{
			StatistikaKolicina(vStavke);
			goto povratak2;
		}
		else if (odabir2 == 2)
		{
			system("CLS");
			povratak:
			cout << "Odabir: " << endl;
			cout << "1) Top 10 (niska tarifa)" << endl;
			cout << "2) Top 10 (Po kolicini)" << endl;
			cout << "3) Top 10 (Po racunu)" << endl;
			cout << "4) Povratak u statistiku " << endl;
			int odabir3;
			cin >> odabir3;

			if (odabir3 == 1)
			{
				topdesetniska(vRacuni);
				system("CLS");
				goto povratak;
			}
			else if(odabir3 == 2)
			{
				topDesetkolicina(vRacuni);
				system("CLS");
				goto povratak;
			}
			else if (odabir3 == 3)
			{
				topDesetracun(vRacuni);
				system("CLS");
				goto povratak;
			}
			else if (odabir3 == 4)
			{
				goto povratak2;
			}
		}
		else if (odabir2 == 3)
		{
			DajIzbornik();
		}
		break;
	case 7:
		Izlazak();
		break;
	default:
		break;
	}
}
/*
* ----------------------------------------------------------
*
* Funkcija main
*
* ----------------------------------------------------------
*/
int main()
{
	/*
    * ----------------------
    *
    * Ucitavanje artikli.xml
    *
    * ----------------------
    */
	vector<Artikl*> vArtikli;
	vArtikli.clear();
	XMLDocument oXmlDocumentArtikli;
	oXmlDocumentArtikli.LoadFile("artikli.xml");

	XMLElement* pArtikl = oXmlDocumentArtikli.FirstChildElement("dataset");
	XMLElement* pChildArtikl;
	for (pChildArtikl = pArtikl->FirstChildElement("Artikl"); pChildArtikl != NULL; pChildArtikl = pChildArtikl->NextSiblingElement())
	{
		string sSifra = pChildArtikl->Attribute("sifra");
		string sNaziv = pChildArtikl->Attribute("naziv");
		float fCijena = stoi(pChildArtikl->Attribute("cijena"));
		vArtikli.push_back(new Artikl(sSifra, sNaziv, fCijena));
	}
	/*
	* ----------------------
	*
	* Ucitavanje kupci.xml
	*
	* ----------------------
	*/
	vector<Kupac*> vKupci;
	vector<Kupac*>::iterator iKup;
	vKupci.clear();
	XMLDocument oXmlDocumentKupci;
	oXmlDocumentKupci.LoadFile("kupci.xml");
	XMLElement* pKupac = oXmlDocumentKupci.FirstChildElement("dataset");
	XMLElement* pChildKupac;
	for (pChildKupac = pKupac->FirstChildElement("Kupac"); pChildKupac != NULL; pChildKupac = pChildKupac->NextSiblingElement())
	{
		string sIme = pChildKupac->Attribute("ime");
		string sPrezime = pChildKupac->Attribute("prezime");
		string sGrad = pChildKupac->Attribute("grad");
		string sAdresa = pChildKupac->Attribute("adresa");
		string sSifraKupca = pChildKupac->Attribute("sifraKupca");
		string sSifraBrojila = pChildKupac->Attribute("sifraBrojila");
		vKupci.push_back(new Kupac(sIme, sPrezime,sGrad, sAdresa, sSifraKupca, sSifraBrojila));
	}
	/*
	* ----------------------
	*
	* Ucitavanje stavke.xml
	*
	* ----------------------
	*/
	vector<Stavka*> vStavke;
	vStavke.clear();
	XMLDocument stavke;
	stavke.LoadFile("stavke.xml");
	XMLElement* pStavka = stavke.FirstChildElement("dataset");
	XMLElement* pChildStavka;
	set<Stavka*> sStavke;
	for (pChildStavka = pStavka->FirstChildElement("Stavka"); pChildStavka != NULL; pChildStavka = pChildStavka->NextSiblingElement())
	{
			int nId = stoi(pChildStavka->Attribute("ID"));
			double dKolicina = stod(pChildStavka->Attribute("kolicina"));
			string sBrojRacuna = pChildStavka->Attribute("brojRacuna");
			float fUkupnaCijena = stof(pChildStavka->Attribute("ukupanIznos"));
			string sSifra = pChildStavka->Attribute("sifra");
			string sNaziv = pChildStavka->Attribute("naziv");
			float fCijena = stof(pChildStavka->Attribute("cijena"));
			vStavke.push_back(new Stavka(nId, sSifra, sNaziv, fCijena, dKolicina, sBrojRacuna, fUkupnaCijena));
			sStavke.insert(new Stavka(nId, sSifra, sNaziv, fCijena, dKolicina, sBrojRacuna, fUkupnaCijena));
	}
	/*
	* ----------------------
	*
	* Ucitavanje racun.xml
	*
	* ----------------------
	*/
	vector<Racun*> vRacuni;
	XMLDocument racuni;
	racuni.LoadFile("racuni.xml");
	XMLElement* pRacun = racuni.FirstChildElement("dataset");
	XMLElement* pChildRacun;
	for (pChildRacun = pRacun->FirstChildElement("Racun"); pChildRacun != NULL; pChildRacun = pChildRacun->NextSiblingElement())
	{		
			int nId = stoi(pChildRacun->Attribute("ID"));
			string sBrojRacuna2 = pChildRacun->Attribute("brojRacuna");
			string sSifraKupca = pChildRacun->Attribute("sifraKupca");
			float fCijena2 = stof(pChildRacun->Attribute("ukupanIznos"));
			string sDatum = pChildRacun->Attribute("datum");
			string sStornirano = pChildRacun->Attribute("stornirano");
			vRacuni.push_back(new Racun(vStavke, nId, sBrojRacuna2, sSifraKupca, fCijena2, sDatum, sStornirano));	
	} 
	/*
	* ----------------------
	*
	* Ucitavanje zapis.xml
	*
	* ----------------------
	*/
	XMLDocument zapis;
	zapis.LoadFile("zapis.xml");
	XMLElement* pZapis = zapis.FirstChildElement("dataset");
	XMLElement* pChildZapis;
	for (pChildZapis = pZapis->FirstChildElement("Zapis"); pChildZapis != NULL; pChildZapis = pChildZapis->NextSiblingElement())
	{
		int nIdRacun = stoi(pChildZapis->Attribute("ID_racun"));
		int nIdStavka = stoi(pChildZapis->Attribute("ID_stavka"));

	}

	/*
	* ------------------------------------------
	*
	* Poziv funkcija za glavni izbornik i odabir
	*
	* ------------------------------------------
	*/
	while (true)
	{
		system("CLS");
		DajIzbornik();
		Odabir(vKupci, vArtikli, vRacuni, vStavke);
	}

	return 0;
}