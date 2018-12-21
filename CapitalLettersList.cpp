/**
    * Jacob Bananal
    *
    * Chapter 18 Programming Assignment (Linked List)
    *
    * April 17, 2018
    *
**/

#include <iostream>
#include <iomanip>
#include "CapitalLettersList.h"
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
void CapitalLettersList::appendNode(char letter)
{
    ListNode *newNode; //point to a new node
    ListNode *nodePtr; //move through the list

    newNode = new ListNode; //allocates a new node and stores a new value there
    newNode->capitalLetter = letter;
    newNode->next = nullptr;

     // checks if letter is not upper case, program will exit
     if (!isupper(letter))
    {
        cout << "\nSorry invalid input. Please enter only Capital Letters. Program will exit!\n";
        exit(EXIT_FAILURE); //program will exit if lower case is inputted
    }

    if(!head) // if there is no nodes in the list, makes the newNode the first node
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

/******************************************************
//name: insertNode
//called by: CapitalLettersList objects
//passed: int position and char letter
//returns: nothing
//calls: nothing
// This function allows the user to insert a node at any position
// but if the user inputs a lower case program will exit. Also,
// if user inputs a position out of range, then it will allow the
// user to input a valid position.
*******************************************************/
int CapitalLettersList::insertNode(int position, char letter)
{

     //checks if letter is not upper case, then program will exit
    if (!isupper(letter))
    {
        cout << "\nSorry invalid input. Please enter only Capital Letters. Program will exit!\n";
        exit(EXIT_FAILURE); // program will exit if lower case is inputted
    }

   ListNode *pre = new ListNode;   // Allocating a new node called previous
	ListNode *cur = new ListNode;   // Allocating a new node called current
	ListNode *temp = new ListNode;  // Allocating a new node called temporary
	cur = head;                     // Sets head to current

									// Low level validation to check if the user is inputting a node
									// in an existing position of the list.
	int length = 1;
	while (cur != NULL)
	{
		length++;
		cur = cur->next;
	}

	if ((position < 1) || (position >(length - 1)))
	{
		return -1;
	}

	cur = head;
	// Inserts new node in position one when user inputs a 1
	if (position == 1)
	{
		temp->capitalLetter = letter;
		temp->next = head;
		head = temp;
		return position;
	}

	else if (position > 1) // Inserts a new node in the available positions other than position 1
	{

		int i = 1;
		for (i = 1; i < position; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->capitalLetter = letter;
		pre->next = temp;
		temp->next = cur;
		return i;
	}
	return 0;

}

/******************************************************
//name: deleteNode
//called by: CapitalLettersList objects
//passed: int position
//returns: nothing
//calls: nothing
// This function allows the user to delete a node at any
// valid position they input. If user inputs a invalid position,
// it will allow them to input a valid position.
*******************************************************/
int CapitalLettersList::deleteNode(int position)
{
    ListNode *currentNode = new ListNode;  //traverse through the list
    ListNode *previousNode = new ListNode; //points to the previous node
    currentNode = head; // sets the currentNode to the head of the list
    if (head == nullptr)
    {
        return -1; //returns -1 if list is empty
    }
    else if (position == 0)
    {
        head = head->next;
    }
    else
    {
        while (currentNode != nullptr)
        {
            currentNode = currentNode->next;
        }
        if (position > 0)
        {
            currentNode = head;
            for (int i = 0; i < position; i++) // goes through each of the position
            {
                previousNode = currentNode; // sets the previous node as the current node
                currentNode = currentNode->next;
            }
            previousNode->next = currentNode->next;
        }
        else
        {
            return -1; // returns -1 if position is invalid
        }
        return -1;
    }
}

/******************************************************
//name: printList
//called by: CapitalLettersList objects
//passed: nothing
//returns: nothing
//calls: nothing
// This function allows the user print the list of their
// capital letters.
*******************************************************/
void CapitalLettersList::printList() const
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
//called by: CapitalLettersList objects
//passed: nothing
//returns: nothing
//calls: nothing
// This function allows the user to reverse the list of their
// capital letter list.
*******************************************************/
void CapitalLettersList::reverseList()
{
    ListNode *nodePtr; //traverses through the list
    ListNode *temp; // allocates a temporary
    ListNode *currentNode = nullptr;// sets currentNode to null
    nodePtr = head; // sets nodePtr at the head of the list
    while(nodePtr != nullptr) // while nodePtr is not at the end of the list
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
//called by: CapitalLettersList objects
//passed: char letter
//returns: nothing
//calls: nothing
// This function allows the user to search into the list and
// whatever letter they input, will give them the position it
// is at currently. If user inputs a invalid input such as a lower
// case letter, program will exit.
*******************************************************/
int CapitalLettersList::searchIntoList(char letter)
{
    ListNode *nodePtr; //traverses through the list
    nodePtr = head; //sets nodePtr as the head of the list
    int pos = 0; //sets the position to 0

    //checks if letter is not upper case, then program will exit
    if (!isupper(letter))
    {
        cout << "\nSorry invalid input. Please enter only Capital Letters. Program will exit!\n";
        exit(EXIT_FAILURE); //program will exit if lower case is inputted
    }

    if (head == nullptr)
    {
        return -1; //returns this if list is empty
    }
    while (nodePtr != nullptr) // while nodePtr is not at the end of the list
    {
        if (nodePtr->capitalLetter == letter)
        {
            return pos; //returns the position of the letter
        }
        pos++; // moves to the next position
        nodePtr = nodePtr->next;
    }
    return -1;
}

/******************************************************
//name: ~CapitalLettersList
//called by: CapitalLettersList objects
//passed: nothing
//returns: nothing
//calls: nothing
// This function is the destructor which deletes every
// node in the list.
*******************************************************/
CapitalLettersList::~CapitalLettersList()
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
