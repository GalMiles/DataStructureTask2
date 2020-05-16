
#ifndef __List_H
#define __List_H


#include "ListNode.h"

class List {
public:
	ListNode* head;
	ListNode* tail;

private:
	List(ListNode* head);
	~List();
	void makeEmpty();
	bool isEmpty();
	void insertToTail();
	void insertAfter(ListNode* nodeToAddAfter);
	void deleteNode();
	void printList();
	
};
#endif

