

//
//  main.cpp
//  Assignment 5 demo
//
//  Created by z on 3/30/18.
//  Copyright © 2018 210. All rights reserved.

#include <string>
#include <iostream>

using namespace std;

//DynamicStack.h



// Stack template
template <class T>
class DynamicStack
{
private:
    int num_elements=0;
    // Structure for the stack nodes
    struct StackNode
    {
        T value; // Value in the node
        StackNode *next; // Pointer to the next node
    };
    
    
    StackNode *top; // Pointer to the stack top
    
public:
    //Constructor
    DynamicStack()
    { top = nullptr; }
    
    // Destructor
    ~DynamicStack();
    
    // Stack operations
    void push(T);
    void pop(T &);
    bool isEmpty();
    
    
    T& peek( );
    // int size( ) const;
    void clear( );
    void size() ;
    
    
};

//***************************************************
// Destructor *
//***************************************************
template <class T>
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodePtr, *nextNode;
    
    // Position nodePtr at the top of the stack.
    nodePtr = top;
    
    // Traverse the list deleting each node.
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//*************************************************************
// Member function push pushes the argument onto *
// the stack. *
//*************************************************************

template <class T>
void DynamicStack<T>::push(T item)
{
    
    StackNode *newNode = nullptr; // Pointer to a new node
    
    // Allocate a new node and store num there.
    newNode = new StackNode;
    newNode->value = item;
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else // Otherwise, insert NewNode before top.
    {
        newNode->next = top;
        top = newNode;
    }
    
    this->num_elements++;
    
}

//*************************************************************
// Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
// passed as an argument. *
//*************************************************************

template <class T>
void DynamicStack<T>::pop(T &item)
{
    StackNode *temp = nullptr; // Temporary pointer
    
    // First make sure the stack isn't empty.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else // pop value off top of stack
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
        
        this->num_elements--;
    }
}

//*************************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise. *
//*************************************************************

template <class T>
bool DynamicStack<T>::isEmpty()
{
    bool status;
    
    if (!top)
        status = true;
    else
        status = false;
    
    return status;
}

template <class T>
T& DynamicStack<T>::peek()
{
    StackNode *top;
    return top;
}


template <class T>
void DynamicStack<T>::clear()
{
    StackNode *temp;
    
    if(!isEmpty()){
        temp = top;
        /// Scan stack and free all nodes
        while(top != NULL){
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    top = NULL;
    
}

template <class T>
void DynamicStack<T>::size()
{
    cout << this->num_elements;
    
}


#include <string>
#include <iostream>

int main() {
    // Create the stack.
    DynamicStack<string> stack;
    
    string item;
    string item2;
    string x="bunch of items";
    string y=" need another items";
    string z= "need to work faster";
    cout << "enter an item" << endl;
    getline(cin, item);
    
    cout << "enter an item" << endl;
    getline(cin, item2);
    
    stack.push(item);
    stack.push(item2);
    stack.pop(item);
    stack.push(x);
    stack.push(y);
    stack.push(z);
    stack.push(x);
    
    
    // Display the item.
    if (item != "")
        cout << item << " was popped.\n";
    
    cout <<"size ";
    stack.size();
    // stack.num_elements;
    
    cout <<"is empty ";
    stack.isEmpty();
    
    cout <<"peek ";
    stack.peek();
    
    cout <<"clear ";
    stack.clear();
    stack.clear();
    
    cout <<"size ";
    stack.size();
    
    stack.pop(x);
    stack.pop(y);
    stack.pop(z);
    stack.pop(x);
    cout <<"is empty ";
    stack.isEmpty();
    
    
    // cout <<"is empty ";
    //stack.peek();
    return 0;
}


