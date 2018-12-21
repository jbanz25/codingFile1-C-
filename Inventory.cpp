/**
    * Jacob Bananal
    *
    * Chapter 13 Programming Assignment - Part 1
    *
    * March 20, 2018
    *
**/
//Inventory.cpp file
//Implementation file for the Inventory class
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Inventory.h"
using namespace std;

/******************************************************
//name: Inventory
//called by: main
//passed: theInventoryNumber, theImageName, theLastName, thePricePaid, thePriceSell, theNumberSold
//returns: nothing
//calls: nobody
// This function accepts a print's from each of the
// following int, string, and float.
*******************************************************/
Inventory::Inventory(int theInventoryNumber, string theImageName, string theLastName,
					float thePricePaid, float thePriceSell, int theNumberSold)
{
	inventoryNumber = theInventoryNumber;
	imageName = theImageName;
	photogLastName = theLastName;
	pricePaid = thePricePaid;
	priceSell = thePriceSell;
	numberSold = theNumberSold;
}

/******************************************************
//name: setInventoryNumber
//called by: main
//passed: theInventoryNumber
//returns: nothing
//calls: nobody
// This function accepts an integer argument that is copied
// to the theInventoryNumber if greater than or equal to 0.
*******************************************************/
void Inventory::setInventoryNumber(int theInventoryNumber)
{
	if (theInventoryNumber >= 0)
	{
		inventoryNumber = theInventoryNumber;
	}
	else
	{
		cout << "Sorry, that was an invalid item number! Can't be less than 0.\n";
		exit(EXIT_FAILURE);
	}
}

/******************************************************
//name: setImageName
//called by: main
//passed: theImageName
//returns: nothing
//calls: nobody
// This function accepts a string argument that is copied to
// the theImageName if less than 25.
*******************************************************/
void Inventory::setImageName(string theImageName)
{
	if (theImageName.length() < 25)
	{
		imageName = theImageName;
	}
	else
	{
		cout << "Sorry, that was an invalid image name! Can't be greater than 25.\n";
		exit(EXIT_FAILURE);
	}
}

/******************************************************
//name: setPhotogLastName
//called by: main
//passed: theLastName
//returns: nothing
//calls: nobody
// The function accepts a string argument that is copied to the
// theLastName if less than 25.
*******************************************************/
void Inventory::setPhotogLastName(string theLastName)
{
	if (theLastName.length() < 25)
	{
		photogLastName = theLastName;
	}
	else
	{
		cout << "Sorry, that was an invalid photographer last name! Can't be greater than 25.\n";
		exit(EXIT_FAILURE);
	}
}

/******************************************************
//name: setPricePaid
//called by: main
//passed: thePricePaid
//returns: nothing
//calls: nobody
// The function accepts a float argument that is copied to the
// thePricePaid if greater than or equal to 0.0.
*******************************************************/
void Inventory::setPricePaid(float thePricePaid)
{
	if (thePricePaid >= 0.0)
	{
		pricePaid = thePricePaid;
	}
	else
	{
		cout << "Sorry, that was an invalid price paid! Can't be less than 0.\n";
		exit(EXIT_FAILURE);
	}
}

/******************************************************
//name: setPriceSell
//called by: main
//passed: thePriceSell
//returns: nothing
//calls: nobody
// The function accepts a float argument that is copied to the
// thePriceSell if greater than or equal to 0.0.
*******************************************************/
void Inventory::setPriceSell(float thePriceSell)
{
	if (thePriceSell >= 0.0)
	{
		priceSell = thePriceSell;
	}
	else
	{
		cout << "Sorry, that was an invalid sell price! Can't be less than 0.\n";
		exit(EXIT_FAILURE);
	}
}

/******************************************************
//name: setNumberSold
//called by: main
//passed: theNumberSold
//returns: nothing
//calls: nobody
// The function accepts an integer that is copied to the
// theNumberSold if greater than or equal to 0.
*******************************************************/
void Inventory::setNumberSold(int theNumberSold)
{
	if (theNumberSold >= 0)
	{
		numberSold = theNumberSold;
	}
	else
	{
		cout << "Sorry, that was an invalid number sold! Can't be less than 0.\n";
		exit(EXIT_FAILURE);
	}
}
