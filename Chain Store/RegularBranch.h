#ifndef REGULARBRANCH_H
#define REGULARBRANCH_H

#include <list>
#include "Branch.h"
#include "Employee.h"

class RegularBranch : virtual public Branch {
protected:
	list<Employee*> employees;								//List of pointers -> Branch polymorphism
	string address;
	void cleanup();

public:
	RegularBranch(const string& name, const string& address);		// Constructor
	RegularBranch(const RegularBranch& other);                      // Copy constructor
	RegularBranch(RegularBranch&& other) noexcept;                  // Move constructor
	virtual ~RegularBranch();                                       // Destructor
	RegularBranch& operator=(const RegularBranch& other);           // Copy assignment operator
	RegularBranch& operator=(RegularBranch&& other) noexcept;       // Move assignment operator

	void addEmployee(const Employee& employee);
	const string& getAddress() const { return address; }
	void setAddress(const string& address);
	int getNumEmployees() const { return employees.size(); }
	virtual Branch* clone() const override { return new RegularBranch(*this); }// Implement clone method
	virtual void toOs(ostream& os) const override;
};

#endif // REGULARBRANCH_H
