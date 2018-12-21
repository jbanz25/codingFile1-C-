/**
* Jacob Bananal
*
* Chapter 19 - Homework 19 Programming Assignment
*
* May 1, 2018
*
**/

#include "stdafx.h"
#include <iostream>
#include "DynIntStacks.h"

/******************************************************
//name: ~DynIntStacks()
//called by: DynIntStack
//passed: nodePtr & nextNode 
//returns: nothing
//calls: nobody
// The deconstructor of theDynIntStacks
*******************************************************/
DynIntStacks::~DynIntStacks()
{
	StackNode *nodePtr = nullptr, *nextNode = nullptr;

	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

/******************************************************
//name: push
//called by: MathStack
//passed: int num
//returns: nothing
//calls: nobody
// This function push pushes the argument onto the stack. 
*******************************************************/
void DynIntStacks::push(int num)
{
	StackNode *newNode = nullptr;

	newNode = new StackNode;
	newNode->value = num;

	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

/******************************************************
//name: pop
//called by: MathStack
//passed: int &num
//returns: nothing
//calls: nobody
// This function pop pops the value at the top of the stack
// off, and copies it into the variable passed as as 
// argument
*******************************************************/
void DynIntStacks::pop(int &num)
{
	StackNode *temp = nullptr;

	if (isEmpty())
	{
		cout << "The stack is empty!\n";
	}
	else
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}


/******************************************************
//name: isEmpty()
//called by: MathStack
//passed: ntohing
//returns: true or false
//calls: nothing
// returns true if the stack is empty, or false otherwise
*******************************************************/
bool DynIntStacks::isEmpty()
{
	bool status;
	if (!top)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

