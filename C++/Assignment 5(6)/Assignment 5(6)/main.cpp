
//  main.cpp
//  Assignment 4

#include <iostream>
#include <string>

#include "MyDynamicArray.h"
#include "MyDynamicArray.cpp"

using namespace std;

int main() {

    
    //class<DataType,n>
    MyDynamicArray<double,1> h;
    int size1; //size of the array
    cout << "Enter the size of the array" << endl;
    cin >> size1;
    MyDynamicArray<double, 100> DoubleArray1(size1);    //create 100 DoubleArray1 objects. each object
    //has size1 array and is able to store size1 elements
    
    string buf;
    double index1;
    double value1;
    
    while (true) {
        //size2++;
        cout << "Input an index and a value [Q to quit]" << endl;
        cin>>buf; value1= atoi(buf.c_str());
        cout << " ";
        cin>>buf; index1= atoi(buf.c_str());
        DoubleArray1[index1]= value1;
        if (buf == "q") {
            cout <<"you stored this many values:" << " Size " << DoubleArray1.getCapacity() << endl;
            cout << "the index-value pairs are:\n";
            for (int x = 0; x < size1; x++) {
                cout << index1 << "=>" << DoubleArray1[x] << endl;
            }
            DoubleArray1.display();
            cout << endl;
            // delete 0s in array
     
             int i;
             int n=0;
             for (i=0; i<DoubleArray1.arraySize; i++) {
             if (DoubleArray1[i] == n)
             DoubleArray1.arraySize = DoubleArray1.arraySize - 1;
             for (int j=i; j<DoubleArray1.arraySize; j++)
             DoubleArray1[j] = DoubleArray1[j+1];
             }
             
            cout << "Input an index for me to look up" << endl;
            cin>>buf; index1= atoi(buf.c_str());
            cout << "get the value " << DoubleArray1.getElementAt(index1) << endl;
            }
        
        if (buf=="Q") {
            exit(0);
            }
        
    }
    
    return 0;
    
}


//Array<int> a(100);
//a.capacity(200); // change capacity to 200


