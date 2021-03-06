// CISC187_ChHw20_Jacob_Bananal.cpp : Defines the entry point for the console application.
//

/**
* Jacob Bananal
*
* Chapter 20 - Homework 20 Programming Assignment
*
* May 15, 2018
*
**/

#include "stdafx.h"
#include "CapitalLetter.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//user choices 
const int APPENDNODE = 1, INSERTNODE = 2, DELETENODE = 3, PRINT = 4, REVERSELIST = 5, SEARCHLIST = 6, COUNTNUMBER = 7, DISPLAYMAX = 8, ENDPROGRAM = 9;

//function declaration
void displayMenu();
void readUserInput(int &);
void userInput(int &, CapitalLetter &);
void append(CapitalLetter &);
void insert(CapitalLetter &);
void deleteNode(CapitalLetter &);
void print(CapitalLetter &);
void reverse(CapitalLetter &);
void search(CapitalLetter &);
void count(CapitalLetter &);
void maxDisplay(CapitalLetter &);
void endProgram();
void defaultMessage();

int main()
{
	int choice = 0;
	CapitalLetter node;
	while (choice != 9)
	{
		displayMenu();
		readUserInput(choice);
		userInput(choice, node);
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
// This function displays the main menu for the capital letters
// list.
*******************************************************/
void displayMenu()
{
	cout << "\nCapital Letters List Main Menu"
		<< "\n1). Append Node\n" // choice 1
		<< "2). Insert at Position\n" // choice 2
		<< "3). Delete at Position\n" // choice 3
		<< "4). Print List\n" // choice 4
		<< "5). Reverse List\n" // choice 5
		<< "6). Search List\n" // choice 6
		<< "7). Count Number of Nodes\n" // choice 7
		<< "8). Display Largest Node\n" //choice 8
		<< "9). End Program\n\n";  //choice 9
}

void readUserInput(int &choice)
{
	do
	{
		cout << "Enter [1-8] to select an option or [9] to exit program: ";
		cin >> choice;
		if (choice <= 0 || choice > 9) // checks to see if they input between 1-8
		{
			defaultMessage();
		}
	} while (choice <= 0 || choice > 9);
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
void userInput(int &choice, CapitalLetter &listOfNodes)
{
	switch (choice)
	{
	case APPENDNODE:
		append(listOfNodes);
		break;
	case INSERTNODE:
		insert(listOfNodes);
		break;
	case DELETENODE:
		deleteNode(listOfNodes);
		break;
	case PRINT:
		print(listOfNodes);
		break;
	case REVERSELIST:
		reverse(listOfNodes);
		break;
	case SEARCHLIST:
		search(listOfNodes);
		break;
	case COUNTNUMBER:
		count(listOfNodes);
		break;
	case DISPLAYMAX:
		maxDisplay(listOfNodes);
		break;
	case ENDPROGRAM:
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
void append(CapitalLetter &p)
{
	char letter;
	cout << "\nEnter an appending capital letter: ";
	cin >> letter;
	while (!isupper(letter))
	{
		cout << "Sorry, invalid input! Must be a Capital Letter. Please try again: ";
		cin >> letter;
	}
	p.appendNode(letter);
}

/******************************************************
//name: insert
//called by: userInput
//passed: CapitalLetter &p
//returns: the letter and the position
//calls: insertNode
// This function allows the user to enter a capital letter 
// and a position. If position doesn't exist, then user will enter
// another position until valid. 
*******************************************************/
void insert(CapitalLetter &p)
{
	char letter;
	int position;
	cout << "\nEnter an appending letter: "; // ask for the capital letter 
	cin >> letter;
	while (!isupper(letter)) // checks if capital letter
	{
		cout << "Sorry, invalid input! Must be a Capital Letter. Please try again: ";
		cin >> letter;
	}

	cout << "\nEnter a node in position: "; // ask for the position 
	cin >> position;
	while (p.insertNode(position,letter) == -1) // checks if position is invalid and equal to -1
	{
		cout << "Sorry invalid input! Must be a valid position!";
		cout << "Enter a valid position: ";
		cin >> position;
	}
	cout << "\nDone!" << endl;
}

/*****************************************************
//name: deleteNode
//called by: userInput
//passed: CapitalLetter &p
//returns: position
//calls: deleteNode
// This function allows the user to delete a position. 
//If position doesn't exist, then user will enter
// another position until valid.
*******************************************************/
void deleteNode(CapitalLetter &p)
{
	int position;
	// allows the user to input a position to delete in the list
	cout << "\nEnter a node in position to delete: ";
	cin >> position;
	while (p.deleteNode(position) == -1) // checks if position exist or not 
	{
		cout << "\nInvalid input! Must be a valid position!\n";
		cout << "\nEnter a valid position to delete: ";
		cin >> position;
	}
	cout << "\nDone!" << endl;
}

/******************************************************
//name: print
//called by: userInput
//passed: CapitalLetter &p
//returns: list of the capital letter
//calls: printList
// This function allows the user to print the list of 
// capital letters to see what they input. 
*******************************************************/
void print(CapitalLetter &p)
{
	cout << "\nList of Capital Letters" << endl;
	cout << "_______________________" << endl;
	p.printList(); // prints the list of the capital letters
}

/******************************************************
//name: reverse
//called by: userInput
//passed: CapitalLetter &p
//returns: the reverse list of the capital letters
//calls: reverseList
// This function allows the user to reverse the list so 
// when the user displays the list, it will be reversed.
*******************************************************/
void reverse(CapitalLetter &p)
{
	cout << "\nList of Capital Letters has been reversed!" << endl;
	p.reverseList(); //calls the reverseList function
}

/******************************************************
//name: search
//called by: userInput
//passed: CapitalLetter &p
//returns: the position of the letter
//calls: searchIntoList
// This function allows the user to input a capital letter
// if letter is valid, then it will search for it. If the
// letter is not in the list, a message will display, if 
// found then it will display the position. 
*******************************************************/
void search(CapitalLetter &p)
{
	char letter;
	cout << "\nEnter a letter to search: "; // ask for the user to input a letter ot search
	cin >> letter;
	while (!isupper(letter)) // checks if letter is uppercase 
	{
		cout << "Sorry, invalid input, must be a Capital Letter. Please try again: ";
		cin >> letter;
	}

	if (p.searchIntoList(letter) == -1) // checks if the letter exist or not 
	{
		cout << "Sorry, your input was not found!" << endl;
	}
	else
	{
		cout << "Your input was found at " << p.searchIntoList(letter) << endl;
	}
}

/******************************************************
//name: count
//called by: userInput
//passed: CapitalLetter &p
//returns: the number of nodes
//calls: numNodes
// This function will display how many nodes are in the 
// list. 
*******************************************************/
void count(CapitalLetter &p)
{
	// displays the message of how many nodes there are
	cout << "\nThe number of nodes is " 
		<< p.numNodes() << endl;
}

/******************************************************
//name: maxDisplay
//called by: userInput
//passed: CapitalLetter &p
//returns: the maximum node
//calls: displayMaxNode
// This function will display the maximum node. Assuming that
//  B is greater than A. 
*******************************************************/
void maxDisplay(CapitalLetter &p)
{
	// displays the message of the maximum letter
	cout << "\nThe maximum letter is "
		<< p.displayMaxNode() << endl;
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
		<< "\nThe valid choices are 1-9"
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