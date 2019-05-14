/**
* @file ODEV1_VY
* @description Burada ogrenci nesnesini tanımlıyoruz ve yaptigi gorevler ogrenci karsilastirmasi ekrana yazdirilmasi gibi islemler.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef OGRENCI_HPP
#define OGRENCI_HPP
#include <iostream>
using namespace std;
class Ogrenci{
	private:	
	char Isim;
	
	public:
	friend ostream& operator<<(ostream&, Ogrenci&);
	bool operator==(Ogrenci&);
	char getIsim()const;
	Ogrenci();
	Ogrenci(char);
   ~Ogrenci();
	
};


#endif