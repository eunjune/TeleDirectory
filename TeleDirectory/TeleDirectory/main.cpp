#include "pch.h"
#include "List.h"
#include "UserData.h"
#include "UserInterface.h"

int main(void)
{
	List db(new UserData);
	UserInterface ui(db);
	ui.run();

	return 0;
}