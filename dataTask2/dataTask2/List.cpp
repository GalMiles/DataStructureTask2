#include "List.h"


List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
}

List::~List()
{
	
}

void List::makeEmpty()
{
	ListNode* next = nullptr;
	ListNode* curr = this->head;

	while (curr)
	{
		if(curr->getNext() != nullptr)
			next = curr->getNext();
		delete curr;
		curr = next;
	}
	this->head = nullptr;
}

bool List::isEmpty()
{
	if (this->head == nullptr)
	{
		return true;
	}
	return false;
}

void List::insertToTail(ListNode * nodeToAdd)
{
	this->tail->setNext(nodeToAdd);
	this->tail = nodeToAdd;
}

void List::insertToHead(ListNode* nodeToAdd)
{
	nodeToAdd->setNext(this->head);
	this->head = nodeToAdd;
}

void List::insertAfter(ListNode* nodeToAddAfter, ListNode* nodeToAdd)
{
	ListNode* next;
	if (nodeToAddAfter == this->tail)
		insertToTail(nodeToAdd);
	else
	{
		next = nodeToAddAfter->getNext();
		nodeToAddAfter->setNext(nodeToAdd);
		nodeToAdd->setNext(next);
	}
}

void List::deleteAfterNode(ListNode* nodeToDeleteAfter)
{
	ListNode* tempNext = nodeToDeleteAfter->getNext();
	ListNode* toDelete = tempNext;
	if (tempNext == this->tail)
	{
		delete tempNext;
		nodeToDeleteAfter->setNext(nullptr);
		this->tail = nodeToDeleteAfter;
	}
	else
	{
		tempNext = tempNext->getNext();
		delete toDelete;
		nodeToDeleteAfter->setNext(tempNext);
	}

}

void List::printList()
{
	ListNode* currentNode = this->head;
	while (currentNode)
	{
		currentNode->printNode();
		cout << endl;
		currentNode = currentNode->getNext();
	}
}

ListNode * List::getHead()
{
	return this->head;
}

ListNode * List::getTail()
{
	return this->tail;
}

void List::setTail(ListNode * tail)
{
	this->tail = tail;
}

void List::setHead(ListNode * head)
{
	this->head = head;
}

