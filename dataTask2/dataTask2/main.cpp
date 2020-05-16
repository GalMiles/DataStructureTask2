#include "BSTree.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student** GetInput(int& n, int& k);


int main()
{
	int n, k;
	Student** studentArr = GetInput(n, k);



}


Student** GetInput(int& n, int& k)
{
	int n,id,k;
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
}