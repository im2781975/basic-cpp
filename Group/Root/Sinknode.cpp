//Find largest connected water volume (4- dir) in grid where > 0 cells form lakes
void dfs(vector <vector <int>> &grid, vector <vector <bool>> &vis, int x, int y, int &curvlm) {
    
    vis[x][y] = true; curvlm += grid[x][y];
    int dx[] = {1, -1, 0, 0}; int dy[] = {0, 0, 1, -1};
    for(int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] > 0 && !vis[newx][newy])
            dfs(grid, vis, newx, newy, curvlm);
    }
}
int maxlakesize(vector <vector <int>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    int maxsz = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int curvlm = 0;
            dfs(grid, vis, i, j, curvlm);
            maxsz = max(maxsz, curvlm);
        }
    }
    return maxsz;
}
int maxlakesize(vector <vector <int> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    int maxsz = 0;
    function <int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j] = true;
        return grid[i][j] + dfs(i - 1,j) + dfs(i + 1,j) + dfs(i,j - 1) + dfs(i,j + 1);
    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] > 0) maxsz = max(maxsz, dfs(i, j));
        }
    }
    return maxsz;
}
// Given n nodes. directed edges times[i] = {u, v, w}, return min time for signal from k to reach ALL nodes, or -1 if impossible
int delayTime(vector <vector <int>> &time, int n, int k) {
    vector <int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    // Relax all edges |V|-1 times
    for(int it = 0; it < n - 1; it++) {
        for(auto &edg : time) {
            int u = edg[0], v = edg[1], w = edg[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    } /*
    vector <int> dist(n + 1, -1);
    queue <int> q; dist[k] = 0;
    q.push(k);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &edg : time) {
            if(edg[0] == u && dist[edg[1]] == -1) {
                dist[edg[1]] = dist[u] + edg[2];
                q.push(edg[1]);
            }
        }
    } */
    int res = *max_element(dist.begin() + 1, dist.end());
    return res == INT_MAX ? -1 : ans;
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
// Binary Search for Rational Numbers without using floating point arithmetic
#include <iostream>
using namespace std;
struct Rational{
    int p, q;
};
// Ucompare two  Rational numbers 'a' and 'b'. It returns
// 0 --> When 'a' and 'b' are same
// 1 --> When 'a' is greater
//-1 --> When 'b' is greater
int compare(struct Rational a, struct Rational b)
{
    // If a/b == c/d then a*d = b*c:
    if (a.p * b.q == a.q * b.p)
        return 0;
    if (a.p * b.q > a.q * b.p)
        return 1;
    return -1;
}
// Returns index of x in arr[l..r] if it is present, else returns -1. It mainly uses Binary Search.
int binarySearch(struct Rational arr[], int l, int r,
                 struct Rational x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (compare(arr[mid], x) == 0) 
            return mid;
        // If element is smaller than mid, then it can only be present in left subarray
        if (compare(arr[mid], x) > 0)
            return binarySearch(arr, l, mid - 1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
    struct Rational arr[] = { { 1, 5 }, { 2, 3 }, 
    { 3, 2 }, { 13, 2 } };
    struct Rational x = { 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    cout << "Element found at index "
         << binarySearch(arr, 0, n - 1, x);
}
#include<bits/stdc++.h>
using namespace std;
// Min path sum from top-left to bottom-right (right/down moves only)
int minpathsum(vector <vector <int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <int>> dp(n, vector <int> (m, 0));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for(int i = 1; i < n; i++) 
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) 
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
    return dp[n - 1][m - 1];
}
// Count right/down paths from (0,0) to (n - 1, n - 1) avoiding traps.
int cntpath(int n, vector <vector <int>> &trap) {
    vector <vector <int>> dp(n, vector <int>(n, 0));
    for(int i = 1; i < n; i++) dp[i][j] = trap[i][0] ? 0 : dp[i - 1][0];
    for(int j = 1; j < n; j++) dp[i][j] = trap[0][j] ? 0 : dp[0][j - 1];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!trap[i][j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    } /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(trap[i][j]) dp[i][j] = 0;
            else if(i || j) dp[i][j] = ((i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0)) % 10000;
        }
    } */
    return dp[n - 1][n - 1];
}
// Given rival pairs (Lykan vs Vampire fights), find maximum number that can be all Vampires OR all Lykans
bool dfs(int u, vector <vector <int>> &adj, vector <int> &match, vector <bool> &vis) {
    for(int v : adj[u]) {
        if(!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v], adj, match, vis)) {
                match[u] = v; match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxfighterteam(int n, vector <pair <int, int>> &fight) { /*
    int n; cin >> n;
    vector <pair <int, int>> fight(n);
    for(int i = 0; i < n; i++) cin >> fight[i].first >> fight[i].second;
    cout << maxfighterteam(n, flight); */
    int num = *max_element(fight.begin(), fight.end(), [](auto &a, auto &b) {
        return max(a.first, a.second) < max(b.first, b.second); }) + 1;
    vector <vector <int> adj(num);
    for(auto [u, v] : fight) {
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector <int> match(num, -1);
    int matching = 0;
    for(int i = 0; i < num; i++) {
        if(match[i] == -1) {
            vector <bool> vis(num, false);
            if(dfs(i, adj, match, vis)) matching++;
        }
    }
    return num - matching;
}
//return the len of the longest increasing path in matrix
int dfs(vector <vector <int>> &grid, int x, int y, vector <vector <int>> &tmp) {
    if(tmp[x][y] != -1) return tmp[x][y];
    int maxpath = 1;
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(const auto &dir : direct) {
        int nx = x + dir[0], ny = y + dir[1];
        if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() 
           && grid[nx][ny] > grid[x][y])
            maxPath = max(maxPath, 1 + dfs(grid, nx, ny, tmp));
    }
    tmp[x][y] = maxpath;
    return maxpath;
}
int pathIncreasing(vector <vector <int>> grid) {
    int n = grid.size(), m = grid[0].size();
    if(grid.empty() || grid[0].empty()) return 0;
    vector <vector <int>> tmp(n, vector <int> (m, -1));
    int maxpath = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            maxpath = max(maxpath, dfs(grid, i, j, tmp));
    }
    return maxpath;
}
using namespace std;
//find the shortest path using multistage graph
using ump = pair <int, unordered_map<int, int> >;
int shortestPath(vector <ump> &graph, int src, int trg, int k){
    vector <int> dist(graph.size(), INT_MAX);
    dist[trg] = 0;
    //Loop over each stage from k-1 to 1
    for(int i = k - 1; i >= 0; i--){
        //Loop over all vertices in the current stage
        for(int u = 0; u < graph.size(); u++){
            if(graph[u].first != i)
                continue;
            for(const auto &v: graph[u].second){
                if(dist[v.first] != INT_MAX)
                     dist[u] = min(dist[u], v.second + dist[v.first]);
            }
        }
    }
    //Return the shortest path distance from source to target
    return dist[src];
}
int main(){
    //Each stage represented a level of nodes
    vector <ump> graph = {
        {0, {{1, 2}, {2, 9}}},
        {1, {{3, 6}, {4, 3}}},  
        {2, {{4, 1}}},          
        {3, {{5, 7}, {6, 2}}},  
        {4, {{5, 1}, {6, 5}}},  
        {5, {{7, 4}}},          
        {6, {{7, 6}}},          
        {7, {}}
    };
    cout << shortestPath(graph, 0, 7, 4) << " ";
}
//find longest lath in DAG.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent_list[N];
int dp[N];

int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}
//find shortest distance in a multistage graph.
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 8
int shortestDist(int graph[N][N]){
    int dist[N]; dist[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        dist[i] = INF;
        for(int j = i; j < N; j++){
            if(graph[i][j] == INF)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}
int main(){
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
    cout << shortestDist(graph);
}
using namespace std;

using ll = long long;

int solve(int n, int m, vector<vector<char>>& grid, vector<vector<ll>>& dp) {
    if (n < 0 || m < 0 || grid[n][m] == '#') {
        return 0;
    }
    if (n == 0 && m == 0) {
        return 1;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    int ans = 0;
    if (n > 0) {
        ans += solve(n - 1, m, grid, dp);
    }
    if (m > 0) {
        ans += solve(n, m - 1, grid, dp);
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, -1));

    cout << solve(n - 1, m - 1, grid, dp) << endl;
    return 0;
}
//find out minimum cost path to connect all the cities
// Function to find out minimum valued node among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
  int mini = numeric_limits<int>::max();
  int mini_index;
 
  // Loop through all the values of the nodes which are not yet included in MST and find
  // the minimum valued one.
    for (int i = 0; i < n; i++) {
        if (mstset[i] == false && keyval[i] < mini) {
            mini = keyval[i], mini_index = i;
        }
    }
  return mini_index;
}
// Function to find out the MST and the cost of the MST.
void findcost(int n, vector<vector<int>> city) {
 /* int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},{1, 0, 5, 0, 7},
    {2, 5, 0, 6, 0},{3, 0, 6, 0, 0}, {4, 7, 0, 0, 0}};
  findcost(n1, city1); */
    int parent[n];
    int keyval[n];
 
  // Boolean Array to hold bool values whether
  // a node is included in MST or not.
  bool mstset[n];
 
  // Set all the key values to infinite and none of the nodes is included in MST.
    for (int i = 0; i < n; i++) {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }
 
    // Start to find the MST from node 0.Parent of node 0 is none so set -1.
    // key value or minimum cost to reach 0th node from 0th node is 0.
    parent[0] = -1;
    keyval[0] = 0;
 
    // Find the rest n-1 nodes of MST
    for (int i = 0; i < n - 1; i++)
    {
        // First find out the minimum node among the nodes which are not yet included in MST.
        int u = minnode(n, keyval, mstset);
 
        // Now the uth node is included in MST.
    mstset[u] = true;
 
        // Update the values of neighbor nodes of u which are not yet included in MST.
    for (int v = 0; v < n; v++) {
 
        if (city[u][v] && mstset[v] == false && city[u][v] < keyval[v]) 
        {
            keyval[v] = city[u][v];
            parent[v] = u;
        }
    }
  }
  // Find out the cost by adding
  // the edge values of MST.
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += city[parent[i]][i];
    cout << cost << endl;
}
using namespace std;
// find the minimum Groups
int dfsheight(int u, int *vis, vector <int> &adj) {
    vis[u] = 1; int maxht = 0;
    for(auto &v : adj[u]) {
        if(vis[v] == 0) maxht = max(maxht, 1 + dfsheight(v, vis, adj));
    }
    return maxht;
}
int mingrp(vector <int> adj[], int nd) {
    int vis[nd + 1] = {0};
    int grp = INT_MIN;
    for(int i = 1; i <= nd; i++) {
        if(vis[i] == 0) {
            int ht = dfsheight(i, vis, adj);
            grp = max(ht, grp);
        }
    }
    return grp;
}
int minGroups(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    int maxHeight = 0;
    
    function<int(int)> dfsHeight = [&](int node) -> int {
        visited[node] = true;
        int height = 0;
        
        for(int child : adj[node]) {
            if(!visited[child]) {
                height = max(height, 1 + dfsHeight(child));
            }
        }
        return height;
    };
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            maxHeight = max(maxHeight, dfsHeight(i));
        }
    }
    return maxHeight;
}
// count walks from u to v with exactly k edges
#define nd 4
int countwalks(int graph[][nd], int u, int v, int k) {
    int count[nd][nd][k + 1];
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < nd; i++) {
            for (int j = 0; j < nd; j++) {
                count[i][j][e] = 0;
                if (e == 0 && i == j) count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
                if (e > 1) {
                    for (int a = 0; a < nd; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e - 1];
                }
            }
        }
    }
    return count[u][v][k];
}
int cntwalks(int graph[][nd], int u, int v, int k) {
    if(k == 0 && u == v) return 1;
    if(k == 1 && graph[u][v]) return 1;
    if(k <= 0) return 0;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] == 1) cnt += cntwalks(graph, i, v, k - 1);
    }
    return cnt;
}
//count walks from u to v with exactly k edges
int CountWalks(int graph[][node], int u, int v, int k){
    if(k == 0 && u == v)
        return 1;
    if(k == 1 && graph[u][v])
        return 1;
    if(k <= 0)
        return 0;
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(graph[u][i] == 1)
            cnt += CountWalks(graph,i, v, k - 1);
    }
    return cnt;
}
int main(){
    int graph[node][node] ={ { 0, 1, 1, 1 },{ 0, 0, 0, 1 },
    { 0, 0, 0, 1 },{ 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v, k);
}
//count walks from u to v with exactly k edges
using namespace std;
#define node 4
int CountWalks(int graph[][node], int u, int v, int k){
    // value count[i][j][e] will store count of possible walks from i to j with exactly k edges
    int cnt[node][node][k + 1];
    for(int e = 0; e <= k; e++){
        for(int i = 0; i < node; i++){
            for(int j = 0; j < node; j++){
                cnt[i][j][e] = 0;
                if(e == 0 && i == j)
                    cnt[i][j][e] = 1;
                if(e == 1 && graph[i][j])
                    cnt[i][j][e] = 1;
                if(e > 1){
                    // adjacent of source i
                    for(int a = 0; a < node; a++){
                        if(graph[i][a] == 1)
                        cnt[i][j][e] += cnt[a][j][e - 1];
                    }
                }
            }
        }
    }
    return cnt[u][v][k];
}
int main(){
    int graph[node][node] =
    { { 0, 1, 1, 1 },{ 0, 0, 0, 1 }
    ,{ 0, 0, 0, 1 }, { 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v , k);
}
// Check if Tree A is mirror image of Tree B
int mirrorTree(int *arr, int *ray) {
    int n = 3, e = 2;
    vector <stack <int>> st; vector <queue <int>> qe;
    for(int i = 0; i <= n; i++) {
        st.push(stack <int> ());
        queue <int> q; qe.push(q);
    }
    for(int i = 0; i < 2 * e; i += 2) {
        st[arr[i]].push(arr[i + 1]);
        qe[ray[i]].push(ray[i + 1]);
    }
    for(int i = 1; i <= n; i++) {
        while(!st[i].empty() && !qe[i].empty()) {
            int x = st[i].top(); st[i].pop();
            int y = qe[i].top(); qe[i].pop();
            if(x != y) return 0;
        }
    }
    return 1;
}
int mirrorTree(int *u1, int *v1, int *u2, int *v2) {
    int n = sizeof(u1) / sizeof(u1[0]);
    unordered_map <int, stack <int>> mp;
    for(int i = 0; i < n; i++) mp[u1[i]].push_back(v1[i]);
    for(int i = 0; i < n; i++) {
        if(mp[u2[i]].top() != v2[i]) return 0;
        mp[u2[i]].pop();
    }
    return 1;
}
// Minimum Knight Moves on chessboard
int minknightmove(int *start, int *target, int n) {
    vector <vector <bool>> vis(n + 1, vector <bool> (n + 1));
    queue <tuple <int, int, int>> q; // x, y, steps
    q.push({start[0], start[1], 0});
    vis[start[0]][start[1]] = 1;
    while(!q.empty()) {
        auto [x, y, steps] = q.front(); q.pop();
        if(x == target[0] && y == target[1]) return steps;
            
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1;
}
// find the longest distance from source to destination with at most K intermediate nodes

int longestpath(int n, vector <vector <int>> &edges, int src, int dst, int k) {
    vector <vector <pair <int, int>>> adj(n);
    for(auto &edges : edg) 
        adj[edg[0]].emplace_back(edg[1], edg[2]);
    queue <pair <int, int>> q; // {src, dist}
    unordered_map <int, int> dist;
    q.push({src, 0}), dist[src] = 0;
    int level = 0;
    while(!q.empty() && level <= k + 1) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            auto [u, d] = q.front(); q.pop();
            if(u == dst) {}
            for(auto [v, w] : adj[u]) {
                int newDist = d + w;
                if(dist.find(v) == dist.end() || newDist > dist[v]) {
                    dist[v] = newDist;
                    q.push({v, newDist});
                }
            }
        }
        level++;
    } 
    return dist[dst];
}
#define x 256
void firstunqalt() {
    int queue[x], front = -1, rear = -1, nextpos = 0;
    bool dup[x] = {false};
    string ing = "geeksforgeeksandgeeksquizfor";
    for(int i = 0; str[i]; i++) {
        char ch = str[i];
        if(!dup[ch]) {
            if(front == -1) front = rear = 0;
            else rear = (rear + 1) % x;
            queue[rear] = ch; dup[ch] = false;
        }
        else {
            int pos = (front + nextpos) % x;
            while(pos != (rear + 1) % x) {
                if(queue[pos] == ch) {
                    // shift val for remove
                    for(int j = pos; j != rear; j = (j + 1) % x)
                        queue[j] = queue[(j + 1) % x];
                    rear = (rear - 1 + x) % x;
                    break;
                }
                pos = (pos + 1) % x;
            }
        }
    }
    if (front != -1 && front <= rear)
            cout << queue[front] << endl;
    else
        cout << "No non-repeating character so far";
}
// printing Minimum Cost Simple Path between two given nodes
int mincostpath(int u, int dest, bool *vis, int graph[][nd]) {
    if(u == dest) return 0;
    vis[u] = 1; int res = INT_MAX;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] != INT_MAX && !vis[i]) {
            int curr = mincostpath(i, dest, vis, graph);
            if(curr < INT_MAX)
                res = min(res, graph[u][i] + curr)
        }
    }
    vis[u] = 0;
    return res;
}

