/**
* @file ODEV1_VY
* @description Icerisinde ogrenci nesnelerinin gosterilmesini saglayan Ogrenci tipinde pointer dizisi bulunmaktadir ve bu dizinin icerigini elde etmek , diziye icerik eklemek gibi sinifla ilgili bilgilere ulasmayi saglayan metodlar bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef SINIF_HPP
#define SINIF_HPP
#include <iostream>
#include "Ogrenci.hpp"

using namespace std;
class Sinif{
	private:
	int ogrenciSayisi=0;
	char Isim;
	Ogrenci **ogrenciler;
	
	public:
	bool ogrenciVarmi(int);
	char getIsim()const;
	int getOgrenciSayisi()const;
	friend ostream& operator<<(ostream&, Sinif&);
	bool operator==(Sinif&);
	void sinifaOgrencileriEkle(char *);
	void ogrenciDegistir(int,Ogrenci *);

	Ogrenci ** getOgrenciler()const;
	Ogrenci * getOgrenci(int);
	Sinif();
	Sinif(char,int);
   ~Sinif();
   void Yoket(Ogrenci **ogrenciler,int ogrSayisi);
	
};
#endif