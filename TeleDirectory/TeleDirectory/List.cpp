#include "List.h"
#include "pch.h"


List::List()
{
	ifstream fin("list.dat",ios_base::in | ios_base::binary);
	
	if (fin.is_open())
	{

		while (!fin.eof())
		{
			UserData data;
			fin.read((char*)&data, sizeof(UserData));
			if (fin && !addNode(data.getName(), data.getPhone()))
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
	UserData *curNode = head.next;

	if (fout.is_open())
	{
		while (curNode != nullptr)
		{
			fout.write((char*)curNode, sizeof(*curNode));
			curNode = curNode->next;
		}
	}

	releaseList();
}


void List::releaseList()
{
	UserData *curNode = head.next;
	UserData *deleteNode = nullptr;

	while (curNode != nullptr)
	{
		deleteNode = curNode;
		curNode = curNode->next;
		free(deleteNode);
	}
	head.next = nullptr;
}


UserData* List::searchNode(const char* name)
{
	UserData *curNode = head.next;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->name, name) == 0)
		{

			return curNode;

		}
		curNode = curNode->next;
	}

	return nullptr;
}


int List::addNode(const char* name, const char* phone)
{
	UserData *newNode = nullptr;


	if (searchNode(name))
	{
		return 0;
	}

	newNode = new UserData;

	strcpy_s(newNode->name, strlen(name) + 1, name);
	strcpy_s(newNode->phone, strlen(phone) + 1, phone);

	newNode->next = head.next;
	head.next = newNode;

	return 1;
}


void List::printAll()
{
	UserData *curNode = head.next;

	if (curNode == NULL)
	{
		printf("없음.");
		return;
	}

	while (curNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n", curNode, curNode->name, curNode->phone, curNode->next);
		curNode = curNode->next;
	}

}


int List::removeNode(const char* name)
{
	UserData *preNode = &head;
	UserData *curNode = head.next;

	while (curNode != nullptr)
	{
		if (strcmp(curNode->name, name) == 0)
		{
			
			preNode->next = curNode->next;

			free(curNode);
			return 1;
		}
		preNode = curNode;
		curNode = curNode->next;
	}


	return 0;
}
