#pragma once

#include "Node.h"
#include "Iterator.h"

class Node;

class List
{
public:
	List(Node *pHead);
	~List();


protected:
	void releaseList();
	Node *m_pHead;

public:
	Node* searchNode(const char* pszKey);
	int addNode(Node *pNode);

	int removeNode(const char* pszKey);
	Iterator makeIterator();
	virtual int OnAddNewNode(Node *pNode);
};

