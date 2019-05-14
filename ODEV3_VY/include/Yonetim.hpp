/**
* @file ODEV3_VY
* @description Burada Program icin gerekli olan temel islemlerinin basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 3.Ödev
* @date 14.12.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef YONETIM_HPP
#define YONETIM_HPP
#include <string>
#include <fstream>
#include "AgacBinarySearchTree.hpp"
#include "BinarySearchTree.hpp"

class Yonetim{

public:
	BinarySearchTree *BST;
	AgacBinarySearchTree *AnaBST;
	Yonetim();
	~Yonetim();
	void Basla();


};
#endif
