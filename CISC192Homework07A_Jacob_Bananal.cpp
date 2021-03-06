// CISC192Homework07A_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/11/2018
	Homework 07A - Programming Challenge #1 (Largest/Smallest Array Values), Page 454
	The function of this is to allow the user to input 10 numbers which will then display
	the largest and smallest values stores in the array. 
**/

#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 10;
	int numbers[SIZE], smallest, largest;
	int count;

	cout << "Enter ten values: " << endl; // User will input 10 values that will store in the numbers array
	for (int i = 0; i < SIZE; i++) 
	{
		cin >> numbers[i];
	}
	
	cout << "\nDisplay the entire Array: " << endl; // Displays the entire array of the user's input
	for (int i = 0; i < SIZE; i++)
	{
		cout << numbers[i] << " ";
	}
	
	smallest = numbers[0];
	largest = numbers[0];
	for (count = 0; count < SIZE; count++)
	{
		if (numbers[count] > largest)
		{
			largest = numbers[count];
		}
		if (numbers[count] < smallest)
		{
			smallest = numbers[count];
		}
	}

	cout << "\n\nThe largest value is: " << largest << endl;
	cout << "The smallest value is: " << smallest << endl;

	system("pause");
	return 0;
}

