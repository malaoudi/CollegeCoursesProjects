
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define NUMNODES 200                 // maximum of node=200

class Graph
{
    int AdjacentMatrix[NUMNODES][NUMNODES];     //AjM[][] to represent the nodes
    int pathsValues[NUMNODES][2];         // compare path value of each vertex
    int distance[NUMNODES] ;               // distance of vertex from source .
    int path[NUMNODES];
    int parent[NUMNODES];                   // parent of vertex.
    
    int Total_InputVertex;
    int source,destination;
    string string1[100];
    string source1,destination1;
    
public:
    void graph_input();
    void print_graph();
    void initialize();
    void insertion(int,int);              // inserting of paths values to make min heap
    void reheapify_upward(int);
    void reheapify_downward();
    void dijkstra();
    int  minPath_find();
    void path_print();
    void deletion();
};



//graph to read the file and construct the vertices
void Graph:: graph_input()
{
    int i;
    int u,v,wt;
    int count=0;
   string name;
    
    for(int i=0;i<=50;i++)
        for(int j=0;j<=50;j++)
            AdjacentMatrix[i][j]=-1;
    
    ifstream file_object;
    file_object.open("MinPath2.txt");
    
    while(file_object>>i)
    {
        if(i==-1)
        break;
        else
        {
        file_object>>name;
        string1[i]=name;
        count++;
        }
    }
    
    Total_InputVertex=count;
    while(file_object>>u)         // reading graph from the file
    {
        if(u==-1)
            break;
        else
        {   file_object >> v >> wt;
            AdjacentMatrix[u][v]=wt;        //create the matrix with the edges
        }
    }
    
}


//function initialize paths values of the vertices and distances
void Graph:: initialize()
{
    pathsValues[0][0]=0;
    insertion(0,source);
    
    for(int i=1;i<=10;i++)
    {
        distance[i]=INT_MAX;               // initialize distance of each vertex to infinite
    }
    distance[source]=0;
}

//function to print the graph represented as matrix
void Graph:: print_graph()
{
    cout<<"Total vertices : "<< Total_InputVertex <<endl;
    for(int i=0;i<Total_InputVertex;i++)
    { for(int j=0;j<Total_InputVertex;j++)
        cout<< AdjacentMatrix[i][j]<<" ";
        cout<<endl;
    }
    
}

//Insertion of values in the graph to the minheap, with int index values, int node values.
void Graph:: insertion(int value ,int vertex)
{
    pathsValues[++pathsValues[0][0]][0]=value;
    pathsValues[pathsValues[0][0]][1]=vertex;
    
    reheapify_upward(pathsValues[0][0]);       // passing index from where have to heapify
    
}

// function to reheapify the minheap in upward direction from the given index
void Graph:: reheapify_upward(int index)
{
    
    while(index>1 && pathsValues[index][0]<pathsValues[index/2][0])
    {
        swap(pathsValues[index][0],pathsValues[index/2][0]);
        swap(pathsValues[index][1],pathsValues[index/2][1]);
        
        index=index/2;
    }
}


//function to reheapify the minheap in downward direction from the given index
void Graph:: reheapify_downward()
{   int index=1;
    int minimum,child1,child2,temp;
    while(2*index<=pathsValues[0][0])
    {
        child1=2*index;
        child2=2*index+1;
        
        if(child2<=pathsValues[0][0])                 // means index node having both child.
        {
            if(pathsValues[child1][0]<pathsValues[child2][0]) // find min from both child and index to swap with parent
            {
                minimum=pathsValues[child1][0];
                temp=child1;
            }
            else
            { minimum=pathsValues[child2][0];
                temp=child2;
            }
            if(minimum<pathsValues[index][0])
            {
                // swapping
                
                swap(pathsValues[index][0],pathsValues[temp][0]);
                swap(pathsValues[index][1],pathsValues[temp][1]);        // vertex swapping
                index=temp;
            }
            
            else
                break;
        }
        else                      // means having only 1 child
        {
            if(pathsValues[child1]<pathsValues[index])
            {
                swap(pathsValues[index][0],pathsValues[child1][0]);                 // path value swapping
                swap(pathsValues[index][1],pathsValues[child1][1]);                 // vertex swapping
                index=child1;
            }
            else
                break;
        }
    }
}


