/*
Insertion Sort
Insertion Sort

Sort Type: Comparison-Based Sorting / Insert and Keep Sorting

Algorithm

Description:

Like all comparison based sorting techniques Insertion Sort is based on comparing two keys and rearranging the associated data in order to place the keys in ascending or descending order.

Insert and Keep Sorting techniques depend on placing each new item in a collection of data in its correct sorted position to start with. This can be done by moving items out of a set of unsorted records into a set of sorted records, doing the sorting as they are inserted. This method also lends itselves to building data sets in sorted order as the data are received. Thus each new record that is entered is placed in its correct sorted position from the start. This is a good approach, if you can afford the overhead of doing the sorting as items arrive, but this may not be practical.


Data holder: A filled array of data structures.

Technique:

Divide the array into a sorted section (array indices 0..m) and an unsorted section (array indices m+1..n-1).
Remove the first record in the unsorted section.
Find the position in the sorted section where it should be inserted.
Move all keys from that position to the end of the sorted section over by one position.
Insert the record being sorted.

Analysis: InsertionSort runs in O(n2) time.

*/

//Sample Code:

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
                
                NotDone = FALSE;
            
        }
        
        
        
        /* Put the removed record into it's correct slot */
        
        DataArray[j] = temp;
        
    }
    
}


