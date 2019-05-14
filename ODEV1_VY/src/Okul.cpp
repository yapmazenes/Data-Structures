/**
* @file ODEV1_VY
* @description Okul nesnesinin icerisine , icinde bulunan herbir pointerin bir sinifi gostermesi amaclanan bir dizi ,Bu dizinin iceriginin doldurulmasını saglayan , iceriginin kucukten buyuge siralanmasini saglayan,pointerlarin gostericilerinin degismesini saglayan vb gerekli islemlerin yapilmasini saglayan metodlar bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Okul.hpp"
#include "Sinif.hpp"
#include <iostream>
using namespace std;
	Okul::Okul(int snfSayisi){
		sinifSayisi=snfSayisi;//Okul sınıfını çalıştırabilmek için bütün satırları okumamız gerekiyor.
		siniflar= new Sinif*[sinifSayisi]();
	}
	
	void Okul::okulaSinifEkle(char sinifIsmi,int ogrenciSayisi,int kacinciSinif){
		//Herbir okunan satırın sonunda kaçıncı sınıfın verildiği bilgisiyle birlikte yeni bir sinif ekler
		
			siniflar[kacinciSinif]=new Sinif(sinifIsmi,ogrenciSayisi);
		
	}

	 void Okul:: sinifSirala(){
	
	for(size_t i = 0; i < sinifSayisi; i++)
	{
	for(size_t j = i; j < sinifSayisi; j++)
	{
		if(siniflar[i]->getIsim()>siniflar[j]->getIsim())
		swap(i,j);
	}
	}
	
	 }
	 
void Okul :: swap(int a,int b){
	if(a<sinifSayisi && b<sinifSayisi)
	{
    Sinif* tmp;
    tmp=siniflar[a];
    siniflar[a]=siniflar[b];
    siniflar[b]=tmp;
	tmp=nullptr;	
	}
}
	void Okul:: sinifDegistir(char sinif1,char sinif2){
	if(sinif1==sinif2)
		cout<<"İki sinif ismi esit olmamali"<<endl;
		else{
		int snfIndis1=-1;
		int snfIndis2=-1;
		char gelenIsim;
		
	for(int i = 0; i < sinifSayisi; i++)
	{
		
		gelenIsim=siniflar[i]->getIsim();
	//	cout<<"Gelen isim"<<gelenIsim<<endl;

		if (gelenIsim==sinif1) {
			snfIndis1=i;
		}
		else if(gelenIsim==sinif2){
			snfIndis2=i;			
		}
	}
	if(snfIndis1==-1)
		{
			cout<<"Sinif 1 bulunamadi"<<endl;
			//cin.ignore();
		}
	 if(snfIndis2==-1)
		{
			cout<<"Sinif 2 bulunamadi"<<endl;
			//cin.ignore();
		}
	 if(snfIndis1==-1&&snfIndis2==-1){
			cout<<"Sinif 1 ve 2 bulunamadi"<<endl;
			//cin.ignore();
	 }
	 if(snfIndis1!=-1&&snfIndis2!=-1) {
  		 swap(snfIndis1,snfIndis2);
	}
	}
	}
	int Okul::getSinifSayisi()const{
		return sinifSayisi;
	}
	Sinif ** Okul::getSiniflar(){
		return siniflar;
	}
	Sinif * Okul::getSinif(int i){
	return siniflar[i];
	}
	
	Okul::~Okul(){
		//cout<<"DECONST okul calisti"<<endl;
		Yoket(siniflar,sinifSayisi);
		delete [] siniflar;
	}
	
	void Okul::Yoket(Sinif **siniflar,int sinifSayisi){
	//	cout<<" okul yoket calisti"<<endl;
		for(int i=0;i<sinifSayisi;i++){ 
			delete siniflar[i];
		}
	}
