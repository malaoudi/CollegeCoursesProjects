
#include <iostream>
#include "MyStaticArray.h"

using namespace std;

template <typename V, int CAP>
V& MyStaticArray<V, CAP>::operator[ ](int index)
{
    if (index < 0) return dummy;
    if (index >= CAP) return dummy;
    return values[index];
}


template <typename V, int CAP>
V MyStaticArray<V, CAP>::operator[ ](int index) const
{
    if (index < 0) return V( );
        if (index >= CAP) return V( );
            return values[index];
}


template <typename V, int CAP>
int& Array<V, CAP>::operator[](int i)
{
    ...
}

...
