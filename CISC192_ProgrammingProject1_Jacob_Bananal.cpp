// CISC192_ProgrammingProject1_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/12/2018
	Programming Project #1 - "Math Tutor", Page 298
	This function allows for young children to have a online math tutor where they will have 5 choices
	to choose from that could help their math skills. These 5 choices are addition, subtraction, 
	multiplication, division, and quit. 
**/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int displayMenu();
int additionProblem();
int subtractionProblem();
int multiplicationProblem();
int divisionProblem();
void displayQuit();
void defaultMessage();
int max(int, int);
int min(int, int);


int main()
{
	int choice;
	int userInput;
	const int ADDITION = 1, SUBTRACTION = 2, MULTIPLICATION = 3, DIVISION = 4, QUIT = 5;
	do
	{
		choice = displayMenu();

		switch (choice)
		{
		case ADDITION:
		{
			additionProblem();
			break;
		}
		case SUBTRACTION:
		{
			subtractionProblem();
			break;
		}
		case MULTIPLICATION:
		{
			multiplicationProblem();
			break;
		}
		case DIVISION:
		{
			divisionProblem();
			break;
		}
		case QUIT:
		{
			displayQuit();
			break;
		}
		default:
		{
			defaultMessage();
			break;
		}
		}
	} 
	while (choice != 5);

	system("pause");
	return 0;
}

	int displayMenu()
	{
		int choice;
		cout << "\nMath Tutor\n\n"
			<< "1. Addition\n\n"
			<< "2. Subtraction\n\n"
			<< "3. Multiplication\n\n"
			<< "4. Division\n\n"
			<< "5. Quit\n\n"
			<< "Enter your choice (1-4): \n\n";
		cin >> choice;
		return choice;
	}

	int additionProblem()
	{
		int userInput;
		const int MIN_VALUE = 1;
		const int MAX_VALUE = 20;

		int num1 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int num2 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int maxNumber = max(num1, num2);
		int minNumber = min(num1, num2);
		int finalAnswer = maxNumber + minNumber;
		cout << num1 << " + " << num2 << " = \n" << endl;
		cout << "Enter the answer: ";
		cin >> userInput;
		if (userInput == finalAnswer)
		{
			cout << "Congratulations! The answer was correct!\n\n";
		}
		else
		{
			cout << "Sorry that was the incorrect answer, the right anwer is " << finalAnswer << endl;
		}
		return finalAnswer;
	}

	int subtractionProblem()
	{
		int userInput;
		const int MIN_VALUE = 1;
		const int MAX_VALUE = 20;

		int num1 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int num2 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int maxNumber = max(num1, num2);
		int minNumber = min(num1, num2);
		int finalAnswer = maxNumber - minNumber;
		cout << num1 << "-" << num2 << "= \n" << endl;
		cout << "Enter the answer: ";
		cin >> userInput;
		if (userInput == finalAnswer)
		{
			cout << "Congratulations! The answer was correct!\n\n";
		}
		else
		{
			cout << "Sorry that was the incorrect answer, the right anwer is " << finalAnswer << endl;
		}
		return finalAnswer;
	}

	int multiplicationProblem()
	{

		int userInput;
		const int MIN_VALUE = 1;
		const int MAX_VALUE = 20;

		int num1 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int num2 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int maxNumber = max(num1, num2);
		int minNumber = min(num1, num2);
		int finalAnswer = maxNumber * minNumber;
		cout << num1 << "*" << num2 << "= \n" << endl;
		cout << "Enter the answer: ";
		cin >> userInput;
		if (userInput == finalAnswer)
		{
			cout << "Congratulations! The answer was correct!\n\n";
		}
		else
		{
			cout << "Sorry that was the incorrect answer, the right anwer is " << finalAnswer << endl;
		}
		return finalAnswer;
	}

	int divisionProblem()
	{
		int userInput;
		const int MIN_VALUE = 1;
		const int MAX_VALUE = 20;

		int num1 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int num2 = ((rand() % MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		
		int maxNumber = max(num1, num2);
		int minNumber = min(num1, num2);
		int finalAnswer = maxNumber / minNumber;
		cout << num1 << "/" << num2 << "= \n" << endl;
		cout << "Enter the answer: ";
		cin >> userInput;
		if (userInput == finalAnswer)
		{
			cout << "Congratulations! The answer was correct!\n\n";
		}
		else
		{
			cout << "Sorry that was the incorrect answer, the right anwer is " << finalAnswer << endl;
		}
		return finalAnswer;
	}

	void displayQuit()
	{
		cout << "The program is ending...\n";
	}

	void defaultMessage()
	{
		cout << "\nThe valid choices are 1-5 \n\n"
			<< "Run the program again \n\n";
	}

	int max(int num1, int num2)
	{
		if (num1 >= num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}

	int min(int num1, int num2)
	{
		if (num1 <= num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
