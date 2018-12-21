/**
    * Jacob Bananal
    *
    * Chapter 18 Programming Assignment (Linked List)
    *
    * April 17, 2018
    *
**/

#ifndef CAPITALLETTERSLIST_H
#define CAPITALLETTERSLIST_H
#include <iostream>
using namespace std;


class CapitalLettersList
{
private:
    // declares a structure for the list
    struct ListNode
    {
        char capitalLetter; // the value in this node
        struct ListNode *next; // to point to the next node
    };

    ListNode *head; // list head pointer
public:
    CapitalLettersList()
    {
        head = nullptr;
    }
    //mutator functions
    void appendNode(char);
    int insertNode(int,char);
    int deleteNode(int);
    void printList() const;
    void reverseList();
    int searchIntoList(char);
    ~CapitalLettersList(); //destructor
};

#endif // CAPITALLETTERSLIST_H
