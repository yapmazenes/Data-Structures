/**
* @file ODEV3_VY
* @description Bu başlık dosyasında Programda kullanılan AnaAgac sınıfının kullandığı AgacDugum sınıfının başlıkları oluşturulmuştur.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP
#include <string>
#include "BinarySearchTree.hpp"
using namespace std;

class AgacDugum{
public:
	BinarySearchTree *veri;
	AgacDugum *sol = NULL;
	AgacDugum *sag = NULL;
	int yukseklik;

	AgacDugum(  BinarySearchTree *, AgacDugum *, AgacDugum *);
	AgacDugum(BinarySearchTree *);
};
#endif