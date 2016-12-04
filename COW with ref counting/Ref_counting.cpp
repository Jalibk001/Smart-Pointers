#include"String_Buffer.h"
#include"String.h"
#include<iostream>
using namespace std;
String::String()
{
	this->_str = new StringBuffer;
}
String::~String()
{
	this->_str->_refcount--;
	if (this->_str->_refcount == 0)
	{
		delete []this->_str;
	}
}
String::String(const String& cp)
{
	this->_str = cp._str;
	++this->_str->_refcount;
}
String::String(char* str, int size)
{
	this->_str = new StringBuffer(str, size);
	str = NULL;
	delete str;
	this->_str->_refcount = 1;
}
char String::charAt(int a) const
{
	if (this->_str->length() > a)
		return this->_str->charAt(a);
	return -1;
}
int String::length() const
{
	return this->_str->length();
}
void String::append(char c)
{
	this->_str->append(c);
}
void main()
{
	char* hello = "hello";


	
	String ss2(hello, 5);
	std::cout << "ss2 length = " << ss2.length() << std::endl;
	cout << hello << endl;
	//multiple references
	String ss(ss2);
	cout << hello << endl;
	//output statements
	std::cout << "ss length = " << ss.length() << std::endl;
	std::cout << "new ss charAt 0 = " << ss.charAt(0) << std::endl;

	//append a character
	ss2.append('w');

	//cout<<hello<<endl;
	//hello = "bye";

	std::cout << "new ss length = " << ss.length() << std::endl;
	std::cout << "new ss2 length = " << ss2.length() << std::endl;
	system("pause");
}

