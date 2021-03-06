// CISC192Homework11_Jacob_Bananal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/**
	Jacob Bananal 01/22/2018
	Homework 11 - Programming Challenge #1 "Movie Data" and #2 "Movie Profit", page 659
	The function of this is display two movies with their year released, revenues, and
	running time. 
**/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData
{
	string title; // title of the movie
	string director; // director of the movie
	int yearReleased; // year when the movie released
	int runningTime; // in minutes 
	double productionCost; // movie's production cost
	double revenues; // first-year revenues 
};

void displayMovieData(MovieData ); // declares function prototype

int main()
{
	MovieData movieOne = { "Elf", "Jon Favreau", 2003, 97, 33000000, 31113501 };
	MovieData movieTwo = { "Grown Ups", "Dennis Dugan",2010, 102, 80000000, 40506562 };
	displayMovieData(movieOne);
	displayMovieData(movieTwo);
	system("pause");
	return 0;
}

/*
This function displays all the movie details that includes the title, director,
year released, running time, and finally either the first year profit or loss. 
*/
void displayMovieData(MovieData m)
{
	cout << "\n\nMovie Details:\n";
	cout << "-----------------\n";
	cout << "Title: " << m.title << endl;
	cout << "Director: " << m.director << endl;
	cout << "Year Released: " << m.yearReleased << endl;
	cout << "Running Time " << m.runningTime << " minutes" << endl;
	if (m.revenues - m.productionCost > 0) // test to see whether the movie has first year profit or loss
	{
		cout << "First year's profit: " << "$" << setprecision(8)
			<< m.revenues - m.productionCost << endl;
	}
	else
	{
		cout << "First year's loss: " << "$" << setprecision(8)
			<< m.productionCost - m.revenues << endl;
	}
}

