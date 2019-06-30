//Print function is added to the stack.h header file

//and test program to test the generic stack
//Stack.h

 #include <string>
 #include <iostream>
 #include <cstring>
 #include <iomanip>
#include "Stack.h"
#include "Stack.cpp"


using namespace std;

int main()
{
    
    
    Stack<double> *theStack;            //stack pointer. pointer
    theStack= new Stack<double>();      //stack object. pointer is in the object
    
    theStack->computeRPN();
    
    
    
    return 0;
}



// Create the stack.
// Stack<string> stack; // Class<DataType> Variable;

//create a stack object
//StackAsLList<class T>    *theStack;
//cout << "\tCreating a stack...\n\n";
//theStack = new StackAsLList<T>(); // Instantiate a stack object
//Pointer<class T> = new Pointer; // declares the object

//pointer of class stack, pointing to a stack. Stack pointer allows to acess all other veriable
// define by the class, or all the stacks defined by the stack class.
//Stack_Object=&stack1; //save the address of stack1 into the object.


