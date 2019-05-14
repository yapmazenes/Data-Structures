/**
* @file ODEV3_VY
* @description Burada Programda kullanılan AnaAgac sınıfının başlık dosyaları bulunmaktadır.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/


#ifndef AGACBINARY_TREE_HPP
#define AGACBINARY_TREE_HPP

#include <cmath>
#include "AgacDugum.hpp"
#include "BinarySearchTree.hpp"

class AgacBinarySearchTree{
	private:
		AgacDugum *root;
		
		void AraveEkle(AgacDugum  *&, BinarySearchTree *&);
		bool AraveSil(AgacDugum *&,BinarySearchTree *&);
		bool DugumSil(AgacDugum *&);
		void SeviyeyiYazdir(AgacDugum *,int)const;
		void AgacaSeviyeEkle(AgacDugum *,int,AgacBinarySearchTree *&);
		void SeviyeyiSil(AgacDugum *, int,AgacDugum **&,int &,bool &);
		void SeviyeyiYazdirTumAgaclarLevelDolas(AgacDugum *, int);
		int Yukseklik(AgacDugum *)const;
		bool Ara(AgacDugum *,const BinarySearchTree *);

		public:
			AgacBinarySearchTree();
			bool Bosmu() const;
			void Ekle( BinarySearchTree *&);
			void Sil( BinarySearchTree *&);
		
			void Levelorder()const;
			bool Arama(const BinarySearchTree *);
			void Temizle();
			void BSTBirlikteTemizle();
			int Yukseklik()const;
			void enBuyukSil();
			void enKucukSil();
			void tumAgaclariLevelOrderYazdir();
			
			AgacBinarySearchTree * agacGuncelle();
			~AgacBinarySearchTree();		
};

#endif