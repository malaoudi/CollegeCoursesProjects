
//  MyStaticArray.cpp
//  Assignment 4
#include <iostream>
#include <string>
#include <new>          // Needed for bad_alloc exception
#include <cstdlib>       // Needed for the exit function
#include "MyStaticArray.h"

using namespace std;

//template <class V, int CAP>
//MyStaticArray<int, 20> a(10);     create int class, storage up to 20 int values. int is passed to to template. becomes <int V>. The  V variable is going to define the data type for the parameter of the function. The template must be used before every fucntion defnition

template <typename V, int CAP>
MyStaticArray<V, CAP>::MyStaticArray(int size)          //constructor
{
     arraySize = size;
    //allocate memoery for the array
    arrayPointer = new V [size];      //pointer array
    //intialize the array to 0
    for (int count = 0; count < arraySize; count++)
        *(arrayPointer + count) = 0;
    //this->operator[](count) = object[count];
    
}


//function for setter.  This function returns a reference to the element in the array indexed by the subscript
template <typename V, int CAP>                   //setter
V &MyStaticArray<V, CAP>::operator[ ]( const int &index)                //v,return type. Name of the class<datatype,size>
{
    if (index < 0 || index >= arraySize)
        IndexError();
        //arrayPointer[index];            //non-const lvalue reference to ype double
    return arrayPointer[index];
}

/*
 //function for getter.  This function returns the value stored at the subcript in the array.
 template <typename V, int CAP>
 V MyStaticArray<V, CAP>::operator[ ](int index)               //getter
 {
 if (index < 0 || index >= arraySize)
 IndexError();
 return arrayPointer[index];
 }
 */

template <typename V, int CAP>
V MyStaticArray<V,CAP>::getElementat(int index)
{
    if (index < 0 || index >= arraySize)
        IndexError();
    return arrayPointer[index];
}


//Your app should keep track of which indexes got entered. Use a bool MyStaticArray for that.

//fucntion for capcacity.
template <typename V, int CAP>                  //capacity
int MyStaticArray<V,CAP>::capacity() const  {
    return CAP;
}

//function for index being out of the capacity range
template <typename V, int CAP>
void MyStaticArray<V, CAP>::IndexError()                   //input out of capcity
{
    cout << "ERROR: Index out of range.\n";
}

//function to display the input index pairs
template <typename V, int CAP>
void MyStaticArray<V,CAP>::display()
{
    cout<<endl<<"Array contains:"<<endl;
    for(int i=0; i<arraySize; i++) {
        cout<<arrayPointer[i]<<"\t";
    }
}

//search function. findItem function.        This function searches for item. If item is found. the subscript is returned. Otherwise âˆ’1  returned.
template <typename V, int CAP>
V MyStaticArray<V,CAP>::findItem(const V item)
{
    for (int count = 0; count <= this->size(); count++)
    {
        if (getElementat(count) == item)
            return count;
    }
    return "none";
}
