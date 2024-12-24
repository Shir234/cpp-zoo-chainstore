#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "ChaineStoreExceptions.h"

#include "ChainStore.h"
#include "Branch.h"
#include "RegularBranch.h"
#include "OnlineBranch.h"
#include "OnlineRegularBranch.h"
#include "Department.h"
#include "Item.h"
#include "Employee.h"
#include "Manager.h"

const int SIZE = 100;
const int MAX_ITERATIONS_LOOPS = 5;

// Utility functions
void cleanBuffer();
bool isValidInteger(const string& str);
int getValidIntegerInput(const string& prompt, int minValue = 0, int maxValue = 100);

// UI functions
void displayMenu();
void displayWelcomeMsg();

// Chain store operations
void establishNetwork(ChainStore*& store);
void addNewBranch(ChainStore*& store);
void addDepartmentToBranch(ChainStore*& store);
void addEmployeeToBranch(ChainStore*& store);
void addItemToInventory(ChainStore*& store);
void removeItemFromInventory(ChainStore*& store);
void displayBranchDetails(ChainStore*& store);
void displayInventoryDetails(ChainStore*& store);
void displayChainStoreDetails(ChainStore*& store);
void createSaleInDepartment(ChainStore*& store);
void cleanupAndExit(ChainStore*& store);

// Helper functions for operations
bool getBranchAndDepartment(ChainStore*& store, Branch*& selectedBranch, Department*& selectedDepartment);
Branch* getBranchFromStore(ChainStore*& store);
Department* getDepartmentFromBranch(Branch*& branch);
Branch* createBranch(int branchType, const string& name, const string& address, const string& url);

// Main system function
void runChainStoreSystem();

#endif // HELPER_FUNCTIONS_H
