#pragma warning (disable : 4996)
#include "Student.h"

Student::Student(int id, const string name)
{
	this->setId(id);
	this->setName(name);
}
Student::Student()
{
	this->name = nullptr;
	this->id = -1;
}
Student::Student(const Student & cpy)
{
	*this = cpy;
}
Student::Student(Student&& other)
{
	this->id = other.id;
	this->name = other.name;
	other.name = nullptr;
}
Student::~Student()
{
}

const Student& Student::operator=(Student&& other)
{
	this->name = other.name;
	this->id = other.id;
	return *this;
}

const Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		id = other.getId();
		name = other.getName();
	}
	return *this;
}
int Student::getId()const
{
	return this->id;
}

const string Student::getName() const
{
	return this->name;
}

bool Student::setId(int id)
{
	this->id = id;
	return true;
}

bool Student::setName(const string name) 
{
	this->name = name;
	return true;
}

void Student::show() const 
{
	cout << this->id;
	cout << this->name << endl;
}