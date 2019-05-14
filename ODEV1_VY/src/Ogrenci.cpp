/**
* @file ODEV1_VY
* @description Burada ogrenci nesnesini tanımlıyoruz ve yaptigi gorevler ogrenci karsilastirmasi ekrana yazdirilmasi gibi islemler.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Ogrenci.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
	Ogrenci::Ogrenci(){
   
	}
	Ogrenci::Ogrenci(char isim){
		Isim=isim;
	}
	ostream& operator<<(ostream& ekran, Ogrenci &sag){
	ekran<<sag.Isim<<" ("<<&sag<<")   ";
	return ekran;
}
bool Ogrenci::operator==(Ogrenci& sag){
	return this->Isim == sag.Isim;
}


	char Ogrenci::getIsim()const{
		return Isim;
	}
	Ogrenci::~Ogrenci(){
		
	}


