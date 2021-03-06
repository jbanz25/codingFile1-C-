// CISC187_Hw21_Jacob_Bananal.cpp : Defines the entry point for the console application.
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
#include "IntBinaryTree.h"
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
void userInput(int &, IntBinaryTree &);
void insertNumbers(IntBinaryTree &);
void displayTree(IntBinaryTree &);
void displayLeaf(IntBinaryTree &);
void displayHeight(IntBinaryTree &);
void displayWidth(IntBinaryTree &);
void endProgram();
void defaultMessage();

int main()
{
	int choice = 0;
	IntBinaryTree intNode;
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
		<< "4). Display Tree Heigh\n" // choice 4
		<< "5). Display Tree Width\n" // choice 5
		<< "6). Exit\n\n"; // choice 6
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void readUserInput(int &choice)
{
	do
	{
		cout << "Enter [1-5] to select an option or [6] to exit program: ";
		cin >> choice;
		if (choice <= 0 || choice > 6) // checks to see if they input between 1-8
		{
			defaultMessage();
		}
	} while (choice <= 0 || choice > 6);
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void userInput(int &choice, IntBinaryTree &node)
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
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void insertNumbers(IntBinaryTree &p)
{
	int number;
	cout << "Enter a integer number: ";
	cin >> number;
	while (!(number))
	{
		cout << "\nSorry, invalid input, must be a numeric value! Try again: ";
		cin >> number;
	}
	p.insertBinaryNode(number);

}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void displayTree(IntBinaryTree &p)
{
	cout << "\nThe int binary tree has been displayed in order!" << endl;
	p.displayInOrder();
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void displayLeaf(IntBinaryTree &p)
{
	cout << "\nThe number of leaf nodes in the binary tree has been displayed!" << endl;
	p.displayLeafCounter();
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void displayHeight(IntBinaryTree &p)
{
	cout << "\nThe height of the binary tree has been displayed!" << endl;
	p.displayTreeHeight();
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
void displayWidth(IntBinaryTree &p)
{
	cout << "\nThe width of the binary tree has been displayed!" << endl;
	p.displayTreeWidth();
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
// ending whenever a user inputs choice 7.
*******************************************************/
void endProgram()
{
	cout << "\nThe program is ending..." << endl; //displays the end of the program message
}