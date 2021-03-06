// CISC192_Homework10_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal - 01/17/2018
	Homework 10 - Menu-Driven Program
	This function has three menu options which are Name Rearranger, Number Validator, or 
	Exit. User will need to input some information depending what menu option he or she chooses, 
**/

#include <iostream>
#include <string>

using namespace std;

int displayMenu();
void nameRearranger();
void numberValidator();
void exitMessage();
void defaultMessage();


int main()
{
	int options;
	const int NAME_REARRANGER = 1, NUMBER_VALIDATOR = 2, EXIT = 3;

	do
	{
		options = displayMenu();
		switch (options)
		{
		case NAME_REARRANGER:
		{
			nameRearranger();
			break;
		}
		case NUMBER_VALIDATOR:
		{
			numberValidator();
			break;
		}
		case EXIT:
		{
			exitMessage();
			break;
		}
		default:
		{
			defaultMessage();
			break;
		}
		}
	} 
	while (options != 3);
	system("pause");
	return 0;
}

int displayMenu()
{
	int options;
	cout << "\n\nMenu\n"
		<< "-----------\n"
		<< "1. Name Rearranger\n\n"
		<< "2. Number Validator\n\n"
		<< "3. Exit\n\n"
		<< "\n Enter your choice (1-3): \n\n";
	cin >> options; 
	return options;
}

void nameRearranger()
{
	
	string fullName, originalName, rearrangedName, firstMiddleName, lastName;
	unsigned space;
	bool isValid, isBeginningSpace, isLastSpace;
	do
	{
		isValid = true;
		cin.ignore();
		cout << "Enter the full name: ";
		getline(cin, fullName);
		originalName = fullName;

		for (int i = 0; i < fullName.length(); i++)
		{
			if (!isalpha(fullName[i]) && fullName[i] != ' ')
			{
				cout << "\nSorry, please enter a valid full name!\n";
				isValid = false;
				break;
			}
		}
	}
	while (!isValid);
	
	// loops through the string and throws out extraneous blanks
	for (int i = 0; i < fullName.length(); i++)
	{
		if (fullName[i] == ' ' && fullName[i + 1] == ' ')
		{
			fullName.erase(i + 1, 1);
		}
	}
			
	
	space = fullName.find_last_of(' ');
	firstMiddleName = fullName.substr(0, space);
	lastName = fullName.substr(space + 1);
	rearrangedName = lastName + ", " + firstMiddleName;

	cout << "\nThe Original Name is: " << originalName << endl;
	cout << "The Rearranged Name is: " << rearrangedName << endl;


}

void numberValidator()
{
	string userNumber, originalNumber;
	double numbDouble;
	bool isValid;
	
	do
	{
		isValid = true;
		cin.ignore();
		cout << "Enter a number as a money value: ";
		getline(cin, userNumber);
		originalNumber = userNumber;

		for (int i = 0; i < userNumber.length(); i++)
		{
			if (userNumber[i] == '$')
			{
				userNumber = userNumber.substr(1);
				i--;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < userNumber.length(); i++)
		{
			if (!isdigit(userNumber[i]) && userNumber[i] != '.')
			{
				cout << "\nSorry, please enter a valid number!\n";
				isValid = false;
				break;
			}
		}
	}
	while (!isValid); 

	numbDouble = atof(userNumber.c_str()); // converts string to double

	cout << "\nThe Original Number is: " << originalNumber << endl;
	cout << "The Number as a double is: " << numbDouble << endl;
}

void exitMessage()
{
	cout << "\nThank you, you are now exiting!\n";
}

void defaultMessage()
{
	cout << "\nThe valid choices are 1-3.\n"
		<< "\nRun the program again!\n";
}