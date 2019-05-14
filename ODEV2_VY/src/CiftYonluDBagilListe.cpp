/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe nesnesinin fonksiyonlarini yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "CiftYonluDBagilListe.hpp"
#include <iostream>
using namespace std;

ListeGezici  CiftYonluDBagilListe::OncekiniKonumuIleBul(int konum) const{
	if (konum<0 || konum > Uzunluk()) {
		cout << "Tasti";
	}
	else{
		int indeks = 0;
		ListeGezici gezici(basDugum);

		while (konum != indeks++) gezici.ilerle();
		return gezici;
	}
}


ListeGezici  CiftYonluDBagilListe::Ilk() const {

	return ListeGezici(basDugum->ileri);
}

CiftYonluDBagilListe::CiftYonluDBagilListe(){
	basDugum = new Dugum(); // Bos bir dugum olusturuluyor	
	sonDugum = new Dugum();
	elemanSayisi = 0;
}
bool CiftYonluDBagilListe::Bosmu() const{
	if (elemanSayisi == 0)
		return true;
	else
		return false;

}
bool CiftYonluDBagilListe::Varmi(int konum){
	if (konum<0 || konum > Uzunluk()) {
		return false;
	}
	else return true;
}

int CiftYonluDBagilListe::Uzunluk() const{
	return elemanSayisi;
}
const  string& CiftYonluDBagilListe::IlkEleman() const {

	if (elemanSayisi == 0) return listeBos;
	return basDugum->ileri->eleman;
}
const string& CiftYonluDBagilListe::SonEleman() const {


	if (elemanSayisi == 0) return listeBos;
	return sonDugum->ileri->eleman;
	//return OncekiniKonumuIleBul(elemanSayisi).Getir();
}
void CiftYonluDBagilListe::Ekle(const string& yeni){
	Ekle(yeni, Uzunluk());
}
void CiftYonluDBagilListe::Ekle(const string& yeni, int konum) {
	ListeGezici  gezici;//konum=0

	gezici = OncekiniKonumuIleBul(konum);

	Dugum  *yeniIleri = gezici.simdiki->ileri;

	if (konum == Uzunluk()) {

		gezici.simdiki->ileri = new Dugum(yeni, basDugum->ileri, gezici.simdiki);
		if (konum == 0){
			gezici.simdiki->ileri->geri = gezici.simdiki->ileri;//Kendi kendini gostersin
		}
		string stackEleman = yeni;
		gezici.simdiki->ileri->yigitaElemanEkle(stackEleman);

		sonDugum->ileri = gezici.simdiki->ileri;
		basDugum->ileri->geri = sonDugum->ileri;

	}

	else{
		gezici.simdiki->ileri = new Dugum(yeni, yeniIleri, gezici.simdiki);//Eleman Araya eklendiyse
		yeniIleri->geri = gezici.simdiki->ileri;
	}

	elemanSayisi++;

}
void CiftYonluDBagilListe::Sil(const string& aranan) {

	int konum = KonumuBul(aranan);
	KonumdakiniSil(konum);

}



void CiftYonluDBagilListe::KonumdakiniSil(int konum) {

	ListeGezici  gezici = OncekiniKonumuIleBul(konum);
	Dugum  *sil = gezici.simdiki->ileri;
	gezici.simdiki->ileri = gezici.simdiki->ileri->ileri;

	if (sil->ileri != NULL) sil->ileri->geri = sil;
	if (konum == 0){
		sonDugum->ileri = sil->geri;
		basDugum->ileri->geri = sonDugum->ileri;
	}
	else if (konum == Uzunluk() - 1)
	{
		sonDugum->ileri = sil->geri;
	}
	delete sil;
	elemanSayisi--;

}


bool CiftYonluDBagilListe::ElemanBul(const string& aranan) const{

	int knm = KonumuBul(aranan);


	return true;

}
int CiftYonluDBagilListe::KonumuBul(const string& aranan) const {

	int indeks = 0;
	for (ListeGezici gezici(basDugum->ileri); !SonaGeldimi(gezici); gezici.ilerle()){
		if (gezici.Getir() == aranan) return indeks;
		indeks++;
	}

}
bool CiftYonluDBagilListe::SonaGeldimi(ListeGezici gezici) const{
	bool gecisHakki = false;
	if (gezici.simdiki == sonDugum->ileri){

		if (gecisHakki == true)
			return true;//Son eleman icin 1 tane gecis hakki taniyorum.Cunku dairesel de son elemanın ilerisi NULL degil,kontrol icin bu sekilde bir yol izledim.  
		gecisHakki = true;

	}
	else
		false;
}

void CiftYonluDBagilListe::Temizle(){

	while (!Bosmu())
		Sil(Ilk().Getir());

}

CiftYonluDBagilListe::~CiftYonluDBagilListe(){
	Temizle();
	delete basDugum;
	delete sonDugum;
}


