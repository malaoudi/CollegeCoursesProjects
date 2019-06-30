//
//  main.cpp
//  Assignment 5 - Stack Template

//The Standard Template Library offers a stack template, which may be
/// implemented as a vector , a list , or a deque .
/// stack<int, vector<int>> iStack; // Vector stack
/// stack<int, list<int>> iStack; // List stack
/// stack<int> iStack; // Default − deque stack

#include <string>

#include <iostream>
#include "MyStack.h"

using namespace std;
int main() {
    
    //Creating a stack
    //template_class <DataType> stack_object
    MyStack<string> stack;
    
    
    string item;
    cout << "enter an item" << endl;
    getline(cin, item);
    
    stack.push(item);
    stack.pop(item);
    
    // Display the item.
    if (item != "")
         cout << item << " was popped.\n";
    
    
    /*
    MyStack<double> *theStack;      //a pointer object
    theStack = new MyStack<double>;     //an object
    
    
    int x=3;
    theStack->push(x);
    theStack->pop(x);
    */
    /*
    MyStack<double> *theStack1;
    //char            testString[50];
    int                i;
    char            ch;
    
    cout << "\tSimple Stack Demonstration\n\n\n";
    cout << "\t(Stack implemented as a linked structure - Stack data type is character.)\n\n";
    cout << "\tCreating a stack...\n\n";
    
    theStack = new MyStack<double>; // Instantiate a stack object
    MyStack<string> stack1;
    cout << "\tStack created...\n\n";
    
    // Test pushing and popping first/last item on a stack
    cout << "\tTesting push and pop of single item.\n\n";
    int y=3;
    theStack->push(y);
    theStack->pop(y);
    cout << "\tPopped: " << "\n\n";
    cout << "\t...done\n\n";
    
    /*
    // Test stack by reversing the order of letters in a string
    cout << "\tEnter a string to be reversed ::: ";
    // Use get() so we can input spaces
    cin.getline(testString,50); // Assume user is smart enought to not exceed the limit
    
    
    // Push all letters on the stack
    i = 0;
    while(testString[i] != '\0')
    {
        theStack->push(testString[i]);
        i++;
    }
    */
    /*
    /// Pop letters and print in reverse
    cout << "\tYour string printed in reverse is...\n\n\t";
    while((ch = theStack->pop()) != '\0') // Pop returns null terminator when stack is empty
        cout  << ch;
    */
    cout << "\n\n\t...done.\n";
    return 0;
   

}
