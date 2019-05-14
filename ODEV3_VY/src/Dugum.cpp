/**
* @file ODEV3_VY
* @description Bu kaynak dosyasında Programda kullanılan Çocuk ağaçların sınıfı olan BinarySearchTree sınıfının kullandığı Dugum sınıfının gövdeleri oluşturulmuştur.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#include "Dugum.hpp"
Dugum::Dugum(const int& vr, Dugum  *sl, Dugum *sg){
	this->veri = vr;
	sol = sl;
	sag = sg;
	yukseklik=0;
}
Dugum::Dugum(const int& vr){
	this->veri = vr;
	sol = NULL;
	sag = NULL;
	yukseklik=0;
}

