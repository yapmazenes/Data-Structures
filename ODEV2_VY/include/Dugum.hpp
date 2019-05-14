/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe icin Dugum nesnesini basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <string>
#include "Stack.hpp"
using namespace std;

class Dugum{
public:
	string eleman;
	Dugum *ileri = NULL;
	Dugum *geri = NULL;
	Stack *yigin;

	Dugum(const string&, Dugum *, Dugum *);
	Dugum();
	const string& yigitTop() const;
	void yigitaElemanEkle(string &);
	void yigitiListele();
	~Dugum();
};
#endif