#pragma once
#include "String.h"

class Node
{
	friend class List;
public:
	Node();
	virtual ~Node();
	
	Node* getNext() const { return m_pNext; };

	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

private:
	Node* m_pNext;

};

