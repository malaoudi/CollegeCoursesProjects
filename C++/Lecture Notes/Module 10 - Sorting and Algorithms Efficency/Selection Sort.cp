/*
Selection Sort
Selection Sort

Sort Type: Comparison-Based Sorting / Priority Queue Sorting

Algorithm

Description:

All Priority Queue Sorting is based on arranging the data structures into a priority queue using the keys. Selection Sort divides the array of structures into a sorted and an unsorted section and repeatedly removes the record with the largest key from the unsorted section and moves it to the front of the sorted section.


Data holder: Filled array of data structures.

Technique:

Divide the array into two sections: (a) Unsorted, and (b) sorted. At the start the unsorted section is the entire array and the sorted section is empty.
Set an index to the first position in the sorted section.
At each point in the sort find the largest key in the unsorted section and swap it's data structure with the one in the position at the next open position in the sorted section.
Continue this technique until there is only one key left in the unsorted section and it is in the first position.

Analysis: Selection Sort runs in O(n2) time.


*/
//Sample Code:

void SelectSort(int DataArray[])

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
