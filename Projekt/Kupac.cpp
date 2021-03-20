#include "Kupac.h"
#include <iostream>

using namespace std;

Kupac::Kupac(string ime, string prezime,string grad, string adresa, string sifraKupca, string sifraBrojila) : Osoba()
{
	m_sIme = ime;
	m_sPrezime = prezime;
	m_sGrad = grad;
	m_sAdresa = adresa;
	m_sSifraKupca = sifraKupca;
	m_sSifraBrojila = sifraBrojila;
}

string Kupac::DajSifruKupca()
{
	return m_sSifraKupca;
}

string Kupac::DajSifruBrojila()
{
	return m_sSifraBrojila;
}

string Kupac::DajIme()
{
	return m_sIme;
}

string Kupac::DajPrezime()
{
	return m_sPrezime;
}

string Kupac::DajGrad()
{
	return m_sGrad;
}

string Kupac::DajAdresu()
{
	return m_sAdresa;
}
