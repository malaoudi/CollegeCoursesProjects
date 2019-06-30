/*
 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>
#include <string.h>

 using namespace std;

 struct RecType
 {
 int id;
 string firstName;
 string lastName;
 double amount;
     char transaction;
 };

 struct NodeType;
 typedef NodeType * NodePtr;

 struct NodeType
 {
 int id;
 string firstName;
 string lastName;
 double amount;
     char transaction;
     
 NodePtr llink;
 NodePtr rlink;
     NodePtr*   tempNodePtr;
 };

 class BinTree
 {
 private:
 NodePtr root;
 ifstream fin;
 ofstream fout;
 void rinsert (NodePtr & nodep, RecType rec);
 void rupdate (NodePtr nodep, RecType rec );
 void rremove (NodePtr & nodep, RecType rec );
 void rdisplay (NodePtr nodep, int level);
 void rfdisplay (NodePtr nodep, int level, ofstream & fout);
 void rstore (NodePtr nodep);
 void rrestore (NodePtr & nodep, int count);
 int rcountNodes (NodePtr nodep);
 double rsearch (NodePtr & nodep, RecType &rec);
     void makeDeletion(NodePtr *&nodePtr);


 public:
 BinTree ( );
 void insert ( RecType rec );
 void update ( RecType rec );
 void remove ( RecType rec );
 void display ();
 void fdisplay (ofstream & fout);
 void store ( );
 void restore ();
 int countNodes ();
 void PointToRoot1();
 double search(RecType rec);


 };

 //The constructor
 BinTree ::BinTree ( )
 {
 root = NULL;
 }

 //Inserting a node in the tree
 void BinTree ::insert (RecType rec )
 {
 rinsert (root, rec);
 }

 void BinTree ::rinsert (NodePtr & nodeptr, RecType rec)
 {
 if (nodeptr == NULL) // reached not found
 {
    // create the node and link it
    nodeptr = new NodeType;
    nodeptr->id = rec.id;
    nodeptr->firstName = rec.firstName;
    nodeptr->lastName = rec.lastName;
    nodeptr->amount = rec.amount;
    nodeptr->llink = NULL;
    nodeptr->rlink= NULL;
    }
     
 else if  (rec.id < nodeptr->id)
     rinsert(nodeptr->llink, rec);
 else
     rinsert (nodeptr->rlink, rec);
 }

 //Updating a node in the tree
 void BinTree ::update (RecType rec )
 {
 rupdate (root, rec);
 }

 void BinTree ::rupdate (NodePtr nodep, RecType rec)
 {
     nodep = new NodeType;

     nodep->id = rec.id;
     nodep->firstName = rec.firstName;
     nodep->lastName = rec.lastName;
     nodep->amount = rec.amount;

 }

 //Removing a node from the tree
 void BinTree ::remove (RecType rec )
 {
 rremove (root, rec);
 }
 void BinTree ::rremove (NodePtr & nodep, RecType rec)
 {
  
     /*
     if (rec.lastName < nodep->lastName){
        rremove(nodep->llink, rec);
     }
     if  (rec.lastName > nodep->lastName){
        rremove(nodep->rlink, rec);
     }
     else{
     }
*/
         /*
         if(nodep==NULL) return;  /// Nothing to clear
        // if(nodep->llink != NULL)
             rremove(nodep->llink,rec); /// Clear left sub-tree
        // if(nodep->rlink != NULL)
             rremove(nodep->rlink,rec); /// Clear right sub-tree
        /// delete nodep;    /// Destroy this node
         return;
         
         
 }
   */


