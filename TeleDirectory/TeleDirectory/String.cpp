//#include "pch.h"
//#include "String.h"
//
//// �⺻ ������
//String::String()
//	: m_pszData(nullptr)
//	, m_nLength(0)
//{
//}
//
//// ��ȯ ������
//String::String(const char* str)
//	:m_pszData(nullptr)
//	, m_nLength(0)
//{
//	SetString(str);
//}
//
//// ���� ������
//String::String(const String& other)
//{
//	this->SetString(other.GetString());
//}
//
//// �̵� ������
//String::String(String&& other)
//{
//	cout << "�̵� ������ ȣ��" << endl;
//
//	m_nLength = other.m_nLength;
//	m_pszData = other.m_pszData;
//
//	other.m_nLength = 0;
//	other.m_pszData = nullptr;
//}
//
//// �Ҹ���
//String::~String()
//{
//	this->Release();
//	m_nLength = 0;
//}
//
//// ���� ������
//String& String::operator=(const String& rhs)
//{
//	cout << "���� ������ ȣ��" << endl;
//	this->SetString(rhs.GetString());
//
//	return *this;
//}
//
//// �̵� ���� ������
//String& String::operator=(String&& rhs)
//{
//	cout << "�̵� ���� ������ ȣ��" << endl;
//	this->m_pszData = rhs.m_pszData;
//	this->m_nLength = rhs.m_nLength;
//
//	rhs.m_pszData = nullptr;
//	rhs.m_nLength = 0;
//
//	return *this;
//}
//
//String String::operator+(const String& rhs)
//{
//	String sum;
//	sum.SetString(this->GetString());
//	sum.Append(rhs.GetString());
//	return sum;
//
//}
//
//String operator+(const char *pszParam, const String &strParam)
//{
//	String sum;
//	sum.SetString(pszParam);
//	sum.Append(strParam);
//	return sum;
//}
//
//String& String::operator+=(const String& rhs)
//{
//	this->Append(rhs.GetString());
//	return *this;
//}
//
//char String::operator[](int nIndex) const
//{
//	assert(nIndex >= 0 && nIndex <= m_nLength);
//
//	return m_pszData[nIndex];
//}
//
//char& String::operator[](int nIndex)
//{
//	assert(nIndex >= 0 && nIndex <= m_nLength);
//
//	return m_pszData[nIndex];
//}
//
//int String::operator==(const String& rhs)
//{
//	if (m_pszData != NULL && rhs.m_pszData != NULL)
//		if (strcmp(m_pszData, rhs.m_pszData) == 0)
//			return 1;
//
//	return 0;
//}
//
//int String::operator!=(const String& rhs)
//{
//	if (m_pszData != NULL && rhs.m_pszData != NULL)
//		if (strcmp(m_pszData, rhs.m_pszData) == 0)
//			return 0;
//
//	return 1;
//}
//
//// setter
//int String::SetString(const char* pszParam)
//{
//
//	if (pszParam == nullptr)
//	{
//		return 0;
//	}
//
//	m_nLength = strlen(pszParam);
//
//	if (m_nLength == 0)
//	{
//		return 0;
//	}
//	this->Release();
//	m_pszData = new char[m_nLength + 1];
//	strcpy_s(m_pszData, m_nLength + 1, pszParam);
//
//	OnSetString(m_pszData, m_nLength);
//
//	return m_nLength;
//}
//
//// getter
//const char* String::GetString() const
//{
//	return m_pszData;
//}
//
//
//void String::Release()
//{
//	if (m_pszData != nullptr)
//	{
//		delete[] m_pszData;
//		m_pszData = nullptr;
//	}
//}
//
//
//int String::GetLength() const
//{
//	return m_nLength;
//}
//
//
//int String::Append(const char* pszParam)
//{
//	int nLenParam, nLenCur;
//	char *newPsz = nullptr;
//
//	if (pszParam == nullptr)
//	{
//		return 0;
//	}
//
//	nLenParam = strlen(pszParam);
//
//	if (nLenParam == 0)
//	{
//		return 0;
//	}
//
//	if (m_pszData == nullptr)
//	{
//		this->SetString(pszParam);
//
//		return m_nLength;
//	}
//
//	nLenCur = m_nLength;
//
//	newPsz = new char[nLenParam + nLenCur + 1];
//	strcpy_s(newPsz, nLenCur + 1, m_pszData);
//	strcpy_s(newPsz + nLenCur, nLenParam + 1, pszParam);
//
//	this->Release();
//	m_pszData = newPsz;
//	m_nLength = nLenCur + nLenParam;
//
//	return m_nLength;
//}
//
//void String::OnSetString(char *pszData, int nLength)
//{
//	// TODO: ���⿡ ���� �ڵ� �߰�.
//}
//
