//****************************************************
// File: PurchaseList.cpp
//
// Purpose: Contains the constructor/destructor and function  
//          definitions for the PurchaseList class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//
//****************************************************

#include "stdafx.h"
#include "PurchaseList.h"
#include <iomanip>
#include <fstream>

//****************************************************
// Function: PurchaseList Default Constructor
//
// Purpose: Gives default values to a new instance of
//			the PurchaseList class.
//
// Runtime: O(1)
//
//****************************************************
PurchaseList::PurchaseList()
{
	length = 0;
	ListData = NULL;
}

//****************************************************
// Function: PurchaseList Copy Constructor
//
// Purpose: Makes a deep copy of an existing PurchaseList
//			class instance.
//
// Runtime: O(n)
//
//****************************************************
PurchaseList::PurchaseList(const PurchaseList & otherList)
{
	length = 0;

	PurchaseListNode *rhstp;
	rhstp = otherList.ListData;

	for (int i = 0; i < otherList.length; i++) {
		PurchaseList::Add(rhstp->data);
		rhstp = rhstp->next;
	}
}

//****************************************************
// Function: PurchaseList Destructor
//
// Purpose: Deallocates memory that was allocated when
//			the class instance was created.
//
// Runtime: O(n)
//
//****************************************************
PurchaseList::~PurchaseList()
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: Clears the list.
//
// Runtime: O(n)
//
//****************************************************
void PurchaseList::Clear()
{
	PurchaseListNode *tp;

	while (ListData != NULL) {
		tp = ListData;
		ListData = ListData->next;
		delete tp;
	}

	length = 0;
}

//****************************************************
// Function: GetLength
//
// Purpose: Returns the length of the current instance
//			of the PurchaseList.
//
// Runtime: O(1)
//
//****************************************************
int PurchaseList::GetLength() const
{
	return length;
}

//****************************************************
// Function: Add(const Purchase p)
//
// Purpose: Adds a Purchase to the PurchaseList.
//
// Runtime: O(1)
//
//****************************************************
void PurchaseList::Add(const Purchase p)
{
	PurchaseListNode *newNode = new PurchaseListNode;
	newNode->data = p;
	newNode->next = NULL;
	
	if (ListData == NULL) {
		ListData = newNode;
	}
	else {
		newNode->next = ListData;
		ListData = newNode;
	}

	length++;
}

//****************************************************
// Function: Add(const PurchaseList & otherList)
//
// Purpose: Adds Purchases from another PurchaseList
//			to the current PurchaseList.
//
// Runtime: O(n)
//
//****************************************************
void PurchaseList::Add(const PurchaseList & otherList)
{
	PurchaseListNode *rhstp;
	rhstp = otherList.ListData;

	for (int i = 0; i < otherList.length; i++) {
		PurchaseList::Add(rhstp->data);
		rhstp = rhstp->next;
	}
}

//****************************************************
// Function: FindByItemName
//
// Purpose: Finds an item in the PurchaseList by
//			comparing the item name to the name entered
//			by the user.
//
// Runtime: O(n)
//
//****************************************************
bool PurchaseList::FindByItemName(string itemName, Purchase & result) const
{
	PurchaseListNode *tp;
	tp = ListData;

	while (tp != NULL) {
		if (tp->data.GetItemName() == itemName) {
			result = tp->data;
			return true;
		}
		else {
			tp = tp->next;
		}
	}
	cout << "Item not found." << endl;
	return false;
}

//****************************************************
// Function: Delete
//
// Purpose: Finds an item in the PurchaseList by
//			comparing the item name to the name entered
//			by the user, and deletes it.
//
// Runtime: O(n)
//
//****************************************************
void PurchaseList::Delete(string itemName)
{
	PurchaseListNode *prev, *current;
	prev = ListData;
	current = ListData->next;

	if (prev->data.GetItemName() == itemName) {
		ListData = ListData->next;
		delete prev;
		length--;
		return;
	}

	while (current != NULL) {
		if (current->data.GetItemName() == itemName) {
			break;
		}
		else {
			prev = current;
			current = current->next;

		}
	}

	if (current == NULL) {
		cout << "Item not found." << endl;
		return;
	}
	else {
		prev->next = current->next;
		delete current;
		length--;
	}
}

//****************************************************
// Function: Assignment Operator Overload
//
// Purpose: Overloads the assignment operator to make
//			a deep copy of the passed in PurchaseList.
//
// Runtime: O(n)
//
//****************************************************
PurchaseList & PurchaseList::operator=(PurchaseList & rhs)
{
	Clear();

	length = 0;

	PurchaseListNode *rhstp;
	rhstp = rhs.ListData;

	for (int i = 0; i < rhs.length; i++) {
		PurchaseList::Add(rhstp->data);
		rhstp = rhstp->next;
	}

	return *this;
}

//****************************************************
// Function: Insertion Operator Overload
//
// Purpose: Overloads the insertion operator for use
//			with an instance of the PurchaseList class.
//
// Runtime: O(n)
//
//****************************************************
ostream & operator<<(ostream & os, PurchaseList & rhs)
{
	PurchaseList::PurchaseListNode *tp;
	tp = rhs.ListData;

	if ((rhs.length == 0) || (rhs.ListData == NULL)) {
		cout << "The list is empty." << endl;
		return os;
	}
	os << "****************************" << endl;
	for (int i = 0; i < rhs.length; i++) {
		if (tp != NULL) {
			os << tp->data << "\n--------------------------" << endl;
			tp = tp->next;
		}
	}
	os << "****************************" << endl;
	return os;
}

//****************************************************
// Function: Extraction Operator Overload
//
// Purpose: Overloads the extraction operator for use
//			with an instance of the PurchaseList class.
//
// Runtime: O(n)
//
//****************************************************
istream & operator >> (istream & is, PurchaseList & rhs)
{
	rhs.Clear();

	while (is.good()) {
		string name;
		double quant, price;

		is >> name;
		is >> quant;
		is >> price;

		Purchase p(name, quant, price);

		if (name != "") {
			rhs.Add(p);
		}
	}

	return is;
}
