// CISC192ProgrammingProject2_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/25/2018
	Programming Project #2
	The function of this program is it displays three cars which will be racing and whoever wins,
	there will be a message displaying one of the cars who won. 
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h> // For the sleep() function 
using namespace std;

struct Car
{
	string name; // Name of the car
	int position; // the position in which the car starts at
};

void displayCarRaces(Car , Car , Car ); // displays the races
void checkWinner(Car , Car , Car ); // Checks to see who the winner is out of the three
void beginRacing(Car , Car , Car ); // Starts the race
int movingForward(); // Allows the car to move foward

int main()
{
	srand(time(0));
	Car carOne = { "LAMBO", 0 };
	Car carTwo = { "BMW", 0 };
	Car carThree = { "AUDI", 0 };
	beginRacing(carOne, carTwo , carThree); // Calls the function
	cout << endl;
	system("pause");
	return 0;
}

/*
This function gets the amount of distance in order for the car
to move forward. This will generate a random number between 0-10.
*/
int movingForward()
{
	int forward = rand() % 10;
	return forward;
}

/*
This function displays each of the car racing on each move. It also
draws three of the cars with their name in the middle. 
*/
void  displayCarRaces(Car car1, Car car2, Car car3 )
{
	for (int i = 0; i < car1.position; i++)
	{
		cout << " ";
	}
	cout << "(o( " << car1.name << " )o)" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < car2.position; i++)
	{
		cout << " ";
	}
	cout << "(o( " << car2.name << " )o)" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < car3.position; i++)
	{
		cout << " ";
	}
	cout << "(o( " << car3.name << " )o)" << endl;
}

/*
This function will check the scores of each of the three cars that are racing
each other.
Once it finds who the winner is, it will display a message on who won including the
score it got. 
*/
void checkWinner(Car car1, Car car2, Car car3)
{
	string winnerCar = car1.name;
	int score = car1.position;
	if (score < car2.position)
	{
		score = car2.position;
		winnerCar = car2.name;
	}
	if (score < car3.position)
	{
		score = car3.position;
		winnerCar = car3.name;
	}
	
	cout << "\n" << winnerCar << " WON! " << score << endl;
}

/*
This function will begin the race while adding the functions checkWinner and displayCarRaces
in this so that it can display the cars racing and checking to see who won. 
*/
void beginRacing(Car car1, Car car2, Car car3)
{
	do
	{
		system("CLS"); // allows the cars to move straight instead of starting another line, clears screen 
		displayCarRaces(car1, car2, car3); // draws all cars and displays them to start the race
		car1.position += movingForward(); // calls the function to move the car forward while position at 0
		car2.position += movingForward();
		car3.position += movingForward();
		if (car1.position >= 50 || car2.position >= 50 || car3.position >= 50)
		{
			if (car1.position == 50 && car2.position == 50 && car3.position == 50)
			{
				continue;
			}
			else
			{
				checkWinner(car1, car2, car3); // calls the function to print the winner car
			}
		}
		cout.flush(); // This clears the buffer by outputting everything
		Sleep(1500); // places one & half seconds sleep in between leaps
	} 
	while (car1.position < 50 && car2.position < 50 && car3.position < 50);
}
