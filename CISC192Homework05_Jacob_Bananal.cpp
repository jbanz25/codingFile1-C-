// CISC192Homework05_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/08/2018
	Homework 05 - Programming Challenge #4 "Calories Burn", Page 297
	The function of this is to calculate the total calories per minute burn after the given minutes. 
**/

#include <iostream>
using namespace std;

int main()
{
	double calsPerMinute; 
	double caloriesBurned;
	int minutes;

	cout << "Enter your calories per minute: ";
	cin >> calsPerMinute;
	
	for (minutes = 5; minutes <= 30; minutes += 5)
	{
		caloriesBurned = minutes * calsPerMinute; 
		cout << "After " << minutes << " minutes, you burned "
			<< caloriesBurned << " calories.\n";
	}

	system("pause");
	return 0;
}

