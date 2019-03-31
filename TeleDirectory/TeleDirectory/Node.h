#pragma once
class Node
{
	friend class List;
public:
	Node();
	virtual ~Node();
	
	Node* getNext() const { return next; };

	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

private:
	Node* next;

};

