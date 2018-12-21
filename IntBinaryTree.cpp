/**
* Jacob Bananal
*
* Chapter 21 - Homework 21 Programming Assignment
*
* May 22, 2018
*
**/

#include "IntBinaryTree.h"
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

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
void IntBinaryTree::insert(BinaryTreeNode *&nodePtr, BinaryTreeNode *&newNode)
{
	if (nodePtr == nullptr)
	{
		nodePtr = newNode; //inserts the newNode 
	}
	else if (newNode->value < nodePtr->value)
	{
		insert(nodePtr->left, newNode); // searches the left branch
	}
	else
	{
		insert(nodePtr->right, newNode); // searches the right branch
	}
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
void IntBinaryTree::insertBinaryNode(int num)
{
	BinaryTreeNode *newNode = nullptr;
	newNode = new BinaryTreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// insert the node
	insert(root, newNode);
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
void IntBinaryTree::destroySubTree(BinaryTreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
		{
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right)
		{
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
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
void IntBinaryTree::displayInOrder(BinaryTreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
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
int IntBinaryTree::leafCounter(BinaryTreeNode *nodePtr)
{
	if (nodePtr == nullptr)
	{
		return 0;
	}
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
	{
		return 1;
	}
	else
	{
		return(leafCounter(nodePtr->left) + leafCounter(nodePtr->right));
	}
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
int IntBinaryTree::treeHeight(BinaryTreeNode *nodePtr)
{
	int leftDepth, rightDepth;
	if (nodePtr == nullptr)
	{
		return -1;
	}
	leftDepth = treeHeight(nodePtr->left);
	rightDepth = treeHeight(nodePtr->right);
	if (leftDepth >= rightDepth)
	{
		return (leftDepth + 1);
	}
	else
	{
		return (rightDepth + 1);
	}
}

int IntBinaryTree::treeWidth(BinaryTreeNode *nodePtr)
{
	int num;
	if (nodePtr == nullptr)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
	else if (num > 1)
	{
		return (treeWidth(nodePtr->left) + treeWidth(nodePtr->right));
	}
}