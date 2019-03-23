#include "list.h"


USERDATA* search(USERDATA *head, char *name)
{
	USERDATA *curNode = head;

	while (curNode != NULL)
	{
		if (strcmp(curNode->szName, name) == 0)
		{

			return curNode;

		}
		curNode = curNode->pNext;
	}


	return NULL;
}

int addNode(USERDATA **head, USERDATA *node)
{
	USERDATA *curNode = *head;

	if (search(*head, node->szName))
	{
		return 0;
	}

	if (curNode == NULL)
	{
		(*head) = node;
	}

	else
	{
		while (curNode->pNext != NULL)
		{
			curNode = curNode->pNext;

		}

		curNode->pNext = node;
	}

	return 1;

}



void printAll(USERDATA *head)
{
	USERDATA *curNode = head;

	if (curNode == NULL)
	{
		printf("¾øÀ½.\n");
		return;
	}

	while (curNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n", curNode, curNode->szName, curNode->szPhone, curNode->pNext);
		curNode = curNode->pNext;
	}
}

int removeNode(USERDATA **head, char *name)
{
	USERDATA *preNode = NULL;
	USERDATA *curNode = *head;
	USERDATA *removeNode = NULL;

	while (curNode != NULL)
	{
		if (strcmp(curNode->szName, name) == 0)
		{
			if (preNode == NULL)
			{
				(*head) = curNode->pNext;
			}
			else
			{
				preNode->pNext = curNode->pNext;
			}

			free(curNode);
			return 1;
		}
		preNode = curNode;
		curNode = curNode->pNext;
	}

	return 0;
}