//****************************************************
// File: ThomasCordiello_DataStructures_Homework.cpp
//
// Purpose: Contains the main program.
//
// Written By: Thomas Cordiello
//
// Compiler: Visual Studio 2015
//              
//****************************************************

#include "stdafx.h"
#include "PurchaseTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{

	Purchase p1("Pizza", 2, 14.99);
	Purchase p2("Bacon", 2, 4);
	Purchase p3("Reeses Peanut Butter Cups", 5, 2);
	Purchase p4("Soda", 1, 3);
	Purchase p5("Chips", 4, 2.50);
	Purchase p6("Car", 1, 37999.99);
	Purchase p7("Mozzarella cheese", 1, 4.50);

	PurchaseTree pt;											//Default constructor

	pt.Add(p1);													//Add
	pt.Add(p2);
	pt.Add(p3);
	pt.Add(p4);
	pt.Add(p5);
	pt.Add(p6);
	pt.Add(p7);

	cout << "\npt size:\n" << pt.Size() << endl;				//Size function

	cout << "\npt:\n" << pt << endl;							//Insertion operator

	PurchaseTree pt2(pt);										//Copy constructor

	cout << "\npt2:\n" << pt2 << endl;

	PurchaseTree pt3 = pt2;										//Assignment operator

	cout << "\npt3:\n" << pt3 << endl;

	double cost;

	pt.GetCost("Car", cost);									//GetCost function

	cout << "\nGetCost of Car:\n" << setprecision(2) << fixed << "$" << cost << endl << endl;
	
	pt2.GetCost("Pizza", cost);

	cout << "\nGetCost of Pizza:\n" << setprecision(2) << fixed << "$" << cost << endl << endl;
	
	cout << "\nPreOrder:" << endl;
	pt.PreOrder();												//PreOrder
	cout << endl << endl;

	cout << "\nInOrder:" << endl;
	pt.InOrder();												//InOrder
	cout << endl << endl;

	cout << "\nPostOrder:" << endl;
	pt.PostOrder();												//PostOrder
	cout << endl << endl;

	pt.Clear();													//Clear

	cout << "\nSize of pt after Clear runs:\n" << pt.Size() << endl;
	cout << "\npt after Clear runs:\n" << pt << endl;

	return 0;
}

