
/*
//  MyStaticArray.DriverTest.cpp
//  Assignment 4
/*Here are the tests you'll do in any test driver:
 1.Test all public functions to make sure they work as you expect them to work.
 2.Const object test. (like const Array c;)
 3.The "ifndef" test. new
 */
//Do tests with int, double, or char. Also do tests with an object, like string.

#include <iostream>
using namespace std;

#include "MyStaticArray.h"
#include "MyStaticArray.h" // ifndef test

int main( )
{
   // ...
    //classname<,> array();
    
   // MyStaticArray<int, 20> a(10);           //testing the function in h. Class<typename, cap> a()
   // MyStaticArray<double, 20> b(12);
   // MyStaticArray<string, 3> c("Hello","Bye");
    
    //test the functions 
    
    
}



/*
 #include <iostream>
 #include <cmath>
 
 using namespace std;
 
 template <class T>
 class CompareIt
 {
 private:
 T a;
 T b;
 public:
 CompareIt(T x =0, T y = 0){a = x; b = y;}
 bool compared() {return (a == b ? true : false);}
 };
 
 template <>
 class CompareIt<float>
 {
 private:
 float a;
 float b;
 float const SMALL = 0.0001;
 public:
 CompareIt(float x =0, float y = 0){a = x; b = y;}
 bool compared() {return (fabs(a - b)< SMALL ? true : false);}
 
 };
 
 int main()
 {
 
 CompareIt<float> a(2.0,2.0);       //array(x1,x2)
 CompareIt<int> b(1,1);
 CompareIt<string> c("Hello", "Bye");
 
 cout << a.compared() << endl;
 cout << b.compared() << endl;
 cout << c.compared() << endl;
 }
 */


