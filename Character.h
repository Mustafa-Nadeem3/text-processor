#include<iostream>
#include<fstream>
#include "Paragraph.h"
using namespace std;

class Character
{
private:
	int cEnglish;
	int cPunctuation;
	int cCharacter;
	Paragraph p3;
public:
	Character();
	Character(int, int, int, const Paragraph&);
	void setCountEnglish(int);
	void setCountPunctuation(int);
	int getCountEnglish();
	int getCountPunctuation();
	friend istream& operator>>(istream&, Character&);
	void setToPara(char*);
	void count_English(char*);
	void count_Punctuation(char*);
	void count_CharactersInWordsInSentence(char*);
};