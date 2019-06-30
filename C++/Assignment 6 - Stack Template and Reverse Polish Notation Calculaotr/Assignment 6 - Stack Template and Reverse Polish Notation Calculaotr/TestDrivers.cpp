//Test Drivers for AS 6
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
    
    
    
    //stack for integers
    
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    int top=0;
    
    cout<<"Integer stack. "<< "Test numbers pushed " << endl;
    cout<<"Stack Contains " << endl;
        stack.print();
    
    cout<<"\nPop the integers"<<endl;
    
    while(!stack.isEmpty()) {
        stack.pop(top);
        cout<<top<<endl;
    }
    cout << "\nClearing" << endl;
    stack.clear();
    
    //stack for characters
    Stack<double> DoubleStack;
    DoubleStack.push(33.51);
    DoubleStack.push(52712.3092);
    DoubleStack.push(9482021);
    
     double double1 = 0.0;
    
    cout<<"\nDouble stack. "<< "Test double numbers pushed " << endl;
    cout<<"\nStack Contains" << endl;
    DoubleStack.print();
    
    cout<<"\nPop the doubles"<<endl;
    
    while(!DoubleStack.isEmpty()) {
        DoubleStack.pop(double1);
        cout<< double1 <<endl;
    }
    
    //stack for string
    Stack<string> stringStack;
    stringStack.push("hurry");
    stringStack.push("carpet");
    stringStack.push("water");
    
    string string1;
    cout<<"\nString stack. "<< "Test strings pushed " << endl;
    cout<<"\nStack Contains " << endl;
    stringStack.print();
    
    cout<<"\nPop the strings"<<endl;
    
    while(!stringStack.isEmpty()) {
        stringStack.pop(string1);
        cout<<string1<<endl;
    }
    
    //stringStack.clear();

    cout << "\nPushing Mohamed";
    stringStack.push(" Mohamed ");
    
    cout << "\n Peeking" << endl;
    stringStack.peek();
    stringStack.clear();
    
    
    cout << "\n\n" << endl;
    
    Stack<double> *theStack;            //stack pointer
    theStack= new Stack<double>();      //stack object. pointer is in the object
    
    theStack->computeRPN();
    
    
    
    return 0;
}




// Create the stack.
// Stack<string> stack; // Class<DataType> Variable;

//create a stack object
//StackAsLList<class T>    *theStack;
//cout << "\tCreating a stack...\n\n";
//theStack = new StackAsLList<T>(); // Instantiate a stack object
//Pointer<class T> = new Pointer; // declares the object

//pointer of class stack, pointing to a stack. Stack pointer allows to acess all other veriable
// define by the class, or all the stacks defined by the stack class.
//Stack_Object=&stack1; //save the address of stack1 into the object.


*/
