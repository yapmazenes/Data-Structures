/**
* @file ODEV1_VY
* @description Icerisinde ogrenci nesnelerinin gosterilmesini saglayan Ogrenci tipinde pointer dizisi bulunmaktadir ve bu dizinin icerigini elde etmek , diziye icerik eklemek gibi sinifla ilgili bilgilere ulasmayi saglayan metodlar bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "Sinif.hpp"
#include "Ogrenci.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
	Sinif:: Sinif(char sinifIsim,int ogrSayisi){
		
		Isim=sinifIsim;
		ogrenciSayisi=ogrSayisi;
		ogrenciler=new Ogrenci*[ogrenciSayisi];
	}
Sinif::Sinif(){

}
void Sinif:: ogrenciDegistir(int yer,Ogrenci * ogr){		
		ogrenciler[yer]=ogr;
}
ostream& operator<<(ostream& ekran, Sinif &sag){
	ekran<<"Sinif: "<<sag.Isim<<"       ";
	return ekran;
}
bool Sinif::operator==(Sinif& sag){
	return this->Isim == sag.Isim;
}

	void Sinif::sinifaOgrencileriEkle(char *ogrenciIsimleri){//Bir sınıfın içerisindeki öğrencileri alır
		//Bu bölüm her bir satır bitince çağırılıp öğrenci isimleri verilmeli.
		for(int i=0;i<ogrenciSayisi;i++){
			ogrenciler[i]=new Ogrenci(ogrenciIsimleri[i]);
		}
	}
	bool Sinif::ogrenciVarmi(int i){
		if((i+1)>ogrenciSayisi)
		return false;
		return true;

	}
	int Sinif::getOgrenciSayisi()const{
		return ogrenciSayisi;
	}
	Ogrenci ** Sinif::getOgrenciler()const{
		return ogrenciler;
	}
	 Ogrenci * Sinif::getOgrenci(int i){
	  return ogrenciler[i];

	}

	char Sinif::getIsim()const{
		return Isim;
	}
	
	Sinif::~Sinif(){
		//cout<<"DECONST sinif calisti"<<endl;
		Yoket(ogrenciler,ogrenciSayisi);
		delete [] ogrenciler;
	}
	void Sinif::Yoket(Ogrenci **ogrenciler,int ogrSayisi){
		//<<"Ogrenci Yoket calisti"<<endl;
		for(int i=0;i<ogrSayisi;i++){ 
			delete	ogrenciler[i];
		}
	}
	

