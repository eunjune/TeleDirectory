#pragma once

#include "Node.h"

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

	void printAll();
	int removeNode(const char* pszKey);
};

