/**
* @file ODEV1_VY
* @description Okul nesnesinin icerisine , icinde bulunan herbir pointerin bir sinifi gostermesi amaclanan bir dizi ,Bu dizinin iceriginin doldurulmasını saglayan , iceriginin kucukten buyuge siralanmasini saglayan,pointerlarin gostericilerinin degismesini saglayan vb gerekli islemlerin yapilmasini saglayan metodlar bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef OKUL_HPP
#define OKUL_HPP
#include "Sinif.hpp"
#include <iostream>
using namespace std;
class Okul{
	private:
	int sinifSayisi;
	Sinif **siniflar;
	
	public:
	Okul();
	Okul(int);
	void okulaSinifEkle(char,int,int);
	void sinifDegistir(char sinif1,char sinif2);
	void sinifSirala();
	void  swap(int,int);
	Sinif **getSiniflar();
	Sinif *  getSinif(int);
	int getSinifSayisi()const;
   ~Okul();
    void Yoket(Sinif **siniflar,int sinifSayisi);
	
};
#endif