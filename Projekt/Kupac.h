#pragma once
#include "Osoba.h"
#include <string>
#include "tinyxml2.h"
using namespace std;

class Kupac :
	public Osoba
{
public:
	Kupac(string ime, string prezime,string grad, string adresa, string sifraKupca, string sifraBrojila);
	~Kupac() {}

	string DajSifruKupca();
	string DajSifruBrojila();
	string DajIme();
	string DajPrezime();
	string DajGrad();
	string DajAdresu();

	string m_sIme;
	string m_sPrezime;
	string m_sGrad;
	string m_sAdresa;
	string m_sSifraKupca;
	string m_sSifraBrojila;
};

