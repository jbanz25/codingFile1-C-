// CISC192Homework03JacobBananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/05/2018
	Homework 03 - Programming Challenge #13 "Currency", Page 146
	The functions of this is to convert the U.S dollars amounts to both
	japanese yens and to euros.

**/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double YEN_PER_DOLLAR = 98.93;
	const double EUROS_PER_DOLLAR = 0.74;
	double dollars, yen, euros;

	cout << setprecision(2) << fixed;
	cout << "Enter dollar amount: ";
	cin >> dollars;

	yen = dollars * YEN_PER_DOLLAR;
	euros = dollars * EUROS_PER_DOLLAR;

	cout << "$" << dollars << " = " << yen << " Yen \n";
	cout << "$" << dollars << " = " << euros << " Euros \n";

	system("pause");
	return 0;
}

