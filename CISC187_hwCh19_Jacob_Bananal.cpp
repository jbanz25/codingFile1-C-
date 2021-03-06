// CISC187_hwCh19_Jacob_Bananal.cpp : Defines the entry point for the console application.
//

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
#include <iomanip>
#include <string>
#include "MathStack.h"
using namespace std;

//constants for the menu choices 
const int PUSH = 1, POP = 2, ADD = 3, SUB = 4, MULT = 5, DIV = 6, DISPLAY = 7, END = 8;

//function declaration
void displayMenu();
void readUserInput(int &);
void userInput(int &, MathStack &);
void pushInt(MathStack &);
void popInt(MathStack &);
void addInt(MathStack &);
void subInt(MathStack &);
void multInt(MathStack &);
void divInt(MathStack &);
void displayStack(MathStack &);
void endProgram();
void defaultMessage();

int main()
{
	int choice = 0;
	MathStack intStack;
	while(choice != 8)
	{
		displayMenu();
		readUserInput(choice);
		userInput(choice, intStack);
	}
	system("pause");
    return 0;
}

/******************************************************
//name: displayMenu
//called by:main
//passed: nothing
//returns: menu
//calls: nobody
// This functions displays the menu of the choices the
// user can input as long as they choose a valid choice
// otherwise a error message will pop up.
*******************************************************/
void displayMenu()
{

	cout << "\nMain Menu"
		<< "\n\n1). Push\n\n" // choice 1
		<< "2). Pop\n\n" // choice 2
		<< "3). Add\n\n" // choice 3
		<< "4). Subtract\n\n" // choice 4
		<< "5). Multiply\n\n" // choice 5
		<< "6). Divide\n\n" // choice 6
		<< "7). Display Stack\n\n"
		<< "8). End Program\n\n";
}

/******************************************************
//name: readUserInput
//called by: main
//passed: int &choice 
//returns: user choice and error message
//calls: nobody
// This function allows the user to input their valid choice
// otherwise, if they input an invalid choice, an error 
// message will pop up. 
*******************************************************/
void readUserInput(int &choice)
{
	const string ERRORMESSAGE = "\nInvalid Input! Expected integers 1-8.\n";
	do
	{
		cout << "\nEnter [1-7] to select an option or [8] to exit program: ";
		cin >> choice;
		if (choice <= 0 || choice > 8) // checks to see if they input between 1-8
		{
			cout << ERRORMESSAGE; //displays if they choose an invalid choice
		}
	} while ( choice <= 0 || choice > 8);

}

/******************************************************
//name: userInput
//called by: main
//passed: int &choice & MathStack &p
//returns: user choice of option 
//calls: pushInt, popInt, addInt, subInt, MultInt, divInt, display, endProgram
// This function allows the user to choose what they want and 
// the option they choose will operate for them. 
*******************************************************/
void userInput(int &choice, MathStack &p)
{
	switch (choice)
	{
	case PUSH:
		pushInt(p);
		break;
	case POP:
		popInt(p);
		break;
	case ADD:
		addInt(p);
		break;
	case SUB:
		subInt(p);
		break;
	case MULT:
		multInt(p);
		break;
	case DIV:
		divInt(p);
		break;
	case DISPLAY:
		displayStack(p);
		break;
	case END:
		endProgram();
		break;
	default:
		defaultMessage();
		break;
	}
}

/******************************************************
//name: pushInt
//called by: userInput
//passed: MathStack &p
//returns: integer num 
//calls: push() from DynIntStack
// This function allows the user to input an integer and 
// if the integer is invalid, then they will need to input 
// it again. Once inputted, it will push onto the stack. 
*******************************************************/
void pushInt(MathStack &p)
{
	int num;
	cin.clear();
	cout << "\nEnter an integer: "; // prompts the user to input 
	cin >> num;
	if (!cin)
	{
		cout << "Sorry, your input was not an integer!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter an integer: "; // allows the user to input again
		cin >> num;

	}
	p.push(num);
}

/******************************************************
//name: popInt
//called by: userInput
//passed: MathStack &p
//returns: integer num
//calls: pop() from DynIntStack
// This function allows the user to pop an integer off 
// the stack and this willthen call the pop function from 
// the MathStack/DynIntStack
*******************************************************/
void popInt(MathStack &p)
{
	int num;
	p.pop(num);

	cout << "The integer is popped!";
}

/******************************************************
//name: addInt
//called by: userInput
//passed: MathStack &p
//returns: sum of the two values
//calls: add() from MathStack
// This function allows the user to add the top two values
// which will then get a message that it is already added. 
*******************************************************/
void addInt(MathStack &p)
{
	int num, numTwo, add;
	p.add(num, numTwo, add); //calls the add() from MathStack 

	cout << "\nThe top two values of the stack has been added!\n\n";

}

/******************************************************
//name: subInt
//called by: userInput
//passed: MathStack &p
//returns: difference of the two values
//calls: sub() from MathStack
// This function allows the user to subtract the top two values
// which will then get a message that it is already subtracted.
*******************************************************/
void subInt(MathStack &p)
{
	int num, numTwo, sub;
	p.sub(num, numTwo, sub); // calls the sub() from MathStack 

	cout << "\nThe top two values of the stack has been subtracted!\n\n";
}

/******************************************************
//name: multInt
//called by: userInput
//passed: MathStack &p
//returns: multiplication of the two values
//calls: mult() from MathStack
// This function allows the user to multiply the top two values
// which will then get a message that it is already multiplied.
*******************************************************/
void multInt(MathStack &p)
{
	int num, numTwo, mult;
	p.mult(num, numTwo, mult);

	cout << "\nThe top two values of the stack has been multiplied!\n\n";
}

/******************************************************
//name: divInt
//called by: userInput
//passed: MathStack &p
//returns: division of the two values
//calls: div() from MathStack
// This function allows the user to divide the top two values
// which will then get a message that it is already divided.
*******************************************************/
void divInt(MathStack &p)
{
	int num, numTwo, div;
	p.div(num, numTwo, div); // calls the div() from MathStack

	cout << "\nThe top two values of the stack has been divided!\n\n";
}

/******************************************************
//name: displayStack
//called by: userInput
//passed: MathStack &p
//returns: display of the stack
//calls: display() from MathStack
// This function allows the user to call the displayStack which 
// will display the stack. 
*******************************************************/
void displayStack(MathStack &p)
{
	cout << "\nThe stack is now displayed!\n";
	p.display(); // calls the display() from MathStack
	
}


/******************************************************
//name: endProgram
//called by: userInput
//passed: ntohing
//returns: end program message
//calls: nothing
// This function displays a message that the program 
// is ending. 
*******************************************************/
void endProgram()
{
	cout << "\nThe program is ending...\n"; //displays the end of the program message
}

/******************************************************
//name: defaultMessage
//called by: userInput
//passed: nothing
//returns: default message
//calls: nothing
// This function notifies the user that they chose an 
// invalid choice which will tell them to run the program
// again. 
*******************************************************/
void defaultMessage()
{
	cout << "\nSorry! That was an invalid choice \n"
		<< "Expected choices [1-7] for an option or [8] to end program!\n"
		<< "Run the program again!\n"; // displays the default message
}