//
//  MyStaticArray.h
//  Assignment 4


#ifndef MyStaticArray_h
#define MyStaticArray_h

template <typename V, int CAP>
class MyStaticArray
{
    //V values[CAP];
    //V dummy;
    // To point to the allocated array
    
private:
    V *arrayPointer;         //Pointer to the array
public:
    int arraySize;         // Holds the array size

    MyStaticArray(int);
    int capacity( ) const; //{return CAP;}              //v will atutomcially do the prototype datatype for the parameters
    //V  operator[ ](int);
    V getElementat(int);
    V& operator[ ](const int&);
    void IndexError();
    void display();
    V findItem(const V );
    
};



#endif /* MyStaticArray_h */
