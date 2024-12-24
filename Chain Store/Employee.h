#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

#include <string>
#include "Person.h"

class Employee : public Person {
private:
	string  position;

public:
	Employee(const string& name, int age, const string& position);		// Constructor
	~Employee() = default;                                              // Destructor

	const string& getPosition() const { return position; }
	void setPosition(const string& position);
	bool operator==(const Employee& other) const;
	virtual void toOs(ostream& os) const override;
	friend class RegularBranch;

protected:
	Employee(const Employee& other) = default;                // Copy constructor
	Employee(Employee&& other) noexcept = default;            // Move constructor
	Employee& operator=(const Employee& other) = default;     // Copy assignment operator
	Employee& operator=(Employee&& other) noexcept = default; // Move assignment operator
};

#endif // EMPLOYEE_H