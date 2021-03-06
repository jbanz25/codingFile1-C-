// CISC192_Homework08_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal - 01/16/2018
	Homework 08 - Programming Challenge #10 (Sorting Orders), page 501
	The function of this is to write two array with the same 8 integers while each of the array
	will be sorted by either Bubble Sort or Selection Sort.
**/

#include <iostream>
#include <iomanip>
using namespace std;

void bubbleSort(int[], int);
void selectionSort(int[], int);
void displayArray(int[], int);
void swap(int &, int &);



int main()
{
	const int ARRAY_SIZE = 8;
	int firstNumbers[ARRAY_SIZE] = {14,36,55,19,22,41,11,8};
	int secondNumbers[ARRAY_SIZE] = {14,36,55,19,22,41,11,8};

	cout << "\nDisplay the first array: \n";
	displayArray(firstNumbers, ARRAY_SIZE);

	cout << "\nDisplay the first array using Bubble Sort: \n";
	bubbleSort(firstNumbers, ARRAY_SIZE);

	cout << "\nDisplay the second array: \n";
	displayArray(secondNumbers, ARRAY_SIZE);

	cout << "\nDisplay the second array using Selection Sort: \n";
	selectionSort(secondNumbers, ARRAY_SIZE);

	system("pause");
	return 0;

}

void bubbleSort(int array[], int size)
{
	int maximumVariable, index;
	for (maximumVariable = size - 1; maximumVariable > 0; maximumVariable--)
	{
		for (index = 0; index < maximumVariable; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
		displayArray(array, size);
	}
}

void selectionSort(int array[], int size)
{
	int minimumIndex, minimumVariable, beginScan, index;
	for (beginScan = 0; beginScan < (size - 1); beginScan++)
	{
		minimumIndex = beginScan;
		minimumVariable = array[beginScan];
		for (index = beginScan + 1; index < size; index++)
		{
			if (array[index] < minimumVariable)
			{
				minimumVariable = array[index];
				minimumIndex = index;
			}
		}
		swap(array[minimumIndex], array[beginScan]);
		displayArray(array, size);
	}
}

void displayArray(int array[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	} 
	cout << endl;
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
