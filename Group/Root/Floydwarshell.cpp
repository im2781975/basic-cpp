#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 505;
int dist[N][N];
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
        if(i == j)
            dist[i][j] = 0;
        else
            dist[i][j] = INT_MAX;
    }
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for(int k = 1; k <= node; k++){
        for(int u = 1; u <= node; u++){
            for(int v = 1; v <= node; v++)
            if(dist[u][k] < INF && dist[k][v] < INF)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
        if(dist[i][j] == INF)
            cout << "__";
        else
            cout << dist[i][j] << " ";
        cout << "\n";
    }
}
/***/
using namespace std;
#define node 4
#define INF 99999
void print(int dist[][node]){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            (dist[i][j] == INF) ? cout << "INF " : cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
void Floydwar(int dist[][node]){
    for(int k = 0; k < node; k++){
        for(int u = 0; u < node; u++){
            for(int v = 0; v < node; v++){
                if(dist[u][k] !=  INF && dist[k][v] != INF)
                    dist[u][v] = dist[u][k] +  dist[k][v];
            }
        }
    }
    print(dist);
}
int main(){
    int graph[node][node] = 
    { { 0, 5, INF, 10 }, { INF, 0, 3, INF },
    { INF, INF, 0, 1 }, { INF, INF, INF, 0 } };
    Floydwar(graph);
}
/***/
//check if there is a negative weight cycle using Floyd Warshall Algorithm
using namespace std;
#define node 4
#define INF 99999
bool NegCycle(int graph[][node]){
    int dist[node][node];
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++)
            dist[i][j] = graph[i][j];
    }
    for(int k = 0; k < node; k++){
        for(int u = 0; u < node; u++){
            for(int v = 0; v < node; v++){
                if(dist[u][k] + dist[k][v] < dist[u][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }
    for(int i = 0; i < node; i++){
        if(dist[i][i] < 0)
            return true;
    }
    return false;
}
int main(){
    int graph[node][node] = 
    { {0 , 1 , INF, INF}, {INF , 0   , -1  , INF},
    {INF , INF , 0 ,-1},{-1  , INF , INF ,   0}};
    (NegCycle(graph)) ? cout << "Yes" : cout << "No";
}
/***/
using namespace std;
const int N 1e3;
const long long INF 1e18;
int dist[N][N];
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
            dist[i][j] = INF;
    }
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int i = 1; i <= node; i++)
        dist[i][i] = 0;
    for(int k = 1; k <= node; k++){
        for(int u = 1; u <= node; u++){
            for(int v = 1; v <= node; v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }
    int query; cin >> query;
    for(int i = 0; i < query; i++){
        int u, v; cin >> u >> v;
        if(dist[u][v] == INF)
            cout << "-1";
        else
            cout << dist[u][v];
    }
}
//Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define V 6
//Returns true if there is a path from source 's' to sink't' in residual graph.
//Also fills parent[] to store the path 
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    // Create a residual graph and fill the residual graph with given capacities in 
    //the original graph as residual capacities in residual graph
    int rGraph[V][V]; 
    // Residual graph where rGraph[i][j] indicates residual capacity of edge
    // from i to j (if there is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; 
    // This array is filled by BFS and to store path
    int max_flow = 0; 
    // There is no flow initially
    // Augment the flow while there is path from source to sink
    while (bfs(rGraph, s, t, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        // Add path flow to overall flow
        max_flow += path_flow;
    }
    // Return the overall flow
    return max_flow;
}
int main()
{
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
    { 0, 0, 0, 7, 0, 4 },{ 0, 0, 0, 0, 0, 0 } };
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
    return 0;
}
// print Eulerian circuit in given directed graph using Hierholzer algorithm
#include <bits/stdc++.h>
using namespace std;
void printCircuit(vector< vector<int> > adj)
{
    //adj represents the adjacency list of the directed graph
    // edge_count represents the number of edges emerging from a vertex
    unordered_map<int,int> edge_count;
    for (int i=0; i<adj.size(); i++)
    {
        //find the count of edges to keep track of unused edges
        edge_count[i] = adj[i].size();
    }
    if (!adj.size())
        return; //empty graph
    // Maintain a stack to keep vertices
    stack<int> curr_path;
    // vector to store final circuit
    vector<int> circuit;
    // start from any vertex
    curr_path.push(0);
    int curr_v = 0;
    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);
            // Find the next vertex using an edge
            int next_v = adj[curr_v].back();
            // and remove that edge
            edge_count[curr_v]--;
            adj[curr_v].pop_back();
            // Move to next vertex
            curr_v = next_v;
        }
        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);
            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }
    // we've got the circuit, now print it in reverse
    for (int i=circuit.size()-1; i>=0; i--)
    {
        cout << circuit[i];
        if (i)
           cout<<" -> ";
    }
}
int main()
{
    vector< vector<int> > adj1, adj2;
    adj1.resize(3);

    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    printCircuit(adj1);
    cout << endl;

    adj2.resize(7);
    adj2[0].push_back(1);
    adj2[0].push_back(6);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[6].push_back(4);
    printCircuit(adj2);
    return 0;
}
// print Eulerian circuit in given directed graph using Hierholzer algorithm
#include <bits/stdc++.h>
using namespace std;
// Function to print Eulerian circuit
void printCircuit(vector<int> adj[], int n)
{
    // adj represents the adjacency list of the directed graph
    if (n == 0)
        return;
 
    // Maintain a stack to keep vertices We can start from any vertex, here we start with 0
    vector<int> curr_path;
    curr_path.push_back(0);
    // list to store final circuit
    vector<int> circuit;
    while (curr_path.size() > 0) {
        int curr_v = curr_path[curr_path.size() - 1];
 
        // If there's remaining edge in adjacency list of the current vertex
        if (adj[curr_v].size() > 0) {
            // Find and remove the next vertex that is adjacent to the current vertex
            int next_v = adj[curr_v].back();
            adj[curr_v].pop_back();
            // Push the new vertex to the stack
            curr_path.push_back(next_v);
        }
        // back-track to find remaining circuit
        else {
            // Remove the current vertex and put it in the circuit
            circuit.push_back(curr_path.back());
            curr_path.pop_back();
        }
    }
    // we've got the circuit, now print it in reverse
    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i];
        if (i)
            cout << " -> ";
    }
}
int main()
{
    int n1 = 3;
    vector<int> adj1[n1];
 
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    printCircuit(adj1, n1);
    cout << endl;
 
    int n2 = 7;
    vector<int> adj2[n2];
    adj2[0].push_back(1);
    adj2[0].push_back(6);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[6].push_back(4);
    printCircuit(adj2, n2);
    cout << endl;
    return 0;
}
 
