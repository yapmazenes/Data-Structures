/**
* @file ODEV3_VY
* @description Bu başlık dosyasında Programda kullanılan Çocuk ağaçların sınıfı olan BinarySearchTree sınıfının başlıkları oluşturulmuştur.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/



#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cmath>
#include "Dugum.hpp" 
#include <iostream>
using namespace std;
class BinarySearchTree{
	private:
		Dugum *root;
		int yukseklik=-1;
		
		void AraveEkle(Dugum  *&, const int &);
		bool AraveSil(Dugum *&,const int &);
		bool DugumSil(Dugum *&);
	
		
		void SeviyeyiYazdir(Dugum *,int)const;
		int Yukseklik(Dugum *)const;
		bool Ara(Dugum *,const int &);
		void enBuyukSil(Dugum *&);
		void enKucukSil(Dugum *&);
		public:
			BinarySearchTree();
			bool Bosmu() const;
			void Ekle(const int &);
			void Sil(const int &);
			
			void Levelorder()const;
			bool Arama(const int &);
			void Temizle();
			int Yukseklik()const;
			int getYukseklik()const;
			void enBuyukSilNP();
			void enKucukSilNP();
			~BinarySearchTree();		
};

#endif