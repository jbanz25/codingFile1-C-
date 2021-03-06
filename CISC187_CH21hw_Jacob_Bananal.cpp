// CISC187_CH21hw_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
/**
* Jacob Bananal
*
* Chapter 21 - Homework 21 Programming Assignment
*
* May 22, 2018
*
**/

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

//user choices 
const int INSERT = 1, DISPLAYTREE = 2, LEAFCOUNTER = 3, TREEHEIGHT = 4, TREEWIDTH = 5, EXIT = 6;

//function declaration
void displayMenu();
void readUserInput(int &);
void userInput(int &, BinaryTree &);
void insertNumbers(BinaryTree &);
void displayTree(BinaryTree &);
void displayLeaf(BinaryTree &);
void displayHeight(BinaryTree &);
void displayWidth(BinaryTree &);
void endProgram();
void defaultMessage();

int main()
{
	int choice = 0; //sets choice to 0
	BinaryTree intNode; //creates a BinaryTree object
	while (choice != 6)
	{
		displayMenu();
		readUserInput(choice);
		userInput(choice, intNode);
	}
	system("pause");
	return 0;
}


/******************************************************
//name: displayMenu
//called by: userInput
//passed: nothing
//returns: choice
//calls: nothing
// This function displays the main menu for binary tree
*******************************************************/
void displayMenu()
{
	cout << "\nCapital Letters List Main Menu"
		<< "\n1). Insert numbers\n" // choice 1
		<< "2). Display the tree (in order)\n" // choice 2
		<< "3). Display Leaf Count\n" // choice 3
		<< "4). Display Tree Height\n" // choice 4
		<< "5). Display Tree Width\n" // choice 5
		<< "6). Exit\n\n"; // choice 6
}

/******************************************************
//name: readUserInput
//called by: main
//passed: int &choice 
//returns: choice 
//calls: defaultMessage
// This function will read the user input and returns the 
// users choice. If invalid choice, a message will be displayed. 
*******************************************************/
void readUserInput(int &choice)
{
	do
	{
		cout << "Enter [1-5] to select an option or [6] to exit program: ";
		cin >> choice;
		if (choice <= 0 || choice > 6) // checks to see if they input between 1-6
		{
			defaultMessage();
		}
	} while (choice <= 0 || choice > 6);
}

/******************************************************
//name: userInput
//called by: main
//passed: int &choice, BinaryTree &node
//returns: choice
//calls: functions from BinaryTree.cpp
// This function allows the user to input a choice and
// whatever choice they input such as insert, displaytree, leafCounter,
// TreeHeight, TreeWidth, and exit will display what they chose.
*******************************************************/
void userInput(int &choice, BinaryTree &node)
{
	switch (choice)
	{
	case INSERT:
		insertNumbers(node);
		break;
	case DISPLAYTREE:
		displayTree(node);
		break;
	case LEAFCOUNTER:
		displayLeaf(node);
		break;
	case TREEHEIGHT:
		displayHeight(node);
		break;
	case TREEWIDTH:
		displayWidth(node);
		break;
	case EXIT:
		endProgram();
		break;
	default:
		defaultMessage();
		break;
	}
}

/******************************************************
//name: insertNumbers
//called by: userInput
//passed: BinaryTree &p
//returns: number
//calls: insertBinaryNode()
// This function allows the user to input an integer number 
// and will be inserted in the binary tree. 
*******************************************************/
void insertNumbers(BinaryTree &p)
{
	int number;
	cout << "Enter a integer number: "; //prompts the user to input an integer number
	cin >> number;
	p.insertBinaryNode(number);

}

/******************************************************
//name: displayTree
//called by: userInput
//passed: BinaryTree &p
//returns: binary tree in order 
//calls: displayInOrder()
// This function will display the binary tree of all the 
// user inputs in order. 
*******************************************************/
void displayTree(BinaryTree &p)
{
	cout << "\nThe int binary tree has been displayed in order!" << endl;
	p.displayInOrder();
}

/******************************************************
//name: displayLeaf
//called by: userInput
//passed: BinaryTree &p
//returns: number of leaf nodes
//calls: displayLeafCounter()
// This function will display the number of leaf nodes in the 
// binary tree. 
*******************************************************/
void displayLeaf(BinaryTree &p)
{
	//displays a message with the number of leaf nodes in the tree
	cout << "\nThe number of leaf nodes in the binary tree is " << p.displayLeafCounter() << endl;
}

/******************************************************
//name: displayHeight
//called by: userInput
//passed: BinaryTree &p
//returns: height of the binary tree
//calls: displayTreeHeight()
// This function will display the height of the binary tree
// and the height is the number of level it contains. 
*******************************************************/
void displayHeight(BinaryTree &p)
{
	//displays a message with the height of the tree
	cout << "\nThe height of the binary tree is " << p.displayTreeHeight() << endl;
}

/******************************************************
//name: displayWidth
//called by: userInput
//passed: BinaryTree &p
//returns: width of the binary tree
//calls: displayTreeWidth()
// This function will display the width of the binary tree
// and the width is the largest number of nodes in the same level
*******************************************************/
void displayWidth(BinaryTree &p)
{
	// displays a message with the width of the tree
	cout << "\nThe width of the binary tree is " << p.displayTreeWidth() << endl;
}

/******************************************************
//name: defaultMessage
//called by: userInput
//passed: nothing
//returns: nothing
//calls: nobody
// This function displays the default message whenever a user
// enters an invalid message.
*******************************************************/
void defaultMessage()
{
	cout << "\nSorry! That was an invalid choice"
		<< "\nThe valid choices are 1-6"
		<< "\nRun the program again!" << endl; // displays the default message
}

/******************************************************
//name: endProgram
//called by: userInput
//passed: nothing
//returns: nothing
//calls: nobody
// This function displays a message that the program is
// ending whenever a user inputs choice 6.
*******************************************************/
void endProgram()
{
	cout << "\nThe program is ending..." << endl; //displays the end of the program message
}