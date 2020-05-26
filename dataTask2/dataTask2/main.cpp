
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
bool checkIfIdExist(int id, int arrSize, Student** studArr);

/*
To run the program insert number of students, insert id space name (this format - 12 david levi) and after insert the next student,
then insert k this wiil be the limit k will print
*/
int main()
{
	int n, k;
	int numCompNaive, numCompBst, numCompSort;
	Student** studentArr = GetInput(n, k);//get input from user
	cout << endl;
	numCompNaive = NaivePrint(studentArr, n, k);//make the list and print and return the number of comparison in the function
	cout << endl;
	numCompBst = BSTPrint(studentArr, n, k);//make the tree and print it and return the number of comparison in the tree while it is build
	cout << endl;
	numCompSort = PrintBySort(studentArr, n, k);//make quick sort to the students array and returnthe number of comparison
	cout << endl;
	cout << "NaivePrint: " << numCompNaive << " comparisons" << endl;
	cout << "BSTPrint: " << numCompBst << " comparisons" << endl;
	cout << "PrintBySort: " << numCompSort << " comparisons" << endl;

	deleteStudentsArr(studentArr, n);
}
	


void deleteStudentsArr(Student** studentsArr, int n)//relese all the the students array
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
		if (!checkIfIdExist(id, i, studentArr))
		{
			cin.ignore(128, ' ');
			getline(cin, name);
			checkName(name);
			studentArr[i] = new Student(id, name);
		}
	}
	cin >> k;
	return studentArr;
}

bool checkIfIdExist(int id,int arrSize,Student** studArr)//check each id is insert one time if try to insert same id the program will exit
{
	for (int i = 0; i < arrSize; i++)
	{
		if (id == studArr[i]->getId())
		{
			cout << "Invalid input" << endl;
			exit(1);
		}
	}
	return false;
}
void makeListFromArr(List& listToReturn,Student** studentArr, int n, int k, int& counter)//make the list and print it, insert to list and make it sorted
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
		}
		counter++;
	}
}

ListNode* findNode(const List& listToScan, int id, int& counter)//find node in the list to add after
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

int NaivePrint(Student** studentArr, int n, int k)//make list,print it and return number of comparison
{
	int compareCounter = 0;
	List listToPrint;
	makeListFromArr(listToPrint,studentArr, n, k, compareCounter);
	listToPrint.printList();
	return compareCounter;
}
int BSTPrint(Student** studentArr, int n, int k)//make bst tree,print it and return number of comparison
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

int PrintBySort(Student** studentArr, int n, int k)//do quick sort for the students array and print if smaller then k
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

int Partition(Student** studentArr, int left, int right, int & compereCounter)// we will chose the pivot to be the right in the array each time
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

void checkName(string& name)//check if valid name
{
	size_t found;
	found = name.find(" ");
	if (found >= name.length())
		exit(1);
}