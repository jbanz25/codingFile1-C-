/**
    * Jacob Bananal
    *
    * Chapter 18 Programming Assignment (Linked List)
    *
    * April 17, 2018
    *
**/

#include <iostream>
#include <iomanip>
#include "CapitalLettersList.h"
using namespace std;

//function declaration
int displayMenu();
int userInput(int, char, CapitalLettersList);
void endProgram();
void defaultMessage();

int main()
{
    CapitalLettersList listOfNodes; // declares the CapitalLettersList
    int position;
    char letter;
    userInput(position,letter,listOfNodes); // calls the function to display the menu and allow the user to input
    return 1;
}

/******************************************************
//name: displayMenu
//called by: userInput
//passed: nothing
//returns: choice
//calls: nothing
// This function displays the main menu for the capital letters
// list.
*******************************************************/
int displayMenu()
{
    int choice;
	cout << "\nCapital Letters List Main Menu"
		<< "\n\n1). Append Node\n\n" // choice 1
		<< "2). Insert at Position\n\n" // choice 2
		<< "3). Delete at Position\n\n" // choice 3
		<< "4). Print List\n\n" // choice 4
		<< "5). Reverse List\n\n" // choice 5
		<< "6). Search List\n\n" // choice 6
		<< "7). End Program\n\n" // choice 7
		<< "\n Enter your choice (1-7): \n\n"; // user will input a number of their choice
	cin >> choice;
	return choice; // returns the choice the user inputs.
}

/******************************************************
//name: userInput
//called by: main
//passed: int position, char letter, CapitalLettersList listofNodes
//returns: userChoice
//calls: functions from CapitalLetterList.cpp
// This function allows the user to input a choice and
// whatever choice they input such as appendNode, insert, delete,
// print, reverse, and search, will display what they chose.
*******************************************************/
int userInput(int position, char letter, CapitalLettersList listOfNodes)
{
    int userChoice = 0;
	// creates a constant for each choice in order for the choices to work
	const int APPENDNODE = 1, INSERTNODE = 2, DELETENODE = 3, PRINTLIST = 4, REVERSELIST = 5, SEARCHLIST = 6, ENDPROGRAM = 7;

	do
	{
		userChoice = displayMenu(); //calls the displayMenu function

		switch (userChoice)
		{
		case APPENDNODE:
		{
		    // allows the user to input a capital letter which then checks if its upper case
		    // otherwise the program will exit if lower case is inputted.
            do
            {
                cout << "\nEnter an appending capital letter: ";
                cin >> letter;
                break;
            }
            while(isupper(letter)); // checks if the user input is upper case

            listOfNodes.appendNode(letter);// calls the appendNode function
            break;
		}
		case INSERTNODE:
		{
		    // allows the user to input a capital letter which then checks if its upper case
		    // otherwise the program will exit if lower case is inputted.
		     do
             {
                 cout << "\nEnter an appending capital letter: ";
                 cin >> letter;
                 break;
             }
		     while (isupper(letter)); //checks if the user input is upper case

		     //allows the user to enter a position to insert the letter
		     cout << "\nEnter a node in position: ";
		     cin >> position;
		     while (position <0)
		     {
		         cout << "\nSorry invalid input! Must be a valid position!";
		         cout << "\nEnter a valid position: \n";
		         cin >> position;
		     }
		     cout << "\nDone!\n";
		     listOfNodes.insertNode(position,letter); // calls the insertNode function
			break;
		}
		case DELETENODE:
		{
		    // allows the user to input a position to delete in the list
		    cout << "\nEnter a node in position to delete: ";
		    cin >> position;
		    while (position < 0)
		    {
		        cout << "\nSorry invalid input! Must be a valid position!";
		        cout << "\nEnter a valid position to delete: ";
		        cin >> position;
		    }
		    cout << "\nDone!\n";
		    listOfNodes.deleteNode(position); // calls the deleteNode function
			break;
		}
		case PRINTLIST:
		{
		    cout << "\nList of Capital Letters\n";
		    cout << "_______________________\n" << endl;
		    listOfNodes.printList(); // prints the list of the capital letters
			break;
		}
		case REVERSELIST:
		{
		    cout << "\nList of Capital Letters has been reversed!\n";
		    listOfNodes.reverseList(); //calls the reverseList function
			break;
		}
		case SEARCHLIST:
        {
            // allows the user to input a capital letter which then checks if its upper case
		    // otherwise the program will exit if lower case is inputted.
            do
            {
                cout << "\nEnter a letter to search: ";
                cin >> letter;
                break;
            }
            while (isupper(letter)); // checks if the user input is upper case

            listOfNodes.searchIntoList(letter);
            cout << "\nCapital Letter found at position " << listOfNodes.searchIntoList(letter) << endl;
            break;
        }
        case ENDPROGRAM:
        {
            endProgram(); // calls the endProgram function
            break;
        }
		default:
		{
			defaultMessage(); //calls the defaultMessage function
			break;
		}

		}
	}
	while (userChoice != 7);
}

/******************************************************
//name: defaultMessage
//called by: userInput
//passed: nothing
//returns: nothing
//calls: nobody
// This function displays the default message whenever a user
// enters an invalid message.
*******************************************************/
void defaultMessage()
{
    cout << "\nSorry! That was an invalid choice \n"
        << "The valid choices are 1-7 \n"
		<< "Run the program again! \n"; // displays the default message
}

/******************************************************
//name: endProgram
//called by: userInput
//passed: nothing
//returns: nothing
//calls: nobody
// This function displays a message that the program is
// ending whenever a user inputs choice 7.
*******************************************************/
void endProgram()
{
    cout << "\nThe program is ending...\n"; //displays the end of the program message
}
