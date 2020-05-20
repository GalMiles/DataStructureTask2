
#include "BSTree.h"
#include "List.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student** GetInput(int& n, int& k);
void makeListFromArr(List& listToReturn,Student** studentArr, int n, int k, int& counter);
ListNode* findNode(const List& listToScan, int id, int& counter);
int NaivePrint(Student** studentArr, int n, int k);
int BSTPrint(Student** studentArr, int n, int k);
void makeBSTree(BSTree& treeToBuild, Student** studentArr, int n, int& compareCounter);
void QuickSort(Student** studentArr, int left, int right, int& compereCounter);
int Partition(Student** studentArr, int left, int right, int& compereCounter);
int PrintBySort(Student** studentArr, int n, int k);
void checkName(string& name);
void deleteStudentsArr(Student** studentsArr, int n);


int main()
{
	int n, k;
	int numCompNaive, numCompBst, numCompSort;
	Student** studentArr = GetInput(n, k);
	cout << endl;
	numCompNaive = NaivePrint(studentArr, n, k);
	cout << endl;
	numCompBst = BSTPrint(studentArr, n, k);
	cout << endl;
	numCompSort = PrintBySort(studentArr, n, k);
	cout << endl;
	cout << "NaivePrint: " << numCompNaive << " comparisons" << endl;
	cout << "BSTPrint: " << numCompBst << " comparisons" << endl;
	cout << "PrintBySort: " << numCompSort << " comparisons" << endl;

	deleteStudentsArr(studentArr, n);
}
	


void deleteStudentsArr(Student** studentsArr, int n)
{
	for (int i = 0; i < n; i++)
		delete studentsArr[i];
	delete[]studentsArr;
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
		cin.ignore(128, ' ');
		getline(cin, name);
		checkName(name);
		studentArr[i] = new Student(id, name);
	}
	cin >> k;
	return studentArr;
}

void makeListFromArr(List& listToReturn,Student** studentArr, int n, int k, int& counter)
{
	int currentIdOfStudentArr;

	for (int i = 0; i < n; i++)
	{
		if (listToReturn.isEmpty())
		{
			currentIdOfStudentArr = studentArr[i]->getId();
			if (currentIdOfStudentArr < k)
			{
				ListNode* newNode = new ListNode(studentArr[i], nullptr);
				listToReturn.getHead()->setNext(newNode);
				listToReturn.setTail(newNode);
			}
		}
		else
		{
			currentIdOfStudentArr = studentArr[i]->getId();
			if (currentIdOfStudentArr < k)
			{
				ListNode* newNode = new ListNode(studentArr[i], nullptr);
				ListNode* nodeToAddAfter = findNode(listToReturn, currentIdOfStudentArr, counter);
				listToReturn.insertAfter(nodeToAddAfter, newNode);
			}
			counter++;
		}
	}
}

ListNode* findNode(const List& listToScan, int id, int& counter)
{
	ListNode* currentNode = listToScan.getHead()->getNext();
	ListNode* next = currentNode->getNext();
	bool foundNode = true;
	ListNode* nodeToReturn = listToScan.getHead();
	if (id < currentNode->getData()->getId())
	{
		return nodeToReturn;
	}
	while (next && foundNode)
	{
		if (id >= currentNode->getData()->getId() && id <= next->getData()->getId())
		{
			foundNode = false;
			nodeToReturn = currentNode;
		}
		counter ++;
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
	List listToPrint;
	makeListFromArr(listToPrint,studentArr, n, k, compareCounter);
	listToPrint.printList();
	return compareCounter;
}
int BSTPrint(Student** studentArr, int n, int k)
{
	BSTree TreeToPrint;
	TreeToPrint.makeEmpty();
	int compareCounter = 0;
	makeBSTree(TreeToPrint, studentArr, n, compareCounter);
	TreeToPrint.PrintTreeLimitedByKey(k);
	return compareCounter;

}

void makeBSTree(BSTree& treeToBuild, Student** studentArr, int n, int& compareCounter)
{
	for (int i = 0; i < n; i++)
	{
		treeToBuild.Insert(studentArr[i]->getId(), studentArr[i]->getName(), compareCounter);
	}
}

int PrintBySort(Student** studentArr, int n, int k)
{
	int numComp = 0;
	QuickSort(studentArr, 0, n - 1, numComp);
	for (int i = 0; i < n; i++)
	{
		int currId = studentArr[i]->getId();
		if (currId < k)
			cout << currId << " " << studentArr[i]->getName() << endl;
		numComp++;
	}
	return numComp;
}

void QuickSort(Student** studentArr, int left, int right, int& compereCounter)
{
	int pivot;
	if (left < right)
	{
		pivot = Partition(studentArr, left, right, compereCounter);
		QuickSort(studentArr, left, pivot - 1, compereCounter);
		QuickSort(studentArr, pivot + 1, right, compereCounter);
	}
}

int Partition(Student** studentArr, int left, int right, int & compereCounter)
{
	int indexToReturn = left;
	for (int i = left; i < right; i++)
	{
		if (studentArr[i]->getId() < studentArr[right]->getId())
		{
			swap(studentArr[i], studentArr[indexToReturn]);
			indexToReturn++;
		}
		compereCounter++;
	}
	swap(studentArr[right], studentArr[indexToReturn]);
	compereCounter++;

	return indexToReturn;
}

void checkName(string& name)
{
	size_t found;
	found = name.find(" ");
	if (found >= name.length())
		exit(1);
}