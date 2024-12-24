#include "HelperFunctions.h"

// Utility functions
void cleanBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidInteger(const string& str)
{
	if (str.empty())
		return false;

	size_t startIndex = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		// If there's only a sign and no digits, it's not valid
		if (str.length() == 1)
			return false;
		startIndex = 1;
	}
	// Check all remaining characters
	for (size_t i = startIndex; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

int getValidIntegerInput(const string& prompt, int minValue, int maxValue)
{
	while (true)
	{
		cout << prompt;
		string input;
		getline(cin, input);

		if (!isValidInteger(input))
		{
			cout << "Invalid input. Please enter a integer number." << endl;
			continue;
		}
		int value = stoi(input);
		if (value < minValue || value > maxValue)
		{
			cout << "Input out of range. Please enter a number between " << minValue << " and " << maxValue << "." << endl;
			continue;
		}
		return value;
	}
}

// UI functions
void displayMenu()
{
	cout << "\nMenu:\n"
		<< "1. Add a new branch\n"
		<< "2. Add a department to a branch\n"
		<< "3. Add an employee to a branch\n"
		<< "4. Add an item to inventory\n"
		<< "5. Remove an item from inventory\n"
		<< "6. Create sale in department\n"
		<< "7. Display branch details\n"
		<< "8. Display inventory details\n"
		<< "9. Display Chain Store Details\n"
		<< "10. Exit\n";
}

void displayWelcomeMsg()
{
	cout << "=============================================================================" << endl;
	cout << "                       Welcome to Chain Store Manager!" << endl;
	cout << "=============================================================================" << endl;
	cout << "Dear user," << endl;
	cout << "You are about to become a chain store manager." << endl;
	cout << "You need to choose a name for your chain store." << endl;
	cout << endl;
	cout << "Once you've made these initial choices, you'll have access to a menu where you can:" << endl;
	cout << "1. Create new branches (both regular and online)" << endl;
	cout << "2. Establish departments within your branches" << endl;
	cout << "3. Hire employees for your regular branches" << endl;
	cout << "4. Add items to department's inventory" << endl;
	cout << "5. Create sale in a department" << endl;
	cout << endl;
	cout << "You'll also be able to view the status of your stores, departments, and inventory at any time." << endl;
	cout << endl;
	cout << "* IMPORTANT NOTE: Employees can only be added to regular branches, not online branches.*" << endl;
	cout << endl;
	cout << "As you navigate through the system, please follow the on-screen instructions carefully." << endl;
	cout << endl;
	cout << "Good luck, and enjoy managing your new chain store!" << endl;
	cout << "=============================================================================" << endl;
	cout << endl;
}

// Chain store operations
void establishNetwork(ChainStore*& store)
{
	bool validInput = false;
	while (!validInput)
	{
		string storeName;
		cout << "Enter the name of the store: ";
		getline(cin, storeName);

		try
		{
			store = ChainStore::getInstance(storeName);
			// store = new ChainStore(storeName);
			validInput = true;
		}
		catch (InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid name for the chain store..\n";
		}
		catch (...)
		{
			cout << "Unknown error occurred";
		}
	}
	cout << *store << endl;
}

void addNewBranch(ChainStore*& store)
{
	string branchName;
	string address = "";
	string urlBranch = "";
	int branchType;

	cout << "\n--------- Create new branch ---------" << endl;
	Branch* newBranch = nullptr;
	bool branchCreated = false;

	while (!branchCreated)
	{
		try
		{
			branchType = getValidIntegerInput("Enter the type of branch (1: Regular, 2: Online, 3: Both): ", 1, 3);
			cout << "Enter the name of the branch: ";
			getline(cin, branchName);

			if (branchType == 1 || branchType == 3)
			{
				cout << "Enter the address of the branch: ";
				getline(cin, address);
			}
			if (branchType == 2 || branchType == 3)
			{
				cout << "Enter the branch's URL: ";
				getline(cin, urlBranch);
			}
			newBranch = createBranch(branchType, branchName, address, urlBranch);
			branchCreated = true;
		}
		catch (const InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid branch name." << endl;
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			cout << "Please try again.\n";
		}
		catch (const bad_alloc& e)
		{
			cout << "Memory allocation failed: " << e.what() << endl;
			cout << "Please try again.\n";
		}
		catch (...)
		{
			cout << "Unknown error occurred while creating employee. Please try again." << endl;
		}
	}
	if (newBranch)
	{
		try
		{
			store->addBranch(*newBranch);
			cout << "Branch was successfully added to store\n";
		}
		catch (...)
		{
			cout << "Unkown error occurred while adding branch." << endl;
			cout << "Branch was not added\n";
		}
		delete newBranch;
	}
}

void addDepartmentToBranch(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		string departmentName;
		while (true)
		{
			cout << "\n--------- Create new department ---------" << endl;
			cout << "Enter department name: ";
			getline(cin, departmentName);

			try
			{
				Department newDepartment(departmentName);
				selectedBranch->addDepartment(newDepartment);
				cout << "Department added successfully.\n";
				break;
			}
			catch (const InvalidNameException& e)
			{
				cout << e.what() << endl;
				cout << "Please enter a valid department name\n";
			}
			catch (...)
			{
				cout << "Unknown error occurred while creating employee. Please try again." << endl;
			}
		}
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add department." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred\n";
	}
}

