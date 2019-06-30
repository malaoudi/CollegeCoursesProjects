//
//  MyDynamicArray.cpp
//  Assignment 5
//

#include <iostream>
#include "MyDynamicArray.h"
using namespace std;

//main constructor
template <typename V, int CAP>
MyDynamicArray<V, CAP>::MyDynamicArray(int cap)          //constructor
{
    this->cap = cap;
    //values = new V[cap];
    
    //int arraySize = size;
    //allocate memoery for the array
    
    values = new V[cap];      //pointer array
    
    //intialize the array to 0
    for (int count = 0; count < arraySize; count++)
        *(values + count) = 0;
    
    //this->operator[](count) = object[count];
}

//copy constructor
template <typename V, int CAP>
MyDynamicArray<V, CAP>::MyDynamicArray(const MyDynamicArray<V, CAP> &original)
{
    cap = original.cap;                            // still just a copy
    values = new V[cap];                    // not a copy -- new object gets its own array
    for (int i = 0; i < cap; i++)                 // copy the contents of the array from the original...
        values[i] = original.values[i]; // ...to the copy
}


//function for setter.  This function returns a reference to the element in the array indexed by the subscript
template <typename V, int CAP>                   //setter
V &MyDynamicArray<V, CAP>::operator[ ]( const int &index)                //v,return type. Name of the class<datatype,size>
{
    //  if (index < 0 || index >= arraySize)
    //    IndexError();
    
    if (index >= cap) return dummy;
    if (index >= cap) setCapacity(2 * index); // more than enough to include this index
        return values[index];
}


//function to display the input index pairs
template <typename V, int CAP>
void MyDynamicArray<V,CAP>::display()
{
    cout<<endl<<"Array contains:"<<endl;
    for(int i=0; i<10; i++) {
        cout<< values[i]<<" ";
    }
}


//get the element at the index
template <typename V, int CAP>
V MyDynamicArray<V,CAP>::getElementAt(int index)
{
    //  if (index < 0 || index >= arraySize)
    //    IndexError();
    return values[index];
}


//search function. findItem function.        This function searches for item. If item is found. the subscript is returned. Otherwise âˆ’1  returned.
template <typename V, int CAP>
V MyDynamicArray<V,CAP>::findItem(const V item)
{
    for (int count = 0; count <= arraySize; count++)
    {
        if (getElementAt(count) == item)
            return count;
    }
    cout << "can not find it" << endl;
    return -1;
}

//setter for capcacity.
template <typename V, int CAP>                  //capacity
void MyDynamicArray<V,CAP>::setCapacity(int cap)  {
    {
        // allocate a new array with the new capacity
        V* temp = new V[cap];
        
        // get the lesser of the new and old capacities
        int limit = min(cap, this->cap); // requires the C++ "algorithm" library
        
        // copy the contents
        for (int i = 0; i < limit; i++)
            temp[i] = values[i];
        
        // set added values to their defaults
        for (int i = limit; i < cap; i++)
            temp[i] = V( );
        
        // deallocate original array
        delete [ ] values;
        
        // switch newly allocated array into the object
        values = temp;
        
        // update the capacity
        this->cap = cap;
    }
}

//getter for capcacity.
template <typename V, int CAP>                  //capacity
int MyDynamicArray<V,CAP>::getCapacity( ) const {
    
    return CAP;
}



