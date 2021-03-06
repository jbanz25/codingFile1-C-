// CISC192Homework04JacobBananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/06/2018
	Homework 04 - Programming Challenge #23 (Geometry Calculator), Page 227
	The function of this is to be able to create Geometry Calculator menu and choose one
	the selections that will perform your selected calculation. 
**/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int choice;
	double area, radius, length, width, base, height;
	const double PI = 3.14159;
	const int CHOICE_CIRCLE = 1, CHOICE_RECTANGLE = 2, CHOICE_TRIANGLE = 3, CHOICE_QUIT = 4;

	cout << "Geometry Calculator\n\n"
		<< "1. Calculate the Area of Circle\n\n"
		<< "2. Calcualate the Area of Rectangle\n\n"
		<< "3. Calculate the Area of Triangle\n\n"
		<< "4. Quit\n\n"
		<< "\n Enter your choice (1-4): \n\n";
	cin >> choice;

	cout << fixed << setprecision(2);

	switch (choice)
	{
	case CHOICE_CIRCLE:
		cout << "Enter the radius of the circle: ";
		cin >> radius;
		if (radius < 0)
		{
			cout << "Radius cannot be negative!\n"
				<< "Enter radius again: \n";
			cin >> radius;
		}
		area = PI * radius * radius;
		cout << "The circle's area is " << area << " square units \n\n";
		break;

	case CHOICE_RECTANGLE:
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		if (length < 0)
		{
			cout << "The Length cannot be less than 0! \n"
				<< "Enter length again: \n";
			cin >> length;
		}
		cout << "Enter the width of the rectangle: ";
		cin >> width;
		if (width < 0)
		{
			cout << "The Width cannot be less than 0! \n"
				<< "Enter width again: \n";
			cin >> width;
		}

		area = length * width;
		cout << "The rectangle's area is " << area << " square units \n\n";
		break;

	case CHOICE_TRIANGLE:
		cout << "Enter the base of the triangle: ";
		cin >> base;
		if (base < 0)
		{
			cout << "Base cannot be less than 0! \n"
				<< "Enter base again: \n";
			cin >> base;
		}
		cout << "Enter the height of the triangle: ";
		cin >> height;
		if (height < 0)
		{
			cout << "The Height cannot be less than 0! \n"
				<< "Enter height again: \n";
			cin >> height;
		}

		area = base * height * 0.5;
		cout << "The triangle's area is " << area << " square units \n\n";
		break;

	case CHOICE_QUIT:
		cout << "\nThe program is ending...\n";
		break;

	default:
		cout << "The valid choices are 1-4 \n"
			<< "Run the program again \n";
	}

	system("pause");
	return 0;
}