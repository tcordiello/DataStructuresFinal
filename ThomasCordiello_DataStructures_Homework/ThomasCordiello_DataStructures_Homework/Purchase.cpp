//****************************************************
// File: Purchase.cpp
//
// Purpose: Contains the constructor/destructor and function definitions 
//          for the Purchase class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//
//****************************************************

#include "stdafx.h"
#include "Purchase.h"
#include <iomanip>

//****************************************************
// Function: Purchase Default Constructor
//
// Purpose: Initializes the member variables with default 
//			values when an instance of the class is created.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: Member variables were changed
//              to pointers. Updated code so that it
//              allocates memory for the member variables
//				before setting their values. 
//
//****************************************************

Purchase::Purchase()
{
	m_ItemName = new string;
	m_Quantity = new double;
	m_ItemPrice = new double;

	*m_ItemName = "No name";
	*m_Quantity = 0;
	*m_ItemPrice = 0;
}

//****************************************************
// Function: Purchase Parameterized Constructor
//
// Purpose: Initializes the member variables with user provided 
//			values when an instance of the class is created.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: Member variables were changed
//              to pointers. Updated code so that it
//              allocates memory for the member variables
//				before setting their values.
//
//****************************************************
Purchase::Purchase(string itemName, double quantity, double itemPrice)
{
	m_ItemName = new string;
	m_Quantity = new double;
	m_ItemPrice = new double;

	*m_ItemName = itemName;
	*m_Quantity = quantity;
	*m_ItemPrice = itemPrice;
}

//****************************************************
// Function: Purchase Copy Constructor
//
// Purpose: Initializes the member variables, with copied 
//			values from another instance, when an instance 
//			of the class is created.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: Member variables were changed
//              to pointers. Updated code so that it
//              allocates memory for the member variables
//				before setting their values. 
//
//****************************************************
Purchase::Purchase(const Purchase& rhs)
{
	m_ItemName = new string;
	m_Quantity = new double;
	m_ItemPrice = new double;

	*m_ItemName = *rhs.m_ItemName;
	*m_Quantity = *rhs.m_Quantity;
	*m_ItemPrice = *rhs.m_ItemPrice;
}

//****************************************************
// Function: Purchase Destructor
//
// Runtime: O(1)
//
// Purpose: Deallocates the memory that was allocated
//			for the member variables.
//
//****************************************************
Purchase::~Purchase()
{
	delete m_ItemName;
	m_ItemName = NULL;

	delete m_Quantity;
	m_Quantity = NULL;

	delete m_ItemPrice;
	m_ItemPrice = NULL;
}

//****************************************************
// Function: GetItemName
//
// Purpose: Returns the value stored in the m_ItemName variable.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: ItemName member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
string Purchase::GetItemName()
{
	return *m_ItemName;
}

//****************************************************
// Function: GetQuantity
//
// Purpose: Returns the value stored in the m_Quantity variable.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: Quantity member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
double Purchase::GetQuantity()
{
	return *m_Quantity;
}

//****************************************************
// Function: GetItemPrice
//
// Purpose: Returns the value stored in the m_ItemPrice variable.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: ItemPrice member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
double Purchase::GetItemPrice()
{
	return *m_ItemPrice;
}

//****************************************************
// Function: SetItemName
//
// Purpose: Sets the m_ItemName variable to the given value.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: ItemName member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
void Purchase::SetItemName(string itemName)
{
	*m_ItemName = itemName;
}

//****************************************************
// Function: SetQuantity
//
// Purpose: Sets the m_Quantity variable to the given value.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: Quantity member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
void Purchase::SetQuantity(double quantity)
{
	*m_Quantity = quantity;
}

//****************************************************
// Function: SetItemPrice
//
// Purpose: Sets the m_ItemPrice variable to the given value.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: ItemPrice member variable was changed
//              to a pointer. Updated code so that it
//              works with pointers. 
//
//****************************************************
void Purchase::SetItemPrice(double itemPrice)
{
	*m_ItemPrice = itemPrice;
}

//****************************************************
// Function: Cost
//
// Purpose: Calculates the cost of a purchase by multiplying 
//			the quantity by the price.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Thomas Cordiello
// Date: 10/06/18
// Description: ItemPrice and Quantity member variables were
//              changed to pointers. Updated code so that it
//              works with pointers. 
//
//****************************************************
double Purchase::Cost()
{
	double cost;
	cost = *m_Quantity * *m_ItemPrice;

	return cost;
}

//****************************************************
// Function: Assignment Operator Overload
//
// Purpose: Overloads the assignment operator to make
//			a deep copy of the passed in Purchase.
//
// Runtime: O(1)
//
//****************************************************
Purchase& Purchase::operator= (const Purchase &rhs)
{
	*m_ItemName = *rhs.m_ItemName;
	*m_Quantity = *rhs.m_Quantity;
	*m_ItemPrice = *rhs.m_ItemPrice;

	return *this;
}

//****************************************************
// Function: Equality Operator Overload
//
// Purpose: Overloads the equality operator for use
//			with an instance of the Purchase class.
//
// Runtime: O(1)
//
//****************************************************
bool operator==(Purchase & lhs, Purchase & rhs)
{
	if (lhs.GetItemName() == rhs.GetItemName()) {
		return true;
	}
	else {
		return false;
	}
}

//****************************************************
// Function: Less Than Operator Overload
//
// Purpose: Overloads the less than operator for use
//			with an instance of the Purchase class.
//
// Runtime: O(1)
//
//****************************************************
bool operator<(Purchase & lhs, Purchase & rhs)
{
	if (lhs.GetItemName() < rhs.GetItemName()) {
		return true;
	}
	else {
		return false;
	}
}

//****************************************************
// Function: Greater Than Operator Overload
//
// Purpose: Overloads the greater than operator for use
//			with an instance of the Purchase class.
//
// Runtime: O(1)
//
//****************************************************
bool operator>(Purchase & lhs, Purchase & rhs)
{
	if (lhs.GetItemName() > rhs.GetItemName()) {
		return true;
	}
	else {
		return false;
	}
}

//****************************************************
// Function: Insertion Operator Overload
//
// Purpose: Overloads the insertion operator for use
//			with an instance of the Purchase class.
//
// Runtime: O(1)
//
//****************************************************
ostream & operator << (ostream & os, Purchase & rhs)
{
	os << "Item: " << rhs.GetItemName() << endl;
	os << "Quantity: " << rhs.GetQuantity() << endl;
	os << "Price: " << setprecision(2) << fixed << "$" << rhs.GetItemPrice() << endl;
	return os;
}

//****************************************************
// Function: Extraction Operator Overload
//
// Purpose: Overloads the extraction operator for use
//			with an instance of the Purchase class.
//
// Runtime: O(1)
//
//****************************************************
istream & operator >> (istream & is, Purchase & rhs)
{
	string name;
	double quant, price;

	is >> name >> quant >> price;

	rhs.SetItemName(name);
	rhs.SetQuantity(quant);
	rhs.SetItemPrice(price);

	return is;
}