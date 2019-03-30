#include "pch.h"

#pragma once

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA *pNext;
} USERDATA;

int loadData(USERDATA **head);
int saveData(USERDATA* head);
