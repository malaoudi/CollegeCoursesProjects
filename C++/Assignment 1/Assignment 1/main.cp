//Mohamed Alaoudi
//CS 210
//Description: This program outputs data into Excel

#include <iostream>
#include <fstream>              //fstream defines the data types of ifstream and ofstream

using namespace std;

int main() {
    string data;
    ofstream object;             //ifstream is file stream data type. defining ifstream object named (object)
    object.open("stocks1.xls");     //callling the object memeber function: open. Member function opens stocks.txt file.

    cout << "writing to the file" << endl;
    
    object << " \t Price $ \t \n \t 1/26/2018 \t 1/27/2018 " << endl;      //column headings
    object << "Cryptocurrency \n";          //rows
    
    object << "Bitcoins" << "\t" <<  10000 <<  "\t" << 150000 << "\n";
    object << "XRP" << "\t" << 2 << "\t" << 3  << "\n";
    object << "TRX" << "\t" << 0.5 << "\t" << 0.9  << "\n";
    
    
  
    
    //close file
    object.close();
    cout << "File closed" << endl;

    
    return 0;
}
