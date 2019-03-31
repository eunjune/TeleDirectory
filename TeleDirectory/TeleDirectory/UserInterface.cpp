#include "UserInterface.h"
#include "List.h"
#include "pch.h"
#include "UserData.h"


UserInterface::UserInterface(List &rList)
	:m_rList(rList)
{
	

}


UserInterface::~UserInterface()
{
}


void UserInterface::printAdd()
{
	char name[32];
	char phone[32];

	cin.ignore();
	cout << "Input name : ";
	gets_s(name, sizeof(name));
	cout << "Input phone number : ";
	gets_s(phone, sizeof(phone));

	if (m_rList.addNode(new UserData(name, phone)))
	{
		cout << "입력완료";
	}
	else
	{
		cout << "중복되는 이름이 있습니다.";
	}
}


void UserInterface::printSearch()
{
	Node *searchNode;
	char name[32];

	cin.ignore();
	cout << "Input name : ";
	gets_s(name, sizeof(name));
	searchNode = m_rList.searchNode(name);
	if (searchNode == nullptr) {
		cout << "존재하지 않는 이름입니다.";
	}
	else
	{
		searchNode->printNode();
	}
}


void UserInterface::printRemove()
{
	char name[32];

	cin.ignore();
	cout << "Input name : ";
	gets_s(name, sizeof(name));
	if (m_rList.removeNode(name))
	{
		cout<< "삭제완료";
	}
	else
	{
		cout<<"삭제오류";
	}
}


/*
1~4,0 => OK
1234 => fail, 버퍼비우면 안됨.
abcd => fail, 버퍼비우기
123abc => fail, 버퍼 비워야 됨.
*/
int UserInterface::printUI()
{
	int num;
	string trash;

	cout << "\n:";
	cin >> num;
	
	if ((num < 0 || num > 4) || cin.fail())
	{
		cin.clear();
		cin.ignore(LLONG_MAX, '\n');
		return -1;
	}

	return num;
}

void UserInterface::printAll()
{
	Iterator it = m_rList.makeIterator();
	UserData *pNode = nullptr;

	while ((pNode = static_cast<UserData*>(it.getCurrent())) != nullptr)
	{
		pNode->printNode();
		it.moveNext();
	}


}

int UserInterface::run()
{
	int num;

	cout << "[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit";

	while ((num = printUI()) != 0)
	{
		switch (num)
		{
		case 1:
			printAdd();
			break;
		case 2:
			printSearch();
			break;
		case 3:
			printAll();
			break;
		case 4:
			printRemove();
			break;
		default:
			cout << "해당하는 메뉴가 존재하지 않음";
			break;
		}

	}
	return 0;
}
