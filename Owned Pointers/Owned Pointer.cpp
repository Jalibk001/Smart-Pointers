#include"String_buffer.h"
#include<iostream>
using namespace std;
StringBuffer::StringBuffer()
{
	_strbuf = NULL;
	_length = -1;
}
StringBuffer::~StringBuffer()
{
	_strbuf = NULL;
	delete[]this->_strbuf;
	_length = -1;
}
StringBuffer::StringBuffer(const StringBuffer& cp)
{
	_length = 0;
	_strbuf = NULL;
	delete[]this->_strbuf;
	_strbuf = new char[cp._length];
	_length = cp._length;
	_strbuf = cp._strbuf;
}
StringBuffer::StringBuffer(char* str, int size)
{
	_length = size;
	_strbuf = str;
	str = NULL;
	delete []str;
}
char StringBuffer::charAt(int a) const
{
	if (a < _length)
		return _strbuf[a];
	else
		cout << "Incorrect index" << endl;
}
int StringBuffer::length() const
{
	return _length;
}
void StringBuffer::reserve(int size)
{
	_strbuf = new char[size];
}
void StringBuffer::append(char c)
{
	char *tmp;
	tmp = new char[_length + 2];
	for (int i = 0; i < _length; i++)
	{
		tmp[i] = _strbuf[i];
	}
	_strbuf = NULL;
	delete[] this->_strbuf;
	_length += 1;
	tmp[_length - 1] = c;
	tmp[_length] = 0;
	_strbuf = tmp;
	tmp = NULL;
	delete[] tmp;
}
void main()
{
	char* hello = "hello";



	StringBuffer ss2(hello, 5);
	std::cout << "ss2 length = " << ss2.length() << std::endl;
	cout << hello << endl;
	//multiple references
	StringBuffer ss(ss2);
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

