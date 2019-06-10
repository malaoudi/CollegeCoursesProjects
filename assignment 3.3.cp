

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;


/*// function for reversing the string
 
 void reverseStr(string &a, string &x){
 
 string b,c;
 
 int n = b.length();
 
 int k = c.length();
 
 // Swap character starting from two
 
 // corners
 
 for (int i=0; i<n/2; i++)
 
 swap(b[i], b[n-i-1]);
 
 for (int i=0; i<k/2; i++)
 
 swap(c[i], c[n-i-1]);
 
 }
 
 */



int main() {
    
    cout << "enter your string delimited by space: ";
    string line, s;
    getline(cin, line);
    cout << "you have entered: " << line << endl;
    
    
    
    vector <string> vs;
    vector <const char*> cs;
    stringstream ss(line);         //stringstream
    
    while(getline(ss, s, ' ')) {
        vs.push_back(s);
        cs.push_back(s.c_str());       //s string. it created a c string.. memebr of .
        
    }
    
    cout << "\nShow the two strings\n";
    for(auto x:vs) cout << x << " | "; cout << endl;            //c++ string
    for(auto x:cs) cout << x << " | "; cout << endl;           //c string
    
    cout << "\n";
    auto str_compare = [] (string s1, string s2) {return (s1 > s2);};
    reverse(vs.begin(),vs.end());
    
    cout << "c++ string: \n";
    for(auto x:vs) cout << x << " | "; cout << endl;
    
    cout << "\n";
    auto cstr_compare = [] (const char* s1, const char* s2){return strcmp(s1,s2);(memcmp(s1,s2, sizeof(s1)) > 0); };
    sort(cs.begin(), cs.end(), cstr_compare);
    
    cout << "c-string: \n";
    for(auto x:cs) cout << x << " | "; cout << endl;
    
    
    // auto reverseStr(s);
    
    // cout << s;
    
    
    
} 





//reverse(myvector.begin(),myvector.end());
// return reverseStr(s1,s2);
