//Mohamed Alaoudi
//CS 210
//Description: This code takes a string, adds one character, show the string and its length and determines if it's
//palindrome

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct StringRec
{
    int strLen;
    char theStr[256];
};

void AddChar(StringRec& str, char theCh); // adds one character to the string
void OutputString(StringRec str); // outputs the string and the length of the string
bool CheckString(StringRec str); // returns true if string is a palindrome, false otherwise

int main() {
    StringRec theString;
    char theChar;
    theString.strLen = 0;
    
    cout << "Enter a string: ";
    getline(cin, theString.theStr;
    cin.getline(cin,theString.theStr);
    
    cin.get(theChar); //cin.get(theChar);  //could not use  getline(cin, theString.theStr); or cin.get(theString.theStr);
    while(theChar != '\n')
    {
        AddChar(theString, theChar);
        cin.get(theChar);
    }
    
    OutputString(theString);
    if( CheckString(theString) )
        cout << "\n\nThe string is a palindrome" << endl;
    else
        cout << "\n\nThe string is not a palindrome\n" << endl;
    
}


void AddChar(StringRec& str, char theCh) {
    /*
    string buf;
    buf = theCh;
    //buf.length = strlen(<#const char *__s#>)
    
  //  cout << buf << endl;
    for (int i=0, j=0; i<buf.length(); i++,j++) {
        
        str.theStr[i] = buf[j];
    }
   
    
    cout << "the string";
    for (int k=0; k< 10; k++) {
    cout <<str.theStr[k] << endl;
    }
    
    cout << "Adding one character to the string" << endl;
    //need to create the string from the buffer, theChar
    for (int i=0; i<256; i++){
        str.thestr = theCh[i]
        
    }
    
   // cout << str.theStr << o << "kk" << endl;
    */

    
}


void OutputString(StringRec str) {
    string input;
    cout << "Displaying the string" << str.theStr << endl;
    cout << "The length of the string is" << str.strLen << endl;
    
    
}



bool CheckString(StringRec str)
{
    bool comparison = true;
    //int j; // for end loop count
    int n = str.strLen;  // find a word's length. int n = word.length();
    for (int i =0, j= n-1; i < n/2; i++, j--)   // set up 2 loops, one starts at position 0, the other at n.
        if (str.theStr[i] == str.theStr[j]) // if it finds a match
            comparison;  // keep valid as true
        else
            comparison = false; // else valid becomes false
    return comparison;
}

