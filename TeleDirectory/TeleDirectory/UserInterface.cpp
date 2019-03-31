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
		cout << "�Է¿Ϸ�";
	}
	else
	{
		cout << "�ߺ��Ǵ� �̸��� �ֽ��ϴ�.";
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
		cout << "�������� �ʴ� �̸��Դϴ�.";
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
		cout<< "�����Ϸ�";
	}
	else
	{
		cout<<"��������";
	}
}


/*
1~4,0 => OK
1234 => fail, ���ۺ��� �ȵ�.
abcd => fail, ���ۺ���
123abc => fail, ���� ����� ��.
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
			cout << "�ش��ϴ� �޴��� �������� ����";
			break;
		}

	}
	return 0;
}
