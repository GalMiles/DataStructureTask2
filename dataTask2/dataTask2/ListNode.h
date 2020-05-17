#ifndef __ListNode_H
#define __ListNode_H

#include <iostream>
#include "Student.h"
#pragma warning(disable: 4996)

using namespace std;


class ListNode {
private:
	Student* data;
	ListNode* next;

public:
	ListNode(Student* data, ListNode* next);
	~ListNode();
	ListNode(const ListNode& cpy);
	Student* getData();
	ListNode* getNext();
	void setData(Student* data);
	void setNext(ListNode* next);
	void insertAfterMe(ListNode* nodeToAdd);
	void operator=(const ListNode& other);
	void printNode();

};

#endif
