#include "Sentence.h"

Sentence::Sentence()
{
	cSentence = 0;
}

Sentence::Sentence(int s, const Paragraph& obj)
{
	cSentence = s;
	p1 = obj;
}

void Sentence::setCountSentence(int s)
{
	cSentence = s;
}

int Sentence::getCountSentence()
{
	return cSentence;
}

istream& operator>>(istream& in, Sentence& obj)
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
	obj.count_Sentence(p);
	return in;
}

void Sentence::setToPara(char* p)
{
	p1.set_Paragraph(p);
}

void Sentence::count_Sentence(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == '.')
			ct++;
	}
	cSentence = ct;
}