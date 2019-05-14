/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe nesnesini basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/


#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP
#include <string>
#include "ListeGezici.hpp"

class CiftYonluDBagilListe{
private:
	Dugum *basDugum = nullptr; 
	Dugum *sonDugum;
	int elemanSayisi = 0;
	string listeBos = "ListeBos";

public:
	bool Varmi(int);
	ListeGezici OncekiniKonumuIleBul(int) const;
	ListeGezici  Ilk() const;
	CiftYonluDBagilListe();
	bool Bosmu() const;
	int Uzunluk() const;
	
	const string& IlkEleman() const;
	
	const string& SonEleman() const;

	void Ekle(const string&);
	
	void Ekle(const string&, int);
	
	void Sil(const string&);
	void KonumdakiniSil(int);
	bool ElemanBul(const string&) const;
	int KonumuBul(const string&) const;
	bool SonaGeldimi(ListeGezici) const;
	void Temizle();
	~CiftYonluDBagilListe();

};
#endif