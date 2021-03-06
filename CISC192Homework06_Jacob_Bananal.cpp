// CISC192Homework06_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/** 
	Jacob Bananal 01/12/2018
	Homework 06
	This functions displays a menu for the user which they have 4 choice to choose from. Once the
	user chooses one of the choices, it will either calculate the summation, exponential, or 
	factorial. 
**/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int displayMenu();
int summation();
int factorial();
int exponential();
void quitMessage();
void displayDefault();

int main()
{
	int choice;
	const int SUMMATION = 1, FACTORIAL= 2, EXPONENTIAL= 3, QUIT = 4;

	do
	{
		choice = displayMenu();

		switch (choice)
		{
		case SUMMATION:
		{
			summation();
			break;
		}
		case FACTORIAL:
		{
			factorial();
			break;
		}
		case EXPONENTIAL:
		{
			exponential();
			break;
		}
		case QUIT:
		{
			quitMessage();
			break;
		}
		default:
		{
			displayDefault();
			break;
		}

		}
	} 
	while (choice != 4);
	system("pause");
	return 0;
}

/* 
This function displays the program's menu to the user and ask for the user's
choice which returns the user's choice back to the main function. They have 4 choices
to choose from and if they choose a number that is not (1-4), an error messages displays.
*/
int displayMenu()
{
	int choice;
	cout << "\n\nArithmetic Functions\n\n"
		<< "1. Summation\n\n"
		<< "2. Factorial\n\n"
		<< "3. Exponential\n\n"
		<< "4. Quit\n\n"
		<< "\n Enter your choice (1-4): \n\n";
	cin >> choice;
	return choice;
}

/* 
This function Summation allows a user to a enter a number which the number is up to which
summation is to be carried out. By displaying a for () loop, we accomplished the desired function 
of summation of the numbers up to the user's chosen number. It then displays the sum and returns 
back the output to the menu.
*/
int summation()
{
	int number, sum = 0;
	cout << "\nEnter a number to calculate the summation: ";
	cin >> number;
	if (number != 0)
	{
		for (int i = 1; i <= number; i++)
		{
			sum += i;
		}
		cout << "\nThe sum of numbers up to the given max number " << number << " is: " << sum;
	}
	else
	{
		cout << "\nEnter a number greater than 0";
	}
	return sum;
}

/*
This function Factorial calculates the user's given number which uses a simple for () loop 
to multiply all the numbers from the user's given number. This will display the calculation
and return the output of the factorial. Once the output is displayed, it will bring you back to
menu. 
*/
int factorial()
{
	int number, factorial; 
	cout << "\nEnter a number to calculate the factorial: ";
	cin >> number;
	factorial = number;
	for (int i = factorial - 1; i > 0; i--)
	{
		number = factorial;
		factorial = factorial * (double)i;
		cout << number << " x " << i << " = " << factorial << endl;
	}
	cout << "\nThe factorial of the user's input is " << factorial << endl;
	return factorial;
}

/*
This function Exponential allows the user to enter the base and exponent which will
raise the user's given number to the desired exponentiation. Once it raises to the desired
exponentiation, it will then display the calculation and the results of it. Once the output is
shown, it will take you back to the menu. 
*/
int exponential()
{
	int base, exponent, result;
	cout << "\nEnter the base and exponent to calculate the exponential: ";
	cin >> base >> exponent;
	result = pow(base, exponent);

	cout << "\nThe exponential problem " << base << "^" << exponent << " = " << result;
	return result;
}

/*
This function Quit allows the user to type in 4 during the menu selection and this will 
automatically display a message that the programming is quitting. Once the message is displayed,
the user can click on any key and the program will exit. 
*/
void quitMessage()
{
	cout << "\nThe program is ending...\n";
}

/*
This function Default is whenever the user doesn't choose a valid choice between (1-4), an error
message will pop up and telling them to choose a valid choice and run the program again. Once the
message is displayed, it will take the user back to the menu. 
*/
void displayDefault()
{
	cout << "The valid choices are 1-4 \n"
		<< "Run the program again \n";
}