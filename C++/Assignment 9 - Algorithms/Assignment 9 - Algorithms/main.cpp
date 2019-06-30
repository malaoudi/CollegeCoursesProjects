/*

// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<iostream>
#include<queue>
#include<stack>
#include<list>

#include <limits>
#include <fstream>
using namespace std;
# define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices
    
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
    
    int        index;        /// Node number
    char    data[64];    /// Some data stored in the graph
    int adjMatrix[400][400];
    
public:
    Graph(int V); // Constructor
    
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
    
    // prints shortest path from s
    void shortestPath(int s);
    int NUMNODES;
    int GraphNodes[];
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
      this->V = NUMNODES;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    //adj[v][u]=adj[v][u];
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
    
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    /* Looping till priority queue becomes empty (or all
     distances are not finalized)
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
        
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
            
            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
    
    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    g.shortestPath(0);
    
    
    struct Node
    {
        
    };
    
    
    bool getNextLine(ifstream& inF, char *line, int lineLen);
 
         /// Matrix to define the graph links
        ifstream    inFile;
        char        line[81];
        int            i, j, idx, numLinks, link;
        
    Graph x(1);
    
        /// Try to open the file with the graph data
        inFile.open("GraphData.txt", ios::in);
        if(!inFile.is_open())
        {
            /// inFile.is_open() returns false if the file could not be found or
            ///    if for some other reason the open failed.
            cout << "Unable to open file graph.txt. \nProgram terminating...\n";
            return 1;
        }
        
        /// Since we know ahead of time there will be 8 nodes in the graph we can
        /// read and skip the line giving the number of nodes.
        getNextLine(inFile, line, 81);
    ///Graph GraphNodes(80);
        /// Read all the graph data and build the adjacency matrix
        for(i=0; i<x.NUMNODES; i++)
        {
            /// Read the graph ID and use this as it's index in the graph
            getNextLine(inFile, line, 81);
            idx = atoi(line);
            
            /// Read the graph string data and store it
            getNextLine(inFile, line, 81);
            strcpy(, line);
            
            /// Read the number of links for this node
            getNextLine(inFile, line, 81);
            numLinks = atoi(line);
            
            /// Read all links and set the marker in the adjacency matrix
            for(j=0; j<numLinks; j++)
            {
                getNextLine(inFile, line, 81);  /// Read next line
                link = atoi(line);                /// Get link index

            
            }
        }
        
        inFile.close();
 
        /// Print data for testing ...
        cout << "\n\nDemonstration of a Graph implemented as an adjacency matrix.\n\n";
        cout << "(0)           (1)---+\n";
        cout << "  \\           /     |\n";
        cout << "    \\       /       |\n";
        cout << "    (2)---(3)       |\n";
        cout << "     |     |\\       |\n";
        cout << "     |     |  \\     |\n";
        cout << "     |     |   (4)  |\n";
        cout << "     |     |   /|   |\n";
        cout << "     |     | /  |   |\n";
        cout << "    (5)---(6)--(7)--+\n\n";
        cout << "                         GRAPH DATA\n";
        cout << "------------------------------------------------------------\n";
        cout << "Index         Data String             Links to\n";
        cout << "------------------------------------------------------------\n";
        for(i=0; i<x.NUMNODES; i++)
        {
            cout << "  " << GraphNodes[i].index << "        " <<
            x.adj << "\t";
            for(j=0; j<x.NUMNODES; j++)
            {
                if(adjMatrix[i][j] == 1)
                    cout << GraphNodes[j].index << "   ";
            }
            cout << "\n"; /// end of line
        }
        cout << "------------------------------------------------------------\n\n";
        cout << " Adjacency Matrix:\n\n";
        cout << "  0 1 2 3 4 5 6 7\n";
        cout << " +---------------+\n";
        
        for(i=0; i<NUMNODES; i++)
        {
            cout << i << "|";
            for(j=0; j<NUMNODES; j++)
            {
                cout << AdjMatrix[i][j] << "|";
            }
            cout << "\n +---------------+\n";
        }
 
        return(0);
    }
    
    
    ///-------------------------------------------
    /// GetNextLine()
    /// Read the next line from the file.
    ///-------------------------------------------
    bool getNextLine(ifstream& inF, char *line, int lineLen)
    {
        int    done = false;
        
        while(!done)
        {
            inF.getline(line, lineLen);
            
            if(inF.good())    /// If a line was successfully read
            {
                if(strlen(line) == 0)  /// Skip any blank lines
                    continue;
                else if(line[0] == '#')  /// Skip any comment lines
                    continue;
                else done = true;    /// Got a valid data line so return with this line
            }
            else
            {
                strcpy(line, "");
                return false;    /// Flag end of file with null string
            }
        } /// end while
        return true; /// Flag successful read
    }

    
    
    



/*
#include<iostream>
#include<queue>
#include<stack>
#include <limits>
#include <fstream>
using namespace std;



class Graph {
private:
    int **adjMatrix;
    int vertexCount;
    // below attributes are for Prims
    
    int *key;
    int *distance;
    int *parent;
    
public:
    Graph(int vertexCount);
    ~Graph();
    void addEdgeDirectedWeight(int i, int j, int cost);
    void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
    void initializeState();
    
    void showBasicInfo();
    void Dijkstra(int startNode);
    int isAllKeyTrue();  //0 means not MST, 1 means MST
    int findMinDistanceNode();
    
    bool getNextLine(ifstream& inFile, char *line, int lineLen); //(object,
    int numNodes;
    
};
Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;
    this->vertexCount = numNodes;

    this->key = new int[vertexCount];
    this->distance = new int[vertexCount];
    this->parent = new int[vertexCount];
    
    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            adjMatrix[i][j] = 0;
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}
void Graph::initializeState(){
    for(int i=0; i<this->vertexCount; i++){
        this->key[i] = 0; // 0=not in MST, 1=yes in MST
        this->distance[i]= INT_MAX; //initially distance is Max int
        this->parent[i] = -1;  // -1=no parent, else parent info
        //
    }
}
void Graph::addEdgeDirectedWeight(int i, int j, int cost) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = cost;
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
}
int Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else{
        cout<<"Invalid vertex number.\n";
        return 0;
    }
}
void Graph::display(){
    int  u,v; //vertex
    cout<<"\t   ";
    for(u=0; u<vertexCount; u++){
        cout<<u<<" ";
    }
    for(u=0; u<vertexCount; u++) {
        cout << "\nNode[" << (char) (u+48) << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << " " << adjMatrix[u][v];
        }
    }
    cout << "\n\n";
}
void Graph::showBasicInfo(){
    for(int i=0; i<vertexCount; i++){
        cout<<"node: "<<i<<" Key: "<<key[i]
        <<" distance: "<<distance[i]<<" parent: "<<parent[i]<<"\n";
    }
}
int Graph::isAllKeyTrue(){
    for(int i=0; i<this->vertexCount; i++){
        if(this->key[i]==0)
            return 0; // not MST yet
    }
    return 1; // MST done
    
}
int Graph::findMinDistanceNode(){
    int minDistant=INT_MAX;
    int minDistantNode;
    
    for(int i=0; i<vertexCount; i++) {
        if(minDistant > this->distance[i] && this->key[i]==0)
        { //0 means that node is not in MST
            minDistantNode = i;
            minDistant = this->distance[i];
            //cout<<"min: "<<minDistantNode<<"\n";
        }
    }
    //cout<<"Min Distant Node: "<<minDistantNode<<" Cost: "<<minDistant<<"\n";
    return minDistantNode;
}

void Graph::Dijkstra(int startNode){
    cout<<"\nDijkstra Shortest Path starts . . . \n";
    
    // initialization is done before call this method
    this->distance[startNode]=0; //start node's distance is 0
    int minDistanceNode, i;
    
    // 0 means Shortest path calculation is not done yet.
    while(!this->isAllKeyTrue()){
        //cout<<"-------------------------------\n";
        minDistanceNode = findMinDistanceNode();
        this->key[minDistanceNode] = 1;  // this node's shortes path is done
        
        cout<<"Shortest Path: "<<this->parent[minDistanceNode]<<"->"
        <<minDistanceNode<<", Destination Node's cost is: "<<distance[minDistanceNode]<<"\n";
        
        
        for(i=0; i<vertexCount; i++){
            if(this->isEdge(minDistanceNode, i) && this->key[i]==0 ){
                //Below is the code for relaxation
                if(this->distance[i] > this->distance[minDistanceNode]
                   + adjMatrix[minDistanceNode][i]){
                    this->distance[i] = this->distance[minDistanceNode]
                    + adjMatrix[minDistanceNode][i];
                    this->parent[i] = minDistanceNode;
                }
            }
        }
        //this->showBasicInfo(); // To visualize more clearly
        // you can comment this to only show the edges of MST
    }
    
}

int main(){
    Graph g(5);
    g.addEdgeDirectedWeight(0, 1, 10);
    g.addEdgeDirectedWeight(0, 3, 5);
    g.addEdgeDirectedWeight(1, 2, 1);
    g.addEdgeDirectedWeight(1, 3, 2);
    g.addEdgeDirectedWeight(2, 4, 4);
    g.addEdgeDirectedWeight(3, 1, 3);
    g.addEdgeDirectedWeight(3, 2, 9);
    g.addEdgeDirectedWeight(3, 4, 2);
    g.addEdgeDirectedWeight(4, 0, 7);
    g.addEdgeDirectedWeight(4, 2, 6);
    
    g.display();
    
    g.initializeState();
    int startNode = 0;
    //g.showBasicInfo();
    g.Dijkstra(startNode);
    //g.showBasicInfo();
    
    
    
    
    
}
*/

