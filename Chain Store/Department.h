#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "ChaineStoreExceptions.h"
#include "LinkedList.h"
#include "Item.h"

class Department {
private:
	LinkedList<Item> inventory;
	string name;
	int salePercentage;

public:
	Department(const string& name);									// Constructor
	Department(const Department& other) = default;                  // Copy constructor
	Department(Department&& other) noexcept = default;              // Move constructor
	~Department() = default;                                        // Destructor
	Department& operator=(const Department& other) = default;       // Copy assignment operator
	Department& operator=(Department&& other) noexcept = default;   // Move assignment operator

	void addItem(const Item& item);
	void removeItem(const Item& item);
	void showInventory() const;
	const string& getName() const { return name; };
	void setName(const string& name);
	int getNumItems() const;

	void setSale(int salePercentage); //acts as 'notify' in Observer pattern
	int getCurrentSalePercentage() const { return salePercentage; }

	// Operator overloads
	Department& operator+(const Item& item);						// Add item to inventory        Department + Item
	Department& operator-(const Item& item);						// Remove item from inventory   Department - Item
	friend ostream& operator<<(ostream& os, const Department& dp);

	typename LinkedList<Item>::Iterator begin() { return inventory.begin(); }
	typename LinkedList<Item>::Iterator end() { return inventory.end(); }
	typename LinkedList<Item>::ConstIterator begin() const { return inventory.begin(); }
	typename LinkedList<Item>::ConstIterator end() const { return inventory.end(); }
};

#endif // DEPARTMENT_H