//function to do Dijkstra's algorithm as to find the shortest path from source to destination in the graph
void Graph:: dijkstra()
{
    
    int i,d,u;
    
    cout << "Enter Start Vertex: ";           // taking input for source vertex
    cin>>source1;
    
    cout << "Enter End Vertex: ";        // taking input for end vertex
    cin>>destination1;
    
    // converting them as integer for indexing purpose
    if(source1=="SF")
            source=0;
    
    else if(source1=="LA")
            source=1;
    
    else if(source1=="DALLAS")
            source=2;
    
    else if(source1=="CONCORD")
            source=3;
    
    else if(source1=="PHOENIX")
            source=4;
    
    else if(source1=="CHICAGO")
            source=5;
    
    else if(source1=="ST LOUIS")
        source=6;
    
    else if(source1=="BOSTON")
        source=7;
    
    else if(source1=="NY")
        source=8;
    
    else if(source1=="LONDON")
        source=9;
    
    else if(source1=="PARIS")
        source=10;
    
    else if(source1=="TOKYO")
        source=11;
    
    else if(source1=="BANGKOK")
        source=12;

    else if(source1=="MEXICO CITY")
        source=13;
    
    else if(source1=="MONTREAL")
        source=14;
    
    if(destination1=="SF")
            destination=0;
    
    else if(destination1=="LA")
            destination=1;
    
    else if(destination1=="DALLAS")
            destination=2;
    
    else if(destination1=="CONCORD")
            destination=3;
    
    else if(destination1=="PHOENIX")
            destination=4;
    
    else if(destination1=="CHICAGO")
            destination=5;
    
    else if(destination1=="ST LOUIS")
        destination=6;
    
    else if(destination1=="BOSTON")
        destination=7;
    
    else if(destination1=="NY")
        destination=8;
    
    else if(destination1=="LONDON")
        destination=9;
    
    else if(destination1=="PARIS")
        destination=10;
    
    else if(destination1=="TOKYO")
        destination=11;
    
    else if(destination1=="BANGKOK")
        destination=12;
    
    else if(destination1=="MEXICO CITY")
        destination=13;
    
    else if(destination1=="MONTREAL")
        destination=14;
    
    initialize();        // pathsValues=0
    
    while(pathsValues[0][0]!=0)
    {
        // here u is vertex having min score
        u=minPath_find();             // extract vertex having min score from priority queue
        int temp_score=distance[u];
        
        for(i=0; i<Total_InputVertex; i++)
            if(AdjacentMatrix[u][i]!=-1)
            {   d=temp_score+AdjacentMatrix[u][i];
                if(d<distance[i])                // update if shortest path is found from source to this node
                {
                    insertion(d,i);      // insert updated value of pathValue with vertex no
                    distance[i]=d;
                    parent[i]=u;
                    
                }
            }
    }
    
}


//Function to find the minimum path, among the paths founded by dijkstra(). vertex with minimum pathvalue
int Graph:: minPath_find()
{
    int min_vertex=pathsValues[1][1];
    deletion();              // delete index 1. extracting min from heap
    return (min_vertex);
}


//Funciton to print the minimum path, or shortest distance
void Graph:: path_print()
{
    int i,j;
    
    int temp_path[10];                 // array for path
    
    int current=destination;
    int last=source;
    int index=-1;
    
    temp_path[++index]=destination;
    
    while(current!=source)                       // loop for path
    {
        current=parent[current];
        temp_path[++index]=current;             // array of reverse path
    }
    cout<<"\nMin Path: ";
    
    for(i=index;i>=0;i--)             // print the path
    {
        cout<<string1[temp_path[i]]<<" ";
        
    }
    
    cout<<" "<<distance[destination]<<endl<<endl;
    
}


//Function deletes the first element of the minheap
void Graph:: deletion()
{   int index=1;
    if(index==pathsValues[0][0])
    {
        pathsValues[0][0]--;
    }
    else
    {
        swap(pathsValues[index][0],pathsValues[pathsValues[0][0]][0]);
        pathsValues[0][0]--;
        
        reheapify_downward();
    }
}

int main()
{
    Graph graph1;
    
    while(true){
    graph1.graph_input();
    graph1.dijkstra();
    graph1.path_print();
    
    }
    
    return 0;
}
