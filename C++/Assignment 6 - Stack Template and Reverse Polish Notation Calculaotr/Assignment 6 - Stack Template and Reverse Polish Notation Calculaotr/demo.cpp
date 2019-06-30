
/*
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;



template <class T>
class Stack
{
    int num_elements=0;
    
private:
    // Structure for the stack nodes
    struct StackNode
    {
        T value; // Value in the node
        StackNode *next; // Pointer to the next node
    };
    
    StackNode *top; // Pointer to the stack top
    
public:
    // Constructor
    Stack();
    
    // Destructor
    ~Stack();
    
    // Stack operations
    void push(T);
    void pop(T&);
    bool isEmpty();
    void peek();
    void clear();
    void size();
    void print();
    
    T top1() {return top->value;};
    bool CheckInput(string myString);
    T computeRPN();

    
    
};


//*********************************************************
// Destructor *
//*********************************************************
template <class T>
void Stack<T>::size()
{
    cout << this->num_elements;
    
}

template <class T>
void Stack<T>::clear(){
    StackNode *temp;
    
    if(!isEmpty()){
        temp = top;
        /// Scan stack and free all nodes
        while(top != NULL){
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    top = NULL;
    
    
}

template <class T>
Stack<T>::Stack(){
    
    top = NULL;
    
}
template <class T>
Stack<T>::~Stack()
{
    StackNode *nodePtr, *nextNode;
    
    // Position nodePtr at the top of the stack
    nodePtr = top;
    
    // Traverse the list deleting each node
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}


//*********************************************************
// Member function push pushes the argument onto the *
// stack. *
//*********************************************************
template <class T>
void Stack<T>::push(T item)
{
    StackNode *newNode; // Pointer to a new node
    
    // Allocate a new node and store num there
    newNode = new StackNode;
    newNode->value = item;
    
    // If there are no nodes in the list make newNode
    // the first node
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else // Otherwise, insert newNode before top
    {
        newNode->next = top;
        top = newNode;
    }
    this->num_elements++;
}


//*********************************************************
// Member function to print elements from the stack*
//*********************************************************
template <class T>
void Stack<T>::print()
{
    StackNode *temp=top;     //node pointing to the top
    T item;
    // Traverse the stack until the temp node is not null
    while (temp != NULL)
    {
        item = temp->value;
        cout<<item<<endl;
        temp = temp->next;
    }
}
template <class T>
void Stack<T>::peek(){
    cout << top->value;
    
}


//*********************************************************
// Member function pop pops the value at the top of the *
// stack off, and copies it into the variable passed as an*
// argument. *
//*********************************************************
template <class T>
void Stack<T>::pop(T &item)
{
    StackNode *temp; // Temporary pointer
    
    // First make sure the stack isn't empty
    if (isEmpty())
    {
        cout << "ERROR! The stack is empty.\n";
    }
    else
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    
    this->num_elements--;
}


//*********************************************************
// Member function isEmpty returns true if the stack is *
// empty, or false otherwise. *
//*********************************************************
template <class T>
bool Stack<T>::isEmpty()
{
    bool status;
    
    if (!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}



//function to quit the program
template <class T>
bool Stack<T>::CheckInput(string myString)
{
    bool valid = true;
    
    if ((myString == "q") || (myString == "Q"))
        valid = false;
    return valid;
}

//function to calculate RPN with the input
template <class T>
T Stack<T>::computeRPN(){
    
    string myToken;
    
    //create a stack
    Stack<double> stack1;
    
    cout << "Enter: ";
    
    do
        {
        
        getline(cin, myToken);
        if (isdigit(myToken[0]))
            {
            
            stack1.push(atof(myToken.c_str()));
            
            //Get next value.
            cout << "Enter: " << stack1.top1() << " ";
            
            }
        
        //Else block.
        else
            {
            
            //Assign top to x.
            double x = stack1.top1();
            
            //Pop the value.
            stack1.pop(x);
            
            //Assign top to y.
            double y = stack1.top1();
            
            //Pop the value.
            stack1.pop(y);
            
            //Switch case.
                switch (myToken[0])
                {
                    
                case '+': stack1.push(x + y);
                    
                    break;
                case '-': stack1.push(y - x);
                    break;
                    
                case '*': stack1.push(y*x);
                    break;
                    
                case '/': stack1.push(y / x);
                    break;
                    
                case '%': stack1.push(y / x);
                    break;
                }
            
            //Prompt user for value
            cout << "Enter: " << stack1.top1() << " ";
            
            }
    }
    
    
    while (stack1.CheckInput(myToken) == true);
    return stack1.top1();
    
}



int main()
{

    
    Stack<double> *theStack;            //stack pointer
    theStack= new Stack<double>();      //stack object. pointer is in the object
    
    theStack->computeRPN();

    
    
    return 0;
}


 */








