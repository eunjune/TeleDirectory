#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main(void)
{
	int num;
	USERDATA *newNode, *root = NULL, *searchNode;
	char name[32], trash;

	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");
	while (1)
	{

		if (scanf_s("%d%*c", &num))
		{
			switch (num)
			{
			case 1:
				newNode = (USERDATA*)malloc(sizeof(USERDATA));
				newNode->pNext = NULL;
				printf("Input name : ");
				gets_s(newNode->szName, sizeof(newNode->szName));
				printf("Input phone number : ");
				gets_s(newNode->szPhone, sizeof(newNode->szPhone));
				if (addNode(&root, newNode))
				{
					printf("입력완료\n:");

				}
				else
				{
					printf("중복되는 이름이 있습니다.\n:");
				}
				break;
			case 2:
				printf("Input name : ");
				gets_s(name, sizeof(name));
				searchNode = search(root, name);
				if (searchNode == NULL) {
					printf("존재하지 않는 이름입니다.\n:");
				}
				else
				{
					printf("[%p] %s\t%s [%p]\n:", searchNode, searchNode->szName, searchNode->szPhone, searchNode->pNext);
				}
				break;
			case 3:
				printAll(root);
				printf(":");
				break;
			case 4:
				printf("Input name : ");
				gets_s(name, sizeof(name));
				if (removeNode(&root, name))
				{
					printf("삭제완료\n:");
				}
				else
				{
					printf("삭제오류\n:");
				}
				break;
			case 0:
				return 0;
			default:
				printf("해당하는 메뉴가 존재하지 않음\n:");
				break;
			}
		}
		else
		{
			printf("정수가 아닙니다.\n:");
			while ((trash = getchar()) != '\n' && trash != EOF);
		}

	}
}