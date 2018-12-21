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
using namespace std;

/******************************************************
//name: appendNode
//called by: CapitalLettersList objects
//passed: char letter
//returns: nothing
//calls: nothing
// This function allows the user to append a capital letter
// but program will exit if user inputs a lower case letter.
*******************************************************/
void CapitalLetter::appendNode(char letter)
{
	ListNode *newNode; //point to a new node
	ListNode *nodePtr; //move through the list

	newNode = new ListNode; //allocates a new node and stores a new value there
	newNode->capitalLetter = letter;
	newNode->next = nullptr;

	// checks if letter is not upper case, program will exit
	if (islower(letter))
	{
		exit(EXIT_FAILURE); //program will exit if lower case is inputted
	}
	else
	{
		if (!head) // if there is no nodes in the list, makes the newNode the first node
		{
			head = newNode;
		}
		else
		{
			nodePtr = head; // initializes nodePtr to the head of the list
			while (nodePtr->next) // finds the last node in the list
			{
				nodePtr = nodePtr->next;
			}
			nodePtr->next = newNode; // inserts newNode as the lastNode
		}
	}
}

/******************************************************
//name: insertNode
//called by: CapitalLetter
//passed: int position and char letter
//returns: nothing
//calls: nothing
// This function allows the user to insert a node at any position
// but if the user inputs a lower case program will exit. Also,
// if user inputs a position out of range, then it will allow the
// user to input a valid position.
*******************************************************/
int CapitalLetter::insertNode(int position, char letter)
{
	ListNode *previousNode = new ListNode;   // Allocates a new node
	ListNode *nodePtr = new ListNode;   // Allocates a new node
	ListNode *temporary = new ListNode;  // Allocates a new node for storage
	nodePtr = head;                     // Sets nodePtr to head

	//checks if letter is not upper case, then program will exit
	if (islower(letter))
	{
		exit(EXIT_FAILURE); // program will exit if lower case and not upper case
	}

	int size = 1;
	while (nodePtr != nullptr)
	{
		size++;
		nodePtr = nodePtr->next;
	}

	if ((position < 1) || (position > (size - 1))) // checks if position doesnt exist 
	{
		return -1; //invalid position 
	}

	nodePtr = head;
	// Inserts new node in position one 
	if (position == 1)
	{
		temporary->capitalLetter = letter;
		temporary->next = head;
		head = temporary;
		return position;
	}

	else if (position > 1) // Inserts a new node in the available positions
	{

		for (int i = 1; i < position; i++)  // goes through the list to see the available positions to insert
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		temporary->capitalLetter = letter;
		previousNode->next = temporary;
		temporary->next = nodePtr;
	}
	else
	{
		return -1; //invalid positon 
	}
}

/******************************************************
//name: deleteNode
//called by: CapitalLetter
//passed: int position
//returns: nothing
//calls: nothing
// This function allows the user to delete a node at any
// valid position they input. If user inputs a invalid position,
// it will allow them to input a valid position.
*******************************************************/
int CapitalLetter::deleteNode(int position)
{
	ListNode *nodePtr = new ListNode; // allocates a new node 
	ListNode *previousNode = new ListNode; // allocates a new node 
	ListNode *temporary = new ListNode; // allocates a new new node for storage 

	nodePtr = head;
	int size = 1;
	while (nodePtr != nullptr)
	{
		size++;
		nodePtr = nodePtr->next;
	}

	if ((position < 0) || (position > (size  - 1))) // checks if position doesn't exist 
	{
		return -1; 
	}

	if (position == 0) // if position is 0 then it sets the temporary and returns positions
	{
		temporary = head;
		head = head->next;
		delete temporary;
		return position; // returns the position once deleted the temporary 
	}

	else
	{
		nodePtr = head;
		for (int i= 1; i < position; i++) // goes through each node to see if that position exist 
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = nodePtr->next;
	}
	return 0;
}

/******************************************************
//name: printList
//called by: CapitalLetter
//passed: nothing
//returns: nothing
//calls: nothing
// This function allows the user print the list of their
// capital letters.
*******************************************************/
void CapitalLetter::printList() const
{
	ListNode *nodePtr; // to move through the list
	nodePtr = head; // sets nodePtr at the head of the list
	while (nodePtr)
	{
		cout << nodePtr->capitalLetter << endl; // prints the value in this node

		nodePtr = nodePtr->next; // moves to the next node
	}
}

