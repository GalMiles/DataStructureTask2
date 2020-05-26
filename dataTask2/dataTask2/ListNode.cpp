
#include "ListNode.h"



ListNode::ListNode(Student * data, ListNode* next)
{
	this->data = data;
	this->next = next;
}

ListNode::~ListNode()//no need to delete becuese no any allocation inside listNode
{
	
}

ListNode::ListNode(const ListNode & cpy)
{
this->data = cpy.data;
this->next = cpy.next;
}


ListNode::ListNode(const ListNode&& cpy)
{
	this->data = cpy.data;
	this->next = cpy.next;

}

Student* ListNode::getData()
{
	return this->data;
}

ListNode* ListNode::getNext()
{
	return this->next;
}

void ListNode::setData(Student* data)
{
	this->data = data;
}


void ListNode::setNext(ListNode* next)
{
	this->next = next;
}

void ListNode::insertAfterMe(ListNode* nodeToAdd)
{
	ListNode* temp;
	if (this->next == nullptr)
	{
		this->next = nodeToAdd;
	}
	else
	{
		temp = this->next;
		this->next = nodeToAdd;
		nodeToAdd->setNext(temp);
	}
}

void ListNode::printNode()
{
	cout << this->data->getId()  << " " << this->data->getName();
}

void ListNode::operator=(const ListNode& other)
{
	this->data = other.data;
	this->next = other.next;
}


