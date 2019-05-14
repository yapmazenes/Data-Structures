/**
* @file ODEV3_VY
* @description Bu kaynak dosyasýnda Programda kullanýlan AnaAgac sýnýfýnýn içerisinde olan BinarySearchTree sýnýfýnýn gövdeleri oluþturulmuþtur.Genel olarak BST ile ilgili metodlar ve Ek olarak EnBuyuk ve EnKucuk deðerleri bulup Silmek için gerekli olan Metodlar yazýlmýþtýr.
* @course 1.Öðretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "BinarySearchTree.hpp"
#include <cmath>
		
		void BinarySearchTree::AraveEkle(Dugum  *&alt_Dugum, const int &yeni){
			
			if(alt_Dugum == NULL) alt_Dugum = new Dugum(yeni);
			else if(yeni < alt_Dugum->veri)
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni > alt_Dugum->veri)
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayný eleman var.
		}
		bool BinarySearchTree::AraveSil(Dugum *&alt_Dugum,const int &yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri == yeni)
				return DugumSil(alt_Dugum);
			else if(yeni < alt_Dugum->veri)
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		void BinarySearchTree::enBuyukSil( Dugum *&alt_Dugum ){
			if (alt_Dugum->sag == NULL) DugumSil(alt_Dugum);
			else enBuyukSil(alt_Dugum->sag);
		}
		void BinarySearchTree::enKucukSil( Dugum *&alt_Dugum){
			if (alt_Dugum->sol == NULL) DugumSil(alt_Dugum);
			else enKucukSil(alt_Dugum->sol);
		}
		void BinarySearchTree::enBuyukSilNP(){
			enBuyukSil(root);
			yukseklik=Yukseklik();
		}
		void BinarySearchTree::enKucukSilNP(){
			enKucukSil(root);
			yukseklik=Yukseklik();
		}
		bool BinarySearchTree::DugumSil(Dugum *&alt_Dugum)
		{			
			Dugum *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				Dugum *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_Dugum->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
	
		void BinarySearchTree:: SeviyeyiYazdir(Dugum *alt_Dugum,int seviye)const{
			if(alt_Dugum == NULL) return;
			if(seviye == 0) cout<<alt_Dugum->veri<<" ";
			else{
				SeviyeyiYazdir(alt_Dugum->sol,seviye-1);
				SeviyeyiYazdir(alt_Dugum->sag,seviye-1);
			}
		}
		int BinarySearchTree::Yukseklik(Dugum *alt_Dugum)const{
			if(alt_Dugum == NULL) return -1; // Ortada düðüm yoksa yükseklik anlamsýzdýr. Kodun çalýþmasý adýna -1 verilmektedir.
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		bool BinarySearchTree::Ara(Dugum *alt_Dugum,const int &aranan){
			if(alt_Dugum == NULL) return false;
			if(alt_Dugum->veri == aranan) return true;
			if(aranan < alt_Dugum->veri) return Ara(alt_Dugum->sol,aranan);
			if(aranan > alt_Dugum->veri) return Ara(alt_Dugum->sag,aranan);
		}
			BinarySearchTree::BinarySearchTree(){
				root = NULL;
			}
			bool BinarySearchTree:: Bosmu() const{
				return root == NULL;
			}
			void BinarySearchTree::Ekle(const int &yeni)
			{
				AraveEkle(root,yeni);
				yukseklik=Yukseklik();
			}
			void BinarySearchTree::Sil(const int &veri) 
			{
				AraveSil(root,veri);
				yukseklik=Yukseklik();				
			}
		
			void BinarySearchTree::Levelorder()const{
				int h = Yukseklik();
				for(int level=0;level<=h;level++)
					SeviyeyiYazdir(root,level);
			}
			bool BinarySearchTree::Arama(const int &aranan){
				return Ara(root,aranan);
			}
			void BinarySearchTree::Temizle(){
				while(!Bosmu()) DugumSil(root);
				yukseklik=-1;
				
			}
			int BinarySearchTree::Yukseklik()const{
				return Yukseklik(root);
			}
			int BinarySearchTree::getYukseklik()const{
				return yukseklik;
			}
		BinarySearchTree::~BinarySearchTree(){
			//	cout<<"BST yikici calisti"<<endl;
				Temizle();
				
			}		


