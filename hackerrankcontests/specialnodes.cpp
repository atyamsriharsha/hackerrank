/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;


/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/*standard values*/

//#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006


/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define INF 1000000

std::vector<std::vector<int> > v2;
int nodes ;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};
 
// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
 
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
 
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}
 
// A recursive function used by shortestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}
 
// The function to find shortest paths from given vertex. It uses recursive 
// topologicalSortUtil() to get topological sorting of given graph.
void Graph::shortestPath(int s)
{
    stack<int> Stack;
    int dist[V];
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;
 
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] > dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
    // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
    {
     //   (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
    	v2[nodes][i] = dist[i] ;
    }
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    int n,m,u,v,w ;
    int min1 = -1 ;
    std::vector<int> v1;
    cin >> n ;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
    	cin >> u >> v >> w ;
        g.addEdge(u,v,w);
    }
    int special ;
    cin >> special ;
    for(int i=0;i<special;i++)
    {
      cin >> nodes ;
      v1.PB(nodes) ;
      g.shortestPath(nodes) ;
    }
    for(int i=0;i<n;i++)
    {
    	min1 = -1 ;
    	for(int j=0;j<special;j++)
    	{
           min1 = min(min1,v2[v1[j]][i]) ; 
    	}
    }
 
    return 0;
}

