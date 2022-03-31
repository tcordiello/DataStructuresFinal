//****************************************************
// File: PurchaseList.h
//
// Purpose: Contains the member variable and function  
//          declarations for the PurchaseList class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************
#ifndef PURCHASELIST_H
#define PURCHASELIST_H

#include "Purchase.h"
#include <iostream>
#include <string>

using namespace std;

class PurchaseList
{
		//Private member variable
	private:
		struct PurchaseListNode
		{
			Purchase data;
			PurchaseListNode* next;
		};

		int length;
		PurchaseListNode* ListData;

		//Constructor and function declarations
	public:

		PurchaseList();
		PurchaseList(const PurchaseList& otherList);

		~PurchaseList();

		PurchaseList & operator=(PurchaseList& rhs);

		void Clear();
		int GetLength() const;
		void Add(const Purchase p);
		void Add(const PurchaseList& otherList);
		bool FindByItemName(string itemName, Purchase& result) const;
		void Delete(string itemName);

		//Insertion operator overload
		friend ostream & operator << (ostream & os, PurchaseList & rhs);

		//Extraction operator overload
		friend istream & operator >> (istream & is, PurchaseList & rhs);

};

#endif