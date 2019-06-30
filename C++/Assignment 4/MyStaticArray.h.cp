#ifndef MyStaticArray_h
#define MyStaticArray_h

template <typename V, int CAP>

class MyStaticArray
{
    V values[CAP];
    V dummy;
    
public:
    MyStaticArray( );
    int capacity( ) const {return CAP;}
    V operator[ ](int) const;
    V& operator[ ](int);
};


#endif
