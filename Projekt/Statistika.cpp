#include "Statistika.h"
#include <iostream>

Statistika::Statistika(string naziv, double ukupnaKolicina)
{
	m_sNaziv = naziv;
	m_dUkupnaKolicina = ukupnaKolicina;
}

bool Statistika::operator< (const Statistika& b) const
{
	if (m_dUkupnaKolicina < b.m_dUkupnaKolicina) return false;
	else return true;
}

string Statistika::DajNaziv() const
{
	return m_sNaziv;
}

double Statistika::DajKolicinu() const
{
	return m_dUkupnaKolicina;

}



