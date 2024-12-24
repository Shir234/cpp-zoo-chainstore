#ifndef CHAIN_STORE_EXCEPTIONS_H_
#define CHAIN_STORE_EXCEPTIONS_H_

#include <iostream>
using namespace std;

class InvalidNameException : public exception
{
private:
	string message;
public:
	InvalidNameException(const string& msg) : message(msg) {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class BranchIndexOutOfRangeException : public out_of_range
{
public:
	BranchIndexOutOfRangeException() : out_of_range("Index is out of range") {}
};

class BranchNotFoundException : public runtime_error
{
public:
	BranchNotFoundException() : runtime_error("No branches in the store") {}
};

class InvalidItemPriceException : public invalid_argument
{
public:
	InvalidItemPriceException() : invalid_argument("Item price must be positive") {}
};

class ItemNotFoundException : public runtime_error
{
public:
	ItemNotFoundException() : runtime_error("Item not found in inventory") {}
};

class InventoryEmptyException : public runtime_error
{
public:
	InventoryEmptyException() : runtime_error("The inventory is empty") {}
};

class DepartmentNotFoundException : public runtime_error
{
public:
	DepartmentNotFoundException() : runtime_error("No departments in the branch") {}
};

class AddEmployeeToNonRegularBranchException : public runtime_error
{
public:
	AddEmployeeToNonRegularBranchException() : runtime_error("Cannot add employees to Online Branch!") {}
};

class InvalidPersonAgeException : public invalid_argument
{
public:
	InvalidPersonAgeException() : invalid_argument("Age can be only between 1 and 120") {}
};

class InvalidSalePercentage : public invalid_argument
{
public:
	InvalidSalePercentage() : invalid_argument("Sale percentage must be between 1 and 100") {}
};
#endif
