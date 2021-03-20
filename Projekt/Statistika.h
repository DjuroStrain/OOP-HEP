#pragma once
#include <string>

using namespace std;

class Statistika
{
public:
	Statistika(string naziv, double ukupnaKolcina);
	~Statistika() {}

	string DajNaziv() const;
	double DajKolicinu() const;

	string m_sNaziv;
	double m_dUkupnaKolicina;

	bool operator < (const Statistika& b) const;

	
};

