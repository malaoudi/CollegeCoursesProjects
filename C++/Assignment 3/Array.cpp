
#include <iostream>
using namespace std;

class Array {
public:
    //create an array of 100 int values and intialzie to zero.
    //Use a constructor. Format class::class(paramter)
    Array(int);        //constructor
    int &operator[](const int &);
    int operator[](int);
    void setValues(int);
    
    double getCapacity();
    double capacity;
private:
    int arraySize;         // Holds the array size
    int *arrayPointer;         //Pointer to the array
    void subscriptError(); // Handles invalid subscripts
    
};

//external constructor definition
Array::Array(int size)                      //format ClassName :: ClassName ( ParameterList )
{
    cout << "You're in the constructor" << endl;
    int arraySize = size;
    //allocate memoery for the array
    arrayPointer = new int [size];      //pointer array
    //intialize the array to 0
    for (int count = 0; count < arraySize; count++)
        *(arrayPointer + count) = 0;
}



void Array::setValues(int val)              //setter
    {
        cout << "You're in setValues." << endl;
       // int inde = ind;
        arrayPointer = &val;
     }


int &Array::operator[](const int &index)      //getter
 {
     if (index < 0 || index >= arraySize)
         subscriptError();
        return arrayPointer[index];
     }

void subscriptError() {
    cout << "Error. Entered index is out of range" << endl;
    exit(0);
}

double Array::getCapacity() {
    return capacity;
}