void addEmployeeToBranch(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		RegularBranch* regularBranch = dynamic_cast<RegularBranch*>(selectedBranch);
		if (!regularBranch)
		{
			throw AddEmployeeToNonRegularBranchException();
		}
		cout << "\n--------- Add new employee ---------" << endl;
		int employeeType = 0;
		int age;
		string employeeName;
		string position;
		string manageDepartment;

		employeeType = getValidIntegerInput("Enter the type of employee to add (1: Employee, 2: Manager):", 1, 2);
		Employee* employee = nullptr;
		bool employeeCreated = false;

		while (!employeeCreated)
		{
			try
			{
				cout << "Enter employee name: ";
				getline(cin, employeeName);

				age = getValidIntegerInput("Enter employee's age: ", 1, 120);

				cout << "Enter employee position: ";
				getline(cin, position);

				if (employeeType == 2)
				{
					cout << "Enter manager department name to manage: ";
					getline(cin, manageDepartment);
				}

				switch (employeeType)
				{
				case 1:
					employee = new Employee(employeeName, age, position);
					break;
				case 2:
					employee = new Manager(employeeName, age, position, manageDepartment);
					break;
				}
				employeeCreated = true;
			}
			catch (const InvalidNameException& e)
			{
				cout << e.what() << endl;
				cout << "Please try again." << endl;
			}
			catch (const InvalidPersonAgeException& e)
			{
				cout << e.what() << endl;
				cout << "Please try again." << endl;
			}
			catch (...)
			{
				cout << "Unknown error occurred while creating employee. Please try again." << endl;
			}
		}
		if (employee)
		{
			regularBranch->addEmployee(*employee);
			cout << "Employee added successfully\n";
			delete employee;
		}
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const AddEmployeeToNonRegularBranchException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add employee." << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred\n";
	}
}

void addItemToInventory(ChainStore*& store)
{
	Branch* selectedBranch = nullptr;
	Department* selectedDepartment = nullptr;
	if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
		return;

	cout << "\n--------- Add new item ---------" << endl;
	string itemName;
	int price;

	while (true)
	{
		cout << "Enter item's name: ";
		getline(cin, itemName);
		price = getValidIntegerInput("Enter item's price:", 1);

		try
		{
			Item newItem(itemName, price);
			*selectedDepartment + newItem;
			cout << "Item added successfully!\n";
			break;
		}
		catch (const InvalidNameException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid item's name..\n";
		}
		catch (const InvalidItemPriceException& e)
		{
			cout << e.what() << endl;
			cout << "Enter valid item's price..\n";
		}
		catch (...)
		{
			cout << "Unknown error occurred. Enter valid input..\n";
		}
	}
}

void removeItemFromInventory(ChainStore*& store)
{
	Branch* selectedBranch = nullptr;
	Department* selectedDepartment = nullptr;
	if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
		return;

	try
	{
		selectedDepartment->showInventory();
	}
	catch (const InventoryEmptyException& e)
	{
		cout << e.what() << endl;
		cout << "The inventory is empty, back to menu" << endl;
		return;
	}

	int max = selectedDepartment->getNumItems();
	int itemIndex = getValidIntegerInput("\n--------- Select item number to remove: ", 1, max);

	try
	{
		auto it = selectedDepartment->begin();
		for (int i = 1; i < itemIndex && it != selectedDepartment->end(); ++i, ++it) {}		//iterate the inventory and get the wanted item

		if (it != selectedDepartment->end())
		{
			Item itemToRemove = *it;
			*selectedDepartment - itemToRemove;
			cout << "Item removed successfully!\n";
		}
		else
		{
			throw ItemNotFoundException();
		}
	}
	catch (const ItemNotFoundException& e)
	{
		cout << e.what() << endl;
		cout << "Cannot remove item\n";
	}
	catch (...)
	{
		cout << "Unknown error occurred while removing the item.\n";
	}
}

void createSaleInDepartment(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = nullptr;
		Department* selectedDepartment = nullptr;
		if (!getBranchAndDepartment(store, selectedBranch, selectedDepartment))
			return;

		cout << "\n--------- Create Sale in Department ---------" << endl;
		int salePercentage = getValidIntegerInput("Enter sale percentage (integer 0-100): ", 0, 100);

		selectedDepartment->setSale(salePercentage);
		cout << "Sale of " << salePercentage << "% created in department " << selectedDepartment->getName() << endl;
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const DepartmentNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
}

