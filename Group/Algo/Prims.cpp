#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
int level[n];
int parent[n];
vector<int> adj_list[n];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    
    parent[src]=-1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                parent[adj_node]=head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int nodes, edges; // Changed variable name from "node" to "nodes" and "edge" to "edges".
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    bfs(src);

    vector<int>path;
    int dst=node;
    if(visited[dst]==0)
    {
        cout<<"Impossible";
    }
    cout<<level[dst]<<"\n";
    int selected_node=dst;
    while(true)
    {
        path.push_back(selected_node);
        if(selected_node==src)
        {
            break;
        }
        selecte_node=parent[src];
    }
    reverse(path.begin(),path.end())
    for(int node:path)
    {
        cout<<node<<" ";
    }

    return 0;
}
// find the path in Peterson graph
#include <bits/stdc++.h>
using namespace std;
// path to be checked 
char S[100005]; 
// adjacency matrix. 
bool adj[10][10];
// resulted path - way 
char result[100005];
// we are applying BFS here
bool findthepath(char* S, int v)
{
    result[0] = v + '0';
    for (int i = 1; S[i]; i++) {
        // first traverse the outer graph
        if (adj[v][S[i] - 'A'] || adj[S[i] -'A'][v]) {
            v = S[i] - 'A';
        }
        // then traverse the inner graph
        else if (adj[v][S[i] - 'A' + 5] || 
         adj[S[i] - 'A' + 5][v]) {
            v = S[i] - 'A' + 5;
        }
        // if the condition failed to satisfy return false
        else
            return false;
        result[i] = v + '0';
    }
    return true;
}
int main()
{
    // here we have used adjacency matrix to make connections between the connected nodes
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = 
    adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] =
    adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] =
    adj[9][6] = adj[6][8] = adj[8][5] = true;
    // path to be checked
    char S[] = "ABB";
    if (findthepath(S, S[0] - 'A') || 
        findthepath(S, S[0] - 'A' + 5)) {
        cout << result;
    } else
        cout << "-1";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, int E, int edges[][3])
{   
    // Create an adjacency list representation of the graph
    vector<vector<int>> adj[V];
    // Fill the adjacency list with edges and their weights
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    // Create a priority queue to store edges with their weights
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Create a visited array to keep track of visited vertices
    vector<bool> visited(V, false);
    // Variable to store the result (sum of edge weights)
    int res = 0;
    // Start with vertex 0
    pq.push({0, 0});
    // Perform Prim's algorithm to find the Minimum Spanning Tree
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first; 
        // Weight of the edge
        int u = p.second;  
        // Vertex connected to the edge
        if(visited[u] == true){
            continue;  // Skip if the vertex is already visited
        }
        res += wt; 
        // Add the edge weight to the result
        visited[u] = true;
        for(auto v : adj[u]){
            // v[0] represents the vertex and v[1] represents the edge weight
            if(visited[v[0]] == false){
                pq.push({v[1], v[0]});  // Add the adjacent edge to the priority queue
            }
        }
    }
    return res;
    //Return the sum of edge weights of the Minimum Spanning Tree
}
int main()
{
    int graph[][3] = {{0, 1, 5},
    {1, 2, 3}, {0, 2, 1}};
    cout << spanningTree(3, 3, graph) << endl;
    return 0;
}
// Prim's Minimum Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;
#define V 5
//  find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
// function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
    // Key values used to pick minimum weight edge in cut
    int key[V];
    // To represent set of vertices included in MST
    bool mstSet[V];
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include 1st vertex in MST. Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    // First node is always root of MST
    parent[0] = -1;
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 },
     { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}

