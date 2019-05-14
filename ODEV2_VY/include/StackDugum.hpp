/**
* @file ODEV2_VY
* @description Burada Stack icin Dugum nesnesini basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef STACKDUGUM_HPP
#define STACKDUGUM_HPP

#include <string>
using namespace std;

class StackDugum{
public:
	string item;
	StackDugum *next = nullptr;
	StackDugum(string, StackDugum *);
};
#endif