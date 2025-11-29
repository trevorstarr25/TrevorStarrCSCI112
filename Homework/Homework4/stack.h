#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();
};

// set to nullptr and initialize stackSize
Stack::Stack()
{
    _top = nullptr;
    stackSize = 0;
}

// iteratively delete the stack starting at top
Stack::~Stack()
{
    while(!empty())
        pop();
}

// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
bool Stack::empty()
{
    return (_top == nullptr);
}

// return number of elements in Stack
size_t Stack::size()
{
    return stackSize;
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
    Node<double>* newNode = new Node<double>();
    newNode->setData(data);
    newNode->setNext(_top);
    _top = newNode;
    stackSize++;
}

// return the first element in the Stack.
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::top()
{
    if(empty()){
        cout << "Error: Stack is empty" << endl;
        return NAN;
    }
    return _top->getData();
}

// remove the first element from the Stack and return its data
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::pop()
{
    if(empty()){
        cout << "Error: Stack is empty" << endl;
        return NAN;
    }

    Node<double>* temp = _top;
    double data = temp->getData();
    _top = temp->getNext();
    delete temp;
    stackSize--;

    return data;
}
