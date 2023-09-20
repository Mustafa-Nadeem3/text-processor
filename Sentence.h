#pragma once
#include<iostream>
#include<fstream>
#include "Paragraph.h"
using namespace std;

class Sentence
{
private:
	int cSentence;
	Paragraph p1;
public:
	Sentence();
	Sentence(int, const Paragraph&);
	void setCountSentence(int);
	int getCountSentence();
	friend istream& operator>>(istream&, Sentence&);
	void setToPara(char*);
	void count_Sentence(char*);
};