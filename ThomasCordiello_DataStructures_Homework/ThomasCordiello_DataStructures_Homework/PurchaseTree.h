//****************************************************
// File: PurchaseTree.h
//
// Purpose: Contains the member variable and function  
//          declarations for the PurchaseTree class.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************
#ifndef PURCHASETREE_H
#define PURCHASETREE_H

#include "Purchase.h"
#include <iostream>
#include <string>

using namespace std;

class PurchaseTree {

	//Member Variables and helper function declarations
	private:
		struct TreeNode {
			Purchase data;
			TreeNode* right;
			TreeNode* left;
		};
		TreeNode* root;
		int m_Size;
		void Clear(TreeNode * tree);
		void Add(TreeNode *& tree, Purchase p);
		void InOrder(TreeNode * tree);
		void PreOrder(TreeNode * tree);
		void PostOrder(TreeNode * tree);
		bool GetCost(TreeNode * tree, string itemName, double& cost);
		void CopyTree(TreeNode*& tree, const TreeNode* rhs);
		void PrintTree(TreeNode * tree, ostream & os);


		//Constructor and function declarations
	public:
		PurchaseTree();
		PurchaseTree(PurchaseTree& rhs);
		~PurchaseTree();
		void Clear();
		int Size();
		void Add(Purchase p);
		void PreOrder();
		void InOrder();
		void PostOrder();
		bool GetCost(string itemName, double& cost);

		//Assignment operator overload
		PurchaseTree& operator=(PurchaseTree& rhs);

		//Insertion operator overload
		friend ostream & operator << (ostream & os, PurchaseTree & rhs);

};

#endif