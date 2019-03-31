
#pragma once

class List;

class UserInterface
{
public:
	UserInterface(List &rList);
	~UserInterface();

protected:
	List& m_rList;

public:
	void printAdd();
	void printSearch();
	void printRemove();
	int printUI();
	void printAll();
	int run();
};

