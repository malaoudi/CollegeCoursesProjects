//The sample code below input student data from file “in.txt”
//and output student data in  file “out.txt”


import java.io.*;
import java.util.StringTokenizer;

import javax.swing.*;
 
public class TestStudentExt
{
  public static void main(String[] args) 
  {
    String in,out,outAll = null, line;
    int studentCount;
 
    //Create a BufferedReader object for inputting froma file in.txt
    BufferedReader br = new BufferedReader(new FileReader("file.txt"));
 
    //Create a PrintWriter object for outputting to a file out.txt.
    PrintWriter pw = new PrintWriter (new FileWriter("out.txt"));
 
    //input the first line of the file containing the number of students
    in = br.readLine();
    studentCount = Integer.parseInt(in);
 
    //Set up a for loop to input one student data during each pass through loop.
    out = "Student report:\n";
    for (int i=0; i<studentCount; i++)
    {
      //read one line containing one student data.
      in = br.readLine();
      pw.write(in);
      //Create a StringTokenizer object to tokenize one student data.
  	String delim= ",";
	String token="" ;
	String pattern;		
	StringTokenizer stk1 = new StringTokenizer(in, delim);
	
//ask to get the tokens. 
	int count = stk1.countTokens();
      
      //create the corresponding StudentExt object
		StudentExt studentObj[j] = new StudentExt();
     }
 
    //Set up a for loop to find grade of one student during each iteration
    //Store the student data and the grade in a corresponding output String.
    for (int j=0; j<studentCount; j++)
    {
      //Find one student grade
 
 
      //Depending on student grade, accumulate its output in a corresponding String.
 
     }
 
    //Catenate all student output in a single String (say outAll)
 
    //Output outAll String using using PrintWriter object.
    //make sure to also call flush( ) after calling println()
    pw.println(outAll);
    pw.flush();
 
    //Call close on File IO objects.
    if (br != null)
      br.close();
    if (pw != null)
      pw.close();
  }
}
**/
*/