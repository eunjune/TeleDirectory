#pragma once
#include "Node.h"

class UserData : public Node
{
public:
	UserData();
	UserData(const char* pName, const char* pPhone);
	~UserData();

protected:
	char name[32];
	char phone[32];

	static int count;
public:
	const char* getName() const { return name; };
	const char* getPhone() const { return phone; };

	static int getCount() { return count; }

	virtual const char* getKey(void);
	virtual void printNode(void);
};

