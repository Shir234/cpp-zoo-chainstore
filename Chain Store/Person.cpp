#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Person.h"
#include <string> 

int Person::nextId = 1; // Initialize static member variable

// Constructor
Person::Person(const string& name, int age) : id(nextId++)
{
	setName(name);
	setAge(age);
}

// Copy constructor
Person::Person(const Person& other) : id(nextId++)
{
	setName(other.name);
	setAge(other.age);
}

// Move constructor
Person::Person(Person&& other) noexcept : id(other.id)
{
	setName(move(other.name));
	setAge(other.age);
	other.id = 0;
}

// Copy assignment operator
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setAge(other.age);
		setName(other.name);
	}
	return *this;
}

// Move assignment operator
Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		setName(move(other.name));
		setAge(other.age);
		swap(id, other.id);
	}
	return *this;
}

// Setter for name
void Person::setName(const string& name)
{
	if (name.empty())
		throw InvalidNameException("Person name cannot be empty");
	this->name = name;
}

// Setter for age
void Person::setAge(int age)
{
	if (age < 1 || age > 120)
		throw InvalidPersonAgeException();
	this->age = age;
}

// Output operator 
ostream& operator<<(ostream& os, const Person& person)
{
	os << "id: " << person.getId() << "\t" << "Name: " << person.getName() << "\t" << "age : " << person.getAge();
	person.toOs(os);
	return os;
}