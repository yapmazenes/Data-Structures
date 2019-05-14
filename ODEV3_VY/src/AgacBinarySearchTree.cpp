/**
* @file ODEV3_VY
* @description Bu kaynak dosyasýnda AnaAgacýn metodlarýnýn gövdeleri yazýlmýþtýr genel olarak Ekleme,Silme,Arama,Yukseklik bulma ,EnBuyuk ,EnKucukSil ve Tüm aðaçlarý Levelorder olarak  dolaþmak için gerekli olan metodlar vardýr.
* @course 1.Öðretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include <cmath>
#include "AgacBinarySearchTree.hpp"


void AgacBinarySearchTree::AraveEkle(AgacDugum  *&alt_Dugum, BinarySearchTree *&yeni){
	if (alt_Dugum == NULL) alt_Dugum = new AgacDugum(yeni);
	else if (yeni->getYukseklik() <= alt_Dugum->yukseklik)
		AraveEkle(alt_Dugum->sol, yeni);
	else if (yeni->getYukseklik() > alt_Dugum->yukseklik)
		AraveEkle(alt_Dugum->sag, yeni);
	//else return; // Ayný eleman var.
}
bool AgacBinarySearchTree::AraveSil(AgacDugum *&alt_Dugum, BinarySearchTree *&yeni)
{
	if (alt_Dugum == NULL) return false; //Eleman yok
	if (alt_Dugum->veri == yeni){
	return DugumSil(alt_Dugum);
	}
	else if (yeni->getYukseklik() <= alt_Dugum->yukseklik)
		return AraveSil(alt_Dugum->sol, yeni);
	else
		return AraveSil(alt_Dugum->sag, yeni);
}
bool AgacBinarySearchTree::DugumSil(AgacDugum *&alt_Dugum)
{
	AgacDugum *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
	else{
		silinecekDugum = alt_Dugum->sol;
		AgacDugum *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL){
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->veri = silinecekDugum->veri;
		if (ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
		else ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

void AgacBinarySearchTree::SeviyeyiYazdir(AgacDugum *alt_Dugum, int seviye)const{
	if (alt_Dugum == NULL) return;
	if (seviye == 0) cout << alt_Dugum->yukseklik << " ";
	else{
		SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
		SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
	}
}
/////////////////////////
void AgacBinarySearchTree:: AgacaSeviyeEkle(AgacDugum *alt_Dugum, int seviye,AgacBinarySearchTree *& guncelAgac){
	if (alt_Dugum == NULL) return;
	if (seviye == 0) guncelAgac->Ekle(alt_Dugum->veri);
	else{
		AgacaSeviyeEkle(alt_Dugum->sol, seviye - 1,guncelAgac);
		AgacaSeviyeEkle(alt_Dugum->sag, seviye - 1,guncelAgac);
	}
}



void AgacBinarySearchTree::SeviyeyiYazdirTumAgaclarLevelDolas(AgacDugum *alt_Dugum, int seviye){
	if (alt_Dugum == NULL) return;
	if (seviye == 0) {alt_Dugum->veri->Levelorder();
	cout << endl;}
	else{
		SeviyeyiYazdirTumAgaclarLevelDolas(alt_Dugum->sol, seviye - 1);
		SeviyeyiYazdirTumAgaclarLevelDolas(alt_Dugum->sag, seviye - 1);
	}
}
void AgacBinarySearchTree::tumAgaclariLevelOrderYazdir(){
	int h = Yukseklik();
	for (int level = 0; level <= h; level++){
		SeviyeyiYazdirTumAgaclarLevelDolas(root, level);
		
	}
}


void AgacBinarySearchTree::SeviyeyiSil(AgacDugum *alt_Dugum, int seviye,AgacDugum** &silinecekBST,int &indis,bool &doluMu ){
	
	if (alt_Dugum == NULL) return;
	if (seviye == 0) {
		 silinecekBST[indis]=alt_Dugum;
		 indis++;
		 doluMu=true;
	}
	else{
		SeviyeyiSil(alt_Dugum->sol, seviye - 1,silinecekBST,indis,doluMu);
		SeviyeyiSil(alt_Dugum->sag, seviye - 1,silinecekBST,indis,doluMu);
	}
}

int AgacBinarySearchTree::Yukseklik(AgacDugum *alt_Dugum)const{
	if (alt_Dugum == NULL) return -1; // Ortada düðüm yoksa yükseklik anlamsýzdýr. Kodun çalýþmasý adýna -1 verilmektedir.
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));

}
void AgacBinarySearchTree::enBuyukSil(){
	int h = Yukseklik();
	if(h!=-1){
	int indis=0;
	bool doluMu=false;
	AgacDugum** silinecekBST=new AgacDugum *[h+2];
	for(int j=0;j<h+2;j++) {
	silinecekBST[j]=NULL;
	}
	
	for (int level = 0; level <= h; level++)
		SeviyeyiSil(root, level,silinecekBST,indis,doluMu);
	
	
	if(doluMu==true){
		
	for(int i =0;i<h+2;i++)
		
		{
		if(silinecekBST[i]!=NULL){
		silinecekBST[i]->veri->enBuyukSilNP();
		silinecekBST[i]->yukseklik = silinecekBST[i]->veri->Yukseklik();
	if (silinecekBST[i]->yukseklik == -1) {
			BinarySearchTree *silinecek;
			silinecek=silinecekBST[i]->veri;
			silinecekBST[i]->veri->Temizle();
			Sil(silinecekBST[i]->veri);
			silinecekBST[i]=NULL;
			delete silinecek;
		}
		}
	}
	}
	delete [] silinecekBST;
	}
}



void AgacBinarySearchTree::enKucukSil(){
	int h = Yukseklik();
	if(h!=-1){
	int indis=0;
	bool doluMu=false;
	AgacDugum** silinecekBST=new AgacDugum *[h+2];
	for(int j=0;j<h+2;j++) {
	silinecekBST[j]=NULL;
	}
	
	for (int level = 0; level <= h; level++)
		SeviyeyiSil(root, level,silinecekBST,indis,doluMu);
	
	
	if(doluMu==true){
		
	for(int i =0;i<h+2;i++)
		
		{
		if(silinecekBST[i]!=NULL){
		silinecekBST[i]->veri->enKucukSilNP();
		silinecekBST[i]->yukseklik = silinecekBST[i]->veri->Yukseklik();
	if (silinecekBST[i]->yukseklik == -1) {
			BinarySearchTree *silinecek;
			silinecek=silinecekBST[i]->veri;
			silinecekBST[i]->veri->Temizle();
			Sil(silinecekBST[i]->veri);
			silinecekBST[i]=NULL;
			delete silinecek;
		}
		}
	}
	}
	delete [] silinecekBST;
	}
}
bool AgacBinarySearchTree::Ara(AgacDugum *alt_Dugum, const BinarySearchTree *aranan){
	if (alt_Dugum == NULL) return false;
	if (alt_Dugum->veri == aranan) return true;
	if (aranan->getYukseklik() < alt_Dugum->yukseklik) return Ara(alt_Dugum->sol, aranan);
	if (aranan->getYukseklik() > alt_Dugum->yukseklik) return Ara(alt_Dugum->sag, aranan);
}
AgacBinarySearchTree::AgacBinarySearchTree(){
	root = NULL;
}
bool AgacBinarySearchTree::Bosmu() const{
	return root == NULL;
}
void AgacBinarySearchTree::Ekle(BinarySearchTree *&yeni)
{
	AraveEkle(root, yeni);
}
void AgacBinarySearchTree::Sil(BinarySearchTree *&veri)
{
	AraveSil(root, veri);
}

void AgacBinarySearchTree::Levelorder()const{
	int h = Yukseklik();
	for (int level = 0; level <= h; level++)
		SeviyeyiYazdir(root, level);
}
bool AgacBinarySearchTree::Arama(const BinarySearchTree *aranan){
	return Ara(root, aranan);
}
void AgacBinarySearchTree::Temizle(){
	while (!Bosmu()) DugumSil(root);
}
void AgacBinarySearchTree::BSTBirlikteTemizle(){
	BinarySearchTree *silinecek;
	while (!Bosmu()) {
		silinecek=root->veri;
		silinecek->Temizle();
		DugumSil(root);
		delete silinecek;
		}
}
int AgacBinarySearchTree::Yukseklik()const{
	return Yukseklik(root);
}

 AgacBinarySearchTree * AgacBinarySearchTree:: agacGuncelle(){
		AgacBinarySearchTree * guncelAgac = new AgacBinarySearchTree();
		
		int h = Yukseklik();
	for (int level = 0; level <= h; level++)
		AgacaSeviyeEkle(root, level,guncelAgac);
	
	this->Temizle();	
	return guncelAgac;
 }


AgacBinarySearchTree::~AgacBinarySearchTree(){
		BSTBirlikteTemizle();
	}