/*
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
using namespace std;

class Graph
{
    vector< vector<int> > Edge;
    vector<unsigned char> visited;
public:
    
    Graph(int V)
    {
        Edge.resize(V);
        visited.resize(V);
    }
    
    void add_edge(int v,int w)
    {
        Edge[v].push_back(w);
    }
    
    void BFS(int s)
    {
        for(auto i : visited) i = false;
        list<int> q;
        visited[s] = true;
        q.push_back(s);
        while (!q.empty())
        {
            s = q.front();
            cout<<s<<" ";
            q.pop_front();
            for(auto i : Edge[s])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }
        
    }
    
};

int main()
{
    Graph g(6);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    int v;
    cout<<"Enter vertex from where to perform BFS"<<endl;
    cin>>v;
    g.BFS(2);
    cout<< (char)true;
}

class Graph1 {
public:
    
    
    
private:
    
    
};

struct NodeType
{
    int dist; //accumulated distance from the start vertex to this vertex.
    int path [20];//An array containing a list of vertices along the path
    //from the start vertex to this vertex.
    int pathlen; //The length of the occupied part of the above array i.e.
    //the length of the path stored in the above array.
    ItemNodeType * link; //Link to the next item node.
}
struct ItemType
{
    int dist; //accumulated distance from the start vertex to this vertex.
    int path [20];//An array containing a list of vertices along the path
    //from the start vertex to this vertex.
    int pathlen; //The length of the occupied part of the above array i.e.
    //the length of the path stored in the above array.
    
}

void Graph::MinPath (int from, int to)
{
    
    //ItemQue is a priority que that queus ItemType items.
    //IntQue is a regular que that queues ints.
    //It’s used to store adjacent vertices.
    ItemQue mq;
    IntQue adjq;
    ItemType item;
    
    //The following variables are used to save values from an item dequed.
    //The item dequeued is considered the parent item.
    //The values saved from the working (parent) item are used
    //to create next level adjacent (child) items.
    
    //
    //We save the parent vertex number.
    //We will use it to pass it to method edges ( )to find each of its
    //child's distance from the parent vertex.
    
    //We obtain this from the vertex path list stored in the parent item.
    //It is stored as the last vertex in the path list.
    //
    //We save the parent distance from the start vertex because
    //we will use this value to find each child’s distance from the
    //start vertex.
    //We will do this by adding the child vertex distance
    //from the parent vertex to the parent vertex distance from the
    //start vertex.
    
    //We save the parent path length.
    //We will use this value to generate the path length of each child.
    //The path list of each child will be one greater than the parent.
    //
    //We do not save the parent path. Because, every child
    //vertex path has the same path as the parent vertex except that an
    //additional vertex is added to the path.
    
    int p_vertex; //parent vertex # (i.e. the vertex just dequeued).
    int p_dist; //total distance of the parent vertex from the start vertex.
    int p_pathlen;//the length of the occupied part of the path array i.e.
    //the length of path.
    
    
    int adjver; //a vertix
    
    int marked [20]; //array to keep track of which vertices are marked.
    
    //unmark all vertices.
    for (int i=0;i<20;i++)
        marked[i] = 0;
    
    //prepare the first item to be queued.
    
    //Initialize the path array to be all zeros.
    for (int i=0;i<20;i++)
        item.path[i] = 0;
    
    //set the distance of the start vertex to the start vertex to be 0.
    item.dist = 0; //its distance from from start vertix.
    
    //set the path of the start vertex to the start vertex to contain
    //the start vertex.
    
    item.path[0] = from; //first entry in the vertix array list.
    
    //set the path length to be 1 because there is only one vertex in
    //the path.
    item.pathlen = 1;
    
    
    
    
    
    //enque the item in the priority queue
    //we enque this to get the algorithm started
    //we will soon deque it and then enque its adjacents (i.e.children).
    
    mq.penque (item);
    
    //start the deque/enque loop
    
    while ( ! (mq.isEmpty() ) )
    {
        //Deque the item.
        mq.dequeue (item);
        
        
        //break if target is reached.
        if (item.path[item.pathlen-1] == to)
            break;
        
        //Save its values (call them parent values. These will be needed
        //to generate (child) next level items
        
        //For this purpose,
        //Save the distance of this vertex from the start vertex.
        //Save the vertex number of this vertex. This vertex is the
        //last vertex in the path list.
        //Save the path length.
        
        //We save them here because the variable item will be reused
        //preparing a next level item.
        
        p_dist = item.dist;
        p_vertex = item.path[item.pathlen-1];
        p_pathlen = item.pathlen;
        
        
        //if the item is not yet marked. find the next level items.
        if(marked[item.path[pathlen-1]] == 0 )
        {
            //mark the item
            marked[item.path[item.pathlen-1]] = 1;
            
            //Find the next level vertices. receive them in an int que
            //Call method findAdj and pass it an int queue.
            //findAdj method will return list of adjacent (child)
            //vertices in the int queue passed to it.
            
            findAdj (item.path[item.pathlen-1], adjq);
            
            //enque next level items in the priority que
            while ( !(adjq.isEmpty()) )
            {
                //deque a next level (i.e. child) vertex
                //the vertix number of one of the next level vertices
                // will be returned in an int vertex
                adjq.deque (adjver);
                
                //if the next level vertix is not marked.
                //Prepare an item for it and
                //enque the item in the priority queue
                //Use the same item variable as above.
                //But modify it as below.
                
                if (marked[adjver] == 0)
                {
                    //prepare an item for it by
                    //reusing the item variable.
                    
                    //calculate its accumulated distance.
                    item.dist = pdist + edges [p_vertex][adjver];
                    
                    //add the vertex to the path list in the item
                    item.path[p_pathlen] = adjver;
                    
                    //update the length of the used verix array list
                    item.pathlen = p_pathlen + 1;
                    
                    //enque the item in the priority que
                    mq.penque (item);
                }
            }
        }
    }
    
    //write code here to display the item
    //display the target vertex distance from the start vertex.
    //display the path from the start vertex to the target vertex.
    
    
}
*/

