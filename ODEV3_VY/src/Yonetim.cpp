/**
* @file ODEV3_VY
* @description Burada Program icin gerekli olan temel islemlerinin gövdeleri yazılıyor.Genel olarak Kullanıcıdan okunan ifade ve bunun ayrıştırılıp istenilen değerlerin alınması ve switch case yapısı ve do while ile programın akışının sürekli olarak devam ettirilmesini sağlayan metodlar bulunmaktadır.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Yonetim.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


Yonetim::Yonetim(){
	
	AnaBST = new AgacBinarySearchTree();
	
}
void Yonetim::Basla(){
	
	
	
	char sec;
	
	srand(time(NULL));
	
	string sayi;
	int uretilenSayi;
	int yukseklik;
	bool kontrol;
	bool girisKontrol=false;
	int agacYukseklik;
	do
	{	
		system("CLS");
		cout << "Lutfen bir sayi giriniz => ";
		cin >> sayi;
		 agacYukseklik=sayi.length();
	
	for (int i = 0; i < agacYukseklik; i++)
	{
		BST = new BinarySearchTree();
		if(((int)sayi[i])>=48 && ((int)sayi[i])<=57){
		yukseklik = sayi[i]-'0';
		girisKontrol=true;
		}
		else {cout<<"Giris Hatali";
			girisKontrol=false;
			break;
			
		}
		
			while(yukseklik!=BST->Yukseklik()){
			uretilenSayi = rand() %1000;
			BST->Ekle(uretilenSayi);
			}
		
		AnaBST->Ekle(BST);
	}
	}while(girisKontrol!=true);
	

	do {
		
		cout << "1- Agaclardan Maksimum Degeri cikart" << endl;
		cout << "2- Agaclardan Minimum Degeri cikart" << endl;
		cout << "3- Tum Agaclari Level Order Yazdir" << endl;
		cout << "4- Cikis" << endl;

		cin >> sec;
		cout<<endl;
		
		switch (sec){

		case '1':
			AnaBST->enBuyukSil();
			AnaBST=	AnaBST->agacGuncelle();
			cin.ignore();
			break;
		case '2':
			AnaBST->enKucukSil();
			AnaBST=	AnaBST->agacGuncelle();
			cin.ignore();
			break;
		case '3':			
			AnaBST->tumAgaclariLevelOrderYazdir();
			cin.get();
			cin.ignore();
			break;
		default:
			cout << "Yanlis tercih yaptiniz !" << endl;
			break;
		}


	} while (sec != '4');
	
}
Yonetim::~Yonetim(){
	delete AnaBST;
}
