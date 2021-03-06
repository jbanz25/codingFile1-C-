// CISC192_Homework09_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal - 01/17/2018
	Homework 09 - Local Farmer's Market Vendor
**/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputVendor(string *, double *, int);
void displayVendorReport(string *, double *, int);
double getAmountPaid(double);

int main()
{
	int numOfVendors;
	cout << "Enter how many vendors participated in the market: ";
	cin >> numOfVendors;

	string *name = new string[numOfVendors];
	double *sales = new double[numOfVendors];

	inputVendor(name, sales, numOfVendors);
	displayVendorReport(name, sales, numOfVendors);

	system("pause");
	return 0;
}

void inputVendor(string *name, double *sales, int numOfVendors)
{
	for (int i = 0; i < numOfVendors; i++)
	{
		cout << "\n\nVendor " << i + 1 << " details: ";
		cout << "\nEnter the name of Vendor: ";
		cin >> name[i];
		if (name[i].empty())
		{
			cout << "Sorry, Please enter a valid name!";
			continue;
			break;
		}

		cout << "\nEnter the gross amount: ";
		cin >> sales[i];
		if (sales < 0)
		{
			cout << "Sorry, you will need to enter a postive gross amount!";
			continue;
			break;
		}
	}
}

void displayVendorReport(string *name, double *sales, int numOfVendors)
{

	cout << "\n\tVendors Report\n";
	cout << "\t____________________\n\n";
	cout << "\tVendor's Name\t\t\tGross Amount\t\tAmount Due to the Market";
	cout << "\n\t----------------------------------------------------------------------------\n";
	for (int i = 0; i < numOfVendors; i++)
	{
		cout << "\n\t" << name[i] << "\t\t\t\t$" << fixed << setprecision(2)
			<< sales[i] << "\t\t\t$" << getAmountPaid(sales[i]) << endl;
	}
}

double getAmountPaid(double salesAmount)
{
	return salesAmount * 10 / 100;
}