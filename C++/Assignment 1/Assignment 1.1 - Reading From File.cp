
#include <iostream>
#include <fstream>              //fstream defines the data types of ifstream and ofstream

using namespace std;

int main() {
    string data;
    ifstream object;             //ifstream is file stream data type. defining ifstream object named (object)
    object.open("stocks.txt");     //callling the object memeber function: open. Member function opens stocks.txt file.
    
    cout << "reading the file" << endl;
    object >> data;
    cout << data;
    if(object.good()){
        object.close();         //close file
    }

    
    
    return 0;
}
