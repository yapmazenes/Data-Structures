/**
* @file ODEV2_VY
* @description Burada CiftYonluDBagilListe nesnesinin Dugumleri icin gerekli olan Stack 'in fonksiyonlarini yaziyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#include "Stack.hpp"
#include <iostream>
using namespace std;

Stack::Stack(){
	topOfStack = NULL;
}
bool Stack::isEmpty()const{
	return topOfStack == NULL;
}
void Stack::push(const string& item){
	topOfStack = new StackDugum(item, topOfStack);
	elemanSayisi++;
}
void Stack::pop(){
	//if(isEmpty())throw HATA
	StackDugum  *tmp = topOfStack;
	topOfStack = topOfStack->next;
	elemanSayisi--;
	delete tmp;
}
int Stack::getElemanSayisi()const{
	return elemanSayisi;
}
string& Stack::getEleman(int konum)const{
	StackDugum *tmp = topOfStack;
	for (size_t i = 0; i < konum; i++)
	{
		tmp = tmp->next;
	}
	return tmp->item;
}


const string& Stack::top()const{
	//if(isEmpty())throw HATA
	return topOfStack->item;
}
void Stack::makeEmpty(){
	while (!isEmpty())
		pop();
}
Stack::	~Stack(){
	makeEmpty();
}