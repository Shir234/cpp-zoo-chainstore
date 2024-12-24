#include "ChainStore.h"
#include "Branch.h"

// Initialize the static instance pointer
ChainStore* ChainStore::instance = nullptr;

// Private Constructor
ChainStore::ChainStore(const string& name) : name()
{
	setName(name);
}

// Static method to get the singleton instance
ChainStore* ChainStore::getInstance(const string& name)
{
	if (instance == nullptr)
	{
		instance = new ChainStore(name);
	}
	return instance;
}

// Destructor
ChainStore::~ChainStore()
{
	for (auto branch : branches)
		delete branch;
}

//Setter for name 
void ChainStore::setName(const string& name)
{
	if (name.empty())
		throw InvalidNameException("Chain Store's name cannot be null or empty");

	this->name = name;
}

void ChainStore::addBranch(const Branch& branch)
{
	branches.push_back(branch.clone());
}

// Getter for branch
Branch* ChainStore::operator[](int index)
{
	if (index < 0 || index >= this->branches.size())
		throw BranchIndexOutOfRangeException();

	auto it = branches.begin();
	advance(it, index);				//advance is used to move an iterator forward (or backward) by a specified number of positions
	return *it;
}

// Output operator (ostream operator<<)
ostream& operator<<(ostream& os, const ChainStore& chainStore)
{
	os << "--------------------------------------------------------------------------------------------------------------------\n";
	os << "Chain Store Name: " << chainStore.name << "\nNumber of Branches: " << chainStore.branches.size() << "\n";
	for (const auto& branch : chainStore.branches)
		os << *branch << "\n"; // Use Branch's operator<<
	os << "--------------------------------------------------------------------------------------------------------------------\n";
	return os;
}

void ChainStore::showBranchesArray() const
{
	int i = 1;
	for (const auto& branch : branches)
		cout << i++ << ". " << branch->getName() << "\n";
}




// Before implementing singletone

//// Copy constructor
//ChainStore::ChainStore(const ChainStore& other) : name()
//{
//	setName(name);
//	for (const auto& branch : other.branches)
//		branches.push_back(branch->clone());
//}
//
//// Move constructor
//ChainStore::ChainStore(ChainStore&& other) noexcept : branches(move(other.branches))
//{
//	setName(move(other.name));
//	other.branches.clear();
//}

//// Copy assignment operator
//ChainStore& ChainStore::operator=(const ChainStore& other)
//{
//	if (this != &other)
//	{
//		setName(other.name);
//
//		for (auto branch : branches)
//			delete branch;
//
//		branches.clear();
//		for (const auto& branch : other.branches)
//			branches.push_back(branch->clone());
//	}
//	return *this;
//}
//
//// Move assignment operator
//ChainStore& ChainStore::operator=(ChainStore&& other) noexcept
//{
//	if (this != &other)
//	{
//		setName(move(other.name));
//		swap(branches, other.branches);
//		other.branches.clear();
//	}
//	return *this;
//}