//#include "pch.h"
//#include "StringEx.h"
//
//
//StringEx::StringEx()
//{
//}
//
//StringEx::StringEx(const char* str) : String(str)
//{
//
//}
//
//StringEx::~StringEx()
//{
//}
//
//void StringEx::OnSetString(char* pszParam, int nLength)
//{
//	if (strcmp(pszParam, "�۸��̾Ƶ�") == 0)
//	{
//		strcpy_s(pszParam, sizeof(char)*(nLength + 1), "*���ѾƵ�*");
//	}
//}
//
//int StringEx::Find(const char* pszParam)
//{
//	int index;
//
//	if (pszParam == nullptr)
//		return NULL;
//
//	index = strstr(GetString(), pszParam) - GetString();
//	return index;
//}
//
//
//
