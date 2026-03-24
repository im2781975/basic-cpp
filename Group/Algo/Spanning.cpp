// LCM of given range queries using Segment Tree
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
// allocate space for tree
int tree[4 * MAX];
int arr[MAX];
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }
// Function to build the segment tree Node starts beginning index of current subtree.
// start and end are indexes in arr[] which is global
void build(int node, int start, int end)
{
    // If there is only one element in current subarray
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    // build left and right segments
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    // build the parent
    int left_lcm = tree[2 * node];
    int right_lcm = tree[2 * node + 1];
 
    tree[node] = lcm(left_lcm, right_lcm);
}
// Function to make queries for array range )l, r). Node is index of root of current segment in segment
// tree (Note that indexes in segment tree begin with 1 for simplicity). start and end are indexes of subarray covered by root of current segment.
int query(int node, int start, int end, int l, int r)
{
    // Completely outside the segment, returning 1 will not affect the lcm;
    if (end < l || start > r)
        return 1;
    // completely inside the segment
    if (l <= start && r >= end)
        return tree[node];

    int mid = (start + end) / 2;
    int left_lcm = query(2 * node, start, mid, l, r);
    int right_lcm = query(2 * node + 1, mid + 1, end, l, r);
    return lcm(left_lcm, right_lcm);
}
int main()
{
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 10;
    arr[5] = 12;
    arr[6] = 11;
    arr[7] = 17;
    arr[8] = 14;
    arr[9] = 1;
    arr[10] = 44;
 
    build(1, 0, 10);
    cout << query(1, 0, 10, 2, 5) << endl;
    cout << query(1, 0, 10, 5, 10) << endl;
    cout << query(1, 0, 10, 0, 10) << endl;
    return 0;
}
// minimum product spanning tree The program is for adjacency matrix
// representation of the graph
#include <bits/stdc++.h>
#define V 5
// find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
// print the constructed MST stored in parent[] and print Minimum Obtainable product
int printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    int minProduct = 1;
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d \n",
               parent[i], i, graph[i][parent[i]]);
 
        minProduct *= graph[i][parent[i]];
    }
    printf("Minimum Obtainable product is %d\n",
           minProduct);
}
 
