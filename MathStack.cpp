/**
* Jacob Bananal
*
* Chapter 19 - Homework 19 Programming Assignment
*
* May 1, 2018
*
**/

#include "stdafx.h"
#include "MathStack.h"

/******************************************************
//name: add
//called by: MathStack
//passed:  int &num, int &numTwo, int &sum
//returns: sum of the two values
//calls: pop() and push()
// This function allows the user to pop off the two top 
// values off the stack and those two values will then be added
// Once added, the value will be pushed onto the stack.
*******************************************************/
void MathStack::add(int &num, int &numTwo, int &sum) 
{
	if (!top || !top->next) // checks if enough integers on the stack
	{
		cout << "Sorry, Not enough integers.";
		exit(EXIT_FAILURE); // exits if not enough integers 
	}
	else
	{
		pop(num); // pops the two values off the stack 
		pop(numTwo);

		sum = num + numTwo; // adds the two values 

		push(sum); // replaces the sum with the two values
	}
}

/******************************************************
//name: sub
//called by: MathStack
//passed:  int &num, int &numTwo, int &mult
//returns: subtraction of the two values
//calls: pop() and push()
// This function allows the user to pop off the two values off
// the stack and those two values will then be subtracted. Then 
// the value is pushed onto the stack. 
*******************************************************/
void MathStack::sub(int &num, int &numTwo, int &diff)
{
	if (!top || !top->next) // checks if enough integers on the stack 
	{
		cout << "Sorry, Not enough integers.";
		exit(EXIT_FAILURE); //exits if not enough integers 
	}
	else
	{
		pop(num); //pops the two values off the stack
		pop(numTwo);

		diff = numTwo - num; // subtracts the difference 

		push(diff); //replaces the two values on the stack
	}
}

/******************************************************
//name: mult
//called by: MathStack
//passed:  int &num, int &numTwo, int &mult
//returns: multiplication of the two values
//calls: pop(), push()
// This function allows the user to pop the first two values 
// off the stack. Then the two values are then multiplied and
// pushed onto the stack. 
*******************************************************/
void MathStack::mult(int &num,int &numTwo, int &mult)
{
	if (!top || !top->next) // checks if there is enough integers 
	{
		cout << "Sorry, Not enough integers.";
		exit(EXIT_FAILURE); // exits if not enough integers 
	}
	else
	{
		pop(num); // pops the two top values off the stack 
		pop(numTwo);

		mult = num * numTwo; // mutiplies the values 

		push(mult); // replaces the top two values of the stack 
	}
}

/******************************************************
//name: div
//called by: MathStack 
//passed: int &num, int &numTwo, int &div
//returns: division of the two values
//calls: pop(), push()
// This function allows the user to pop the first two values
// off the stack. The second value is divided by the first num 
// then the value is pushed onto the stack.
*******************************************************/
void MathStack::div(int &num, int &numTwo, int &div)
{
	if (!top || !top->next) // checks to see if there is enough integers
	{
		cout << "Sorry, Not enough integers."; 
		exit(EXIT_FAILURE); // exits if not enough
	}
	else
	{
		pop(num); // pops the first two numbers of the stack 
		pop(numTwo);
		div = numTwo / num; // divides the two values
		while(num=0) // checks if 0 is the divisor 
		{
			cout << "Invalid operation of division because the divisor is 0!"; 
			continue; // will exit if divisor is 0
		}
		
		push(div); // replaces the two top values 
	}
}

/******************************************************
//name: display
//called by: 
//passed: temp
//returns: display of the stack
//calls: StackNode from DynIntStack
// This function allows the user to display the stack
*******************************************************/
void MathStack::display() const
{
	StackNode *temp = top; // sets temp to the top 
	while (temp != nullptr)
	{
		cout << temp->value << endl; // this will display vertically
		temp = temp->next; 
	}
}