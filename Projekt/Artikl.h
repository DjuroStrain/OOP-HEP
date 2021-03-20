#pragma once
#include <string>
#include "tinyxml2.h"


using namespace std;

class Artikl
{
public:
	Artikl(string sifra, string naziv, float cijena);
	~Artikl() {}

	string m_sSifra;
	string m_sNaziv;
	float m_fCijena;

	

	float UkupnaCijena();
	string DajSifru();
	string DajNaziv();
	float Cijena();
};
