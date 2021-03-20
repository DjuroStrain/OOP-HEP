#pragma once
#include <string>
using namespace std;
class top10
{
public:
	top10(string brojRacuna,string sifraKupca, double kolicina, float UkupanIznos);
	~top10() {}

	string DajBrojRacuna() const;
	string DajSifruKupca() const;
	double DajKolicinu() const;
	float DajUkupanIznos() const;

	bool operator< (const top10& b) const;


	string m_sBrojRacuna;
	string m_sSifraKupca;
	double m_dKolicina;
	float m_fUkupanIznos;
	
};

