#ifndef CHAINSTORE_H
#define CHAINSTORE_H

#pragma warning (disable: 4996)
#include <string>
#include <list>
#include "ChaineStoreExceptions.h"

class Branch;
#include "RegularBranch.h"
#include "OnlineBranch.h"
#include "OnlineRegularBranch.h"

class ChainStore {
private:
	string name;
	list<Branch*> branches;									//List of pointers -> Branch polymorphism

	static ChainStore* instance;							// Singleton pattern

	ChainStore(const string& name);								 // Private constructor
	ChainStore(const ChainStore& other) = delete;				 // Deleted copy constructor
	ChainStore(ChainStore&& other) noexcept = delete;			 // Deleted move constructor
	ChainStore& operator=(const ChainStore& other) = delete;     // Deleted copy assignment operator
	ChainStore& operator=(ChainStore&& other) noexcept = delete; // Deleted move assignment operator


public:
	static ChainStore* getInstance(const string& name);
	~ChainStore();

	void setName(const string& name);
	string getName() const { return name; }
	int getNumBranches() const { return branches.size(); }

	void addBranch(const Branch& branch);
	Branch* operator[](int index);
	friend ostream& operator<<(ostream& os, const ChainStore& chainStore);
	void showBranchesArray() const;
};
#endif // CHAINSTORE_H