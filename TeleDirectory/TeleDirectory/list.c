#include "list.h"
#include "file.h"

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

void releaseList(USERDATA **head)
{
	USERDATA *curNode = *head;
	USERDATA *deleteNode = NULL;

	while (curNode != NULL)
	{
		deleteNode = curNode;
		curNode = curNode->pNext;
		free(deleteNode);
	}

	*head = NULL;
}