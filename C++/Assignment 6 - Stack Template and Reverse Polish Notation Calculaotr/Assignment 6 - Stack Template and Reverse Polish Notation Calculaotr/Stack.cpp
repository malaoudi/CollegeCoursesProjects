//  Stack.cpp
//  Assignment 6 - Stack Template and Reverse Polish Notation Calculaotr


#include "Stack.h"
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
//*********************************************************
// Destructor *
//*********************************************************
template <class T>
void Stack<T>::size()
{
    cout << this->num_elements;
    
}

template <class T>
void Stack<T>::clear(){
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
Stack<T>::Stack(){
    
    top = NULL;
    
}
template <class T>
Stack<T>::~Stack()
{
    StackNode *nodePtr, *nextNode;
    
    // Position nodePtr at the top of the stack
    nodePtr = top;
    
    // Traverse the list deleting each node
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}


//*********************************************************
// Member function push pushes the argument onto the *
// stack. *
//*********************************************************
template <class T>
void Stack<T>::push(T item)
{
    StackNode *newNode; // Pointer to a new node
    
    // Allocate a new node and store num there
    newNode = new StackNode;
    newNode->value = item;
    
    // If there are no nodes in the list make newNode
    // the first node
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else // Otherwise, insert newNode before top
    {
        newNode->next = top;
        top = newNode;
    }
    this->num_elements++;
}


//*********************************************************
// Member function to print elements from the stack*
//*********************************************************
template <class T>
void Stack<T>::print()
{
    StackNode *temp=top;     //node pointing to the top
    T item;
    // Traverse the stack until the temp node is not null
    while (temp != NULL)
    {
        item = temp->value;
        cout<<item<<endl;
        temp = temp->next;
    }
}
template <class T>
void Stack<T>::peek(){
    cout << top->value;
    
}


//*********************************************************
// Member function pop pops the value at the top of the *
// stack off, and copies it into the variable passed as an*
// argument. *
//*********************************************************
template <class T>
void Stack<T>::pop(T &item)
{
    StackNode *temp; // Temporary pointer
    
    // First make sure the stack isn't empty
    if (isEmpty())
    {
        cout << "ERROR! The stack is empty.\n";
    }
    else
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    
    this->num_elements--;
}


//*********************************************************
// Member function isEmpty returns true if the stack is *
// empty, or false otherwise. *
//*********************************************************
template <class T>
bool Stack<T>::isEmpty()
{
    bool status;
    
    if (!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}



//function to quit the program
template <class T>
bool Stack<T>::CheckInput(string myString)
{
    bool valid = true;
    
    if ((myString == "q") || (myString == "Q"))
        valid = false;
    return valid;
}

//function to calculate RPN with the input
template <class T>
T Stack<T>::computeRPN(){
    
    string myToken;
    
    //create a stack
    Stack<double> stack1;
    
    cout << "Enter: ";
    
    do
    {
        
        getline(cin, myToken);
        if (isdigit(myToken[0]))
        {
            
            stack1.push(atof(myToken.c_str()));
            
            //Get next value.
            cout << "Enter: " << stack1.top1() << " ";
            
        }
        
        //Else block.
        else
        {
            
            //Assign top to x.
            double x = stack1.top1();
            
            //Pop the value.
            stack1.pop(x);
            
            //Assign top to y.
            double y = stack1.top1();
            
            //Pop the value.
            stack1.pop(y);
            
            //Switch case.
            switch (myToken[0])
            {
                    
                case '+': stack1.push(x + y);
                    
                    break;
                case '-': stack1.push(y - x);
                    break;
                    
                case '*': stack1.push(y*x);
                    break;
                    
                case '/': stack1.push(y / x);
                    break;
                    
                case '%': stack1.push(y / x);
                    break;
            }
            
            //Prompt user for value
            cout << "Enter: " << stack1.top1() << " ";
            
        }
    }
    
    
    while (stack1.CheckInput(myToken) == true);
    return stack1.top1();
    
}


