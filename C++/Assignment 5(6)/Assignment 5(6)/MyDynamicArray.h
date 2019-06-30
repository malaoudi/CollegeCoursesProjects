//
//  MyDynamicArray.h
//  Assignment 5
//
//  Created by z on 3/6/18.
//  Copyright © 2018 210. All rights reserved.
//

#ifndef MyDynamicArray_h
#define MyDynamicArray_h

template <typename V, int CAP>
class MyDynamicArray
{
    
private:
    V dummy;
    //int arraySize;                            // Holds the array size
    int cap;
    V *values;
   // V *arrayPointer;                             //Pointer to the array
    
    V a;
    V b;
    V c;
    V d;
public:
    int arraySize;                                // Holds the array size
    ~MyDynamicArray( ){delete [ ] values;}   //destrcutor function, no reutrn type
    MyDynamicArray(int=2);                       // default constructor for capacity
    MyDynamicArray(const MyDynamicArray<V,CAP> &original);    //copy constructor
    
    
    
    int getCapacity( ) const;        //getter for capacity
    void setCapacity(int);                 //setter for capacity
    //int capacity( ) const; //{return CAP;}
    
    // V  operator[ ](int);
    V& operator[ ](const int&);
    //void IndexError();                  // no longer need, Auto-Adjustable array
    
    
    V getElementAt(int);
    V findItem(const V );
    void display();
    V deleteElement(int x);
    
    
    
};


#endif /* MyDynamicArray_h */


//v,return type. Name of the class<datatype,size>
//v will atutomcially do the prototype datatype for the parameters

