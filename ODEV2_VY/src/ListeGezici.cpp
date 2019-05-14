/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe icin gerekli olan ListeGezici nesnesinin fonksiyonlarini yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "ListeGezici.hpp"
ListeGezici::ListeGezici(){  // Yap�c� metot
	simdiki = NULL;
}
ListeGezici::ListeGezici(Dugum *dugum){  // Yap�c� metot
	simdiki = dugum;
}

void ListeGezici::ilerle() { // ilerleme metodu

	simdiki = simdiki->ileri;
}
void ListeGezici::gerile(){

	simdiki = simdiki->geri;
}
const string& ListeGezici::Getir() const { // o anki konumdaki nesneyi getirir.
	if (simdiki == NULL) { cout << "HATA"; }
	else
		return simdiki->eleman;
}