#include "list.h"

int getData(USERDATA **head)
{
	FILE * fp = NULL;
	USERDATA *data=NULL;
	int length = 0;

	fopen_s(&fp,"list.dat", "rb");
	if (fp == NULL)
	{
		return 0;
	}

	while (!feof(fp))
	{
		data = (USERDATA*)malloc(sizeof(USERDATA));
		
		if (fread(data, sizeof(USERDATA), 1, fp) == 0)
		{
			fclose(fp);
			free(data);
			return length;
		}
		data->pNext = NULL;
		if (length==0)
		{
			*head = data;
		}
		else
		{
			if (!addNode(head, data))
			{
				printf("파일 읽기 중 오류\n");
				fclose(fp);
				return 0;
			}
		}
		length++;
	}
}

int saveData(USERDATA* head)
{
	FILE * fp = NULL;
	USERDATA* curNode = head;

	fopen_s(&fp,"list.dat", "wb");
	if (fp == NULL)
	{
		puts("ERROR : Failed to open file!");
		return 0;
	}
	while (curNode != NULL)
	{
		fwrite(curNode, sizeof(USERDATA), 1, fp);
		curNode = curNode->pNext;
	}
		
	fclose(fp);

	return 1;
}

int removeData(USERDATA* data)
{
	FILE * fp = NULL;

	fopen_s(&fp, "list.dat", "ab");
	if (fp == NULL)
	{
		puts("ERROR : Failed to open file!");
		return 0;
	}

	while (!feof(fp))
	{
		data = (USERDATA*)malloc(sizeof(USERDATA));
		if (fread(data, sizeof(USERDATA), 1, fp) == 0)
		{
			fclose(fp);
			return 0;
		}



	}
	fclose(fp);

	return 1;
}