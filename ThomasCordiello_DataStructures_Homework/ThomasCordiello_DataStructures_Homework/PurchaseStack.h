//****************************************************
// File: PurchaseStack.h
//
// Purpose: Contains the member variable and function  
//          declarations for the PurchaseStack class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************

#ifndef PURCHASESTACK_H
#define PURCHASESTACK_H

#include "Purchase.h"
#include <iostream>
#include <string>

using namespace std;
#define MAX_ITEMS 10

class PurchaseStack
{
	//Private member variable
	private:
		int m_Top;
		int m_Max;
		Purchase *m_Purchases;

	//Constructor and function declarations
	public:
		PurchaseStack();
		PurchaseStack(int max);
		PurchaseStack(PurchaseStack& rhs);
		~PurchaseStack();

		void Clear();
		int Size();
		int MaxStorage();
		bool Push(Purchase p);
		bool Pop();
		bool Top(Purchase &returnedPurchase);
		PurchaseStack & operator=(PurchaseStack& rhs);

		friend ostream & operator << (ostream & os, PurchaseStack & rhs);
};

#endif