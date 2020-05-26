#include "List.h"


List::List()
{
	ListNode* dummy = new ListNode(nullptr, nullptr);
	this->head = dummy;
	this->tail = dummy;
}

List::~List()
{
	makeEmpty();
	delete this->head;
}

List::List(const List & cpy)
{
	ListNode* nextCpy = nullptr;
	ListNode* next = nullptr;
	ListNode* currCpy = cpy.getHead()->getNext();
	ListNode *curr = this->head;
	
	while (currCpy)
	{
		curr = currCpy;
		nextCpy = currCpy->getNext();
		next = curr->getNext();
		currCpy = nextCpy;
		curr = next;
	}

}

List::List(const List&& cpy)
{
	this->setHead(cpy.getHead());
}

void List::makeEmpty()
{
	ListNode* next = nullptr;
	ListNode* curr = this->head->getNext();

	while (curr)
	{
		next = curr->getNext();
		delete curr;
		curr = next;
	}
	this->head = nullptr;
}

bool List::isEmpty()
{
	if (this->head == this->tail)
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
	ListNode* currentNode = this->head->getNext();
	while (currentNode)
	{
		currentNode->printNode();
		cout << endl;
		currentNode = currentNode->getNext();
	}
}

ListNode* List::getHead() const
{
	return this->head;
}

ListNode * List::getTail() const
{
	return this->tail;
}

void List::setTail(ListNode * tail)
{
	this->tail = tail;
}

void List::setHead(ListNode* head)
{
	this->head = head;
}

