/**
* @file ODEV2_VY
* @description Burada Programın testi icin gerekli olan fonksiyonlari yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Yonetim.hpp"
#include <iostream>
using namespace std;


Yonetim::Yonetim(){
	liste = new CiftYonluDBagilListe();
	dosyaOku();
}
void Yonetim::Basla(){
	char sec;
	do {
		system("CLS");
		cout << "1- Sola Hareket" << endl;
		cout << "2- Saga Hareket" << endl;
		cout << "3- Bir Dugumun Durumlarini Yazdir" << endl;
		cout << "4- Tum Durumlari Yazdir" << endl;
		cout << "5- Cikis" << endl;

		cin >> sec;
		cout<<endl;
		
		switch (sec){

		case '1':
			solaKaydir();
			cin.ignore();
			break;
		case '2':
			sagaKaydir();
			cin.ignore();
			break;
		case '3':
			int index;
			cout << "Yazdirilacak dugumun index'i nedir ? => ";
			cin >> index;
			cout << "Dugum Konumu:" << index << endl;
			
			birDugumunDurumlari(index);
			cin.get();
			cin.ignore();
			break;
		case '4':
			tumDugumlerinDurumlari();
			cin.get();
			cin.ignore();
			break;
		case '5':break;
			break;
		default:
			cout << "Yanlis tercih yaptiniz !" << endl;
			break;
		}


	} while (sec != '5');
	delete liste;
}
void Yonetim::sagaKaydir(){
	ListeGezici gezici = liste->Ilk();
	string tmp = liste->IlkEleman();
	string yeniYigitEleman;
	int i = 0;
	for (gezici; i < liste->Uzunluk(); gezici.ilerle()){

		gezici.simdiki->ileri->eleman = tmp;
		tmp = gezici.simdiki->ileri->yigitTop();

		yeniYigitEleman = gezici.simdiki->ileri->eleman;
		gezici.simdiki->ileri->yigitaElemanEkle(yeniYigitEleman);

		i++;
	}

}
void Yonetim::solaKaydir(){

	ListeGezici gezici = liste->Ilk();
	string tmp = liste->IlkEleman();
	string yeniYigitEleman;
	int i = 0;
	for (gezici; i < liste->Uzunluk(); gezici.gerile()){

		gezici.simdiki->geri->eleman = tmp;
		tmp = gezici.simdiki->geri->yigitTop();

		yeniYigitEleman = gezici.simdiki->geri->eleman;
		gezici.simdiki->geri->yigitaElemanEkle(yeniYigitEleman);

		i++;
	}

}
void Yonetim::birDugumunDurumlari(int index){
	if (liste->Varmi(index) == true){
		ListeGezici gezici = liste->OncekiniKonumuIleBul(index);
		gezici.simdiki->ileri->yigitiListele();
	}
	else cout << "Index gecerli degil.";
}
void Yonetim::tumDugumlerinDurumlari(){

	for (size_t i = 0; i < liste->Uzunluk(); i++)
	{
		birDugumunDurumlari(i);
	}
}
void Yonetim::dosyaOku(){
	myfile.open("Sayi.txt");
	string okunanDeger;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> okunanDeger;
			liste->Ekle(okunanDeger);
		}
		myfile.close();
	}
}
