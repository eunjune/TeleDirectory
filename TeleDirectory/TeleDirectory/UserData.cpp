#include "UserData.h"
#include "pch.h"

int UserData::count = 0;

UserData::UserData()
{
	count++;
}

UserData::UserData(const char * pName, const char * pPhone)
{
	mName = new String(pName);
	mPhone = new String(pPhone);
	count++;

}

UserData::~UserData()
{
	count--;
}

const char* UserData::getKey(void)
{
	return mName->GetString();
}

void UserData::printNode(void)
{
#ifdef _DEBUG
	cout << "[" << this << "] " << this->getNameStr() << "\t"
		<< this->getPhoneStr() << " [" << this->getNext() << "]"<<endl;
#else
	cout << this->getName().GetString() << "\t"
		<< this->getPhone().GetString() << endl;
#endif

}
