#pragma once
class UserData
{
	friend class List;
public:
	UserData();
	~UserData();

protected:
	char name[32];
	char phone[32];
	UserData* next;

	static int count;
public:
	const char* getName() const { return name; };
	const char* getPhone() const { return phone; };
	const UserData* getNext() const { return next; };

	static int getCount() { return count; }
};

