/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe icin gerekli olan Dugum nesnesinin fonksiyonlarini yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#include "Dugum.hpp"
Dugum::Dugum(const string& eleman, Dugum  *ilr, Dugum *gr){
	this->eleman = eleman;
	ileri = ilr;
	geri = gr;
	yigin = new Stack();
}
Dugum::Dugum(){
	yigin = new Stack();
}
const string&  Dugum::yigitTop()const{
	return yigin->top();
}

void Dugum::yigitaElemanEkle(string &eklenecekEleman){
	yigin->push(eklenecekEleman);
}

void Dugum::yigitiListele(){
	string yigitBas = yigitTop();
	cout << yigitBas;


	for (size_t i = yigitBas.length(); i < 11; i++)
	{
		cout << " ";
	}
	cout << ":";
	for (size_t i = 0; i < 10; i++)
	{
		cout << " ";
	}
	int yiginElemanSayisi = yigin->getElemanSayisi();

	for (size_t i = 0; i < yiginElemanSayisi; i++)
	{
		yigitBas = yigin->getEleman(i);
		cout << yigitBas;
		for (size_t i = yigitBas.length(); i < 7; i++)
		{
			cout << " ";
		}

	}




	//yigin->Listele();
	cout << endl;
}

Dugum::~Dugum(){
	yigin->makeEmpty();
	delete yigin;
}