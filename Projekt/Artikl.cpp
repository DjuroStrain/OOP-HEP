#include "Artikl.h"
#include <iostream>

using namespace std;
using namespace tinyxml2;

Artikl::Artikl(string sifra, string naziv, float cijena)
{
	m_sSifra = sifra;
	m_sNaziv = naziv;
	m_fCijena = cijena;
}


string Artikl::DajSifru()
{
	return m_sSifra;
}
string Artikl::DajNaziv()
{
	return m_sNaziv;
}
float Artikl::UkupnaCijena()
{
	int kolicina;
	float ukupnaCijena;
	cout << "Unesite kolicinu: " << endl;
	cin >> kolicina;
	ukupnaCijena = kolicina * m_fCijena;
	return ukupnaCijena;
}

float Artikl::Cijena()
{
	return m_fCijena;
}




