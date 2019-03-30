#include "UserData.h"
#include "pch.h"

int UserData::count = 0;

UserData::UserData()
	:next(nullptr)
{

	memset(name, 0, sizeof(name));
	memset(phone, 0, sizeof(phone));
	count++;
}

UserData::~UserData()
{
	count--;
}