/******************************************************
//name: reverseList
//called by: CapitalLetter
//passed: nothing
//returns: nothing
//calls: nothing
// This function allows the user to reverse the list of their
// capital letter list.
*******************************************************/
void CapitalLetter::reverseList()
{
	ListNode *nodePtr; //traverses through the list
	ListNode *temp; // allocates a temporary
	ListNode *currentNode = nullptr;// sets currentNode to null
	nodePtr = head; // sets nodePtr at the head of the list
	while (nodePtr != nullptr) // while nodePtr is not at the end of the list
	{
		temp = nodePtr->next; // saves a pointer to the next node
		nodePtr->next = currentNode;
		currentNode = nodePtr; //puts current Node into nodePtr
		nodePtr = temp; //puts nodePtr into the temporary

	}
	head = currentNode;
}

/******************************************************
//name: searchIntoList
//called by: CapitalLetter
//passed: char letter
//returns: nothing
//calls: nothing
// This function allows the user to search into the list and
// whatever letter they input, will give them the position it
// is at currently. If user inputs a invalid input such as a lower
// case letter, program will exit.
*******************************************************/
int CapitalLetter::searchIntoList(char letter)
{
	ListNode *nodePtr; //traverses through the list
	nodePtr = head; //sets nodePtr as the head of the list
	int pos = -1; //sets the position to -1

				  //checks if letter is not upper case, then program will exit
	if (islower(letter))
	{
		exit(EXIT_FAILURE); //program will exit if lower case is inputted
	}
	else
	{
		if (!head)
		{
			return -1; //returns this if list is empty
		}
		while (nodePtr) // while nodePtr is not at the end of the list
		{
			pos++;
			if (nodePtr->capitalLetter == letter)
			{
				return pos; //returns the position of the letter
			}
			else
			{
				nodePtr = nodePtr->next; // moves to the next 
			}
		}
		return -1; // returns -1 if position or letter doesnt exist 
	}
}

/******************************************************
//name: countNumberOfNodes
//called by: CapitalLetter
//passed: ListNode object
//returns: number of nodes in the list 
//calls: countNumberofNodes
// This recursive function will count how many nodes are
// in the list if there are none, then it will return 0
*******************************************************/
int CapitalLetter::countNumberOfNodes(ListNode *nodePtr) const
{
	if (nodePtr != nullptr) // if current node has a value then returns the number 
	{
		return 1 + countNumberOfNodes(nodePtr->next);
	}
	else
	{
		return 0; // returns 0 if no values 
	}
}

/******************************************************
//name: maxNode
//called by: CapitalLetter 
//passed: ListNode object
//returns: max value 
//calls: maxNode
// This is a recursive function that will go through the list
// and find the maximum value assuming that B is greater than A
*******************************************************/
char CapitalLetter::maxNode(ListNode *nodePtr) const
{
	char tempMaximum; // temporary maximum value to compare
	char largeValue = nodePtr->capitalLetter; 

	if (nodePtr->next == nullptr)
	{
		return largeValue; // returns large value if the next node is null
	}
	else
	{
		tempMaximum = maxNode(nodePtr->next); //sets temp to the next node
	}
	if (largeValue > tempMaximum) //compares so we know which is bigger in the list 
	{
		return largeValue; // returns the head if greater than the next node
	}
	else
	{
		return tempMaximum; // returns the next node if greater than the head
	}
}

/******************************************************
//name: ~CapitalLetters
//called by: CapitalLettersList objects
//passed: nothing
//returns: nothing
//calls: nothing
// This function is the destructor which deletes every
// node in the list.
*******************************************************/
CapitalLetter::~CapitalLetter()
{
	ListNode *nodePtr; // traverse the list
	ListNode *nextNode; //points to the next node

	nodePtr = head; //positions nodePtr at the head of the list

	while (nodePtr != nullptr) // while nodePtr is not at the end of the list
	{
		nextNode = nodePtr->next; // this saves a pointer to the next node
		delete nodePtr; // deletes the current node
		nodePtr = nextNode; //this positions nodePtr at the next node
	}
}