#include "Word.h"

Word::Word()
{
	cWordP = 0;
}

Word::Word(int cP, const Paragraph& objP, const Sentence& objS)
{
	cWordP = cP;
	p2 = objP;
	s1 = objS;
}

void Word::setCountWordP(int cP)
{
	cWordP = cP;
}

int Word::getCountWordP()
{
	return cWordP;
}

istream& operator>>(istream& in, Word& obj)
{
	in >> noskipws;
	int ct = 0 , s = 0;
	char* p;
	p = new char[150];
	while (!in.eof())
	{
		in >> p[ct];
		if (p[ct] == '.')
		{
			s++;
		}
		else if (in.eof())
		{
			p[ct + 1] = '\0';
			break;
		}
		ct++;
	}
	obj.setTo(p, s);
	obj.count_WordsInParagraph(p);
	obj.count_WordsInSentence(p);
	return in;
}

void Word::setTo(char* p, int s)
{
	p2.set_Paragraph(p);
	s1.setCountSentence(s);
}

void Word::count_WordsInParagraph(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '.' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
			ct++;
	}
	cWordP = ct;
}

void Word::count_WordsInSentence(char* p)
{
	int ct = 0, x = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
			ct++;
		else if (p[i] == '.')
		{
			ct = ct + 1;
			cout << "Number of Words in Sentence " << x + 1 << " are: " << ct << endl;
			cout << endl;
			x++;
			ct = 0;
		}
	}
}