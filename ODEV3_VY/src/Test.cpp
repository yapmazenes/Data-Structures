
/**
* @file ODEV3_VY
* @description Burada programi Test etmek icin gerekli olan Yonetim nesnesi olusturuluyor ve program baslatiliyor.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Yonetim.hpp"
#include <iostream>
using namespace std;
int main(){
	Yonetim *y = new Yonetim();
	y->Basla();
	delete y;

	return 0;
}