/*

//Removing a node from the tree
double BinTree ::search (RecType rec )
{
    rsearch (root, rec);
    return 0;
}

double BinTree ::rsearch (NodePtr & nodep, RecType &rec)
{
    //NodeType *nodePtr = root;
    
    while (nodep!=NULL)
    {
        cout << "nodep->lastname " << nodep->lastName <<endl;
        cout << "nodep->amount " << nodep->amount <<endl;
        cout << "rec.lastname "    << rec.lastName << endl;
        cout << "rec.amount "    << rec.amount << endl;
        
        
        if (nodep->lastName == rec.lastName) {  //nodep->lastName == rec.lastName
            rec.amount=nodep->amount;
            nodep->amount=nodep->amount;

            cout << " matched ***" << rec.amount;
            return rec.amount;
            break;
        }
        
        //nodep->amount == rec.amount
             if(nodep->id < rec.id)
            //rec.lastName < nodep->lastName
            nodep = nodep->llink;
            else if(nodep->id > rec.id)
            nodep = nodep->rlink;
        
         }
    
    //cout << "nodep->amount " << nodep->amount <<endl;
    cout << "rec.amount"    << rec.amount << endl;
    
   // return false;
    
    
    return 0;
}

void BinTree::PointToRoot1(){
    
  NodeType * NodePtr=root;
    BinTree();
    
}




 //Displaying the tree in reverse in order traversal with levels
 void BinTree::display ()
 {
 rdisplay (root, 1);
 }
     
 void BinTree::rdisplay (NodePtr nodep, int level)
 {
     if (nodep != NULL)
     {
     rdisplay (nodep->rlink, level + 1);
     cout <<  setw (7 * level) << nodep->id <<endl;
     rdisplay (nodep->llink, level + 1);
     }
 }
     
 //Logging the tree in reverse In-order traversal with levels
 void BinTree::fdisplay (ofstream & fout)
 {
 rfdisplay (root, 1, fout);
 }
     
 void BinTree::rfdisplay (NodePtr nodep, int level, ofstream & fout)
 {
     if (nodep != NULL)
     {
         rfdisplay (nodep->rlink, level + 1,fout);
         fout <<  setw (7 * level) << nodep->id <<endl;
         rfdisplay (nodep->llink, level + 1,fout);
     }
 }
 //Storing the tree to a file OrderedMaster.txt
 void BinTree::store ()
 {
     fout.open("OrderedMaster.txt",ios::out );
     //save the node count as the first number in the file
     int count = countNodes();
     fout << count << endl;
     //save the tree
     rstore (root);
     fout.close();
 }
     
 void BinTree::rstore (NodePtr nodep)
     {
         if (nodep != NULL)
        {
            rstore (nodep->llink);
            fout << nodep->id << " "
            << nodep->firstName << " "
            <<  nodep->lastName <<  " "
            << nodep->amount << endl;
            rstore (nodep->rlink);
        }
 }
 //Restoring the tree from a file OrderedMaster.txt
 void BinTree::restore ()
 {
     fin.open("OrderedMaster.txt",ios::in );
     //input node count. This was stored as the first number in file.
     int count;
     fin >> count;
     //restore the tree
     rrestore (root,count);
     fin.close();
}
     
 void BinTree::rrestore (NodePtr & nodep, int count)
 {
     if (count > 0)
     {
         //create a node
         nodep = new NodeType;
         nodep->llink = NULL;
         nodep->rlink = NULL;
         //create and fill the left subtree
         if ( (count % 2) == 0)
             rrestore (nodep->llink, ((count-1)/2) + 1);
         else
     rrestore (nodep->llink, count/2);
         //fill in the node
         fin >> nodep->id >> nodep->firstName >> nodep->lastName >> nodep->amount;
         //create and fill the right subtree
         if ( (count % 2) == 0)
             rrestore (nodep->rlink, ((count-1)/2) );
         else
             rrestore (nodep->rlink, count/2);
     }
 }

 //Counting nodes
 int BinTree::rcountNodes (NodePtr nodep )
 {
     
     if (nodep != NULL)
     {
         return (rcountNodes (nodep->llink) + rcountNodes(nodep->rlink) + 1);
     }
     else
    return 0;
}
     
 int BinTree::countNodes ()
 {
     return rcountNodes (root);
 }



 int main ( ) {
     
 BinTree tree;
     
 ofstream fout ("Log.txt");
 ifstream finMaster ("Master.txt");
 ifstream finTransaction ("Transaction.txt");
 ifstream finOrderedMaster ("OrderedMaster.txt");
                            
 RecType r;
 finMaster >> r.id;
     char transaction;
     
 while (!finMaster.eof( ) )     //read one person at atime, one line at a time. reads and stores
     //into one variable until a a space is found
 {
 finMaster >> r.firstName;
     cout << "first name " << r.firstName << endl;

 finMaster >> r.lastName;
     cout << "last name " << r.lastName << endl;

 finMaster >> r.amount;
     cout << "amount " << r.amount << endl;

 finMaster >> r.id;
     cout << "id " << r.id << endl;

      tree.insert(r);
     cout << "\n";
 }
     //display the tree
     tree.PointToRoot1();
     tree.display();
     tree.fdisplay(fout);
     tree.store();

     string firstName, lastName;
     int id=0;
     const int size=10;
     char transactionb[size];
  
     BinTree binarytree1;
     //tree.pointToRoot();      //start at the root
   
     
     RecType x;
     cout << "\n\n";
     int counter=0;
     
             
     
     while(!finTransaction.eof( ) ){
         
         //finTransaction.get(r.transaction);
         
         
         finTransaction >> r.transaction;
         // cout << "transaction " << r.transaction << endl;
         
         finTransaction >> r.id;
         cout << "ID        " << r.id << endl;
         
         finTransaction >> r.firstName;
         cout << "first name " << r.firstName << endl;
         
         finTransaction >> r.lastName;
         cout << "last name " << r.lastName << endl;
         
         tree.search(r);
         
         finTransaction >> transactionb;
         cout << "new transaction " << transactionb << endl;
         
         //remove the + and - from the amount
         cout << "current balance: " << r.amount << endl;
         cout << "transactionb[0] " << transactionb[0] << endl;
         
         double tempWallet;
         tempWallet = atof(transactionb);     //*****
         cout << "tempwallet " << tempWallet << endl;
         if(transactionb[0] == '-'){
             r.amount=r.amount+tempWallet;
             cout << " balance: " << r.amount << endl;
             
         }
         
         else if (transactionb[0] == '+'){
             r.amount=r.amount+tempWallet;
             cout << " balance: " << r.amount << endl;
         }
         
         else if (transactionb[0] == '0'){
             tree.remove(r);
         }
         
         
         
         cout << "executing Trasaction: " << r.transaction << endl;
         if(r.transaction=='D') {
             tree.remove(r);
             cout << "removing...";
         }
         if (r.transaction=='U'){
             tree.update(r);
             cout << "updating...";
         }
         if (r.transaction=='I'){
             tree.insert(r);
             cout << "adding...";
         }
         
         cout << "\n\n" ;
         
         
     }
     
     
     
     while(!finTransaction.eof( ) ){
         
         //finTransaction.get(r.transaction);
         
         
         finTransaction >> r.transaction;
        // cout << "transaction " << r.transaction << endl;
         
         finTransaction >> r.id;
         cout << "ID        " << r.id << endl;
         
         finTransaction >> r.firstName;
         cout << "first name " << r.firstName << endl;
         
         finTransaction >> r.lastName;
         cout << "last name " << r.lastName << endl;
        
          r.amount=tree.search(r);

         cout << "@@@ ";
             finTransaction >> transactionb;
         cout << "new transaction " << transactionb << endl;
         cout << "@@@ ";

         //remove the + and - from the amount
         cout << "current balance: " << r.amount << endl;
         cout << "transactionb[0] " << transactionb[0] << endl;
         
         double tempWallet;
           tempWallet = atof(transactionb);     //*****
         cout << "tempwallet " << tempWallet << endl;
         if(transactionb[0] == '-'){
             r.amount=r.amount+tempWallet;
             cout << " balance: " << r.amount << endl;

                }

         else if (transactionb[0] == '+'){
                 r.amount=r.amount+tempWallet;
                 cout << " balance: " << r.amount << endl;
         }
         
         else if (transactionb[0] == '0'){
             tree.remove(r);
         }
         
        
         
         cout << "executing Trasaction: " << r.transaction << endl;
         if(r.transaction=='D') {
             tree.remove(r);
             cout << "removing...";
         }
         if (r.transaction=='U'){
             tree.update(r);
             cout << "updating...";
         }
         if (r.transaction=='I'){
             tree.insert(r);
             cout << "adding...";
         }

         cout << "\n\n" ;

         
    }
     
     
     
     
     //store the tree
     tree.store();
    
     //display the tree
     tree.display();
     tree.fdisplay(fout);
     
     //store the tree
     tree.store();
     //restore the tree
     tree.restore();
     //display the restored tree.
     tree.display();
     tree.fdisplay(fout);
     tree.store();

 
     return 0;
 
 }
*/









