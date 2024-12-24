#pragma warning (disable: 4996)
#include "Employee.h"

// Constructor
Employee::Employee(const string& name, int age, const string& position) : Person(name, age)
{
	setPosition(position);
}

// Setter for position
void Employee::setPosition(const string& position)
{
	if (position.empty())
		throw InvalidNameException("Position cannot be empty");

	this->position = position;
}

// Equality operator
bool Employee::operator==(const Employee& other) const
{
	return (this->getId() == other.getId());
}

void Employee::toOs(ostream& os) const
{
	os << "\n\t\tposition: " << getPosition() << "\n";
}


//// Copy constructor
//Employee::Employee(const Employee& other) : Person(other)
//{
//	setPosition(other.position);
//}
//
//// Move constructor
//Employee::Employee(Employee&& other) noexcept : Person(move(other))
//{
//	setPosition(move(other.position));
//}
//
//// Copy assignment operator
//Employee& Employee::operator=(const Employee& other)
//{
//	if (this != &other)
//	{
//		Person::operator=(other);
//		setPosition(other.position);
//	}
//	return *this;
//}
//
//// Move assignment operator
//Employee& Employee::operator=(Employee&& other) noexcept
//{
//	if (this != &other)
//	{
//		Person::operator=(move(other));
//		setPosition(move(other.position));
//	}
//	return *this;
//}