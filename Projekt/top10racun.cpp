#include "top10racun.h"

top10racun::top10racun(string brojRacuna, string sifraKupca, float ukupanIznos)
{
	m_sBrojRacuna3 = brojRacuna;
	m_sSifraKupca3 = sifraKupca;
	m_fUkupanIznos3 = ukupanIznos;
}
bool top10racun::operator< (const top10racun& b) const
{
	if (m_fUkupanIznos3 < b.m_fUkupanIznos3) return false;
	else return true;
}

string top10racun::DajBrojRacuna2() const
{
	return m_sBrojRacuna3;
}

string top10racun::DajSifruKupca2() const
{
	return m_sSifraKupca3;
}

float top10racun::DajUkupanIznos2() const
{
	return m_fUkupanIznos3;
}