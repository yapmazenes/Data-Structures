/**
* @file ODEV2_VY
* @description Burada Stack nesnesi icin gerekli olan Dugum 'un yapici metodunu yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#include "StackDugum.hpp"

StackDugum::StackDugum(string itm, StackDugum *nx){
	item = itm;
	next = nx;
}