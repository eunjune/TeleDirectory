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
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int GetLength() const;
	int Append(const char* pszParam);
	virtual void OnSetString(char *pszData, int nLength);
};

