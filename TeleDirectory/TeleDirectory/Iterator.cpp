#include "Iterator.h"
#include "pch.h"

Iterator::Iterator()
	:m_pHead(nullptr),m_pCurrent(nullptr)
{
}


Iterator::~Iterator()
{
}


void Iterator::moveNext()
{
	if (m_pCurrent != nullptr)
	{
		m_pCurrent = m_pCurrent->getNext();
	}
}
