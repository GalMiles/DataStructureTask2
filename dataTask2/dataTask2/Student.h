#ifndef ST_H
#define ST_H
#include <string>
#include <iostream>
using namespace std;
class Student {

private:
	int id;
	string name;
	
public:
	Student(int id, const string name);
	Student(const Student&cpy);
	Student();
	Student(Student&& other);
	~Student();
	int getId()const;
	const Student& operator=(Student&& other);
	const string getName()const;
	bool setId(int id);
	bool setName(const string name);
	const Student&operator=(const Student&other);
	void show()const;

};
#endif // !ST_H
