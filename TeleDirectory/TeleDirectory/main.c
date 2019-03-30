#include "ui.h"

int main(void)
{
	int num;
	USERDATA *root;
	
	char trash;
	
	if (!loadData(&root)) {
		root = NULL;
	}

	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit");

	while ((num = printUi()) != 0)
	{
		
		switch (num)
			{
			case 1:
				printAdd(&root);
				break;
			case 2:
				printSearch(root);
				break;
			case 3:
				printAll(root);
				break;
			case 4:
				printRemove(&root);
				break;
			default:
				printf("�ش��ϴ� �޴��� �������� ����");
				break;
			}

	}

	if (!saveData(root))
	{
		printf("�������\n:");
	}
	releaseList(&root);
	return 0;
}