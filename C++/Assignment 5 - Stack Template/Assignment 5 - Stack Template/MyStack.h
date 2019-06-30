//
//  MyStack.h
//  Assignment 5 - Stack Template
//
///Write a template, MyStack.h, to implement a LIFO stack.
//dynamic stack template using linked list.

#ifndef MyStack_h
#define MyStack_h

template <typename V>
class MyStack
{
    /// Define a structure to be used as the stack item
    struct StackNode
    {
        V ch;                    //value in the node
        StackNode *next;        //pointer to the next node
    };

private:
    char ch;
    StackNode *top;        /// Pointer to top of the stack
    int size;

public:
    ///member functions
    
    MyStack( );              ///Class constructor. May have a defaulted parameter
    ~MyStack();              /// Class destructor
    
    V size1();
    
    void push(const V&);    /// Push an element onto the stack
    V& peek( );             /// returns a reference to the element at the top of the stack
    void pop(V);           ///Removes an element from the stack
    int setSize( );        /// Return size of the stack. The number of the elements in the list
    bool empty( ) const;   /// Return true if stack is empty. Returns false if it has elements
    void clear( );         /// Remove all items from the stack
    
    int getSize(bool);
    int num_elements;
};


#endif /* MyStack_h */
