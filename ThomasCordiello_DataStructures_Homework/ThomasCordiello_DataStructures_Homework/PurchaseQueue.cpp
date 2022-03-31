//****************************************************
// File: PurchaseQueue.cpp
//
// Purpose: Contains the constructor/destructor and function  
//          definitions for the PurchaseQueue class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//
//****************************************************

#include "stdafx.h"
#include "PurchaseQueue.h"
#include <iomanip>
#include <fstream>

//****************************************************
// Function: PurchaseQueue Default Constructor
//
// Purpose: Gives default values to a new instance of
//			the PurchaseQueue class.
//
// Runtime: O(1)
//
//****************************************************
PurchaseQueue::PurchaseQueue()
{
	length = 0;
	Front = NULL;
	Rear = NULL;
}

//****************************************************
// Function: PurchaseQueue Copy Constructor
//
// Purpose: Makes a deep copy of an existing PurchaseQueue
//			class instance.
//
// Runtime: O(n)
//
//****************************************************
PurchaseQueue::PurchaseQueue(PurchaseQueue & rhs)
{
	*this = rhs;
}

//****************************************************
// Function: PurchaseQueue Destructor
//
// Purpose: Deallocates memory that was allocated when
//			the class instance was created.
//
// Runtime: O(n)
//
//****************************************************
PurchaseQueue::~PurchaseQueue()
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: Clears the queue.
//
// Runtime: O(n)
//
//****************************************************
void PurchaseQueue::Clear()
{
	PQNode* tp;

	while (Front != NULL) {
		tp = Front;
		Front = Front->next;
		delete tp;
	}

	Rear = NULL;
	length = 0;
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the current instance
//			of the PurchaseQueue.
//
// Runtime: O(1)
//
//****************************************************
int PurchaseQueue::Size()
{
	return length;
}

//****************************************************
// Function: Enqueue
//
// Purpose: Adds a Purchase to the rear of the 
//			PurchaseQueue.
//
// Runtime: O(1)
//
//****************************************************
void PurchaseQueue::Enqueue(Purchase p)
{
	PQNode* newNode = new PQNode;
	newNode->data = p;
	newNode->next = NULL;

	if (Rear == NULL) {
		Front = newNode;
	}
	else {
		Rear->next = newNode;
	}
	Rear = newNode;
	length++;
}

//****************************************************
// Function: Dequeue
//
// Purpose: Removes and returns the item at the front
//			of the queue.
//
// Runtime: O(1)
//
//****************************************************
bool PurchaseQueue::Dequeue(Purchase & returnedPurchase)
{
	if (Front == NULL) {
		cerr << "\nQueue is empty.\n" << endl;
		return false;
	}
	else {
		PQNode* tp;
		tp = Front;

		returnedPurchase = Front->data;
		Front = Front->next;

		if (Front == NULL) {
			Rear = NULL;
		}
		
		delete tp;
		length--;
		return true;
	}
}

//****************************************************
// Function: Assignment Operator Overload
//
// Purpose: Overloads the assignment operator to make
//			a deep copy of the passed in PurchaseQueue.
//
// Runtime: O(n)
//
//****************************************************
PurchaseQueue & PurchaseQueue::operator=(const PurchaseQueue & rhs)
{
	Clear();

	length = 0;

	PQNode *rhstp;
	rhstp = rhs.Front;

	for (int i = 0; i < rhs.length; i++) {
		Enqueue(rhstp->data);
		rhstp = rhstp->next;
	}

	return *this;
}

//****************************************************
// Function: Insertion Operator Overload
//
// Purpose: Overloads the insertion operator for use
//			with an instance of the PurchaseQueue class.
//
// Runtime: O(n)
//
//****************************************************
ostream & operator<<(ostream & os, PurchaseQueue & rhs)
{
	PurchaseQueue::PQNode *tp;
	tp = rhs.Front;

	if ((rhs.length == 0) || (rhs.Front == NULL)) {
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
