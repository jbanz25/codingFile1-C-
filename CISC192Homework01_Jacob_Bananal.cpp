// CISC192Homework01_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/04/2018
	Homework 01 - Program 1-1, Page 9
	The function of this is to calculate the user's gross pay.
**/

// This program calculates the user's pay.
#include <iostream>
using namespace std;

int main()
{
	double hours, rate, pay;

	// Get the number of hours worked.
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the hourly pay rate.
	cout << "How much do you get paid per hour? ";
	cin >> rate;

	// Calculate the pay.
	pay = hours * rate;

	// Display the pay.
	cout << "You have earned $" << pay << endl;

	system("pause");
	return 0;
}

