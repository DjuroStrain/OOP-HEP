#include "Stavka.h"
#include <iostream>

Stavka::Stavka(int id, string sifra, string naziv, float cijena, double kolicina, string brojRacuna, float ukupnaCijena) :Artikl(sifra, naziv, cijena)
{
	m_nId = id;
	m_dKolicina = kolicina;
	m_sBrojRacuna = brojRacuna;
	m_fUkupnaCijena = ukupnaCijena;
}


bool Stavka::operator> (const Stavka& b) const
{
	if (m_dKolicina > b.m_dKolicina) return true;
	else return false;
}

double Stavka::DajKolicinu()
{
	return m_dKolicina;
}

string Stavka::DajNaziv()
{
	return m_sNaziv;
}

string Stavka::DajSifru()
{
	return m_sSifra;
}

float Stavka::DajCijenu()
{
	return m_fCijena;
}

string Stavka::DajBrojRacuna()
{
	return m_sBrojRacuna;
}

float Stavka::DajUkupnuCijenu()
{
	return m_fUkupnaCijena;
}

int Stavka::DajID()
{
	return m_nId;
}


