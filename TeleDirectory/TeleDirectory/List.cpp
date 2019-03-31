#include "List.h"
#include "UserData.h"
#include "pch.h"

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

} USERDATA;

List::List(Node * pHead)
{
	m_pHead = pHead;

	ifstream fin("list.dat", ios_base::in | ios_base::binary);

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			/*
				리컴파일하면 동적 바인딩이 안됨.
				왜냐하면 가상함수 테이블 주소도 파일로 저장되는데 다시 컴파일하면
				함수 위치 주소도 다시 바뀌기 땜에 이전에 썼던 주소를 받아와도 함수 인식을 못함.
			*/
			USERDATA buffer;

			fin.read(reinterpret_cast<char*>(&buffer), sizeof(USERDATA));
			
			UserData *data = new UserData(buffer.szName, buffer.szPhone);
			data->m_pNext = nullptr;
			if (fin && !addNode(data))
			{
				cout << "파일 읽기 오류" << endl;
				fin.close();
			}
		}
	}
	fin.close();
}

List::~List()
{
	ofstream fout("list.dat",ios_base::out | ios_base::binary);
	UserData *curNode = static_cast<UserData*>(m_pHead->m_pNext);

	if (fout.is_open())
	{
		while (curNode != nullptr)
		{
			USERDATA buffer;
			strcpy_s(buffer.szName, curNode->getName()->GetLength()+1,curNode->getNameStr());
			strcpy_s(buffer.szPhone, curNode->getName()->GetLength()+1,curNode->getPhoneStr());
			fout.write(reinterpret_cast<char*>(&buffer), sizeof(USERDATA));
			curNode = static_cast<UserData*>(curNode->m_pNext);
		}
	}

	releaseList();
}


void List::releaseList()
{
	Node *curNode = m_pHead->m_pNext;
	Node *deleteNode = nullptr;

	while (curNode != nullptr)
	{
		deleteNode = curNode;
		curNode = curNode->m_pNext;
		delete deleteNode;
	}
	m_pHead->m_pNext = nullptr;
}


Node* List::searchNode(const char* pszKey)
{
	Node *curNode = m_pHead->m_pNext;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->getKey(), pszKey) == 0)
		{
			return curNode;
		}
		curNode = curNode->m_pNext;
	}

	return nullptr;
}


int List::addNode(Node *pNode)
{

	if (searchNode(pNode->getKey()))
	{
		delete pNode;

		return 0;
	}

	if (OnAddNewNode(pNode))
	{
		pNode->m_pNext = m_pHead->m_pNext;
		m_pHead -> m_pNext = pNode;
	}

	return 1;
}





int List::removeNode(const char* pszKey)
{
	Node *preNode = m_pHead;
	Node *curNode = m_pHead->m_pNext;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->getKey(), pszKey) == 0)
		{
			preNode->m_pNext = curNode->m_pNext;

			delete curNode;
			return 1;
		}
		preNode = curNode;
		curNode = curNode->m_pNext;
	}
	return 0;
}


Iterator List::makeIterator()
{
	Iterator it;
	it.m_pCurrent = m_pHead->m_pNext;
	it.m_pCurrent = m_pHead->m_pNext;

	return it;
}

int List::OnAddNewNode(Node *pNode)
{
	return 1;
}
