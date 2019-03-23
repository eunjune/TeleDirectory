
#include "file.h"

#pragma once

USERDATA* search(USERDATA *head, char *name);
int addNode(USERDATA **head, USERDATA *node);
void printAll(USERDATA *head);
int removeNode(USERDATA **head, char *name);