#pragma once
#include <string>

using namespace std;

class top10kolicina
{
public:
	top10kolicina(string brojRacuna, string sifraKupca, double kolicina);
	~top10kolicina() {}

	string DajBrojRacuna2() const;
	string DajSifruKupca2() const;
	double DajKolicinu2() const;

	bool operator< (const top10kolicina& b) const;

	string m_sBrojRacuna2;
	string m_sSifraKupca2;
	double m_dKolicina2;
};

