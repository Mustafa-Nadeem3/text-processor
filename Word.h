#include<iostream>
#include<fstream>
#include "Paragraph.h"
#include "Sentence.h"
using namespace std;

class Word
{
private:
	int cWordP;
	Paragraph p2;
	Sentence s1;
public:
	Word();
	Word(int, const Paragraph&, const Sentence&);
	void setCountWordP(int);
	int getCountWordP();
	friend istream& operator>>(istream&, Word&);
	void setTo(char*, int);
	void count_WordsInParagraph(char*);
	void count_WordsInSentence(char*);
};