void displayBranchDetails(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		cout << *selectedBranch;
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
}

void displayInventoryDetails(ChainStore*& store)
{
	try
	{
		Branch* selectedBranch = getBranchFromStore(store);
		Department* selectedDepartment = getDepartmentFromBranch(selectedBranch);
		selectedDepartment->showInventory();
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const DepartmentNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const InventoryEmptyException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot show department inventory." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
}

void displayChainStoreDetails(ChainStore*& store)
{
	cout << *store << "\n";
}

void cleanupAndExit(ChainStore*& store)
{
	cout << *store << "\n";
	delete store;
	//store = nullptr; // No need to delete the store pointer as it's managed by the Singleton
	cout << "Exiting program. Goodbye!" << endl;
}


// Helper functions for operations
bool getBranchAndDepartment(ChainStore*& store, Branch*& selectedBranch, Department*& selectedDepartment)
{
	try
	{
		selectedBranch = getBranchFromStore(store);
		selectedDepartment = getDepartmentFromBranch(selectedBranch);
		return true;
	}
	catch (const BranchNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const DepartmentNotFoundException& e)
	{
		cout << e.what() << endl;
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
		cout << "Cannot add / remove item." << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred." << endl;
	}
	return false;
}

Branch* getBranchFromStore(ChainStore*& store)
{
	if (store->getNumBranches() == 0)
		throw BranchNotFoundException();

	cout << "\n--------- Select a branch ---------" << endl;
	store->showBranchesArray();

	Branch* selectedBranch = nullptr;
	int attempts = 0;

	while (attempts < MAX_ITERATIONS_LOOPS)
	{
		int max = store->getNumBranches();
		int branchIndex = getValidIntegerInput("Enter branch number: ", 1, max);

		try
		{
			selectedBranch = (*store)[branchIndex - 1];
			return selectedBranch;
		}
		catch (BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid branch index\n";
			attempts++;
		}
		catch (...)
		{
			cout << "Unknown error occurred, try again." << endl;
			attempts++;
		}
	}
	throw runtime_error("Maximum number of attempts to select branch reached. Unable to select a branch.");
}

Department* getDepartmentFromBranch(Branch*& branch)
{
	if (branch->getNumDepartments() == 0)
		throw DepartmentNotFoundException();

	cout << "\n--------- Select a department ---------" << endl;
	branch->showDepartmentArray();

	Department* selectedDepartment = nullptr;
	int attempts = 0;
	while (attempts < MAX_ITERATIONS_LOOPS)
	{
		int max = branch->getNumDepartments();
		int departmentIndex = getValidIntegerInput("Enter department number: ", 1, max);

		try
		{
			selectedDepartment = &((*branch)[departmentIndex - 1]);
			return selectedDepartment;
		}
		catch (const BranchIndexOutOfRangeException& e)
		{
			cout << e.what() << endl;
			cout << "Please enter a valid department index." << endl;
			attempts++;
		}
		catch (...)
		{
			cout << "Unknown error occurred, try again." << endl;
			attempts++;
		}
	}
	throw runtime_error("Maximum number of attempts to select department reached. Unable to select a department.");
}

Branch* createBranch(int branchType, const string& name, const string& address, const string& url)
{
	switch (branchType)
	{
	case 1:
		return new RegularBranch(name, address);
	case 2:
		return new OnlineBranch(name, url);
	case 3:
		return new OnlineRegularBranch(name, url, address);
	default:
		throw invalid_argument("Invalid branch type");
	}
}

// Main system function
void runChainStoreSystem()
{
	try
	{
		displayWelcomeMsg();
		ChainStore* store = nullptr;
		establishNetwork(store);
		if (!store)
			throw runtime_error("Failed to establish network, Store is null, Exiting..");

		while (true)
		{
			displayMenu();
			int choice = getValidIntegerInput("Enter your choice: ", 1, 10);

			switch (choice)
			{
			case 1: addNewBranch(store); break;
			case 2: addDepartmentToBranch(store); break;
			case 3: addEmployeeToBranch(store); break;
			case 4: addItemToInventory(store); break;
			case 5: removeItemFromInventory(store); break;
			case 6: createSaleInDepartment(store); break;
			case 7: displayBranchDetails(store); break;
			case 8: displayInventoryDetails(store); break;
			case 9: displayChainStoreDetails(store); break;
			case 10: cleanupAndExit(store); return;
			default:
				cout << "Invalid choice. Please enter a number between 1 and 9.\n";
				break;
			}
		}
	}
	catch (const runtime_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return;
	}
}