/**
* @file ODEV3_VY
* @description Bu kaynak dosyasında Programda kullanılan AnaAgac sınıfının kullandığı AgacDugum sınıfının gövdeleri yazılmıştır.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#include "AgacDugum.hpp"
AgacDugum::AgacDugum( BinarySearchTree * vr, AgacDugum  *sl, AgacDugum *sg){
	this->veri = vr;
	sol = sl;
	sag = sg;
	yukseklik=veri->Yukseklik();
}

AgacDugum::AgacDugum( BinarySearchTree * vr){
	this->veri = vr;
	sol = NULL;
	sag = NULL;
	yukseklik=veri->Yukseklik();
}
