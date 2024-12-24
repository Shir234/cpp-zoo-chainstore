#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Manager.h"
#include <string> 

// Constructor
Manager::Manager(const string& name, int age, const string& position, const string& manageDepartment) : Employee(name, age, position)
{
	setManageDepartment(manageDepartment);
}

// Setter for manageDepartment
void Manager::setManageDepartment(const string& manageDepartment)
{
	if (manageDepartment.empty())
		throw InvalidNameException("Manage department cannot be empty");

	this->manageDepartment = manageDepartment;
}

void Manager::toOs(ostream& os) const
{
	os << "\nemployee position: " << getPosition() << "\n";
	os << "manager department: " << getManageDepartment() << "\n";
}


//// Copy constructor
//Manager::Manager(const Manager& other) : Employee(other)
//{
//	setManageDepartment(other.manageDepartment);
//}
//
//// Move constructor
//Manager::Manager(Manager&& other) noexcept : Employee(move(other))
//{
//	setManageDepartment(move(other.manageDepartment));
//}
//
//// Copy assignment operator
//Manager& Manager::operator=(const Manager& other)
//{
//	if (this != &other)
//	{
//		Employee::operator=(other);
//		setManageDepartment(other.manageDepartment);
//	}
//	return *this;
//}
//
//// Move assignment operator
//Manager& Manager::operator=(Manager&& other) noexcept
//{
//	if (this != &other)
//	{
//		Employee::operator=(move(other));
//		setManageDepartment(move(other.manageDepartment));
//	}
//	return *this;
//}