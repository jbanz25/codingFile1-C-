// CISC187_HwCH13_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
* Jacob Bananal
*
* Chapter 13 Programming Assignment - Part 1
*
* February 20, 2018
*
**/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Inventory.h"
using namespace std;

int main()
{
	const int INVENTORY_SIZE = 3;
	Inventory inventoryObjects[INVENTORY_SIZE];
	int theInventoryNumber;
	string theImageName;
	string thePhotogLastName;
	float thePricePaid;
	float thePriceSell;
	int theNumberSold;

	cout << "Fine Art Prints by Duncan Gallery" << endl;
	cout << "__________________________________" << endl;


	// inputs
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		cout << "\nEnter inventory number: ";
		cin >> theInventoryNumber;
		inventoryObjects[i].setInventoryNumber(theInventoryNumber);

		cout << "Enter image name: ";
		getline(cin.ignore(), theImageName);
		inventoryObjects[i].setImageName(theImageName);

		cout << "Enter the last name of the photographer: ";
		cin >> (thePhotogLastName);
		inventoryObjects[i].setPhotogLastName(thePhotogLastName);

		cout << "Enter the price that the gallery paid for the print: ";
		cin >> thePricePaid;
		inventoryObjects[i].setPricePaid(thePricePaid);

		cout << "Enter the the sell price of the print: ";
		cin >> thePriceSell;
		inventoryObjects[i].setPriceSell(thePriceSell);

		cout << "Enter the number of prints sold: ";
		cin >> theNumberSold;
		inventoryObjects[i].setNumberSold(theNumberSold);
	}

	//outputs
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		cout << "Inventory number: \n" << inventoryObjects[i].getInventoryNumber() << endl;
		cout << "Image name: \n" << inventoryObjects[i].getImageName().substr(0, inventoryObjects[i].getImageName().length() - 1);
		cout << "Photographer last name: \n" << inventoryObjects[i].getPhotogLastName().substr(0, inventoryObjects[i].getPhotogLastName().length() - 1);
		cout << "Price paid: \n" << fixed << setprecision(2) << inventoryObjects[i].getPricePaid();
		cout << "Sell price: \n" << fixed << setprecision(2) << inventoryObjects[i].getPriceSell();
		cout << "Number of prints sold: \n" << inventoryObjects[i].getNumberSold();
	}
	
	return 0;
}

