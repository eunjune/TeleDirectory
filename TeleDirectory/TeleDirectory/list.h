#pragma once

#include "UserData.h"

class List
{
public:
	List();
	~List();


protected:
	void releaseList();
	UserData head;


public:
	char* searchNode(const char* name);
	int addNode(const char* name, const char* phone);

	void printAll();
	int removeNode(const char* name);
};

