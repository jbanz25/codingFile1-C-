/**
* Jacob Bananal
*
* Chapter 20 - Homework 20 Programming Assignment
*
* May 15, 2018
*
**/

#ifndef CAPITALLETTER_H
#define CAPITALLETTER_H
#include <iostream>
using namespace std;

class CapitalLetter
{
private:
	// declares a structure for the list
	struct ListNode
	{
		char capitalLetter; // the value in this node
		struct ListNode *next; // to point to the next node
	};

	ListNode *head; // list head pointer
	//private member functions
	int countNumberOfNodes(ListNode *) const;
	char maxNode(ListNode *) const;
public:
	CapitalLetter()
	{
		head = nullptr;
	}
	//mutator functions
	void appendNode(char);
	int insertNode(int, char);
	int deleteNode(int);
	void printList() const;
	void reverseList();
	int searchIntoList(char);
	int numNodes() const
	{
		return countNumberOfNodes(head); // calls the private member functions 
	}
	char displayMaxNode() const
	{
		return maxNode(head); // calls the private member functions 
	}
	~CapitalLetter(); //destructor
};

#endif 

