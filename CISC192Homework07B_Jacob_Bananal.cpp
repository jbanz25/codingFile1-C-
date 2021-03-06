// CISC192Homework07B_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/11/2018
	Homework 07B - Programming Challenge #1 (Largest/Smallest Array Values), Page 454
	The function of this is to allow the user to enter 10 values and display the largest
	and smallest values but instead this uses functions. 
**/

#include <iostream>
using namespace std;

void getUserInput(int[], int);
int findHighest(int[], int); // Returns Highest Value in the array
int findLowest(int[], int); // Returns lowest value in the array
void displayArray(int[], int);

int main()
{
	const int SIZE = 10;
	int numbers[SIZE], smallest, largest;

	getUserInput(numbers, SIZE);
	displayArray(numbers, SIZE);
	largest = findHighest(numbers, SIZE);
	smallest = findLowest(numbers, SIZE);

	cout << "\n\nThe largest value is: " << largest << endl;
	cout << "\nThe smallest value is: " << smallest << endl;

	system("pause");
	return 0;
}

void getUserInput(int numbers[], int SIZE)
{
	cout << "Enter ten values: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> numbers[i];
	}
}

int findHighest(int numbers[], int SIZE)
{
	int largest = numbers[0];
	for (int count = 0; count < SIZE; count++)
	{
		if (numbers[count] > largest)
		{
			largest = numbers[count];
		}
	}
	return largest;
}

int findLowest(int numbers[], int SIZE)
{
	int smallest = numbers[0];
	for (int count = 0; count < SIZE; count++)
	{
		if (numbers[count] < smallest)
		{
			smallest = numbers[count];
		}
	}
	return smallest;
}

void displayArray(int numbers[], int SIZE)
{
	cout << "\nDisplay the entire Array:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << numbers[i] << " ";
	}
}