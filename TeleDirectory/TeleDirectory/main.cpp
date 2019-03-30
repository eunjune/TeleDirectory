#include "pch.h"
#include "List.h"
#include "UserInterface.h"

int main(void)
{
	List db;

	UserInterface ui(db);
	ui.run();

	return 0;
}