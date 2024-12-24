#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "RegularBranch.h"
#include "Employee.h"
#include <string> 

// Constructor
RegularBranch::RegularBranch(const string& name, const string& address) : Branch(name)
{
	setAddress(address);
}

// Copy constructor
RegularBranch::RegularBranch(const RegularBranch& other) : Branch(other)
{
	setAddress(other.address);
	for (const auto& emp : other.employees)
		employees.push_back(new Employee(*emp));
}

// Move constructor
RegularBranch::RegularBranch(RegularBranch&& other) noexcept : Branch(move(other)), employees(move(other.employees))
{
	setAddress(move(other.address));
}

// Destructor
RegularBranch::~RegularBranch()
{
	cleanup();
}

// Copy assignment operator
RegularBranch& RegularBranch::operator=(const RegularBranch& other)
{
	if (this != &other)
	{
		Branch::operator=(other);
		cleanup();
		setAddress(other.address);
		for (const auto& emp : other.employees)
			employees.push_back(new Employee(*emp));
	}
	return *this;
}

// Move assignment operator
RegularBranch& RegularBranch::operator=(RegularBranch&& other) noexcept
{
	if (this != &other)
	{
		Branch::operator=(move(other));
		cleanup();
		setAddress(move(other.address));
		swap(employees, other.employees);
	}
	return *this;
}

// Setter for address
void RegularBranch::setAddress(const string& address)
{
	if (address.empty())
		throw InvalidNameException("Address cannot be empty");

	this->address = address;
}

// Method to add an employee
void RegularBranch::addEmployee(const Employee& employee)
{
	employees.push_back(new Employee(employee));
}

void RegularBranch::toOs(ostream& os) const
{
	os << "Address: " << address << endl;
	os << "Number of employees: " << employees.size() << endl;
	int i = 1;
	for (const auto& emp : employees)
		os << "\t" << i++ << ") " << *emp << endl;
}

void RegularBranch::cleanup()
{
	for (auto& emp : employees)
		delete emp;

	employees.clear();
}