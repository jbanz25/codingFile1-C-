/**
    * Jacob Bananal
    *
    * Chapter 13 Programming Assignment - Part 1
    *
    * March 20, 2018
    *
**/
//Inventory.h file
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
using namespace std;

class Inventory
{
private:
	int inventoryNumber;
	string imageName;
	string photogLastName;
	float pricePaid;
	float priceSell;
	int numberSold;

public:
	Inventory()
	{
		inventoryNumber = 0;
		imageName = "";
		photogLastName = "";
		pricePaid = 0.0;
		priceSell = 0.0;
		numberSold = 0;
	}

	// Overloaded constructor
	Inventory(int, string, string, float, float, int);

	//Mutator functions
	void setInventoryNumber(int);
	void setImageName(string);
	void setPhotogLastName(string);
	void setPricePaid(float);
	void setPriceSell(float);
	void setNumberSold(int);

	// Accessor functions
	int getInventoryNumber() const
	{
		return inventoryNumber;
	}

	string getImageName() const
	{
		return imageName;
	}

	string getPhotogLastName() const
	{
		return photogLastName;
	}

	float getPricePaid() const
	{
		return pricePaid;
	}

	float getPriceSell() const
	{
		return priceSell;
	}

	int getNumberSold() const
	{
		return numberSold;
	}

};
#endif // INVENTORY_H
