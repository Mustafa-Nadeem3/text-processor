#include "Paragraph.h"

Paragraph::Paragraph()
{
	para = new char[150];
	para[0] = '\0';
}

Paragraph::Paragraph(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
		ct++;
	para = new char[ct + 1];
	for (int i = 0; i < ct; i++)
		para[i] = p[i];
	para[ct] = '\0';
}

void Paragraph::set_Paragraph(char* p)
{
	int ct = 0;
	for (int i = 0; p[i] != '\0'; i++)
		ct++;
	para = new char[ct + 1];
	for (int i = 0; i < ct; i++)
		para[i] = p[i];
	para[ct] = '\0';
}

char* Paragraph::get_Paragraph()
{
	return para;
}

istream& operator>>(istream& in, Paragraph& obj)
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
			p[ct] = '\0';
			break;
		}
		ct++;
	}
	obj.set_Paragraph(p);
	return in;
}

ostream& operator<<(ostream& out, const Paragraph& obj)
{
	out << obj.para << endl;

	return out;
}

bool Paragraph::operator==(Paragraph& obj)
{
	int ct1 = 0, ct2 = 0;
	for (int i = 0; obj.para[i] != '\0'; i++)
	{
		if (this->para[i] == obj.para[i])
			ct1++;
		else if (this->para[i] != obj.para[i])
			ct2++;
	}

	if (ct1 > ct2)
		return true;
	else if (ct1 < ct2)
		return false;
}

bool Paragraph::find_Character()
{
	int ct1 = 0, ct2 = 0;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] >= 'a' && this->para[i] <= 'z')
			ct1++;
		else if (this->para[i] >= 'A' && this->para[i] <= 'Z')
			ct2++;
	}

	if (ct1 > ct2)
		return true;
	else if (ct1 < ct2)
		return false;
}

Paragraph Paragraph::operator+()
{
	cout << "CONVERTING UPPERCASE TO LOWERCASE..." << endl;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] >= 'A' && this->para[i] <= 'Z')
			this->para[i] = this->para[i] + 32;
		else
			this->para[i] = this->para[i];
	}
	return *this;
}

Paragraph Paragraph::operator-()
{
	cout << "CONVERTING LOWERCASE TO UPPERCASE..." << endl;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] >= 'a' && this->para[i] <= 'z')
			this->para[i] = this->para[i] - 32;
		else 
			this->para[i] = this->para[i];
	}
	return *this;
}

Paragraph Paragraph::operator+(const Paragraph& obj)
{
	int ct = 0;
	Paragraph temp;
	temp.para = new char[300];
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		temp.para[ct] = this->para[i];
		ct++;
	}
	for (int j = 0; obj.para[j] != '\0'; j++)
	{
		temp.para[ct] = obj.para[j];
		ct++;
	}
	temp.para[ct] = '\0';
	return temp;
}

bool Paragraph::find_PlainText()
{
	int ct = 0;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] == ' ' || this->para[i] == '.' || this->para[i] == '?' || this->para[i] == '!' || this->para[i] == ',' || this->para[i] == ';')
			ct++;
	}
	if (ct > 0)
		return true;
	else if (ct == 0)
		return false;
}

Paragraph Paragraph::operator+(int x)
{
	cout << "Encrypting the Paragraph..." << endl;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] == 'Z' || this->para[i] == 'z')
		{
			this->para[i] = this->para[i] - (24 + x);
		}
		this->para[i] = this->para[i] + x;
	}
	return *this;
}

Paragraph Paragraph::operator-(int x)
{
	cout << "Decrypting the Paragraph..." << endl;
	for (int i = 0; this->para[i] != '\0'; i++)
	{
		if (this->para[i] == 'Z' || this->para[i] == 'z')
		{
			this->para[i] = this->para[i] + (24 - x);
		}
		this->para[i] = this->para[i] - x;
	}
	return *this;
}

void Paragraph::check_Dictionary(const Paragraph& obj)
{
	int x = 0;
	char ch[10];
	for (int i = 0; obj.para[i] != '\0'; i++)
	{
		ch[x] = obj.para[i];
		x++;
		if (obj.para[i] == ' ' || obj.para[i] == '.' || obj.para[i] == '?' || obj.para[i] == '!' || obj.para[i] == ',' || obj.para[i] == ';')
		{
			ch[x] = '\0';
			if (check_Available(ch, this->para))
			{
				for (int j = 0; ch[j] != '\0'; j++)
					cout << ch[j];
				cout << endl;
				x = 0;
			}
			else
			{
				x = 0;
			}
		}
	}
}

bool Paragraph::check_Available(char* x, char* y)
{
	int z = 0;
	for (int i = 0; y[i] != '\0'; i++)
	{
		if (x[z] == y[i])
		{
			if (x[z + 1] == y[i + 1])
			{
				if (x[z + 2] == y[i + 2])
				{
					if (x[z + 3] == y[i + 3])
					{
						return false;
					}
					else if (x[z + 3] == '\0' && y[i + 3] == '\0')
					{
						return false;
					}
					else
						return true;
				}
				else if (x[z + 2] == '\0' && y[i + 2] == '\0')
				{
					return false;
				}
				else
					return true;
			}
			else if (x[z + 1] == '\0' && y[i + 1] == '\0')
			{
				return false;
			}
			else
				return true;
		}
	}
}