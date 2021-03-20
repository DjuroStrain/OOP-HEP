#include "Racun.h"

Racun::Racun(vector<Stavka*> stavka,int id, string brojRacuna, string sifraKupca, float ukupanIznos, string datum, string stornirano)
{
	 m_pStavka = stavka;
	 m_nId = id;
	 m_nBrojRacuna = brojRacuna;
	 m_sSifraKupca = sifraKupca;
	 m_fUkupanIznos = ukupanIznos;
	 m_sDatum = datum;
	 m_sStornirano = stornirano;
}

string Racun::DajBrojRacuna()
{
	return m_nBrojRacuna;
}

string Racun::DajSifruKupca()
{
	return m_sSifraKupca;
}

float Racun::DajUkupanIznos()
{
	return m_fUkupanIznos;
}

string Racun::DajDatum()
{
	return m_sDatum;
}

string Racun::Stornirano()
{
	return m_sStornirano;
}

int Racun::DajId()
{
	return m_nId;
}


