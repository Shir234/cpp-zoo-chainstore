#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "ChaineStoreExceptions.h"
#include "Observer.h"


class Item : public Observer {
private:
	string name;
	int price;
	int priceInSale;

public:
	Item(string name, int price);						// Constructor
	Item(const Item& other) = default;					// Copy constructor
	Item(Item&& other) noexcept = default;				// Move constructor
	~Item() = default;									// Destructor
	Item& operator=(const Item& other) = default;		// Copy assignment operator
	Item& operator=(Item&& other) noexcept = default;	// Move assignment operator

	const string& getName() const { return name; };
	void setName(string name);
	int getPrice() const { return priceInSale; };
	void setPrice(int price);
	int getOriginalPrice() const { return price; }

	// Operator overloads
	bool operator==(const Item& other) const;
	friend ostream& operator<<(ostream& os, const Item& item);

	void update(const Department* department, int salePercentage) override;
};

#endif // ITEM_H