//
//  MyStack.cpp
//  Assignment 5 - Stack Template
//


#include "MyStack.h"
#include <iostream>
using namespace std;


//constructor
template <typename V>
MyStack<V>::MyStack(){
     top = nullptr;
}


///destructor
template <typename V>
MyStack<V>::~MyStack(){
    clear();
}


///push
template <typename V>
void MyStack< V>::push(const V& element) {
    StackNode *newNode = nullptr; // Pointer to a new node
    
     // Allocate a new node and store num there.
     newNode = new StackNode;
     newNode->value = element;
    
     // If there are no nodes in the list
     // make newNode the first node.
     if (empty()) {
             top = newNode;
             newNode->next = nullptr;
             }
     else // Otherwise, insert NewNode before top.
         {
             newNode->next = top;
             top = newNode;
             }
    
    size++;
}


///pop
template <typename V>
void MyStack< V>::pop(V element) {
    
     StackNode *temp = nullptr; // Temporary pointer
    // First make sure the stack isn't empty.
     if (empty()) {
             cout << "The stack is empty.\n";
             }
     else // pop value off top of stack
    {
             element = top->value;
             temp = top->next;
             delete top;
            top = temp;
            }
}


///peek
template <typename V>
V &MyStack<V>::peek(){
     StackNode *top;
    return top;
}


///Set size
template <typename V>
int MyStack<V>::setSize( ) {
    // Get the desired stack size.
     cout << "How big should I make the stack? ";
     cin >> size;
    
     // Validate the size.
  while (size < 1)
         {
             cout << "Enter 1 or greater: ";
             cin >> size;
             }
}


///get Size
template <typename V>
int MyStack<V>::getSize(bool update) {
    if (!update) {
        return this->list_size;
    }
    int size = 0;
    V* temp = this->head;
    while (temp) {
        size++;
        temp = temp->next;
    }
    this->list_size = size;
    return this->list_size;
}

/*
///size
template <typename V>
int MyStack<V>::size1()
{
    if (first == NULL && last == NULL) {return 0;}
    
    Node<T>* temp = first;
    int nodeCounter = 0;
    
    while (temp != NULL)
    {
        nodeCounter = nodeCounter + 1;
        temp = temp->next;
    }
    return nodeCounter;
}
*/



///empty
template <typename V>
bool MyStack<V>::empty( ) const{
    bool status;
    
     if (!top)
         status = true;
    else
         status = false;
    return status;
}


///clear
template <typename V>
void MyStack< V>::clear( ){
    struct StackNode *temp;
    
    if(!empty()){
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
