//  Stack.hpp
//  Assignment 6 - Stack Template and Reverse Polish Notation Calculaotr

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <string>


template <class T>
class Stack
{
    int num_elements=0;
    
private:
    // Structure for the stack nodes
    struct StackNode
    {
        T value; // Value in the node
        StackNode *next; // Pointer to the next node
    };
    
    StackNode *top; // Pointer to the stack top
    
public:
    // Constructor
    Stack();
    
    // Destructor
    ~Stack();
    
    // Stack operations
    void push(T);
    void pop(T&);
    bool isEmpty();
    void peek();
    void clear();
    void size();
    void print();
    
    T top1() {return top->value;};
    bool CheckInput(std::string);
    T computeRPN();
    
    
};



#endif /* Stack_hpp */