int minCost = INT_MAX;
void findMinPath(unordered_map<int, vector<pair<int,int>>>& graph,
     vector<bool>& visited, vector<int>& required,
    int curr, int dest, int cost) {
    if(curr == dest) {
        bool allVisited = true;
        for(int node : required) {
            if(!visited[node]) {
                allVisited = false;
                break;
            }
        }
        if(allVisited) minCost = min(minCost, cost);
        return;
    }
    visited[curr] = true;
    for(auto [next, weight] : graph[curr]) {
        if(!visited[next]) {
            findMinPath(graph, visited, required, next, dest, cost + weight);
        }
    }
    visited[curr] = false; 
}
int main() {
    unordered_map<int, vector<pair<int,int>>> graph = {
        {0, {{1,2},{2,3},{3,2}}},
        {1, {{4,4},{0,1}}},
        {2, {{4,5},{5,6}}},
        {3, {{5,7},{0,1}}},
        {4, {{6,4}}},
        {5, {{6,2}}},
        {6, {{7,11}}}
    };
    int src = 0, dst = 6;
    vector<int> required = {2, 4};
    vector<bool> visited(8, false);
    findMinPath(graph, visited, required, src, dst, 0);
    cout << (minCost == INT_MAX ? -1 : minCost) << endl;
}
int minDistance(vector<string>& grid) {
    // vector<string> grid = {
        "0*s", "*0**", "0***", "d***" };
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<tuple<int,int,int>> q;  // r, c, dist
    
    // Find start position
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 's') {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }
    
    int dr[] = {-1, 1, 0, 0};  // up, down, left, right
    int dc[] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [r, c, dist] = q.front(); q.pop();
        
        if(grid[r][c] == 'd') return dist;
        
        // 4 directions
        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
               grid[nr][nc] != '0' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }
    return -1;
}
#include<bits/stdc++.h>
using namespace std;
//find longest lath in DAG.
int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}
//You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
//Your task is to walk from room 1 to room n. What is the maximum score you can get?
const int MAX_N = 105;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> tunnels[MAX_N];
int dp[MAX_N][MAX_N];

