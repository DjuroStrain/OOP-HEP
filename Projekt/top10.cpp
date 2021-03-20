#include "top10.h"

top10::top10(string brojRacuna,string sifraKupca, double kolicina, float ukupanIznos)
{
	m_sBrojRacuna = brojRacuna;
	m_sSifraKupca = sifraKupca;
	m_dKolicina = kolicina;
	m_fUkupanIznos = ukupanIznos;
}

bool top10::operator< (const top10& b) const
{
	if (m_dKolicina < b.m_dKolicina) return false;
	else return true;
}

string top10::DajBrojRacuna() const
{
	return m_sBrojRacuna;
}

string top10::DajSifruKupca() const
{
	return m_sSifraKupca;
}

double top10::DajKolicinu() const
{
	return m_dKolicina;
}

float top10::DajUkupanIznos() const
{
	return m_fUkupanIznos;
}