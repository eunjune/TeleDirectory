#pragma once
#include "Node.h"

class Iterator
{
	friend class List;
public:
	Iterator();
	~Iterator();

private:
	Node* m_pHead;
	Node* m_pCurrent;
public:
	Node* getCurrent() const { return m_pCurrent; }

	void moveNext();
};

