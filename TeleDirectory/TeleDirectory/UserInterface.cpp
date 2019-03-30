#include "UserInterface.h"
#include "List.h"
#include "pch.h"


UserInterface::UserInterface(List &pList)
	:list(pList)
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
	printf("Input name : ");
	gets_s(name, sizeof(name));
	printf("Input phone number : ");
	gets_s(phone, sizeof(phone));

	if (list.addNode(name, phone))
	{
		printf("입력완료");

	}
	else
	{
		printf("중복되는 이름이 있습니다.");
	}
}


void UserInterface::printSearch()
{
	UserData *searchNode;
	char name[32];

	cin.ignore();
	printf("Input name : ");
	gets_s(name, sizeof(name));
	searchNode = list.searchNode(name);
	if (searchNode == nullptr) {
		printf("존재하지 않는 이름입니다.");
	}
	else
	{
		printf("[%p] %s\t%s [%p]", searchNode, searchNode->getName()
			, searchNode->getPhone(), searchNode->getNext());
	}
}


void UserInterface::printRemove()
{
	char name[32];

	cin.ignore();
	printf("Input name : ");
	gets_s(name, sizeof(name));
	if (list.removeNode(name))
	{
		printf("삭제완료");
	}
	else
	{
		printf("삭제오류");
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

	printf("\n:");
	cin >> num;
	
	if ((num < 1 || num > 4))
	{
		cin.clear();
		cin.ignore(LLONG_MAX, '\n');
		return -1;
	}

	return num;
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
			list.printAll();
			break;
		case 4:
			printRemove();
			break;
		default:
			printf("해당하는 메뉴가 존재하지 않음");
			break;
		}

	}
	return 0;
}
