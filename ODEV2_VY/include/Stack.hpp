/**
* @file ODEV2_VY
* @description Burada Stack nesnesini basliklarini tanimliyoruz.
* @course 1.Öğretim C Grubu
* @assignment 2.Ödev
* @date 23.11.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/
#ifndef STACK_HPP
#define STACK_HPP
#include <string>
#include "StackDugum.hpp"
#include <iostream>
using namespace std;

class Stack{
private:
	StackDugum  *topOfStack;
	int elemanSayisi = 0;
public:
	int	getElemanSayisi() const;

	string& getEleman(int)const;
	Stack();
	bool isEmpty()const;
	void push(const string&);
	void pop();
	const string& top()const;
	void makeEmpty();
	~Stack();
};
#endif