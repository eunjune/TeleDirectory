#pragma once

class List;

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

protected:
	List& list;

public:
	void printAdd();
	void printSearch();
	void printRemove();
	int printUI();
	int run();
};

