#pragma once
#include "String.h"
class StringEx :
	public String
{
public:
	StringEx();
	StringEx(const char* str);
	~StringEx();
private:

public:
	void OnSetString(char* pszParam, int nLength);
	int Find(const char* pszParam);

};

class StringEx :
	public String
{
public:
	StringEx();
	StringEx(const char* str);
	~StringEx();
private:

public:
	void OnSetString(char* pszParam, int nLength);
	int Find(const char* pszParam);

};

