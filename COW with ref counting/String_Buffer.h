#pragma once
#ifndef STRINGBUFFER_H
#define	STRINGBUFFER_H
#include<iostream>
using namespace std;
class StringBuffer {
public:
	StringBuffer() 
	{
		_strbuf = NULL;
		_length = -1;
	}/*
	~StringBuffer()
	{
		delete[]_strbuf;
		_length = -1;
	}*/
	StringBuffer(const StringBuffer& cp)
	{
		_length = cp._length;
		_strbuf = cp._strbuf;
	}
	StringBuffer(char* str, int size)
	{
		_length = size;
		_strbuf = str;
		str = NULL;
		delete[]str;
	}
	char charAt(int a) const
	{
		if (a < _length)
			return _strbuf[a];
		return -1;
	}
	int length() const
	{
		return _length;
	}
	void reserve(int size)
	{
		_strbuf = new char[size];
	}
	void append(char c)
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
	int _refcount;
private:
	char* _strbuf;
	int _length;

};

#endif	/* STRINGBUFFER_H */

