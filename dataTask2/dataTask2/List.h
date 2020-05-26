
#ifndef __List_H
#define __List_H


#include "ListNode.h"

class List {
private:
	ListNode* head;
	ListNode* tail;

public:
	List();
	~List();
	List(const List& cpy);
	List(const List&& cpy);
	void makeEmpty();
	bool isEmpty();
	void insertToTail(ListNode* nodeToAdd);
	void insertAfter(ListNode* nodeToAddAfter, ListNode* nodeToAdd);
	void deleteAfterNode(ListNode* nodeToDeleteAfter);
	void printList();
	ListNode* getHead() const;
	ListNode* getTail() const;
	void setTail(ListNode* tail);
	void setHead(ListNode* head);
	
};
#endif

