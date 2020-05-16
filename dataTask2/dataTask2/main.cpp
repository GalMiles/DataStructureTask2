
#include "BSTree.h"
#include "List.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student** GetInput(int& n, int& k);
List makeListFromArr(Student** studentArr, int n, int k);
ListNode* findNode(List listToScan, int id);

int main()
{
	int n, k;
	Student** studentArr = GetInput(n, k);
	List sortedListById = makeListFromArr(studentArr,n,k);
	sortedListById.printList();

}


Student** GetInput(int& n, int& k)
{
	int id;
	string name;
	cin >> n;
	Student** studentArr = new Student*[n];
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		getline(cin, name);
		studentArr[i] = new Student(id, name);
	}
	cin >> k;
	return studentArr;
}

List makeListFromArr(Student** studentArr, int n, int k)
{
	int currentIdOfStudentArr;
	List listToReturn;

	for (int i = 0; i < n; i++)
	{
		if (listToReturn.isEmpty())
		{
			ListNode* newNode = new ListNode(studentArr[i], nullptr);
			listToReturn.setHead(newNode);
			listToReturn.setTail(newNode);
		}
		else
		{
			ListNode* newNode = new ListNode(studentArr[i], nullptr);
			currentIdOfStudentArr = studentArr[i]->getId();
			ListNode* nodeToAddAfter = findNode(listToReturn,currentIdOfStudentArr);
			if (currentIdOfStudentArr < k)
			{
				if (nodeToAddAfter == listToReturn.getHead() && currentIdOfStudentArr < listToReturn.getHead()->getData()->getId())
					listToReturn.insertToHead(newNode);
				else
					listToReturn.insertAfter(nodeToAddAfter, newNode);
			}
		}
	}
	return listToReturn;
}

ListNode* findNode(List listToScan,int id)
{
	ListNode* currentNode = listToScan.getHead();
	ListNode* next = currentNode->getNext();
	bool foundNode = true;
	ListNode* nodeToReturn = listToScan.getHead();
	while (next && foundNode)
	{
		if (id >= currentNode->getData()->getId() && id <= next->getData()->getId())
		{
			foundNode = false;
			nodeToReturn = currentNode;
		}
		else if (id <= currentNode->getData()->getId())
		{
			foundNode = false;
			nodeToReturn = listToScan.getHead();
		}
		currentNode = next;
		next = next->getNext();
	}
	if (foundNode == true)
		nodeToReturn = listToScan.getTail();
	
	return nodeToReturn;
}
