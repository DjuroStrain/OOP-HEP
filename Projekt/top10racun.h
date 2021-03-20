#pragma once
#include <string>

using namespace std;

class top10racun
{
public:
	top10racun(string brojRacuna, string sifraKupca, float ukupanIznos);
	~top10racun() {}

	string DajBrojRacuna2() const;
	string DajSifruKupca2() const;
	float DajUkupanIznos2() const;

	bool operator< (const top10racun& b) const;

	string m_sBrojRacuna3;
	string m_sSifraKupca3;
	float m_fUkupanIznos3;
};