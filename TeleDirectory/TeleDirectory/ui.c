#include "ui.h"

int printUi()
{
	int num;
	char trash;

	printf("\n:");
	if (!scanf_s("%d%*c", &num))
	{
		while ((trash = getchar()) != '\n' && trash != EOF);
		return -1;
	}

	return num;
}

void printAdd(USERDATA **root)
{
	USERDATA *newNode = (USERDATA*)malloc(sizeof(USERDATA));
	newNode->pNext = NULL;
	printf("Input name : ");
	gets_s(newNode->szName, sizeof(newNode->szName));
	printf("Input phone number : ");
	gets_s(newNode->szPhone, sizeof(newNode->szPhone));

	if (addNode(root, newNode))
	{
		printf("입력완료");

	}
	else
	{
		printf("중복되는 이름이 있습니다.");
	}
}

void printSearch(USERDATA *root)
{
	USERDATA *searchNode;
	char name[32];

	printf("Input name : ");
	gets_s(name, sizeof(name));
	searchNode = search(root, name);
	if (searchNode == NULL) {
		printf("존재하지 않는 이름입니다.");
	}
	else
	{
		printf("[%p] %s\t%s [%p]", searchNode, searchNode->szName, searchNode->szPhone, searchNode->pNext);
	}
}

void printAll(USERDATA *head)
{
	USERDATA *curNode = head;

	if (curNode == NULL)
	{
		printf("없음.");
		return;
	}

	while (curNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n", curNode, curNode->szName, curNode->szPhone, curNode->pNext);
		curNode = curNode->pNext;
	}
}

void printRemove(USERDATA **root)
{
	char name[32];

	printf("Input name : ");
	gets_s(name, sizeof(name));
	if (removeNode(root, name))
	{
		printf("삭제완료");
	}
	else
	{
		printf("삭제오류");
	}
}

