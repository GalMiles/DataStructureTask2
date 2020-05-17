
#include "BSTree.h"
#include "List.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student** GetInput(int& n, int& k);
List makeListFromArr(Student** studentArr, int n, int k, int& counter);
ListNode* findNode(List listToScan, int id,int& counter);
int NaivePrint(Student** studentArr, int n, int k);
int BSTPrint(Student** studentArr, int n, int k);
void makeBSTree(BSTree& treeToBuild, Student** studentArr, int n, int& compareCounter);

int main()
{
	int n, k;
	//int numCompNaive
	int numCompBst;
	Student** studentArr = GetInput(n, k);
	//numCompNaive = NaivePrint(studentArr, n, k);
	//cout << numCompNaive;
	numCompBst = BSTPrint(studentArr, n, k);

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

List makeListFromArr(Student** studentArr, int n, int k, int& counter)
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
			ListNode* nodeToAddAfter = findNode(listToReturn,currentIdOfStudentArr,counter);
			if (currentIdOfStudentArr < k)
			{
				counter += 2;
				if (nodeToAddAfter == listToReturn.getHead() && currentIdOfStudentArr < listToReturn.getHead()->getData()->getId())
					listToReturn.insertToHead(newNode);
				else
					listToReturn.insertAfter(nodeToAddAfter, newNode);
			}
		}
	}
	return listToReturn;
}
//2->5->
ListNode* findNode(List listToScan,int id,int& counter)
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
			counter++;
			foundNode = false;
			nodeToReturn = listToScan.getHead();
		}
		counter += 2;
		currentNode = next;
		next = next->getNext();
	}
	if (foundNode == true)
		nodeToReturn = listToScan.getTail();
	
	return nodeToReturn;
}

int NaivePrint(Student** studentArr, int n, int k)
{
	int compareCounter = 0;
	List listToPrint = makeListFromArr(studentArr, n, k, compareCounter);
	listToPrint.printList();

	return compareCounter;
	
}
int BSTPrint(Student** studentArr, int n, int k)
{	
	BSTree TreeToPrint;
	TreeToPrint.makeEmpty();
	int compareCounter = 0;
	makeBSTree(TreeToPrint,studentArr, n, compareCounter);
	TreeToPrint.PrintTreeLimitedByKey(k);
	return compareCounter;
	
}

 void makeBSTree(BSTree& treeToBuild,Student** studentArr, int n, int& compareCounter)
{
	

	for (int i = 0; i < n; i++)
	{
		treeToBuild.Insert(studentArr[i]->getId(), studentArr[i]->getName(), compareCounter);
	}

}
