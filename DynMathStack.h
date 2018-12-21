#ifndef DYNMATHSTACK_H
#define DYNMATHSTACK_H

class DynMathStack
{
private:
    struct StackNode
    {
        int value;
        StackNode *next;
    };

    StackNode *top;

public:
    DynMathStack()
    {
        top = nullptr;
    }
    ~DynMathStack();

    void push(int);
    void pop (int &);
    void add();
    void sub();
    void multiply();
    void divide();
    bool isEmpty();
};

#endif // DYNMATHSTACK_H
