// CISC192Homework02JacobBananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/04/2018
	Homework 02 - Programming Challenge #4 "Restaurant Bill", Page 81
	The function of this is to calculate the tax of the meal, tip of the cost, and finding the total
	bill of the meal cost. 
**/

#include <iostream>
using namespace std;
int main()
{
	double mealCost = 88.75; // The cost of the meal. 
	double mealTax = mealCost * 0.0675; // The cost of the charge after being tax 6.75 %
	double subTotal = mealCost + mealTax; // The subtotal which adds both the meal cost and meal cost after being tax
	double mealTip = subTotal * 0.20; //The tip is 20% of the total after adding the tax
	double finalTotal = subTotal + mealTip; // The total bill 

	cout << "The meal cost: " << mealCost << endl;
	cout << "The tax amount: " << mealTax << endl;
	cout << "The tip amount: " << mealTip << endl;
	cout << "The total bill: " << finalTotal << endl;

	system("pause");
	return 0;
}

