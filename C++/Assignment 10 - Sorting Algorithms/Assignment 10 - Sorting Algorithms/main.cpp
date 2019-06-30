
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

// Constants
 const int size = 500000;
// global array
int randomValues[size] = {};

//global pointer for the dynamically allocated array
int *randomValues2;

//bubblesort function. //sort the array
void bubbleSort(int array_size, int  arr[])
{
    int pass =1, temp;
    bool swap  =  true;
    while ( pass < array_size && swap == true)
    {
        swap= false;
        int x=1;
        for ( int i = 0; i< array_size-x; i++)
        {
            if  ( arr [i]  >  arr[ i+1])
            {
                temp  = arr[i];
                arr[i]  =  arr[i+1];
                arr[i+1]  =  temp;
                swap= true;
            }
        }
        pass = pass + 1;
    }
}

//selection sort function
void selectSort(int SIZE,int DataArray[])
{
    int            NextIdx;    /* Next open position in sorted section */
    int            LargestKey;    /* INdex of largest key in unsorted section */
    int            i;
    int    temp;
    NextIdx = SIZE - 1;
    while(NextIdx > 0)
    {
        LargestKey = NextIdx;  /* Initialize the search by assuming the  */
        /* entry in the next open position in the */
        /* sorted section has the largest key.    */
        /* Find next largest key in unsorted section */
        for(i=0; i<NextIdx; i++)
            if(DataArray[i] > DataArray[LargestKey])
                LargestKey = i;
        /* Swap the largest key with the one at the top of the Priority Queue */
        temp = DataArray[LargestKey];
        DataArray[LargestKey] = DataArray[NextIdx];
        DataArray[NextIdx] = temp;
        /* Set NextIdx to next position up */
        NextIdx--;
    }
}

/***************************************/
/* InsertSort()                        */
/*                                     */
/* Sorts integer keys using   */
/*  an insertion sort.                 */
/***************************************/
void InsertSort(int DataArray[], int count)
{
    int            i, j;
    int            temp;
    int            NotDone;
    int            Key;
    for(i=1; i<count; i++)
    {
        Key = DataArray[i];
        j = i;
        NotDone = (DataArray[j-1] > Key);
        temp = DataArray[j]; /* Remove and hold the one to be moved */
        while(NotDone)
        {
            /* Slide all others to the right */
            DataArray[j] = DataArray[j-1];
            j--;
            if(j > 0)
                NotDone = (DataArray[j - 1] > Key);
            else
                NotDone = false;
        }
        /* Put the removed record into it's correct slot */
        DataArray[j] = temp;
    }
}

//merge sort function
void Merge(int numbers[], int i, int j, int k) {
    int mergedSize = k - i + 1;                /// Size of merged partition
    int mergePos = 0;                          /// Position to insert merged number
    int leftPos = 0;                           /// Position of elements in left partition
    int rightPos = 0;                          /// Position of elements in right partition
    int* mergedNumbers = new int[mergedSize];  /// Dynamically allocates temporary array
    /// for merged numbers
    leftPos = i;                               /// Initialize left partition position
    rightPos = j + 1;                          /// Initialize right partition position
    /// Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }
    /// If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }
    /// If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }
    /// Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
}
void MergeSort(int numbers[], int i, int k) {
    int j = 0;
    if (i < k) {
        j = (i + k) / 2;  /// Find the midpoint in the partition
        /// Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);
        /// Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}


//heapify function to assist in heapsort, get the max elem
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

//functino to print the array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

//parition function to assist in quicksort
int Partition(int numbers[], int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;
    
    /** Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];
    
    l = i;
    h = k;
    
    while (!done) {
        /** Increment l while numbers[l] < pivot */
        while (numbers[l] < pivot) {
            ++l;
        }
        /** Decrement h while pivot < numbers[h] */
        while (pivot < numbers[h]) {
            --h;
        }
        /** If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        
        if (l >= h) {
            done = true;
        }
        
        else {
            /** Swap numbers[l] and numbers[h],
             update l and h */
            
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            
            ++l;
            --h;
        }
    }
    return h;
}


//function to do Quicksort
void Quicksort(int numbers[], int i, int k) {
    int j = 0;
    /** Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }
    
    /** Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);
    
    /** Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
    return;
    
}


    




int main() {
         // Constants
         const int MIN_VALUE = 1; // Minimum die value
         const int MAX_VALUE = 200; // Maximum die value
        
         // Get the system time.
         unsigned seed = time(0);
        
         // Seed the random number generator.
         srand(seed);
        
        
        clock_t start, finish;
   
        cout << "Calculating the time it takes for each sorting algorithm to sort the numbers. Time shown is in seconds" << endl;
        cout << "Data Size" << "\t\t" << "Heap Sort (s)" << "\t\t" << "Merge Sort(s)" << "\t\t" << "Quick Sort(s)"
        << "\t\t" << "Bubble Sort(s)" << "\t\t" << "Selection Sort(s)" << "\t\t" << "Insertion Sort(s)" << endl;

        
        for (int j=100000; j<=500000; j+=100000) {
                            
            //randomValues2= new int[j];

            //cout << "Generating random numbers…\n";
            for (int i=0; i<j; i++){
                randomValues[i] = ((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);
                //&randomValues[i];
            }
            
                         //for (int i=0; i<size; i++){
                         //cout << randomValues[i] << endl;;
                         // }
            

            start =clock( ); //time in milliseconds
            heapSort(randomValues, j);
            finish=clock( ); //time in milliseconds
            double duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << j;
            cout << "\t\t\t" << duration;
        
            start =clock( ); //time in milliseconds
            MergeSort(randomValues, 0, j - 1);
            finish=clock( ); //time in milliseconds
            duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << "\t\t\t" << duration;
            
            start =clock( ); //time in milliseconds
            Quicksort(randomValues, 0, j);
            finish=clock( ); //time in milliseconds
            duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << "\t\t\t" << duration;
            
            start =clock( ); //time in milliseconds
            bubbleSort(j, randomValues);
            finish=clock( ); //time in milliseconds
            duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << "\t\t\t" << duration;
            
            start =clock( ); //time in milliseconds
            selectSort(j, randomValues);
            finish=clock( ); //time in milliseconds
            duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << "\t\t\t" << duration;
            
            start =clock( ); //time in milliseconds
            InsertSort(randomValues, j);
            finish=clock( ); //time in milliseconds
            duration = ((double)finish-start)/CLOCKS_PER_SEC; //time in secs.
            cout << "\t\t\t\t\t" << duration;
                cout << "\n";
            }
        
            //delete [] randomValues2;
        return 0;
  
}
    

