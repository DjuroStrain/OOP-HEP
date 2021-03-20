#pragma once
#include "Artikl.h"
#include "tinyxml2.h"

class Stavka :
	public Artikl
{
public:

	Stavka(int id, string sifra, string naziv, float cijena, double kolicina, string brojRacuna, float ukupnaCijena);
	~Stavka(){}

	double m_dKolicina;
	string m_sBrojRacuna;
	float m_fUkupnaCijena;
	int m_nId;

	int DajID();
	double DajKolicinu();
	string DajNaziv();
	string DajSifru();
	float DajCijenu();
	string DajBrojRacuna();
	float DajUkupnuCijenu();

	bool operator>(const Stavka& b) const;
};

