#pragma warning (disable: 4996)
#include "Branch.h"

// Constructor
Branch::Branch(const string& name)
{
	setName(name);
}

// Method to add a department
void Branch::addDepartment(const Department& department)
{
	departments.push_back(department);
}

// Setter for name
void Branch::setName(const string& name)
{
	if (name.empty())
		throw InvalidNameException("Branch name cannot be empty");
	this->name = name;
}

// Getter for department
Department& Branch::operator[](int index)
{
	if (index < 0 || index >= departments.size())
		throw BranchIndexOutOfRangeException();

	auto it = departments.begin();
	advance(it, index);
	return *it;
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Branch& branch)
{
	os << "----------------------------------------\n";
	os << "Branch name: " << branch.name << " \n";
	os << "Number of department(s): " << branch.departments.size() << endl;
	branch.toOs(os);
	os << "department(s): \n";
	int i = 1;
	for (const auto& dept : branch.departments)
		os << i++ << ". " << dept; // Department has operator<<
	return os;
}

void Branch::showDepartmentArray() const
{
	int i = 1;
	for (const auto& dept : departments)
		cout << i++ << ". " << dept.getName() << "\n";
}


// Don't need to implement the copy / move c'tors / operators --> name is string (handle its own memory) and the list provide the other needed implementations
/*
// Copy constructor
Branch::Branch(const Branch& other) : departments(other.departments)
{
	setName(other.name);
}

// Move constructor
Branch::Branch(Branch&& other) noexcept : departments(move(other.departments))
{
	setName(move(other.name));
}

// Copy assignment operator
Branch& Branch::operator=(const Branch& other)
{
	if (this != &other)
	{
		setName(other.name);
		departments = other.departments;
	}
	return *this;
}

// Move assignment operator
Branch& Branch::operator=(Branch&& other) noexcept
{
	if (this != &other)
	{
		setName(move(other.name));
		departments = move(other.departments);
	}
	return *this;
}
*/