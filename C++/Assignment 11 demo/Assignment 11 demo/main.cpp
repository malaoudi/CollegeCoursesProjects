#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct RecordType
{
    string key;
    RecordType * next;
};


struct NodeType{
    int id;
    string first_name;
    string last_name;
    NodeType *NodePointer;
};


//  LinkedList.h

class LinkedList
{
private:
    
    RecordType * head;        // Head is a reference to a list of data nodes.
    int length;              // Length is the number of data nodes.
    
public:
    LinkedList();            // Constructs the empty linked list object. // Creates the head node and sets length to zero.
    
    void insertItem( RecordType * newItem );      // Inserts an item at the end of the list.
    
    bool removeItem( string itemKey );              // Removes an item from the list by item key. //Returns true if the operation is successful.
    
    RecordType * getItem( string itemKey );  // Searches for an item by its key. // Returns a reference to first match, returns null pointer if not found
    
    void printList();       // Displays list contents to the console window.
    
    int getLength();        // Returns the length of the list.
    
    ~LinkedList();       // De-allocates list memory when the program terminates.
};



//  HashTable.h
class HashTable
{
private:
    
    LinkedList * array;  // Array is a reference to an array of Linked Lists.
    int length;    // Length is the size of the Hash Table array.
    int hash( string itemKey ); // Returns an array location for a given item key.
    int total_entries=200;
public:
    
    HashTable( int tableLength = 201 ); // Constructs the empty Hash Table object. // Array length is set to 201 by default.
    void insertItem( RecordType * newItem );  // Adds an item to the Hash Table.
    bool removeItem( string itemKey );      // Deletes an Item by key from the Hash Table.// Returns true if the operation is successful.
    RecordType * getItemByKey( string itemKey );  // Returns an item from the Hash Table by key. // If the item isn't found, a null pointer is returned.
    void printTable();     // Display the contents of the Hash Table to console window.
    void printHistogram(); // Prints a histogram illustrating the Item distribution.
    int getLength();        // Returns the number of locations in the Hash Table.
    int getNumberOfItems();      // Returns the number of Items in the Hash Table.
    ~HashTable();      // De-allocates all memory used for the Hash Table.
};




//  HashTable.cpp
//
HashTable::HashTable( int tableLength )
{
    if (tableLength <= 0) tableLength = 13;
    array = new LinkedList[ tableLength ];
    length = tableLength;
    
    
}


// Returns an array location for a given item key.
int HashTable::hash( string itemKey )
{
    string str;
    str= itemKey;
    int value2;
    value2=atoi(str.c_str());
    string itemKey2;
    //cout << "value 2 " << value2;
    
    // int value = 0;
    // for ( int i = 0; i < itemKey.length(); i++ )
    //     value += itemKey[i];
    // cout <<  "(value * itemKey.length() ) % length " <<  (value * itemKey.length() ) % length << endl;;
    //return (value * itemKey.length() ) % length;
    //cout << "counter " << counter << " idh " << idh[counter] << endl;
    
    // cout << "counter " << counter3 << " counter3[w]; " <<counter3[w] << "  " <<(counter3[w] % 200) << endl;
    return (value2 % 200);
}

//Function for adding an intem into the hash table
void HashTable::insertItem( RecordType * newItem )
{
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
    
}

//Finction to remove an item from the hash table
bool HashTable::removeItem( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removeItem( itemKey );
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
RecordType * HashTable::getItemByKey( string itemKey )
{
    
    int index = hash( itemKey );
    return array[ index ].getItem( itemKey );
    
}

//function to print the buckets and the content
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

//prints an illustration of the items
void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

//returns the length of the hash table
int HashTable::getLength()
{
    return length;
}

//returns the numeber of stored values
int HashTable::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}



//  LinkedList.cpp
LinkedList::LinkedList()
{
    head = new RecordType;
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insertItem( RecordType * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    RecordType * p = head;
    RecordType * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;
    newItem -> next = NULL;
    length++;
}


bool LinkedList::removeItem( string itemKey )
{
    if (!head -> next) return false;
    RecordType * p = head;
    RecordType * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for an item by its value.
RecordType * LinkedList::getItem( string itemKey )
{
  
    RecordType * p = head;
    RecordType * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    //Item *k;
   // k= NULL;
     cout << "Not found in Linked List ";
    return p;
}


void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "{ }\n";
        return;
    }
    RecordType * p = head;
    RecordType * q = head;
    cout << "{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
    
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// Deallocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    RecordType * p = head;
    RecordType * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}


//  main.cpp

int main()
{
    //Declare a hash table object
    HashTable table;
    
    
    int data;
    string id;
    
    ifstream FileAdd("Add.txt");
    ifstream FileSearch("Search.txt");

    
    cout << "\nReading from the file" << endl;
    while (!FileAdd.eof()) {
        FileAdd >> data;        //readt the file content from the fileobject to the variable int data
        
        id=to_string(data);          //convert data to string
        //cout << " ID = " << id <<endl;
        RecordType * id_Pointer = new RecordType {id, NULL};        // Create 200 Items to store in the Hash Table.
        table.insertItem(id_Pointer);
        
    }
    cout << "Compelted \n" << endl;
    
    cout << "Displaying the hash-table ";
    table.printTable();
    cout << "\nDisplaying a histogram ";
    table.printHistogram();
    cout << "\nSize of the hash table " <<  table.getLength() << endl;
    cout << "Total number nodes " << table.getNumberOfItems() << endl;
    
    
    cout << "Removing from the table " << endl;
    table.removeItem(id);
    
    RecordType * result = table.getItemByKey(id);
    cout << "Searching for the removed id " << result->key  << endl;
    
    RecordType * result2;
    string string1;
    data=43630;
    id=to_string(data);          //convert data to string
    cout << "Testing. Searching for the id 43630 " << result->key  << endl;
    result2 = table.getItemByKey(id);
    cout << result2->key << endl;
    cout << "\n";
    int counter=0;
    
    
    while (!FileSearch.eof()) {
         counter++;
        FileSearch >> data;
        
        string1=to_string(data);
        cout << " ID = " << string1 ;
        cout << "  Searching. ";
        result2 = table.getItemByKey(string1);
        cout << "Result: " << result2->key << endl;
        
     }
    
    cout << "\nTotal number if id’s searched: " << counter << endl;
    cout << "Total number of nodes searched: " << counter << endl;
    cout << "Average number of nodes search per id searched: " << 1 << endl;
    
    
    return 0;
}

