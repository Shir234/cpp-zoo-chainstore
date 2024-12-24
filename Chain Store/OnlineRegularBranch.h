#ifndef ONLINEREGULARBRANCH_H
#define ONLINEREGULARBRANCH_H

#include "OnlineBranch.h"
#include "RegularBranch.h"

class OnlineRegularBranch : public OnlineBranch, public RegularBranch
{
public:
	OnlineRegularBranch(const string& name, const string& url, const string& address);	// Constructor
	OnlineRegularBranch(const OnlineRegularBranch& other) = default;					// Copy constructor
	OnlineRegularBranch(OnlineRegularBranch&& other) noexcept = default;				// Move constructor
	~OnlineRegularBranch() = default;													// Destructor
	OnlineRegularBranch& operator=(const OnlineRegularBranch& other) = default;			// Copy assignment operator
	OnlineRegularBranch& operator=(OnlineRegularBranch&& other) noexcept = default;		// Move assignment operator

	Branch* clone() const override { return new OnlineRegularBranch(*this); } // Implement clone method
	virtual void toOs(ostream& os) const override;
};
#endif // ONLINEREGULARBRANCH_H
