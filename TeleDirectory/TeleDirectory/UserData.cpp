#include "UserData.h"
#include "pch.h"

int UserData::count = 0;

UserData::UserData()
	
{
	memset(name, 0, sizeof(name));
	memset(phone, 0, sizeof(phone));
	count++;
}

UserData::UserData(const char * pName, const char * pPhone)
{
	strcpy_s(name, strlen(pName) + 1, pName);
	strcpy_s(phone, strlen(pPhone) + 1, pPhone);
	count++;

}

UserData::~UserData()
{
	count--;
}

const char* UserData::getKey(void)
{
	return name;
}

void UserData::printNode(void)
{
	cout << "[" << this << "] " << this->getName() << "\t"
		<< this->getPhone() << " [" << this->getNext() << "]\n";
}
