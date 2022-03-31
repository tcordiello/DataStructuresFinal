//****************************************************
// File: PurchaseStack.cpp
//
// Purpose: Contains the constructor/destructor and function  
//          definitions for the PurchaseStack class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//
//****************************************************

#include "stdafx.h"
#include "PurchaseStack.h"
#include <iomanip>
#include <fstream>
#include <array>

//****************************************************
// Function: PurchaseStack Default Constructor
//
// Purpose: Gives default values to a new instance of
//			the PurchaseStack class.
//
// Runtime: O(1)
//
//****************************************************
PurchaseStack::PurchaseStack()
{
	m_Top = -1;
	m_Max = MAX_ITEMS;
	m_Purchases = new Purchase[MAX_ITEMS];
}

//****************************************************
// Function: PurchaseStack Parameterized Constructor
//
// Purpose: Gives user defined values to a new instance of
//			the PurchaseStack class.
//
// Runtime: O(1)
//
//****************************************************
PurchaseStack::PurchaseStack(int max)
{
	m_Top = -1;
	m_Max = max;
	m_Purchases = new Purchase[max];
}

//****************************************************
// Function: PurchaseStack Copy Constructor
//
// Purpose: Makes a deep copy of an existing PurchaseStack
//			class instance.
//
// Runtime: O(n)
//
//****************************************************
PurchaseStack::PurchaseStack(PurchaseStack & rhs)
{
	*this = rhs;
}

//****************************************************
// Function: PurchaseStack Destructor
//
// Purpose: Deallocates memory that was allocated when
//			the class instance was created.
//
// Runtime: O(n)
//
//****************************************************
PurchaseStack::~PurchaseStack()
{
	delete[] m_Purchases;
}

//****************************************************
// Function: Clear
//
// Purpose: Sets the top element to -1 clearing the stack.
//
// Runtime: O(1)
//
//****************************************************
void PurchaseStack::Clear()
{
	m_Top = -1;
}

//****************************************************
// Function: Size
//
// Purpose: Returns how many items are on the stack.
//
// Runtime: O(1)
//
//****************************************************
int PurchaseStack::Size()
{
	return (m_Top + 1);
}

//****************************************************
// Function: MaxStorage
//
// Purpose: Returns the max storage size of the stack.
//
// Runtime: O(1)
//
//****************************************************
int PurchaseStack::MaxStorage()
{
	return m_Max;
}

//****************************************************
// Function: Push
//
// Purpose: If the stack is not full, this adds an item
//			to the top of the stack.
//
// Runtime: O(1)
//
//****************************************************
bool PurchaseStack::Push(Purchase p)
{
	if (Size() == MaxStorage()) {
		cerr << "\nStack is full\n" << endl;
		return false;
	}
	else {
		m_Top++;
		m_Purchases[m_Top] = p;
		return true;
	}
}

//****************************************************
// Function: Pop
//
// Purpose: If the stack is not empty, removes the top
//			item from the stack.
//
// Runtime: O(1)
//
//****************************************************
bool PurchaseStack::Pop()
{
	if (m_Top == -1) {
		cerr << "\nStack is empty\n" << endl;
		return false;
	}
	else {
		m_Purchases[m_Top];
		m_Top--;
		return true;
	}
}

//****************************************************
// Function: Top
//
// Purpose: If the stack is not empty, returns the top
//			item from the stack.
//
// Runtime: O(1)
//
//****************************************************
bool PurchaseStack::Top(Purchase & returnedPurchase)
{
	if (m_Top == -1) {
		cerr << "\nStack is empty\n" << endl;
		return false;
	}
	else {
		returnedPurchase = m_Purchases[m_Top];
		return true;
	}
}

//****************************************************
// Function: Assignment Operator Overload
//
// Purpose: Overloads the assignment operator to make
//			a deep copy of the passed in PurchaseStack.
//
// Runtime: O(n)
//
//****************************************************
PurchaseStack & PurchaseStack::operator=(PurchaseStack & rhs)
{
	delete[] m_Purchases;

	m_Top = rhs.m_Top;
	m_Max = rhs.m_Max;
	m_Purchases = new Purchase[rhs.m_Max];
	for (int i = 0; i <= m_Top; i++) {
		m_Purchases[i].SetItemName(rhs.m_Purchases[i].GetItemName());
		m_Purchases[i].SetQuantity(rhs.m_Purchases[i].GetQuantity());
		m_Purchases[i].SetItemPrice(rhs.m_Purchases[i].GetItemPrice());
	}

	return *this;
}

//****************************************************
// Function: Insertion Operator Overload
//
// Purpose: Overloads the insertion operator for use
//			with an instance of the PurchaseStack class.
//
// Runtime: O(n)
//
//****************************************************
ostream & operator<<(ostream & os, PurchaseStack & rhs)
{
	if (rhs.m_Top == -1) {
		os << "\nStack is empty\n" << endl;
		return os;
	}
	else {
		os << "****************************" << endl;
		for (int i = 0; i < rhs.Size(); i++) {
			os << rhs.m_Purchases[i] << "\n--------------------------" << endl;
		}
		os << "****************************" << endl;
		return os;
	}
}