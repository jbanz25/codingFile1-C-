/**
    * Jacob Bananal
    *
    * Chapter 15 Programming Assignment
    *
    * April 3, 2018
    *
**/

#include <iostream>
#include <string>
#include <cstdlib>
#include "GradedActivity.h"
#include "ProgrammingProject.h"
using namespace std;

/******************************************************
//name: ProgrammingProject
//called by: ProgrammingProject Objects
//passed:theUseOfClasses,theCodeExecution,theProperChoice,theCorrectPseudoCode,theComments,theProfessionalism
//returns: nothing
//calls: nobody
// This is a overloaded constructor which initializes variables to pass
// in the parameter.
*******************************************************/
ProgrammingProject::ProgrammingProject(int theUseOfClasses, int theCodeExecution, int theProperChoice,
    int theCorrectPseudoCode, int theComments, int theProfessionalism)
    {
        useOfClasses = theUseOfClasses;
        codeExecution = theCodeExecution;
        properChoiceOfCode = theProperChoice;
        correctPseudocode = theCorrectPseudoCode;
        useOfComments = theComments;
        inputOutputProfessionalism = theProfessionalism;
    }

/******************************************************
//name: setUseOfClasses
//called by: ProgrammingProject Objects
//passed: theUseOfClasses
//returns: nothing
//calls: nobody
// The function makes sure the user enter a valid number greater than
// or equal to 0 or else the function will exit if enter a invalid number.
*******************************************************/
void ProgrammingProject::setUseOfClasses(int theUseOfClasses)
{
    if (theUseOfClasses >=0)
    {
        useOfClasses = theUseOfClasses;
    }
    else
    {
        cout << "Sorry, that was an  invalid number of points for classes!\n";
        exit(EXIT_FAILURE);
    }
}

/******************************************************
//name: setCodeExecution
//called by: ProgrammingProject Objects
//passed: theCodeExecution
//returns: nothing
//calls: nobody
// The function makes sure the user enter a valid number greater than
// or equal to 0 or else the function will exit if enter a invalid number.
*******************************************************/
void ProgrammingProject::setCodeExecution(int theCodeExecution)
{
    if (theCodeExecution >=0)
    {
        codeExecution = theCodeExecution;
    }
    else
    {
        cout << "Sorry, that was an invalid number of points for code execution!\n";
        exit(EXIT_FAILURE);
    }
}

/******************************************************
//name: setProperChoiceOfCode
//called by: ProgrammingProject objects
//passed: theProperChoice
//returns: nothing
//calls: nobody
// The function makes sures the user inputs a valid number or else
// the program will exit.
*******************************************************/
void ProgrammingProject::setProperChoiceOfCode(int theProperChoice)
{
    if (theProperChoice >=0)
    {
        properChoiceOfCode = theProperChoice;
    }
    else
    {
        cout << "Sorry, that was an invalid number of points for choice of code!\n";
        exit(EXIT_FAILURE);
    }
}

/******************************************************
//name: setCorrectPseudocode
//called by: ProgrammingProject Objects
//passed: theCorrectPseudoCode
//returns: nothing
//calls: nobody
// The function makes sure the user enter a valid number greater than
// or equal to 0 or else the function will exit if enter a invalid number.
*******************************************************/
void ProgrammingProject::setCorrectPseudocode(int theCorrectPseudoCode)
{
    if (theCorrectPseudoCode >=0)
    {
        correctPseudocode = theCorrectPseudoCode;
    }
    else
    {
       cout << "Sorry, that was an invalid number of points for pseudocode!\n";
       exit(EXIT_FAILURE);
    }
}

/******************************************************
//name: setUseOfComments
//called by: ProgrammingProject Objects
//passed: theComments
//returns: nothing
//calls: nobody
// The function makes sure the user enter a valid number greater than
// or equal to 0 or else the function will exit if enter a invalid number.
*******************************************************/
void ProgrammingProject::setUseOfComments(int theComments)
{
    if (theComments >= 0)
    {
        useOfComments = theComments;
    }
    else
    {
        cout << "Sorry, that was an invalid number of points for comments!\n";
        exit(EXIT_FAILURE);
    }
}

/******************************************************
//name: setInputOutputProfessionalism
//called by: ProgrammingProject Objects
//passed: theProfessionalism
//returns: nothing
//calls: nobody
// The function makes sure the user enter a valid number greater than
// or equal to 0 or else the function will exit if enter a invalid number.
*******************************************************/
void ProgrammingProject::setInputOutputProfessionalism(int theProfessionalism)
{
    if (theProfessionalism >= 0)
    {
        inputOutputProfessionalism = theProfessionalism;
    }
    else
    {
        cout << "Sorry, invalid number of points for professionalism! Can't be greater than 8 points.\n";
        exit(EXIT_FAILURE);
    }
}
