#include "List.h"
#include "UserData.h"
#include "pch.h"

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
			UserData *data = new UserData;
			fin.read(reinterpret_cast<char*>(data), sizeof(UserData));
			data->next = nullptr;
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
	UserData *curNode = static_cast<UserData*>(m_pHead->next);

	if (fout.is_open())
	{
		while (curNode != nullptr)
		{
			fout.write(reinterpret_cast<char*>(curNode), sizeof(UserData));
			curNode = static_cast<UserData*>(curNode->next);
		}
	}

	releaseList();
}


void List::releaseList()
{
	Node *curNode = m_pHead->next;
	Node *deleteNode = nullptr;

	while (curNode != nullptr)
	{
		deleteNode = curNode;
		curNode = curNode->next;
		delete deleteNode;
	}
	m_pHead->next = nullptr;
}


Node* List::searchNode(const char* pszKey)
{
	Node *curNode = m_pHead->next;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->getKey(), pszKey) == 0)
		{
			return curNode;
		}
		curNode = curNode->next;
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

	pNode->next = m_pHead->next;
	m_pHead -> next = pNode;

	return 1;
}


void List::printAll()
{
	Node *curNode = m_pHead->next;

	if (curNode == NULL)
	{
		printf("없음.");
		return;
	}

	while (curNode != NULL)
	{
		curNode->printNode();
		curNode = curNode->next;
	}

}


int List::removeNode(const char* pszKey)
{
	Node *preNode = m_pHead;
	Node *curNode = m_pHead->next;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->getKey(), pszKey) == 0)
		{
			preNode->next = curNode->next;

			delete curNode;
			return 1;
		}
		preNode = curNode;
		curNode = curNode->next;
	}
	return 0;
}
