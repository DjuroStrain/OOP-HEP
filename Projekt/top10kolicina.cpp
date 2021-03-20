#include "top10kolicina.h"

top10kolicina::top10kolicina(string brojRacuna, string sifraKupca, double kolicina)
{
	m_sBrojRacuna2 = brojRacuna;
	m_sSifraKupca2 = sifraKupca;
	m_dKolicina2 = kolicina;
}
bool top10kolicina::operator< (const top10kolicina& b) const
{
	if (m_dKolicina2 < b.m_dKolicina2) return false;
	else return true;
}

string top10kolicina::DajBrojRacuna2() const
{
	return m_sBrojRacuna2;
}

string top10kolicina::DajSifruKupca2() const
{
	return m_sSifraKupca2;
}

double top10kolicina::DajKolicinu2() const
{
	return m_dKolicina2;
}


