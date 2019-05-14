/**
* @file ODEV3_VY
* @description Bu başlık dosyasında Programda kullanılan Çocuk ağaçların sınıfı olan BinarySearchTree sınıfının kullandığı Dugum sınıfının başlıkları oluşturulmuştur.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <string>
using namespace std;

class Dugum{
public:
	int veri;
	Dugum *sol = NULL;
	Dugum *sag = NULL;
	int yukseklik;

	Dugum(const int&, Dugum *, Dugum *);
	Dugum(const int&);
};
#endif