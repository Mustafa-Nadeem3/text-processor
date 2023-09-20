#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Paragraph
{
private:
	char* para;
public:
	Paragraph();
	Paragraph(char*);
	void set_Paragraph(char*);
	char* get_Paragraph();
	friend istream& operator>>(istream&, Paragraph&); //insertion
	friend ostream& operator<<(ostream&, const Paragraph&);
	bool operator==(Paragraph&);
	bool find_Character();
	Paragraph operator+();
	Paragraph operator-();
	Paragraph operator+(const Paragraph&);
	bool find_PlainText();
	Paragraph operator+(int);
	Paragraph operator-(int);
	void check_Dictionary(const Paragraph&);
	bool check_Available(char*, char*);
};