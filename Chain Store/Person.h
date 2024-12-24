#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "ChaineStoreExceptions.h"

class Person {
private:
	string name;
	int age;
	int id;								// Unique ID for each Person
	static int nextId;					// Static variable to track next available ID

public:
	Person(const string& name, int age); // Constructor
	~Person() = default;                 // Destructor

	void setName(const string& name);
	const string& getName() const { return name; }
	void setAge(int age);
	int getAge() const { return age; }
	int getId() const { return id; }
	virtual void toOs(ostream& os) const {}
	friend ostream& operator<<(ostream& os, const Person& person);

protected:
	Person(const Person& other);                // Copy constructor
	Person& operator=(const Person& other);     // Copy assignment operator
	Person(Person&& other) noexcept;            // Move constructor
	Person& operator=(Person&& other) noexcept; // Move assignment operator
};

#endif // PERSON_H
