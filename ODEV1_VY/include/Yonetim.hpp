/**
* @file ODEV1_VY
* @description Bu sinifta icerisinde Okul nesnesini gosterecek bir pointer, okul sinifindan elde edilen tek bir sinifi gosterecek Sinif pointeri vb sistemin isleyisini kolaylastiracak elde edilen verileri barindiran veriler bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef YONETIM_HPP
#define YONETIM_HPP
#include "Sinif.hpp"
#include "Okul.hpp"
#include "Ogrenci.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Yonetim{
	private:
	
		Okul  *okul=NULL;
		Sinif *sinif;
		Ogrenci tmp;
		int   sinifSayisi;
		int   ogrenciSayisi;
		char  sinifIsim;
		char  *ogrenciIsimleri;
		ifstream myfile;
		
	
	public:
		void Baslat();
		int getSinifSayisi()const;
		void satirSay();
	    char* boyutarttir(char*,int,int);
		void dosyaOku(Okul&);
		Okul * getOkul(int);
		void yazdir(Okul&,int,int);
		void ogrenciDegistir(char,char,Okul&);
		bool rtrim(string s);
		string rtrimDegistir(string str);
		string ltrim(string);
		Yonetim();
};
#endif