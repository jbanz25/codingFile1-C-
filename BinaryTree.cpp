/**
* Jacob Bananal
*
* Chapter 21 - Homework 21 Programming Assignment
*
* May 22, 2018
*
**/

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************
//name: insert
//called by: BinaryTree
//passed: BinaryTreeNode *&nodePtr, *&newNode
//returns: inserted number 
//calls: recursive insert()
// This function inserts the node into the tree pointed to by
// the BinaryTreeNode pointer in which this case we are using
// recursive. 
*******************************************************/
void BinaryTree::insert(BinaryTreeNode *&nodePtr, BinaryTreeNode *&newNode)
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
//name: insertBinaryNode
//called by: BinaryTree
//passed: int num
//returns: inserted new node in the tree
//calls: insert()
// This function insertBinaryNode creates a new node 
// to hold num as its value and passed it to the 
// insert function
*******************************************************/
void BinaryTree::insertBinaryNode(int num)
{
	BinaryTreeNode *newNode = nullptr; //pointer to a new node 

	// creates a new node and stores num in it 
	newNode = new BinaryTreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// insert the node
	insert(root, newNode);
}

/******************************************************
//name: destroySubTree
//called by: destructor
//passed: BinaryTreeNode *nodePtr
//returns: deletes all nodes
//calls: recursive destroySubtree()
// This function is called by the destructor which will
// delete all the nodes in the binary tree.
*******************************************************/
void BinaryTree::destroySubTree(BinaryTreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left) //points to left branch
		{
			destroySubTree(nodePtr->left); //deletes all the left branch 
		}
		if (nodePtr->right) //points to right branch 
		{
			destroySubTree(nodePtr->right); // deletes all the right branch
		}
		delete nodePtr;
	}
}

/******************************************************
//name: displayInOrder
//called by: displayInOrder()
//passed: BinaryTreeNode *nodePtr
//returns: binary tree in order 
//calls: recursive displayInOrder()
// This function displays the values in the subtree pointed
// to by nodePtr, via inorder traversal. 
*******************************************************/
void BinaryTree::displayInOrder(BinaryTreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl; //displays each value in order 
		displayInOrder(nodePtr->right);
	}
}

/******************************************************
//name: leafCounter
//called by: displayLeafCounter()
//passed: BinaryTreeNode *nodePtr
//returns: number of leaf nodes 
//calls: recursive leafCounter()
// This function leafCounter counts all the leaf nodes in the 
// binary tree and returns the number of leaf nodes
*******************************************************/
int BinaryTree::leafCounter(BinaryTreeNode *nodePtr)
{
	if (nodePtr == nullptr)
	{
		return 0; //returns 0 if empty 
	}
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
	{
		return 1; // if left and right are empty, returns 1
	}
	else
	{
		return(leafCounter(nodePtr->left) + leafCounter(nodePtr->right)); //uses recursive to count 
	}
}

/******************************************************
//name: treeHeight
//called by: displayTreeHeight()
//passed: BinaryTreeNode *nodePtr
//returns: height of the tree
//calls: recursive treeHeight()
// This function treeHeight will count and return the height 
// of the tree in which case the height is the number of level
// it contains. 
*******************************************************/
int BinaryTree::treeHeight(BinaryTreeNode *nodePtr)
{
	int leftDepth, rightDepth;
	if (nodePtr == nullptr)
	{
		return 0; // if list is empty, return 0
	}
	leftDepth = treeHeight(nodePtr->left); //sets the leftDept
	rightDepth = treeHeight(nodePtr->right); //sets the rightdept 
	if (leftDepth >= rightDepth) //if left is greater than or equal to right, return left dept
	{
		return (leftDepth + 1);
	}
	else // if right is greater then return right dept 
	{
		return (rightDepth + 1);
	}
}

/******************************************************
//name: treeWidth
//called by: maxTreeWidth()
//passed: BinaryTreeNode *nodePtr, int num
//returns: width of the tree
//calls: recursive treeWidth()
// This function treeWidth will get the width of each level
// and returns width of each level
*******************************************************/
int BinaryTree::treeWidth(BinaryTreeNode *nodePtr, int num)
{
	if (nodePtr == nullptr)
	{
		return 0; // if empty, return 0
	}
	if (num == 1)
	{
		return 1; //if level is 1, return 1
	}
	else if (num > 1) // if level is greater than 1, return the width of the level
	{
		return (treeWidth(nodePtr->left, num-1) + treeWidth(nodePtr->right, num-1));
	}
}

/******************************************************
//name: maxTreeWidth
//called by: displayTreeWidth
//passed: BinaryTreeNode *nodePtr
//returns: maximum width of the tree
//calls: treeWidth, treeHeight
// This function maxTreeWidth will the largest number of nodes
// in the same level and also prints level order traversal
*******************************************************/
int BinaryTree::maxTreeWidth(BinaryTreeNode *nodePtr)
{
	int maximumWidth = 0;
	int widthOfTree;
	int heightOfTree = treeHeight(nodePtr); //calls the treeHeight function

	/* Get width of each level and compare
	the width with maximum width so far */
	for (int i = 1; i <= heightOfTree; i++)
	{
		widthOfTree = treeWidth(nodePtr, i);
		if (widthOfTree > maximumWidth) // if width is greater than max, set max to it 
		{
			maximumWidth = widthOfTree;
		}
	}

	return maximumWidth;
}