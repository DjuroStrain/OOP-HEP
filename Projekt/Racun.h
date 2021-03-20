#pragma once
#include <string>
#include "tinyxml2.h"
#include "Stavka.h"
#include <vector>
#include <set>

using namespace std;

class Racun
{public:
	Racun(vector<Stavka*> stavka,int id, string brojRacuna, string sifraKupca, float ukupanIznos, string datum, string stornirano);
	~Racun() {}

	vector<Stavka*> m_pStavka;
	int m_nId;
	string m_nBrojRacuna;
	string m_sSifraKupca;
	float m_fUkupanIznos;
	string m_sDatum;
	string m_sStornirano;
	set<Racun> m_sRacun;

	string DajBrojRacuna();
	string DajSifruKupca();
	float DajUkupanIznos();
	string DajDatum();
	string Stornirano();
	int DajId();
	
	
};

