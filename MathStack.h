/**
* Jacob Bananal
*
* Chapter 19 - Homework 19 Programming Assignment
*
* May 1, 2018
*
**/

#ifndef MATHSTACK_H
#define MATHSTACK_H
#include "DynIntStacks.h"

class MathStack : public DynIntStacks //inherits and derives the DynIntStacks
{
public:
	//Constructor
	MathStack() : DynIntStacks(){}

	//MathStack operations
	void add(int &,int &,int &);
	void sub(int &,int &,int &);
	void mult(int &,int &,int &);
	void div(int &,int &,int &);
	void display() const;
};
#endif // !MATHSTACK_H

