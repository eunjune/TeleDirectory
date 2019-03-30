#include "file.h"

#pragma once

USERDATA* search(USERDATA *head, char *name);
int addNode(USERDATA **head, USERDATA *node);
int removeNode(USERDATA **head, char *name);
void releaseList(USERDATA **head);
