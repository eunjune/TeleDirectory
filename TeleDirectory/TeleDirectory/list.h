#pragma once

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA *pNext;
} USERDATA;

USERDATA* search(USERDATA *head, char *name);
int addNode(USERDATA **head, USERDATA *node);
void printAll(USERDATA *head);
int removeNode(USERDATA **head, char *name);