#include "Character.h"

Character::Character()
{
	cEnglish = 0;
	cPunctuation = 0;
	cCharacter = 0;
}

Character::Character(int e, int P, int c, const Paragraph& obj)
{
	cEnglish = e;
	cPunctuation = P;
	cCharacter = c;
	p3 = obj;
}

istream& operator>>(istream& in, Character& obj)
{
	in >> noskipws;
	int ct = 0;
	char* p;
	p = new char[150];
	while (!in.eof())
	{
		in >> p[ct];
		if (in.eof())
		{
			p[ct + 1] = '\0';
			break;
		}
		ct++;
	}
	obj.setToPara(p);
	obj.count_English(p);
	obj.count_Punctuation(p);
	obj.count_CharactersInWordsInSentence(p);
	return in;
}

void Character::setCountEnglish(int e)
{
	cEnglish = e;
}

void Character::setCountPunctuation(int P)
{
	cPunctuation = P;
}

int Character::getCountEnglish()
{
	return cEnglish;
}

int Character::getCountPunctuation()
{
	return cPunctuation;
}

void Character::setToPara(char* p)
{
	p3.set_Paragraph(p);
}

void Character::count_English(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] >= 'a' && p[i] <= 'z' || p[i] >= 'A' && p[i] <= 'Z')
			ct++;
	}
	cEnglish = ct;
}

void Character::count_Punctuation(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == '.' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
			ct++;
	}
	cPunctuation = ct;
}

void Character::count_CharactersInWordsInSentence(char* p)
{
	int ct1 = 1, ct2 = 1, ct3 = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
		{
			cout << "Characters in Word no " << ct1 << " of Sentence no " << ct2 << " : " << ct3 << endl;
			cout << endl;
			ct1++;
			ct3 = 0;
		}
		else if (p[i] == '.')
		{
			cout << "Characters in Word no " << ct1 << " of Sentence no " << ct2 << " : " << ct3 << endl;
			cout << endl;
			ct1++;
			ct2++;
			ct3 = 0;
		}
		else
			ct3++;
	}
}