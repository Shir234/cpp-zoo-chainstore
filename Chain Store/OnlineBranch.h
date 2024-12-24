#ifndef ONLINEBRANCH_H
#define ONLINEBRANCH_H

#include "Branch.h"

class OnlineBranch : virtual public Branch
{
protected:
	string  url;

public:
	OnlineBranch(const string& name, const string& url);				// Constructor
	OnlineBranch(const OnlineBranch& other) = default;                  // Copy constructor
	OnlineBranch(OnlineBranch&& other) noexcept = default;              // Move constructor
	virtual ~OnlineBranch() = default;									// Destructor
	OnlineBranch& operator=(const OnlineBranch& other) = default;       // Copy assignment operator
	OnlineBranch& operator=(OnlineBranch&& other) noexcept = default;   // Move assignment operator

	const string& getUrl() const { return url; }
	void setUrl(const string& url);
	Branch* clone() const override { return new OnlineBranch(*this); } // Implement clone method
	virtual void toOs(ostream& os) const override;
};

#endif // ONLINEBRANCH_H