/********************************************************
 
 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>
 #include <string.h>
 
 using namespace std;
 
 struct RecType
 {
 int id;
 string firstName;
 string lastName;
 double amount;
 char transaction;
 double balance;
 };
 
 struct NodeType;
 typedef NodeType * NodePtr;
 
 struct NodeType
 {
 int id;
 string firstName;
 string lastName;
 double amount;
 char transaction;
 double balance[100];
 
 NodePtr llink;
 NodePtr rlink;
 };
 
 class BinTree
 {
 private:
 NodePtr root;
 ifstream fin;
 ofstream fout;
 void rinsert (NodePtr & nodep, RecType rec);
 void rupdate (NodePtr nodep, RecType rec );
 void rremove (NodePtr & nodep, RecType rec );
 void rdisplay (NodePtr nodep, int level);
 void rfdisplay (NodePtr nodep, int level, ofstream & fout);
 void rstore (NodePtr nodep);
 void rrestore (NodePtr & nodep, int count);
 int rcountNodes (NodePtr nodep);
 double rsearch (NodePtr & nodep, RecType &r);
 //void makeDeletion(NodePtr *&nodePtr);
 void makeDeletion(NodeType *&nodePtr);
 
 int key;
 double key2[100];
 public:
 BinTree ( );
 void insert ( RecType rec );
 void update ( RecType rec );
 void remove ( RecType rec );
 void display ();
 void fdisplay (ofstream & fout);
 void store ( );
 void restore ();
 int countNodes ();
 void PointToRoot1();
 double search(RecType rec);
 double transfer(NodePtr & nodep, RecType &rec);
 
 double transfer2(RecType &, int);
 
 
 
 };
 
 //The constructor
 BinTree ::BinTree ( )
 {
 root = NULL;
 }
 
 //Inserting a node in the tree
 void BinTree ::insert (RecType rec )
 {
 rinsert (root, rec);
 }
 
 void BinTree ::rinsert (NodePtr & nodeptr, RecType rec)
 {
 if (nodeptr == NULL) // reached not found
 {
 // create the node and link it
 nodeptr = new NodeType;
 nodeptr->id = rec.id;
 nodeptr->firstName = rec.firstName;
 nodeptr->lastName = rec.lastName;
 nodeptr->amount = rec.amount;
 nodeptr->llink = NULL;
 nodeptr->rlink= NULL;
 }
 
 else if  (rec.id < nodeptr->id)
 rinsert(nodeptr->llink, rec);
 else
 rinsert (nodeptr->rlink, rec);
 }
 
 //Updating a node in the tree
 void BinTree ::update (RecType rec )
 {
 rupdate (root, rec);
 }
 
 void BinTree ::rupdate (NodePtr nodep, RecType rec)
 {
 if((nodep=NULL)){
 nodep = new NodeType;
 
 if(nodep!=NULL){
 nodep->id = rec.id;
 nodep->firstName = rec.firstName;
 nodep->lastName = rec.lastName;
 nodep->amount = rec.amount;
 }}
 }
 
 //Removing a node from the tree
 void BinTree ::remove (RecType rec )
 {
 rremove (root, rec);
 }
 void BinTree ::rremove (NodePtr & nodep, RecType rec)
 {
 
 
 
 if(nodep==NULL) return;  /// Nothing to clear
 // if(nodep->llink != NULL)
 rremove(nodep->llink,rec); /// Clear left sub-tree
 // if(nodep->rlink != NULL)
 rremove(nodep->rlink,rec); /// Clear right sub-tree
 /// delete nodep;    /// Destroy this node
 
 /*
 if (rec.id < nodep->id)
 rremove(nodep->llink, rec);
 else if (rec.id > nodep->id)
 rremove(nodep->rlink, rec);
 else
 makeDeletion(nodep);
 




return;











}


void BinTree::makeDeletion(NodeType *&nodePtr){
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    NodeType *tempNodePtr = nullptr;
    
    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->rlink == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->llink; // Reattach the left child.
        delete tempNodePtr;
    }
    else if (nodePtr->llink == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->rlink; // Reattach the right child.
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node to the right.
        tempNodePtr = nodePtr->rlink;
        // Go to the end left node.
        while (tempNodePtr->llink)
            tempNodePtr = tempNodePtr->llink;
        // Reattach the left subtree.
        tempNodePtr->llink = nodePtr->llink;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->rlink;
        delete tempNodePtr;
    }
}




//Removing a node from the tree
double BinTree ::search (RecType rec )
{
    rsearch (root, rec);
    return 0;
}


double BinTree ::rsearch (NodePtr & nodep, RecType &r)
{
    //NodeType *nodePtr = root;
    double currentbalance;
    
    while (nodep!=NULL)
    {
        cout << "nodep->lastname " << nodep->lastName <<endl;
        cout << "nodep->amount " << nodep->amount <<endl;
        cout << "rec.lastname "    << r.lastName << endl;
        cout << "rec.amount "    << r.amount << endl;
        
        
        if (nodep->lastName == r.lastName) {  //nodep->lastName == rec.lastName
            int x=0;
            x++;
            r.amount=nodep->amount;
            nodep->amount=nodep->amount;
            
            cout << " matched ***" << r.amount;
            key=x;
            //NodeType currentbalance;
            currentbalance=r.amount;
            
            transfer(nodep, r);
            currentbalance=transfer2(r,x);
            nodep->amount=currentbalance;
            break;
            //return rec.amount;
            
        }
        
        //nodep->amount == rec.amount
        if(nodep->id < r.id)
            //rec.lastName < nodep->lastName
            nodep = nodep->llink;
        else if(nodep->id > r.id)
            nodep = nodep->rlink;
    }
    
    //cout << "nodep->amount " << nodep->amount <<endl;
    cout << "rec.amount$$"    << r.amount << endl;
    
    // return false;
    //  nodep->amount=r.amount;
    
    return currentbalance;
    
}

double BinTree::transfer(NodePtr & nodep, RecType &r){
    //nodep->amount=r.amount;
    
    cout << "from transfer 1  funct: " << r.amount <<endl;
    
    key2[2]=r.amount;
    return r.amount;
}

double BinTree::transfer2(RecType &r, int key2){
    
    //r.amount=amount2;
    cout << "from transfer2 funct" << r.amount <<endl;
    double array[key2];
    array[key2]=r.amount;
    return  array[key2];
}




void BinTree::PointToRoot1(){
    
    NodeType * NodePtr=root;
    BinTree();
    
}




//Displaying the tree in reverse in order traversal with levels
void BinTree::display ()
{
    rdisplay (root, 1);
}

void BinTree::rdisplay (NodePtr nodep, int level)
{
    if (nodep != NULL)
    {
        rdisplay (nodep->rlink, level + 1);
        cout <<  setw (7 * level) << nodep->id <<endl;
        rdisplay (nodep->llink, level + 1);
    }
}

//Logging the tree in reverse In-order traversal with levels
void BinTree::fdisplay (ofstream & fout)
{
    rfdisplay (root, 1, fout);
}

void BinTree::rfdisplay (NodePtr nodep, int level, ofstream & fout)
{
    if (nodep != NULL)
    {
        rfdisplay (nodep->rlink, level + 1,fout);
        fout <<  setw (7 * level) << nodep->id <<endl;
        rfdisplay (nodep->llink, level + 1,fout);
    }
}
//Storing the tree to a file OrderedMaster.txt
void BinTree::store ()
{
    fout.open("OrderedMaster.txt",ios::out );
    //save the node count as the first number in the file
    int count = countNodes();
    fout << count << endl;
    //save the tree
    rstore (root);
    fout.close();
}

void BinTree::rstore (NodePtr nodep)
{
    if (nodep != NULL)
    {
        rstore (nodep->llink);
        fout << nodep->id << " "
        << nodep->firstName << " "
        <<  nodep->lastName <<  " "
        << nodep->amount << endl;
        rstore (nodep->rlink);
    }
}
//Restoring the tree from a file OrderedMaster.txt
void BinTree::restore ()
{
    fin.open("OrderedMaster.txt",ios::in );
    //input node count. This was stored as the first number in file.
    int count;
    fin >> count;
    //restore the tree
    rrestore (root,count);
    fin.close();
}

void BinTree::rrestore (NodePtr & nodep, int count)
{
    if (count > 0)
    {
        //create a node
        nodep = new NodeType;
        nodep->llink = NULL;
        nodep->rlink = NULL;
        //create and fill the left subtree
        if ( (count % 2) == 0)
            rrestore (nodep->llink, ((count-1)/2) + 1);
        else
            rrestore (nodep->llink, count/2);
        //fill in the node
        fin >> nodep->id >> nodep->firstName >> nodep->lastName >> nodep->amount;
        //create and fill the right subtree
        if ( (count % 2) == 0)
            rrestore (nodep->rlink, ((count-1)/2) );
        else
            rrestore (nodep->rlink, count/2);
    }
}

//Counting nodes
int BinTree::rcountNodes (NodePtr nodep )
{
    
    if (nodep != NULL)
    {
        return (rcountNodes (nodep->llink) + rcountNodes(nodep->rlink) + 1);
    }
    else
        return 0;
}

int BinTree::countNodes ()
{
    return rcountNodes (root);
}



int main ( ) {
    
    BinTree tree;
    
    ofstream fout ("Log.txt");
    ifstream finMaster ("Master.txt");
    ifstream finTransaction ("Transaction.txt");
    ifstream finOrderedMaster ("OrderedMaster.txt");
    
    RecType r;
    finMaster >> r.id;
    char transaction;
    
    while (!finMaster.eof( ) )     //read one person at atime, one line at a time. reads and stores
        //into one variable until a a space is found
    {
        finMaster >> r.firstName;
        cout << "first name " << r.firstName << endl;
        
        finMaster >> r.lastName;
        cout << "last name " << r.lastName << endl;
        
        finMaster >> r.amount;
        cout << "amount " << r.amount << endl;
        
        finMaster >> r.id;
        cout << "id " << r.id << endl;
        
        tree.insert(r);
        cout << "\n";
    }
    //display the tree
    tree.PointToRoot1();
    tree.display();
    tree.fdisplay(fout);
    tree.store();
    
    string firstName, lastName;
    int id=0;
    const int size=10;
    char transactionb[size];
    
    BinTree binarytree1;
    //tree.pointToRoot();      //start at the root
    
    
    RecType x;
    cout << "\n\n";
    int counter=0;
    
    
    
    while(!finTransaction.eof( ) ){
        
        //finTransaction.get(r.transaction);
        
        
        finTransaction >> r.transaction;
        // cout << "transaction " << r.transaction << endl;
        
        finTransaction >> r.id;
        cout << "ID        " << r.id << endl;
        
        finTransaction >> r.firstName;
        cout << "first name " << r.firstName << endl;
        
        finTransaction >> r.lastName;
        cout << "last name " << r.lastName << endl;
        
        //tree.search(r);
        cout << "\n\nbefore r.amount" << r.amount << "\n\n\n tsearch =";
        cout << tree.search(r) << "\n\n\n" << endl;
        
        r.amount=tree.search(r);
        
        
        // r.amount=tree.transfer2(r, 1);
        
        // cout << "tracing @@@:" << r.amount << endl;
        // cout << "tracing @@@:" << r.amount << endl;
        
        // r.amount=tree.transfer2(r, 0);
        //cout << "tracing @@@:" << r.amount << endl;
        
        //  r.amount=tree.transfer2(r, 2);
        //  cout << "tracing @@@:" << r.amount << endl;
        
        
        
        r.amount=tree.transfer(nodep, r);
        //cout << "transfer1 func" << tree.transfer(nodep, r) << endl;
        
        //cout << "transfer2 func" << tree.transfer2(nodep, r) << endl;
        //cout << "key=" << n.key2[2] << endl;
        
        //cout << "transfer func2" << tree.transfer() << endl;
        
        finTransaction >> transactionb;
        cout << "new transaction " << transactionb << endl;
        
        //remove the + and - from the amount
        cout << "current balance: " << r.amount << endl;
        cout << "transactionb[0] " << transactionb[0] << endl;
        
        double tempWallet;
        tempWallet = atof(transactionb);     //*****
        cout << "tempwallet " << tempWallet << endl;
        if(transactionb[0] == '-'){
            r.amount=r.amount+tempWallet;
            cout << " balance: " << r.amount << endl;
            
        }
        
        else if (transactionb[0] == '+'){
            r.amount=r.amount+tempWallet;
            cout << " balance: " << r.amount << endl;
        }
        
        else if (transactionb[0] == '0'){
            tree.remove(r);
        }
        
        
        
        cout << "executing Trasaction: " << r.transaction << endl;
        if(r.transaction=='D') {
            tree.remove(r);
            cout << "removing...";
        }
        if (r.transaction=='U'){
            tree.update(r);
            cout << "updating...";
        }
        if (r.transaction=='I'){
            tree.insert(r);
            cout << "adding...";
        }
        
        cout << "\n\n" ;
        
        
    }
    
    cout << "tracing" << endl;
    
    /*
     while(!finTransaction.eof( ) ){
     
     //finTransaction.get(r.transaction);
     
     
     finTransaction >> r.transaction;
     // cout << "transaction " << r.transaction << endl;
     
     finTransaction >> r.id;
     cout << "ID        " << r.id << endl;
     
     finTransaction >> r.firstName;
     cout << "first name " << r.firstName << endl;
     
     finTransaction >> r.lastName;
     cout << "last name " << r.lastName << endl;
     
     r.amount=tree.search(r);
     
     cout << "tracing" << endl;
     finTransaction >> transactionb;
     cout << "new transaction " << transactionb << endl;
     
     //remove the + and - from the amount
     cout << "current balance: " << r.amount << endl;
     cout << "transactionb[0] " << transactionb[0] << endl;
     
     double tempWallet;
     tempWallet = atof(transactionb);     //*****
     cout << "tempwallet " << tempWallet << endl;
     if(transactionb[0] == '-'){
     r.amount=r.amount+tempWallet;
     cout << " balance: " << r.amount << endl;
     
     }
     
     else if (transactionb[0] == '+'){
     r.amount=r.amount+tempWallet;
     cout << " balance: " << r.amount << endl;
     }
     
     else if (transactionb[0] == '0'){
     tree.remove(r);
     }
     
     
     
     cout << "executing Trasaction: " << r.transaction << endl;
     if(r.transaction=='D') {
     tree.remove(r);
     cout << "removing...";
     }
     if (r.transaction=='U'){
     tree.update(r);
     cout << "updating...";
     }
     if (r.transaction=='I'){
     tree.insert(r);
     cout << "adding...";
     }
     
     cout << "\n\n" ;
     
     
     }
     
    
    
    
    //store the tree
    tree.store();
    
    //display the tree
    tree.display();
    tree.fdisplay(fout);
    
    //store the tree
    tree.store();
    //restore the tree
    tree.restore();
    //display the restored tree.
    tree.display();
    tree.fdisplay(fout);
    tree.store();
    
    
    return 0;
    
}

**************************************************************/
