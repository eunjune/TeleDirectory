#pragma once
class String
{

public:
	String();
	explicit String(const char* str);
	String(const String& other);
	String(String &&rhs);
	~String();
	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	String operator+(const String& rhs);
	friend String operator+(const char *pszParam, const String &strParam);
	String& operator+=(const String& rhs);
	char operator[](int nIndex) const;
	char& operator[](int nIndex);
	int operator==(const String& rhs);
	int operator!=(const String& rhs);
	operator char*(void) const { return m_pszData; }
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int GetLength() const;
	int Append(const char* pszParam);
	virtual void OnSetString(char *pszData, int nLength);
};

