//****************************************************
// File: Purchase.h
//
// Purpose: Contains the member variables and function 
//          declarations for the Purchase class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************

#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include <iostream>

using namespace std;

class Purchase
{
	//Private member variables
	private:
		string *m_ItemName;
		double *m_Quantity;
		double *m_ItemPrice;

	public:
		//Default Constructor declaration
		Purchase();

		//Parameterized Constructor declaration
		Purchase(string itemName, double quantity, double itemPrice);

		//Copy Constructor declaration
		Purchase(const Purchase& rhs);

		//Destructor declaration
		~Purchase();

		//Get function declarations
		string GetItemName();
		double GetQuantity();
		double GetItemPrice();

		//Set function declarations
		void SetItemName(string itemName);
		void SetQuantity(double quantity);
		void SetItemPrice(double itemPrice);

		//Cost function declaration
		double Cost();

		//Overload for assignment operator declaration
		Purchase& Purchase::operator= (const Purchase &rhs);

		//Overload for equality operator declaration
		friend bool operator==(Purchase &lhs, Purchase& rhs);

		//Overload for the less than operator declaration
		friend bool operator<(Purchase &lhs, Purchase& rhs);

		//Overload for the greater than operator declaration
		friend bool operator>(Purchase &lhs, Purchase& rhs);
};
//Overload for insertion operator declaration
ostream & operator << (ostream & os, Purchase & rhs);

//Overload for extraction operator declaration
istream & operator >> (istream & is, Purchase & rhs);

#endif