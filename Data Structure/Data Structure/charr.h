#pragma once
#include"all.h"

class str
{
	char* ch;
	int length;
public:
	str();
	str(const char* c);
	~str() { delete []ch; }
	str& operator=(const char* ch);
	ostream& operator<<(ostream& os);
};

str::str()
{
	ch = new char;
	length = 0;
}

str::str(const char* c)
{
	int len = 0;
	while (c[len] != '\0')
	{
		len++;
	}
	ch = new char[len];
	for (int i = 0; i < len; i++)
		ch[i] = c[i];
}

str& str::operator=(const char* c)
{
	delete[] ch;
	int len = 0;
	while (c[len] != '\n')
		len++;

}