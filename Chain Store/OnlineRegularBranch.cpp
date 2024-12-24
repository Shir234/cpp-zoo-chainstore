#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "OnlineRegularBranch.h"

// Constructor
OnlineRegularBranch::OnlineRegularBranch(const string& name, const string& url, const string& address)
	: Branch(name), OnlineBranch(name, url), RegularBranch(name, address)
{
}

void OnlineRegularBranch::toOs(ostream& os) const
{
	os << "Address: " << getAddress() << endl;
	os << "Number of employees: " << getNumEmployees() << endl;
	int i = 1;
	for (const auto& emp : employees)
		os << "\t" << i++ << ") " << *emp << endl;
	os << "URL: " << (getUrl().empty() ? "N/A" : getUrl()) << std::endl;
}


// Before all the changes we called the base classes constructors 
//// Copy constructor
//OnlineRegularBranch::OnlineRegularBranch(const OnlineRegularBranch& other)
//	: Branch(other), OnlineBranch(other), RegularBranch(other)
//{
//}
//
//// Move constructor
//OnlineRegularBranch::OnlineRegularBranch(OnlineRegularBranch&& other) noexcept
//	: Branch(move(other)), OnlineBranch(move(other)), RegularBranch(move(other))
//{
//}
//
//// Copy assignment operator
//OnlineRegularBranch& OnlineRegularBranch::operator=(const OnlineRegularBranch& other)
//{
//	if (this != &other)
//	{
//		Branch::operator=(other);
//		OnlineBranch::operator=(other);
//		RegularBranch::operator=(other);
//	}
//	return *this;
//}
//
//// Move assignment operator
//OnlineRegularBranch& OnlineRegularBranch::operator=(OnlineRegularBranch&& other) noexcept
//{
//	if (this != &other)
//	{
//		Branch::operator=(move(other));
//		OnlineBranch::operator=(move(other));
//		RegularBranch::operator=(move(other));
//	}
//	return *this;
//}
