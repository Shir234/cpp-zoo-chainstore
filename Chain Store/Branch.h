#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <list>
#include "ChaineStoreExceptions.h"
#include "Department.h"

// Abstract class
class Branch {
protected:
	string name;
	list<Department> departments;

public:
	Branch(const string& name);								// Constructor
	//Branch(const Branch& other) = default;                  // Copy constructor
	//Branch(Branch&& other) noexcept = default;              // Move constructor
	virtual ~Branch() = default;							// Destructor
	//Branch& operator=(const Branch& other) = default;       // Copy assignment operator
	//Branch& operator=(Branch&& other) noexcept = default;   // Move assignment operator
	
	void addDepartment(const Department& department);   // Method to add a department
	void setName(const string& name);
	int getNumDepartments() const { return departments.size(); }
	const string& getName() const { return name; }
	
	virtual Branch* clone() const = 0; // Pure virtual clone method (Prototype pattern)

	// Operator overloads
	Department& operator[](int index); // Access department from list - getter for department
	friend ostream& operator<<(ostream& os, const Branch& branch);
	void showDepartmentArray() const;
	virtual void toOs(ostream& os) const {}
};

#endif // BRANCH_H
