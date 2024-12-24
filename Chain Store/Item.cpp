#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include <string>
#include "Item.h"

#include "Department.h"


// Constructor
Item::Item(string name, int price) : price(0)
{
	setName(move(name));
	setPrice(price);
}

// Setter for name
void Item::setName(string name)
{
	if (name.empty())
		throw InvalidNameException("Item name cannot be empty");
	this->name = move(name);
}

// Setter for price
void Item::setPrice(int price)
{
	if (price <= 0)
		throw InvalidItemPriceException();

	this->price = price;
	this->priceInSale = price;
}

// Equality operator
bool Item::operator==(const Item& other) const
{
	return (getName() == other.getName() && getPrice() == other.getPrice());
}


ostream& operator<<(ostream& os, const Item& item)
{
	os << "Item: " << item.name << "\tPrice: $: " << item.price << "\tCurrent price: $" <<item.priceInSale << "\n";
	return os;
}


void Item::update(const Department* department, int salePercentage)
{
	priceInSale = price - ((price * salePercentage) / 100);
	cout << "Item " << name << " price updated to $" << priceInSale << " duo to " 
		<< salePercentage << "% sale in department " << department->getName() << endl;
}
