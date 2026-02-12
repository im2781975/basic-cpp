//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
    
    vector<vector<int>> adj(V);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}

//Driver Code Ends
// Helper function for DFS to check bipartite graph
bool dfs(int u, int color, vector<int> &colors,
                           vector<vector<int>> &adj) {

    // Assign color to the current u
    colors[u] = color; 

    // Iterate through all adjacent vertices
    for(auto &v : adj[u]) {
        if(colors[v] == -1) {

            // Assign alternate color to the adjacent u
            if(!dfs(v, 1 - color, colors, adj))
                return false;
        }
        else if(colors[v] == color) {
          
            // If the adjacent u has the same color,
            // it's not bipartite
            return false;
        }
    }
    return true;
}

// Function to check if the graph is Bipartite using DFS
bool isBipartite(int V, vector<vector<int>> &edges) {

    // Initialize all vertices as uncolored
    vector<int> colors(V, -1); 
    
    // create adjacency list
    vector<vector<int>> adj = constructadj(V,edges);

    // Check each component of the graph
    for(int i = 0; i < V; i++) {

        // If the vertex is uncolored
        if(colors[i] == -1) { 

            // If DFS fails, the graph is not bipartite
            if(!dfs(i, 0, colors, adj))
                return false; 
        }
    }

    // All vertices can be colored bipartitely
    return true;
}
//Driver Code Starts

int main() {
    
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if(isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}

//Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

// Function to find the height sizeof
// the current component with vertex s
int height(int s, vector<int> adj[],
           int* visited)
{
    // Visit the current Node
    visited[s] = 1;
    int h = 0;

    // Call DFS recursively to find the
    // maximum height of current CC
    for (auto& child : adj[s]) {

        // If the node is not visited
        // then the height recursively
        // for next element
        if (visited[child] == 0) {
            h = max(h, 1 + height(child, adj,
                                  visited));
        }
    }
    return h;
}

// Function to find the minimum Groups
int minimumGroups(vector<int> adj[], int N)
{
    // Initialise with visited array
    int visited[N + 1] = { 0 };

    // To find the minimum groups
    int groups = INT_MIN;

    // Traverse all the non visited Node
    // and calculate the height of the
    // tree with current node as a head
    for (int i = 1; i <= N; i++) {

        // If the current is not visited
        // therefore, we get another CC
        if (visited[i] == 0) {
            int comHeight;
            comHeight = height(i, adj, visited);
            groups = max(groups, comHeight);
        }
    }

    // Return the minimum bipartite matching
    return groups;
}

// Function that adds the current edges
// in the given graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Drivers Code
int main()
{
    int N = 5;

    // Adjacency List
    vector<int> adj[N + 1];

    // Adding edges to List
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 3);

    cout << minimumGroups(adj, N);
}
//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
    
    vector<vector<int>> adj(V);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}
