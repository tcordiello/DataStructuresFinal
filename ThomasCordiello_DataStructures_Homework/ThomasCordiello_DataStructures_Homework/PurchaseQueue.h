//****************************************************
// File: PurchaseQueue.h
//
// Purpose: Contains the member variable and function  
//          declarations for the PurchaseQueue class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************
#ifndef PURCHASEQUEUE_H
#define PURCHASEQUEUE_H

#include "Purchase.h"
#include <iostream>
#include <string>

using namespace std;

class PurchaseQueue
{
	//Member Variables
	private:
		struct PQNode
		{
			Purchase data;
			PQNode* next;
		};
		int length;
		PQNode* Front;
		PQNode* Rear;

	//Constructor and function declarations
	public:
		PurchaseQueue();
		PurchaseQueue(PurchaseQueue& rhs);
		~PurchaseQueue();

		void Clear();
		int Size();
		void Enqueue(Purchase p);
		bool Dequeue(Purchase& returnedPurchase);
		PurchaseQueue & operator=(const PurchaseQueue& rhs);

		friend ostream & operator << (ostream & os, PurchaseQueue & rhs);
};

#endif