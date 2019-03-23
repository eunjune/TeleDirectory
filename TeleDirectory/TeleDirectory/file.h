#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA *pNext;
} USERDATA;

int getData(USERDATA **head);
int saveData(USERDATA* head);