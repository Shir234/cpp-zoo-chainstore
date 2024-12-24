#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "OnlineBranch.h"
#include <string> 

// Constructor
OnlineBranch::OnlineBranch(const string& name, const string& url) : Branch(name)
{
	setUrl(url);
}

// Setter for URL
void OnlineBranch::setUrl(const string& url)
{
	if (url.empty())
		throw InvalidNameException("URL cannot be empty");
	this->url = url;
}

void OnlineBranch::toOs(ostream& os) const
{
	os << "URL: " << (url.empty() ? "N/A" : url) << std::endl;
}



// Don't need to implement the copy / move c'tors / operators --> The default do what we need
//// Copy constructor
//OnlineBranch::OnlineBranch(const OnlineBranch& other) : Branch(other)
//{
//	setUrl(other.url);
//}
//
//// Move constructor
//OnlineBranch::OnlineBranch(OnlineBranch&& other) noexcept : Branch(move(other))
//{
//	setUrl(move(other.url));
//}
//
//// Copy assignment operator
//OnlineBranch& OnlineBranch::operator=(const OnlineBranch& other)
//{
//	if (this != &other)
//	{
//		Branch::operator=(other);
//		setUrl(other.url);
//	}
//	return *this;
//}
//
//// Move assignment operator
//OnlineBranch& OnlineBranch::operator=(OnlineBranch&& other) noexcept
//{
//	if (this != &other)
//	{
//		Branch::operator=(move(other));
//		setUrl(move(other.url));
//	}
//	return *this;
//}