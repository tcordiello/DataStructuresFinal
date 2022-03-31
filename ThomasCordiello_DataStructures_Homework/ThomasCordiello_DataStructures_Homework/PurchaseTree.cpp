//****************************************************
// File: PurchaseTree.cpp
//
// Purpose: Contains the constructor/destructor and function  
//          definitions for the PurchaseTree class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//
//****************************************************

#include "stdafx.h"
#include "PurchaseTree.h"
#include <iomanip>
#include <fstream>

//****************************************************
// Function: PurchaseTree Default Constructor
//
// Purpose: Gives default values to a new instance of
//			the PurchaseTree class.
//
// Runtime: O(1)
//
//****************************************************
PurchaseTree::PurchaseTree() 
{
	root = NULL;
	m_Size = 0;
}

//****************************************************
// Function: PurchaseTree Copy Constructor
//
// Purpose: Makes a deep copy of an existing 
//			PurchaseTree class instance.
//
// Runtime: O(log n)
//
//****************************************************
PurchaseTree::PurchaseTree(PurchaseTree& rhs) 
{
	*this = rhs;
}

//****************************************************
// Function: PurchaseTree Destructor
//
// Purpose: Deallocates memory that was allocated when
//			the class instance was created.
//
// Runtime: O(log n)
//
//****************************************************
PurchaseTree::~PurchaseTree() 
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: Calls the Clear helper function. Then,
//			sets the size member variable to 0.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::Clear() 
{
	Clear(root);
	root = NULL;
	m_Size = 0;
}

//****************************************************
// Function: Clear (helper)
//
// Purpose: Clears the tree.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::Clear(TreeNode * tree) 
{
	if (tree != NULL) {
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the current instance
//			of the PurchaseTree.
//
// Runtime: O(1)
//
//****************************************************
int PurchaseTree::Size() 
{
	return m_Size;
}

//****************************************************
// Function: Add
//
// Purpose: Calls the Add helper function.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::Add(Purchase p) 
{
		Add(root, p);
		m_Size++;
}

//****************************************************
// Function: Add (helper)
//
// Purpose: Finds the correct placement in the tree,
//			and then add the purchase.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::Add(TreeNode*& tree, Purchase p) 
{
	if (tree == NULL) {
		tree = new TreeNode;
		tree->data = p;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (p < tree->data) {
		Add(tree->left, p);
	}
	else {
		Add(tree->right, p);
	}
}

//****************************************************
// Function: PreOrder
//
// Purpose: Calls the PreOrder helper function.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::PreOrder() 
{
	PreOrder(root);
}

//****************************************************
// Function: PreOrder (helper)
//
// Purpose: Prints the item names of the Purchases in
//			the tree in pre-order.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::PreOrder(TreeNode * tree) 
{
	if (tree != NULL) {
		if (tree != NULL) {
			cout << tree->data.GetItemName() << endl;
			InOrder(tree->left);
			InOrder(tree->right);
		}
	}
}

//****************************************************
// Function: InOrder
//
// Purpose: Calls the InOrder helper function.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::InOrder() 
{
	InOrder(root);
}

//****************************************************
// Function: InOrder (helper)
//
// Purpose: Prints the item names of the Purchases in
//			the tree in alphabetical order.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::InOrder(TreeNode * tree) 
{
	if (tree != NULL) {
		InOrder(tree->left);
		cout << tree->data.GetItemName() << endl;
		InOrder(tree->right);
	}
}

//****************************************************
// Function: PostOrder
//
// Purpose: Calls the PostOrder helper function.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::PostOrder() 
{
	PostOrder(root);
}

//****************************************************
// Function: PostOrder (helper)
//
// Purpose: Prints the item names of the Purchases in
//			the tree in post-order.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::PostOrder(TreeNode * tree) 
{
	if (tree != NULL) {
		InOrder(tree->left);
		InOrder(tree->right);
		cout << tree->data.GetItemName() << endl;
	}
}

//****************************************************
// Function: GetCost
//
// Purpose: Calls the GetCost helper function.
//
// Runtime: O(log n)
//
//****************************************************
bool PurchaseTree::GetCost(string itemName, double& cost) 
{
	return GetCost(root, itemName, cost);
}

//****************************************************
// Function: GetCost (helper)
//
// Purpose: Attempts to Find the given item name in
//			the purchase list and returns the cost of
//			that item.
//
// Runtime: O(log n)
//
//****************************************************
bool PurchaseTree::GetCost(TreeNode * tree, string itemName, double& cost) 
{
	if (tree == NULL) {
		return false;
	}

	if (tree->data.GetItemName() == itemName) {
		cost = tree->data.Cost();
		return true;
	}

	if (itemName < tree->data.GetItemName()) {
		return GetCost(tree->left, itemName, cost);
	}

	return GetCost(tree->right, itemName, cost);
}

//****************************************************
// Function: Assignment Operator Overload
//
// Purpose: Clears the current instance of PurchaseTree,
//			and calls the CopyTree helper function.
//
// Runtime: O(log n)
//
//****************************************************
PurchaseTree& PurchaseTree::operator=(PurchaseTree& rhs)
{
	Clear();
	m_Size = 0;
	CopyTree(root, rhs.root);
	return *this;
}

//****************************************************
// Function: CopyTree 
//			 (Assignment Operator Overload helper)
//
// Purpose: Makes a deep copy of the passed in PurchaseTree.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::CopyTree(TreeNode *& tree, const TreeNode * rhs)
{
	if (rhs == NULL)
		tree = NULL;
	else
	{
		tree = new TreeNode;
		tree->data = rhs->data;
		m_Size++;
		CopyTree(tree->left, rhs->left);
		CopyTree(tree->right, rhs->right);
	}
}

//****************************************************
// Function: Insertion Operator Overload
//
// Purpose: Calls the PrintTree helper function.
//
// Runtime: O(log n)
//
//****************************************************
ostream & operator << (ostream & os, PurchaseTree & rhs)
{
	if (rhs.root != NULL)
	{
		rhs.PrintTree(rhs.root, os);
		return os;
	}
	else
	{
		os << "The tree is empty" << endl;
	}
}

//****************************************************
// Function: PrintTree 
//			 (Insertion Operator Overload helper)
//
// Purpose: Prints the elements in the PurchaseTree.
//
// Runtime: O(log n)
//
//****************************************************
void PurchaseTree::PrintTree(TreeNode* tree, ostream& os)
{
	if (tree != NULL)
	{
		PrintTree(tree->left, os);
		os << tree->data;
		PrintTree(tree->right, os);
	}

}