// CISC187_HomeworkCh06_07_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	* Jacob Bananal
	*
	* Chapter 6 & 7 - Homework 01 Programming Assignment
	* 
	* February 20, 2018
	*
**/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int displayMenu();
void displayArray(int[5][5]);
void multiplyArray(int[5][5]);
void swapRows(int[5][5]);
void sumArray(int[5][5]);
void quitMessage();
void defaultMessage();
int main()
{
	const int rows = 5; // rows will have 5 
	const int columns = 5; // columns will have 5 
	// intializes the 2D array 
	int myArray[rows][columns] = {{1,2,3,4,5},
								{-20,-40,-60,-80,-100},
								{3,3,3,3,3},
								{5,7,9,11,13},
								{-15,-25,-35,-45,-55}};
	int choice; 
	// creates a constant for each choice in order for the choices to work 
	const int DISPLAYARRAY = 1, MULTIPLY = 2, SWAP = 3, SUM = 4, QUIT = 5; 
	
	do
	{
		choice = displayMenu(); //calls the displayMenu function 

		switch (choice)
		{
		case DISPLAYARRAY:
		{
			displayArray(myArray); // calls the displayArray function
			break;
		}
		case MULTIPLY:
		{
			multiplyArray(myArray); // calls the multiplyArray function 
			break;
		}
		case SWAP:
		{
			swapRows(myArray); // calls the swapRows function 
			break;
		}
		case SUM:
		{
			sumArray(myArray); // calls the sumArray function 
			break;
		}
		case QUIT:
		{
			quitMessage(); //calls the quitMessage function
			break;
		}
		default:
		{
			defaultMessage(); //calls the defaultMessage function
			break;
		}

		}
	} 
	while (choice != 5);
	system("pause");
    return 0;
}

/******************************************************
	//name: displayMenu
	//called by: main
	//passed: nothing
	//returns: choice
	//calls: nobody
	// The displayMenu displays a menu with 5 choices, which the user will input
	// a valid choice (1-5). 
*******************************************************/
int displayMenu()
{
	int choice;
	cout << "\tMenu\n\n"
		<< "1. Display array\n\n" // choice 1
		<< "2. Multiply the array by 3\n\n" // choice 2 
		<< "3. Swap row two with row three\n\n" // choice 3 
		<< "4. Display the sum of all elements\n\n" // choice 4
		<< "5. Quit\n\n" // choice 5 
		<< "\n Enter your choice (1-5): \n\n"; // user will input a number of their choice 
	cin >> choice;
	return choice; // returns the choice the user inputs. 
}

/******************************************************
	//name: displayArray
	//called by: main
	//passed: myArray
	//returns: nothing
	//calls: nobody 
	// The displayArray function displays the array in an
	// organized 5x5 order in the console. 
*******************************************************/
void displayArray(int myArray[5][5])
{
	cout << "\nDisplay the current array: " << endl; // displays a message about the array
	// displays each value in the row and column, this creates a new line for each
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			//include the <iomanip> to use setw 
			cout << setw(5) << right << myArray[row][column] << " "; //displays the array in an organized row and column. 
		}
		cout << endl;
	}
	cout << endl;
}

/******************************************************
	//name: multiplyArray
	//called by: main
	//passed: myArray
	//returns: nothing
	//calls: nobody
	// The multiplyArray function multiplies each of the
	// values in the array by 3. Therefore, when displaying
	// the array, it will display all values, multiply by 3. 
*******************************************************/
void multiplyArray(int myArray[5][5])
{
	// Goes through each each value in the rows and columns
	for (int row = 0; row < 5; row++) 
	{
		for (int column = 0; column < 5; column++)
		{
			myArray[row][column] = myArray[row][column] * 3; // multiples each value by 3
		}
	}
	cout << "\nThe values has been multiply by 3!\n" << endl; // displays a message that it was multiplied
}

/******************************************************
	//name: swapRows
	//called by: main
	//passed: myArray
	//returns: nothing 
	//calls: nobody
	// The swapRows function swaps the values in row two 
	// with row three. It will then display a messages indicating
	// that row two has swapped with row three. 
*******************************************************/
void swapRows(int myArray[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		int tempArray = myArray[1][i]; // set up a third variable as a temporary storage
		myArray[1][i] = myArray[2][i]; // row 2 swaps with row three 
		myArray[2][i] = tempArray; // row three is now store in the tempory storage
	}
	cout << "\nRow two has been swapped with Row three!\n" << endl; //indicates a message that it has been swapped. 
}

/******************************************************
	//name: sumArray
	//called by: main
	//passed: myArray
	//returns: nothing
	//calls: nobody
	// The sumArray calculates the sum of all the elements
	// in the array and will display the total number. 
*******************************************************/
void sumArray(int myArray[5][5])
{
	int totalSum = 0; // accumulator 
	// goes through each value in the row and columns 
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			totalSum += myArray[row][column]; // sums all the array elements
		}
	}
	cout << "\nThe sum of all elements is " << totalSum << endl; //displays the sum
}

/******************************************************
	//name: quitMessage
	//called by: main
	//passed: nothing
	//returns: nothing
	//calls: nobody
	// The quitMessage function displays a message that the program
	// is now ending. 
******************************************************/
void quitMessage()
{
	cout << "\nThe program is ending...\n"; //displays the quit message
}

/*****************************************************
	//name: defaultMessage
	//called by: main
	//passed: nothing
	//returns: nothing
	//calls: nobody
	// The defaultMessage function displays a message whenenever
	// the user enters a invalid choice that is not within the choice
	// 1-5. 
******************************************************/
void defaultMessage()
{
	cout << "Sorry, that was an invalid choice \n"
		<< "The valid choices are 1-5 \n"
		<< "Run the program again! \n"; // displays the default message
}