// Function to check if the graph is Bipartite using BFS
//Driver Code Ends
bool isBipartite(int V, vector<vector<int>> &edges) {

    // Vector to store colors of vertices.
    // Initialize all as -1 (uncolored)
    vector<int> color(V, -1);
    
    //create adjacency list
    vector<vector<int>> adj = constructadj(V,edges);
    // Queue for BFS
    queue<int> q;
    
    // Iterate through all vertices to handle disconnected graphs
    for(int i = 0; i < V; i++) {

        // If the vertex is uncolored, start BFS from it
        if(color[i] == -1) {

            // Assign first color (0) to the starting vertex
            color[i] = 0;
            q.push(i);
            
            // Perform BFS
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                // Traverse all adjacent vertices
                for(auto &v : adj[u]) {

                    // If the adjacent vertex is uncolored,
                    // assign alternate color
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }

                    // If the adjacent vertex has the same color,
                    // graph is not bipartite
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    
    // If no conflicts in coloring, graph is bipartite
//Driver Code Starts
    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if(isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}

//Driver Code Ends
#include<bits/stdc++.h>
// M Coloring problem using backtracking
using namespace std;
#define node 4
bool IsSafe(int src, int graph[node][node], int color[], int type){
    for(int v = 0; v < node; v++){
        if(graph[src][v] && type == color[v])
            return false;
    }
    return true;
}
bool graphcolor(int graph[node][node], int num, int color[], int src){
    if(src == node)
        return true;
    for(int i = 1; i <= num; i++){
        if(IsSafe(src, graph, color, i)){
            color[src] = i;
            if(graphcolor(graph, num, color, src + 1))
                return true;
                 //If assigning color c doesn't lead to a solution then remove it
            color[src] = 0;
        }
    }
    return false;
}
void print(int color[]){
    for(int i = 0; i < node; i++)
        cout << color[i] << " ";
}
int main(){
    int graph[node][node] = {
        { 0, 1, 1, 1 }, { 1, 0, 1, 0 },
        { 1, 1, 0, 1 }, { 1, 0, 1, 0 },
    };
    int num = 3; 
    //represent the color type
    int color[node] = {0}
    for(int i = 0; i < node; i++)
        color[i] = 0;
    for(int i = 0; i < node; i++){
        if(graphcolor(graph, num, color, 0) == false){
            cout << "Solution doesn't exit";
            return 0;
        }
    }
    print(color);
}
using namespace std;
const int n = 1e5;
int visited[n + 1];
int color[n];
vector <int> adj[n + 1];
bool DFS(int u, int type){
    visited[u] = 1;
    color[u] = type;
    for(int v : adj[u]){
        if(!visited[v]){
            if(!DFS(v, 3 - type))
                return false;
        }
        else if(color[v] == color[u])
            return false;
    }
    return true;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool IsBicolorable = true;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool ok = DFS(i, 1);
            if(!ok){
                IsBicolorable = false;
                break;
            }
        }
    }
    if(!IsBicolorable)
        cout << "Impossible";
    else{
        for(int i = 1; i <= node; i++)
            cout << color[i] << " ";
    }
}
//find out whether a given graph is Bipartite or not
#include<iostream>
#include<queue>
using namespace std;
#define node 4
bool IsBaipartite(int graph[][node], int src){
    //Create a color array. Vertex  number is used as index in this array. value '-1'used 
    //to indicate that no color is assigned to vertex 'i'. value 1 is used to indicate first color & 0 for second color.
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    color[src] = 1;
    queue <int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        //Return false if there is a self-loop 
        if(graph[u][u] == 1)
            return false;
        for(int v = 0; v < node; v++){
            if(graph[u][v] == 1 && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(graph[u][v] == 1 && color[u] == color[v])
                return false;
        }
    }
    return true;
}
int main(){
    int graph[][node] = 
    {{0, 1, 0, 1}, {1, 0, 1, 0},
    {0, 1, 0, 1}, {1, 0, 1, 0} };
    IsBaipartite(graph, 0)? cout << "Yes" : cout << "No";
}
/***/
bool IsBipartite(int node, vector <int> adj[]){
    //vector to store colour of vertex assigning all to -1
    vector <int> color(node, -1);
    queue <pair<int, int> >q;
    for(int u = 0; u < node; u++){
        if(color[u] == -1){
            color[u] = 0;
            q.push({u, 0});
            while(!q.empty()){
                pair <int, int> p = q.front();
                q.pop();
                //first node
                int v = p.first;
                //color of first node
                int c = p.second;
                for(int j : adj[v]){
                    //if already coloured with parent vertex 
                    //color then bipartite graph is not possible
                    if(color[j] == c)
                        return 0;
                    if(color[j] == -1){
                        color[j] = (c) ? 0 : 1;
                        q.push({j, color[j]});
                    }
                        
                }
            }
        }
    }
    return 1;
}
int main(){
    int node = 4, edge = 8;
    vector <int> adj[node];
    adj[0] = {1, 3}; adj[1] = {0, 2};
    adj[2] = {1, 3}; adj[2] = {0, 2};
    (IsBipartite(node, adj))? cout << "Yes" : cout << "No";
}
/***/
#define node 4
bool colorGraph(int graph[][node], int color[], int u, int c){
    if(color[u] != -1 && color[u] != c)
        return false;
    //color this pos as c and all its neighbours and 1-c
    color[u] = c;
    bool ans = true;
    for(int v = 0; v < node; v++){
        if(graph[u][v]){
            if(color[v] == -1)
                ans &= colorGraph(graph, color, v, 1 - c);
            if(color[v] != -1 && color[v] != 1 - c)
                return false;
        }
        if(!ans)
            return false;
    }
    return true;
}
bool IsBipartite(int graph[][node]){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    int src = 0;
    return colorGraph(graph, color, src, 1);
}
int main(){
    int graph[][node] = 
    {{0, 1, 0, 1}, {1, 0, 1, 0},
    {0, 1, 0, 1}, {1, 0, 1, 0} };
    IsBipartite(graph)? cout << "Yes" : cout << "No";
}
/***/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  // Initialize color array to -1 (unvisited)

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Color the first vertex with 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Color adjacent vertices with the opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  // If an adjacent vertex has the same color, it's not Bipartite
                    }
                }
            }
        }
    }

    return true;  // If no adjacent vertices have the same color, the graph is Bipartite
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }
    if (isBipartite(graph)) {
        cout << "The graph is Bipartite." << endl;
    } else {
        cout << "The graph is not Bipartite." << endl;
    }
    return 0;
}
//find maximal Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;
// M is number of applicants 
// and N is number of jobs
#define M 6
#define N 6
// A DFS based recursive function  that returns true if a matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u,
         bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in  job v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true; 
            // If job 'v' is not assigned to an  applicant OR previously assigned 
            // applicant for job v (which is matchR[v]) has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] in the following  recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the applicants assigned to jobs.  The value of matchR[i] is the 
    // applicant number assigned to job i,the value -1 indicates nobody is assigned.
    int matchR[N];
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    // Count of jobs assigned to applicants
    int result = 0; 
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
int main()
{
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
     {1, 0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0, 0},
     {0, 0, 1, 1, 0, 0},
     {0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 1}};
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  // Initialize color array to -1 (unvisited)

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Color the first vertex with 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Color adjacent vertices with the opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  // If an adjacent vertex has the same color, it's not Bipartite
                    }
                }
            }
        }
    }

    return true;  // If no adjacent vertices have the same color, the graph is Bipartite
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }
    if (isBipartite(graph)) {
        cout << "The graph is Bipartite." << endl;
    } else {
        cout << "The graph is not Bipartite." << endl;
    }
    return 0;
}
//find maximal Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;
// M is number of applicants 
// and N is number of jobs
#define M 6
#define N 6
// A DFS based recursive function  that returns true if a matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u,
         bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in  job v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true; 
            // If job 'v' is not assigned to an  applicant OR previously assigned 
            // applicant for job v (which is matchR[v]) has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] in the following  recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the applicants assigned to jobs.  The value of matchR[i] is the 
    // applicant number assigned to job i,the value -1 indicates nobody is assigned.
    int matchR[N];
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    // Count of jobs assigned to applicants
    int result = 0; 
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
int main()
{
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
     {1, 0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0, 0},
     {0, 0, 1, 1, 0, 0},
     {0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 1}};
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);
    return 0;
}
