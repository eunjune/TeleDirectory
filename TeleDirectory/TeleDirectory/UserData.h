#pragma once
#include "Node.h"
#include "String.h"

class UserData : public Node
{
public:
	UserData();
	UserData(const char* pName, const char* pPhone);
	~UserData();

protected:
	String *mName;
	String *mPhone;

	static int count;
public:
	const char* getNameStr() const { return mName->GetString(); };
	String* getName() const { return mName; };
	const char* getPhoneStr() const { return mPhone->GetString(); };
	String* getPhone() const { return mPhone; };

	static int getCount() { return count; }

	virtual const char* getKey(void);
	virtual void printNode(void);
};

