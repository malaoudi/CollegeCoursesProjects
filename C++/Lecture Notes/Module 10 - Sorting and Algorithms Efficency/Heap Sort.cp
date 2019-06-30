//Heap Sort
/*Heap Sort

Sort Type: Comparison-Based Sorting / Priority Queue Sorting

Algorithm

Description:

All Priority Queue Sorting is based on arranging the data structures into a priority queue using the keys. Because of its structure a Heap is automatically a priority queue. Repeatedly dequeuing structures from the heap and moving them into an array will give a sorted array.


Data holder: Heap of data structures and an empty array of data structures.

Technique:

Build a heap from the given data.
Copy the data in the root node of the heap (it will be the one with the largest key or greatest priority) and place it at the end of the sorted data (assuming the sorted array is filled from right to left).
Reheap the heap.
Repeat until the heap is empty.

Analysis: At first, it would seem that because of the shifting and re-building of the heap that this sort would take as long, or longer, than Selection Sort. Surprisingly this sort can run in O(n log n).

*/

/// https://www.programiz.com/dsa/heap-sort

#include <cstdlib>

#include <ctime>

#include <iostream>

using namespace std;



// C++ program for implementation of Heap Sort

#include <iostream>

using namespace std;



void heapify(int arr[], int n, int i)

{
    
    // Find largest among root, left child and right child
    
    int largest = i;
    
    int l = 2*i + 1;
    
    int r = 2*i + 2;
    
    
    
    if (l < n && arr[l] > arr[largest])
        
        largest = l;
    
    
    
    if (r < n && arr[r] > arr[largest])
        
        largest = r;
    
    
    
    // Swap and continue heapifying if root is not largest
    
    if (largest != i)
        
    {
        
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);
        
    }
    
}



// main function to do heap sort

void heapSort(int arr[], int n)

{
    
    // Build max heap
    
    for (int i = n / 2 - 1; i >= 0; i--)
        
        heapify(arr, n, i);
    
    
    
    // Heap sort
    
    for (int i=n-1; i>=0; i--)
        
    {
        
        swap(arr[0], arr[i]);
        
        
        
        // Heapify root element to get highest element at root again
        
        heapify(arr, i, 0);
        
    }
    
}



void printArray(int arr[], int n)

{
    
    for (int i=0; i<n; ++i)
        
        cout << arr[i] << " ";
    
    cout << "\n";
    
}



int main()

{
    
    int arr[] = {1,12,9,5,6,10};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    heapSort(arr, n);
    
    
    
    cout << "Sorted array is \n";
    
    printArray(arr, n);
    
}
