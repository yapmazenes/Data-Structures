/**
* @file ODEV2_VY
* @description Burada Program icin gerekli olan temel islemlerinin basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef YONETIM_HPP
#define YONETIM_HPP
#include <string>
#include <fstream>
#include "CiftYonluDBagilListe.hpp"

class Yonetim{

public:
	CiftYonluDBagilListe *liste;
	Yonetim();
	void Basla();
	void sagaKaydir();
	void solaKaydir();
	void birDugumunDurumlari(int);
	void tumDugumlerinDurumlari();
	void dosyaOku();
	fstream myfile;

};
#endif
