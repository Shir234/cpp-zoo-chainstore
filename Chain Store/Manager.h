#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
	string manageDepartment;

public:
	Manager(const string& name, int age, const string& position, const string& manageDepartment);	// Constructor
	~Manager() = default;																			// Destructor

	const string& getManageDepartment() const { return manageDepartment; }
	void setManageDepartment(const string& manageDepartment);
	virtual void toOs(ostream& os) const override;

private:
	Manager(const Manager& other) = default;                  // Copy constructor
	Manager(Manager&& other) noexcept = default;              // Move constructor
	Manager& operator=(const Manager& other) = default;       // Copy assignment operator
	Manager& operator=(Manager&& other) noexcept = default;   // Move assignment operator
};

#endif // MANAGER_H