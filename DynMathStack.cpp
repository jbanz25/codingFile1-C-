#include "DynMathStack.h"
#include <iostream>
using namespace std;

DynMathStack::~DynMathStack()
{
    StackNode *nodePtr = nullptr, *nextNode = nullptr;

    nodePtr = top;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DynMathStack::push(int num)
{
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = num;

    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void DynMathStack::pop(int &num)
{
    StackNode *temp = nullptr;

    if (isEmpty())
    {
        cout << "The stack is empty!\n";
    }
    else
    {
        num = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

void DynMathStack::add()
{
    int num, sum;

    pop(sum);
    pop(num);

    sum += num;

    push(sum);
}

void DynMathStack::sub()
{
    int num, diff;

    pop(diff);
    pop(num);

    diff -= num;

    push(diff);
}


bool DynMathStack:: isEmpty()
{
    bool status;
    if(!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

