#include<iostream>
#include<fstream>
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"
#include "Character.h"
using namespace std;

int main()
{
	int key;
	char file1[11] = { "Text1.txt" }, file2[11] = { "Text2.txt" };
	char* p;
	p = new char[150];
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 Text Processor                                 " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	//Info on Paragraph 1:-
	Paragraph p1;
	ifstream fin1;
	fin1.open("Text1.txt");
	fin1 >> p1;
	fin1.close();
	cout << p1;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sentence s1;
	ifstream fin2;
	fin2.open("Text1.txt");
	fin2 >> s1;
	fin2.close();
	cout << "Number of Sentences in Paragraph 1 are: " << s1.getCountSentence() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Word w1;
	ifstream fin3;
	fin3.open("Text1.txt");
	fin3 >> w1;
	fin3.close();
	cout << "Number of Words in Paragraph 1 are: " << w1.getCountWordP() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Character c1;
	ifstream fin4;
	fin4.open("Text1.txt");
	fin4 >> c1;
	fin4.close();
	cout << "Number of English Characters in Paragraph 1 are: " << c1.getCountEnglish() << endl;
	cout << endl;
	cout << "Number of Punctuation Characters in Paragraph 1 are: " << c1.getCountPunctuation() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//Info on Paragraph 2:-
	Paragraph p2;
	ifstream fin5;
	fin5.open("Text2.txt");
	fin5 >> p2;
	fin5.close();
	cout << p2;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sentence s2;
	ifstream fin6;
	fin6.open("Text2.txt");
	fin6 >> s2;
	fin6.close();
	cout << "Number of Sentences in Paragraph 2 are: " << s2.getCountSentence() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Word w2;
	ifstream fin7;
	fin7.open("Text2.txt");
	fin7 >> w2;
	fin7.close();
	cout << "Number of Words in Paragraph 2 are: " << w2.getCountWordP() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Character c2;
	ifstream fin8;
	fin8.open("Text2.txt");
	fin8 >> c2;
	fin8.close();
	cout << "Number of English Characters in Paragraph 2 are: " << c2.getCountEnglish() << endl;
	cout << endl;
	cout << "Number of Punctuation Characters in Paragraph 2 are: " << c2.getCountPunctuation() << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	
	//Comparing two Paragraph:-
	if (p1 == p2)
		cout << "THE PARAGRAPHS ARE EQUAL..." << endl;
	else
		cout << "THE PARAGRAPHS ARE NOT EQUAL..." << endl;
		
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	
	//Conversion to Uppercase or Lowercase:-
	Paragraph p3;
	ifstream fin9;
	fin9.open("Text1.txt");
	fin9 >> p3;
	fin9.close();
	if (p3.find_Character())
		-p3;
	else
		+p3;
	cout << p3;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	
	Paragraph p4;
	ifstream fin10;
	fin10.open("Text2.txt");
	fin10 >> p4;
	fin10.close();
	if (p4.find_Character())
		-p4;
	else
		+p4;
	cout << p4;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//Encrpyting or Decrypting Paragraph:-
	Paragraph p5;
	p5 = p1;
	if (p5.find_PlainText())
	{
		cout << "Enter key for encryption: ";
		cin >> key;
		cout << endl;
		p5 + key;
	}
	else
	{
		cout << "Enter key for decryption: ";
		cin >> key;
		cout << endl;
		p5 - key;
	}
	cout << endl;
	cout << p5;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	Paragraph p6;
	p6 = p5;
	if (p6.find_PlainText())
	{
		cout << "Enter key for encryption: ";
		cin >> key;
		cout << endl;
		p6 + key;
	}
	else
	{
		cout << "Enter key for decryption: ";
		cin >> key;
		cout << endl;
		p6 - key;
	}
	cout << endl;
	cout << p6;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//Checking Words from Dictionary:-
	Paragraph p7;
	ifstream fin11;
	fin11.open("Dictionary.txt");
	fin11 >> p7;
	fin11.close();
	cout << "Words missing in Dictionary: " << endl;
	p7.check_Dictionary(p1);
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//Adding two Paragraphs into one Paragraph:-
	Paragraph p8;
	p8 = p1 + p2;
	cout << "Adding two paragraphs into one paragraph: " << endl;
	cout << endl;
	cout << p8;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//Output to file:-
	ofstream fout;
	fout.open("Frequency.txt");
	fout << "Paragraph number: 1" << endl;
	fout << endl;
	Sentence s3;
	ifstream fin13;
	fin13.open("Text1.txt");
	fin13 >> s3;
	fin13.close();
	fout << "Sentences in Paragraph 1 are: " << s3.getCountSentence() << endl;
	fout << endl;
	Word w3;
	fout << "Words in Paragraph 1 are: " << w1.getCountWordP() << endl;
	fout << endl;
	ifstream fin14;
	fin14.open("Text1.txt");
	fin14 >> noskipws;
	int ct1 = 0;
	while (!fin14.eof())
	{
		fin14 >> p[ct1];
		if (fin14.eof())
		{
			p[ct1 + 1] = '\0';
			break;
		}
		ct1++;
	}
	int d = 1, e = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
			e++;
		else if (p[i] == '.')
		{
			fout << "Words in Sentence " << d << " are : " << e + 1 << endl;
			fout << endl;
			d++;
			e = 0;
		}
	}
	fin14.close();
	Character c3;
	ifstream fin15;
	fin15.open("Text1.txt");
	fin15 >> noskipws;
	int ct3 = 0;
	while (!fin15.eof())
	{
		fin15 >> p[ct3];
		if (fin15.eof())
		{
			p[ct3 + 1] = '\0';
			break;
		}
		ct3++;
	}
	int x = 1, y = 1, z = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
		{
			fout << "Characters in Word no " << x << " of Sentence no " << y << " : " << z << endl;
			fout << endl;
			x++;
			z = 0;
		}
		else if (p[i] == '.')
		{
			fout << "Characters in Word no " << x << " of Sentence no " << y << " : " << z << endl;
			fout << endl;
			x++;
			y++;
			z = 0;
		}
		else
			z++;
	}
	fout << "Paragraph number: 2" << endl;
	fout << endl;
	Sentence s4;
	ifstream fin16;
	fin16.open("Text2.txt");
	fin16 >> s4;
	fin16.close();
	fout << "Sentences in Paragraph 2 are: " << s4.getCountSentence() << endl;
	fout << endl;
	Word w4;
	fout << "Words in Paragraph 2 are: " << w1.getCountWordP() << endl;
	fout << endl;
	ifstream fin17;
	fin17.open("Text2.txt");
	fin17 >> noskipws;
	int ct4 = 0;
	while (!fin17.eof())
	{
		fin17 >> p[ct4];
		if (fin17.eof())
		{
			p[ct4 + 1] = '\0';
			break;
		}
		ct4++;
	}
	int f = 1, g = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
			g++;
		else if (p[i] == '.')
		{
			fout << "Words in Sentence " << f << " are : " << g + 1 << endl;
			fout << endl;
			f++;
			g = 0;
		}
	}
	fin17.close();
	Character c4;
	ifstream fin18;
	fin18.open("Text2.txt");
	fin18 >> noskipws;
	int ct5 = 0;
	while (!fin18.eof())
	{
		fin18 >> p[ct5];
		if (fin18.eof())
		{
			p[ct5 + 1] = '\0';
			break;
		}
		ct5++;
	}
	int a = 1, b = 1, c = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';')
		{
			fout << "Characters in Word no " << a << " of Sentence no " << b << " : " << c << endl;
			fout << endl;
			a++;
			c = 0;
		}
		else if (p[i] == '.')
		{
			fout << "Characters in Word no " << a << " of Sentence no " << b << " : " << c << endl;
			fout << endl;
			a++;
			b++;
			c = 0;
		}
		else
			c++;
	}
	fout.close();

	return 0;
}