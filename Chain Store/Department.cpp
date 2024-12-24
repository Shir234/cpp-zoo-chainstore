#pragma warning (disable: 4996)

#include "Department.h"

// Constructor
Department::Department(const string& name) : inventory()
{
	setName(move(name));
}

// Method to add an item
void Department::addItem(const Item& item)
{
	inventory.addToEnd(item);
}

// Method to remove an item
void Department::removeItem(const Item& item)
{
	inventory.deleteElement(item);
}

// Method to display all items in the department
void Department::showInventory() const
{
	cout << "Inventory of Department- " << name << ":\n";
	if (begin() == end())
		throw InventoryEmptyException();

	int index = 1;
	for (const auto& item : inventory)
		cout << "\t" << index++ << ". " << item;
}

// Setter for name
void  Department::setName(const string& name)
{
	if (name.empty())
		throw InvalidNameException("Department name cannot be empty");
	this->name = move(name);
}

int Department::getNumItems() const
{
	return inventory.size();
}

// Add item to inventory      Department + Item
Department& Department::operator+(const Item& item)
{
	addItem(item);
	return *this;
}

// Remove item from inventory    Department - Item
Department& Department::operator-(const Item& item)
{
	removeItem(item);
	return *this;
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name << "\n\tInventory:\n";
	department.inventory.print();
	return os;
}


void Department::setSale(int salePercentage)
{
	if (salePercentage < 0 || salePercentage > 100)
		throw InvalidSalePercentage();

	this->salePercentage = salePercentage;
	for (auto& item : inventory)
		item.update(this, salePercentage);	// Notify all observers (items)
}


// Don't need to implement the copy / move c'tors / operators --> name is string (handle its own memory) and the LinkedList provide the other needed implementations
/*// Copy constructor
Department::Department(const Department& other) : inventory(other.inventory)
{
	setName(other.name);
}

// Move constructor
Department::Department(Department&& other) noexcept : inventory(move(other.inventory))
{
	setName(move(other.name));
}

// Destructor
Department::~Department() = default;

// Copy assignment operator
Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		setName(other.name);
		inventory = other.inventory;
	}
	return *this;
}

// Move assignment operator
Department& Department::operator=(Department&& other) noexcept
{
	if (this != &other)
	{
		setName(move(other.name));
		inventory = move(other.inventory);
	}
	return *this;
}
*/