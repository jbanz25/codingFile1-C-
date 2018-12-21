/**
    * Jacob Bananal
    *
    * Chapter 15 Programming Assignment
    *
    * April 3, 2018
    *
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "GradedActivity.h"
using namespace std;

/******************************************************
//name: getLetterGrade
//called by: GradedActivity objects
//passed: nothing
//returns: letterGrade
//calls: nobody
// This function has if statements so that when the total grade
// comes up, it will display one of the following letter grades.
*******************************************************/
char GradedActivity::getLetterGrade() const
{
    char letterGrade; // To hold the letter grade

    if (score > 89)
    letterGrade = 'A';
    else if (score > 79)
    letterGrade = 'B';
    else if (score > 69)
    letterGrade = 'C';
    else if (score > 59)
    letterGrade = 'D';
    else
    letterGrade = 'F';

    return letterGrade;
}
