/**
* Jacob Bananal
*
* Chapter 19 - Homework 19 Programming Assignment
*
* May 1, 2018
*
**/

#ifndef DYNINTSTACKS_H
#define DYNINTSTACKS_H
#include <iostream>
using namespace std;

class DynIntStacks
{
protected:
	struct StackNode
	{
		int value; // value in the node 
		StackNode *next; // pointer to the next node 
	};

	StackNode *top; //pointer to the stack top

public:
	//constructor
	DynIntStacks()
	{
		top = nullptr;
	}
	~DynIntStacks(); //deconstructor

	//stack operations
	void push(int);
	void pop(int &);
	bool isEmpty();
};

#endif // !DYNINTSTACKS_H