// Function to construct and print MST for a graph
// represented using adjacency matrix representation
// inputGraph is sent for printing actual edges and
// logGraph is sent for actual MST operations
void primMST(int inputGraph[V][V], double logGraph[V][V])
{
    int parent[V]; 
    // Array to store constructed MST
    int key[V]; 
    // Key values used to pick minimum
    // weight edge in cut
    bool mstSet[V]; 
    // To represent set of vertices not
    // yet included in MST
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    key[0] = 0;
    // Make key 0 so that this vertex is
    // picked as first vertex
    parent[0] = -1; 
    // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of
        // vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            // logGraph[u][v] is non zero only for  adjacent vertices of m mstSet[v] is false
            // for vertices not yet included in MST Update the key only if logGraph[u][v] is
            // smaller than key[v]
            if (logGraph[u][v] > 0 && mstSet[v] == false && logGraph[u][v] < key[v])
 
                parent[v] = u, key[v] = logGraph[u][v];
    }
    // print the constructed MST
    printMST(parent, V, inputGraph);
}
// Method to get minimum product spanning tree
void minimumProductMST(int graph[V][V])
{
    double logGraph[V][V];
 
    // Constructing logGraph from original graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] > 0)
                logGraph[i][j] = log(graph[i][j]);
            else
                logGraph[i][j] = 0;
        }
    }
    // Applying standard Prim's MST algorithm on Log graph.
    primMST(graph, logGraph);
}
int main()
{
    /* Let us create the following graph
           2    3
       (0)--(1)--(2)
        |   / \   |
       6| 8/   \5 |7
        | /     \ |
       (3)-------(4)
             9          */
    int graph[V][V] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 },
    };
    minimumProductMST(graph);
 
    return 0;
}
#include<bits/stdc++.h> 
using namespace std; 
// find number of spanning  trees in a graph using Matrix 
// Chain Multiplication 
#define MAX 100 
#define MOD 1000000007 
// Matrix Multiplication 
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) 
{ 
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < MAX; j++) 
            for (int k = 0; k < MAX; k++) 
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;     
} 
// Function to find Nth power of A 
void power(int A[MAX][MAX], int N, int result[MAX][MAX]) 
{ 
    int temp[MAX][MAX]; 
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < MAX; j++) 
            result[i][j] = (i == j); 
    while (N>0) 
    { 
        if (N%2 == 1) 
        { 
            multiply(A, result, temp); 
            for (int i=0; i<MAX; i++) 
                for (int j=0; j<MAX; j++) 
                    result[i][j] = temp[i][j]; 
        } 
        N = N/2; 
        multiply(A, A, temp); 
        for (int i=0; i<MAX; i++) 
            for (int j=0; j<MAX; j++) 
                A[i][j] = temp[i][j]; 
    } 
} 
// Function to find number of Spanning Trees in a Graph using Matrix Chain  Multiplication. 
int numOfSpanningTree(int graph[][MAX], int V) 
{ 
    int result[MAX][MAX] = {0}; 
    int temp[MAX][MAX] = {0}; 
    // Create a copy of graph as the Adjacency matrix will be changed during the process 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            temp[i][j] = graph[i][j]; 
 
    // Find (V-2)th power of Adjacency  matrix 
    power(temp, V-2, result); 
    int ans = 0; 
    // Find sum of all elements in (V-2)th 
    // power 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            ans = (ans + result[i][j])%MOD; 
 
    return ans; 
} 
int main() 
{ 
    // Let us create the following graph 
    // 2 <-> 3 
    // | | 
    // 0 <-1-> 1 
    int V = 4; 
    int E = 5; 
    int graph[][MAX] = { 
     {0, 1, 1, 1},  {1, 0, 1, 1}, 
    {1, 1, 0, 1}, {1, 1, 1, 0} }; 
    cout << numOfSpanningTree(graph, V); 
    return 0; 
}
//printing shortest path between two vertices of unweighted graph
using namespace std;
const int n = 1e5;
int parent[n], dist[n];
bool visited[n];
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool BFS(vector <int> adj[], int src, int dst, int parent[], int dist[], int node){
    list <int> queue;
    for(int i = 0; i < node; i++){
        visited[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue.push_back(v);

                if (v == dst)
                    return true;
            }
        }
    }
    return false;
}
void sortestDist(vector <int> adj[], int src, int dst, int node){
    if(!BFS(adj, src, dst, parent, dist, node)){
        clog << "Src & dest aren't connect";
        return;
    }
    vector <int> path;
    int val = dst;
    path.push_back(val);
    while(parent[val]!= -1){
        path.push_back(parent[val]);
        val = parent[val];
    }
    cout << "Sortest pth length is: " << dist[dst];
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> adj[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        addEdge(adj, u, v);
    }
    int src, dst; cin >> src >> dst;
    sortestDist(adj, src, dst, node);
}
using namespace std;
#define node 4
int Travelling(int graph[node][node], int src){
    vector <int> vertix;
    for(int i = 0; i < node; i++){
        if(i != src)
            vertix.push_back(i);
    }
    int minPath = INT_MAX;
    do{
        int curPathWeight = 0;
        int k = src;
        for(int i = 0; i < vertix.size(); i++){
            curPathWeight += graph[k][vertix[i]];
            k = vertix[i];
        }
        curPathweight += graph[k][src];
        minPath = min(minpath, curPathWeight);
    }while(next_permutation(vertix.begin(), vertix.end()));
    return minPath;
}
int main(){
    int graph[][node] { 
        { 0, 10, 15, 20 }, { 10, 0, 35, 25 },
    { 15, 35, 0, 30 }, { 20, 25, 30, 0 } };
    cout << Travelling(graph, 0);
}
