/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe icin ListeGezici nesnesini basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP
#include <cstring>
#include "Dugum.hpp"
#include <iostream>
using namespace std;


class ListeGezici{
public:
	Dugum  *simdiki; // Listede o anki bulunan konumu ifade eder.
	ListeGezici();
	ListeGezici(Dugum *);
	void ilerle();
	void gerile();
	const string& Getir() const;
};
#endif