/*
 
 template <class T>
 class Stack
 {
 int num_elements=0;
 
 private:
 // Structure for the stack nodes
 struct StackNode
 {
 T value; // Value in the node
 StackNode *next; // Pointer to the next node
 };
 
 StackNode *top; // Pointer to the stack top
 
 public:
 // Constructor
 Stack();
 
 // Destructor
 ~Stack();
 
 // Stack operations
 void push(T);
 void pop(T&);
 bool isEmpty();
 void peek();
 void clear();
 void size();
 void print();
 
 T top1() {return top->value;};
 bool InputGoodness(string myString);
 
 
 };
 
 //*********************************************************
 // Destructor *
 //*********************************************************
 
 
 template <class T>
 void Stack<T>::size()
 {
 cout << this->num_elements;
 
 }
 
 template <class T>
 void Stack<T>::clear(){
 StackNode *temp;
 
 if(!isEmpty()){
 temp = top;
 /// Scan stack and free all nodes
 while(top != NULL){
 temp = top;
 top = top->next;
 delete temp;
 }
 }
 top = NULL;
 
 
 }
 
 template <class T>
 Stack<T>::Stack(){
 
 top = NULL;
 
 }
 template <class T>
 Stack<T>::~Stack()
 {
 StackNode *nodePtr, *nextNode;
 
 // Position nodePtr at the top of the stack
 nodePtr = top;
 
 // Traverse the list deleting each node
 while (nodePtr != NULL)
 {
 nextNode = nodePtr->next;
 delete nodePtr;
 nodePtr = nextNode;
 }
 }
 
 //*********************************************************
 // Member function push pushes the argument onto the *
 // stack. *
 //*********************************************************
 template <class T>
 void Stack<T>::push(T item)
 {
 StackNode *newNode; // Pointer to a new node
 
 // Allocate a new node and store num there
 newNode = new StackNode;
 newNode->value = item;
 
 // If there are no nodes in the list make newNode
 // the first node
 if (isEmpty())
 {
 top = newNode;
 newNode->next = NULL;
 }
 else // Otherwise, insert newNode before top
 {
 newNode->next = top;
 top = newNode;
 }
 this->num_elements++;
 }
 
 //*********************************************************
 // Member function to print elements from the stack*
 //*********************************************************
 template <class T>
 void Stack<T>::print()
 {
 StackNode *temp=top;     //node pointing to the top
 T item;
 // Traverse the stack until the temp node is not null
 while (temp != NULL)
 {
 item = temp->value;
 cout<<item<<endl;
 temp = temp->next;
 }
 }
 template <class T>
 void Stack<T>::peek(){
 cout << top->value;
 
 }
 
 
 //*********************************************************
 // Member function pop pops the value at the top of the *
 // stack off, and copies it into the variable passed as an*
 // argument. *
 //*********************************************************
 template <class T>
 void Stack<T>::pop(T &item)
 {
 StackNode *temp; // Temporary pointer
 
 // First make sure the stack isn't empty
 if (isEmpty())
 {
 cout << "ERROR! The stack is empty.\n";
 }
 else
 {
 item = top->value;
 temp = top->next;
 delete top;
 top = temp;
 }
 
 this->num_elements--;
 }
 
 //*********************************************************
 // Member function isEmpty returns true if the stack is *
 // empty, or false otherwise. *
 //*********************************************************
 template <class T>
 bool Stack<T>::isEmpty()
 {
 bool status;
 
 if (!top)
 {
 status = true;
 }
 else
 {
 status = false;
 }
 return status;
 }
 
 
 
 
 //test program for stack
 #include <iostream>
 #include <string>
 
 
 
 int main()
 {
 
 //stack for integers
 Stack<int> stack;
 stack.push(2);
 stack.push(3);
 stack.push(4);
 
 int top=0;
 
 cout<<"--->integer stack<---"<<endl;
 cout<<"Integer stack"<<endl;
 cout<<"---------------"<<endl;
 stack.print();
 cout<<"Popping integers"<<endl;
 cout<<"---------------"<<endl;
 stack.pop(top);
 cout<<top<<endl;
 stack.pop(top);
 cout<<top<<endl;
 stack.pop(top);
 cout<<top<<endl;
 
 //stack for characters
 Stack<char> charstack;
 charstack.push('a');
 charstack.push('b');
 charstack.push('c');
 
 char ch;
 
 cout<<"--->Character stack<---"<<endl;
 cout<<"Character stack"<<endl;
 cout<<"---------------"<<endl;
 charstack.print();
 cout<<"Popping characters elements"<<endl;
 cout<<"---------------"<<endl;
 charstack.pop(ch);
 cout<<ch<<endl;
 charstack.pop(ch);
 cout<<ch<<endl;
 charstack.pop(ch);
 cout<<ch<<endl;
 
 //stack for string
 Stack<string> stringStack;
 stringStack.push("windows");
 stringStack.push("apple");
 stringStack.push("unix");
 
 string os;
 
 cout<<"--->String stack<---"<<endl;
 cout<<"String stack"<<endl;
 cout<<"---------------"<<endl;
 stringStack.print();
 cout<<"Popping strings elements"<<endl;
 cout<<"---------------"<<endl;
 stringStack.pop(os);
 cout<<os<<endl;
 stringStack.pop(os);
 cout<<os<<endl;
 stringStack.pop(os);
 cout<<os<<endl;
 cout << "peeking";
 stringStack.push(" mohamed ");
 stringStack.peek();
 stringStack.clear();
 // stringStack.peek();
 
 
 
 
 //Include the necessary files.
 
 
 
 
 
 
 //Driver function.
 
 
 //Declare a Stack.
 
 Stack<double> myX;
 
 //Declare a string for token.
 
 string myToken;
 
 //Prompt user.
 
 cout << "Enter 0 or 1: ";
 
 //Get input.
 
 getline(cin, myToken);
 
 //Check if the input is 1.
 
 if (atof(myToken.c_str()) == 1)
 {
 cout << "Enter: ";
 
 //Do-While to get the values from user repeatedly.
 
 do
 
 {
 
 getline(cin, myToken);
 
 //Check if the value is digit.
 
 if (isdigit(myToken[0]))
 
 {
 
 //Push.
 
 myX.push(atof(myToken.c_str()));
 
 //Get next value.
 
 cout << "Enter: " << myX.top1() << " ";
 
 }
 
 //Else block.
 
 else
 
 {
 
 //Assign top to x.
 
 double x = myX.top1();
 
 //Pop the value.
 
 myX.pop(x);
 
 //Assign top to y.
 
 double y = myX.top1();
 
 //Pop the value.
 
 myX.pop(y);
 
 //Switch case.
 
 switch (myToken[0])
 
 {
 
 //Case add.
 
 case '+': myX.push(x + y);
 
 break;
 
 //Case subtract.
 
 case '-': myX.push(y - x);
 
 break;
 
 //Case multiply.
 
 case '*': myX.push(y*x);
 
 break;
 
 //Case divide.
 
 case '/': myX.push(y / x);
 
 break;
 
 //Case modulo.
 
 case '%': myX.push(y / x);
 
 break;
 
 }
 
 //Prompt user for value
 
 cout << "Enter: " << myX.top1() << " ";
 
 }
 
 }
 
 //End of do-while().
 
 while (myX.InputGoodness(myToken) == true);
 
 }
 
 else
 
 {
 
 //On success.
 
 //Prompt user for values.
 
 cout << "Enter: ";
 
 //Do-While to get the values from user repeatedly.
 
 do
 
 {
 
 //Get the value.
 
 getline(cin, myToken);
 
 //Check if the value is digit.
 
 if (isdigit(myToken[0]))
 
 {
 
 //Push.
 
 myX.push(atof(myToken.c_str()));
 
 //Get next value.
 
 cout << "Enter: " << myX.top1() << " ";
 
 }
 
 //Else block.
 
 else
 
 {
 
 //Assign top to x.
 
 double x = myX.top1();
 
 //Pop the value.
 
 myX.pop(x);
 
 //Assign top to y.
 
 double y = myX.top1();
 
 //Pop the value.
 
 myX.pop(y);
 
 //Switch case.
 
 switch (myToken[0])
 
 {
 
 //Case add.
 
 case '+': myX.push(x + y);
 
 break;
 
 //Case subtract.
 
 case '-': myX.push(y - x);
 
 break;
 
 //Case multiply.
 
 case '*': myX.push(y*x);
 
 break;
 
 //Case divide.
 
 case '/': myX.push(y / x);
 
 break;
 
 //Case modulo.
 
 case '%': myX.push(y / x);
 
 break;
 
 }
 
 //Prompt user for value
 
 cout << "Enter: " << myX.top1() << " ";
 
 }
 
 }
 
 //End of do-while().
 
 while (myX.InputGoodness(myToken) == true);
 
 }
 
 
 
 
 
 /*
 
 double operand1=0, operand2=0;
 string operation;
 string buffer;
 char cstring[100];
 string choice;
 int x=0;
 string result;
 int y;
 cout <<"Entering the loop" << endl;
 // while(buffer != "q" ) {
 cout << "Enter: ";
 cin >> operand1;
 cin >> operand2;
 cin >> cstring[100];
 
 
 char *strPtr = nullptr;
 
 strPtr = strstr(&cstring[100], "-");
 if (strPtr != nullptr) {
 operation='-';
 }
 
 strPtr = strstr(&cstring[100], "+");
 if (strPtr != nullptr) {
 operation='+';
 }
 
 strPtr = strstr(&cstring[100], "*");
 if (strPtr != nullptr) {
 operation='*';
 }
 
 strPtr = strstr(&cstring[100], "/");
 if (strPtr != nullptr) {
 operation='/';
 }
 int operation1;
 operation1=atoi(operation.c_str());
 
 switch (operation1){
 
 case '+':
 result=operand1+operand2;
 stringStack.push(result);
 case '-':
 result=operand1-operand2;
 stringStack.push(result);
 case '*':
 result=operand1*operand2;
 stringStack.push(result);
 case '/':
 result=operand1/operand2;
 stringStack.push(result);
 }
 
 x++;
 cout << "Enter: " << endl;
 stringStack.print();
 //  ;}
 
 
 
 
 
 return 0;
 }
 
 
 //Define a boolean function for input goodness.
 template <class T>
 bool Stack<T>::InputGoodness(string myString)
 
 {
 
 //Declare a boolean variable.
 
 //Initialize it to true.
 
 bool isGood = true;
 
 //Check whether the input is "Q" or "q".
 
 if ((myString == "q") || (myString == "Q"))
 
 //On success, update boolean variable as false.
 
 isGood = false;
 
 //Otherwise.
 
 return isGood;
 
 }
 
 
 */