int maxScore(int curRoom, int remainingRooms) {
    if (remainingRooms == 0) {
        if (curRoom == n) {
            return 0;
        } else {
            return -INF; // It's not possible to reach room n in the given number of moves.
        }
    }
    if (dp[curRoom][remainingRooms] != -1) {
        return dp[curRoom][remainingRooms];
    }
    int maxScore = -INF;
    for (auto tunnel : tunnels[curRoom]) {
        int nextRoom = tunnel.first;
        int score = tunnel.second;

        int result = maxScore(nextRoom, remainingRooms - 1);
        if (result != -INF) {
            maxScore = max(maxScore, result + score);
        }
    }
    return dp[curRoom][remainingRooms] = maxScore;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        tunnels[u].push_back({v, x});
    }
    memset(dp, -1, sizeof(dp));
    int result = maxScore(1, n);
    if (result == -INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
// sink node is a node with no outgoing edges.
int cntsinknode(int nd, int edg, int *src, int *dst) {
    int vis[nd] = {0}, cnt = 0;
    for(int i = 0; i < edg; i++) vis[src[i]] = 1;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(!vis[i]) ++cnt;
    }
    /* int arr[node] = {0};
    for(int i = 0; i < node; i++) arr[src[i]] = 1;
    for(int i = 1; i <= node; i++){
        if(arr[i] == 0) cnt++;
    } */
    return cnt;
}
//find transpose of a graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}
void Display(vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void TransposeGraph(vector <int> transpose[], vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    vector <int> transpose[node];
    
    TransposeGraph(transpose, adj, node);
    //Display(adj, node);
    Display(transpose, node);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <vector <int>> edgeList(4);
    edgeList[0].push_back(0);
    edgeList[0].push_back(1);
    edgeList[1].push_back(2);
    edgeList[1].push_back(1);
    edgeList[2].push_back(1);
    edgeList[2].push_back(3);
    edgeList[3].push_back(2);
    edgeList[3].push_back(3);
    for(int i = 0; i < edgeList.size(); i++){
        for(int j = 0; j < edgeList[i].size(); j++)
            cout << edgeList[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    vector <vector <int> >edgeList 
    {{1, 2, 3}, {4, 5, 6}, 
    {7, 8, 9}, {10, 11, 12},};
    edgeList.push_back({13, 14, 15});
    for(int i = 0; i < edgeList.size(); i++){
        cout << edgeList[i][0] << " " << edgeList[i][1] << " " << edgeList[i][2] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    int node, edge; cin >> node >> edge;
    cout << "Maximum number of edges that can be added to maintain DAG is: " << (node * (node - 1) /2) - edge;
}
