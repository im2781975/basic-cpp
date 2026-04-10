const int x = 1e5;
int parent[x], pos[x];
// implements the Disjoint‑Set (Union‑Find) with path compression and union by rank
int find(int nd) {
    if(nd == parent[nd]) return nd;
    return parent[nd] = find(parent[nd]);
}
void unite(int a, int b) {
    /* for(int i = 0; i <= nd; i++) parent[i] = i;
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        unite(u, v);
    }
    for(int i = 1; i <= nd; i++) cout << pos[i] << " " << parent[i] << endl; */
    a = find(a); b = find(b);
    if(a == b) return;
    if(pos[a] < pos[b]) parent[a] = b;
    if(pos[b] < pos[a]) parent[b] = a;
    else {
        parent[b] = a; pos[a]++
    }
}
using namespace std;
vector <int> parent;
int find(int x) {
    return parent[x] == -1 ? x : parent[x] = find(parent[x]); 
}
void union_set(int a, int b) {
    parent[find(a)] = find(b);
}
int main() {
    int n, m; cin >> n >> m;
    parent.assign(n, -1);
    bool hasCycle = false;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(find(u) == find(v)) {
            hasCycle = true; break;
        }
        union_set(u, v);
    }
    cout << (has_Cycle ? "Yes" : "No");
}
#include <bits/stdc++.h>
using namespace std;
// Union-Find (Disjoint Set Union - DSU) for incremental connectivity:
int root(int arr[], int i) {
    while (arr[i] != i) i = arr[arr[i]];  // Path compression
    return i;
}

void union_sets(int arr[], int rank[], int a, int b) {
    int ra = root(arr, a), rb = root(arr, b);
    if (ra != rb) {
        if (rank[ra] < rank[rb])
            arr[ra] = rb;
        else {
            arr[rb] = ra;
            if (rank[ra] == rank[rb]) rank[ra]++;
        }
    }
}

int main() {
    int n = 7;
    vector<int> parent(n), rank(n, 1);
    iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    
    // Operations: 1=query, 2=union
    vector<pair<int, pair<int,int>>> ops = {
        {1, {0,1}}, {2, {0,1}}, {2, {1,2}}, {1, {0,2}},
        {2, {0,2}}, {2, {2,3}}, {2, {3,4}}, {1, {0,5}},
        {2, {4,5}}, {2, {5,6}}, {1, {2,6}}
    };
    
    for (auto& op : ops) {
        int type = op.first, x = op.second.first, y = op.second.second;
        if (type == 1)
            cout << (root(parent.data(), x) == root(parent.data(), y) ? "Yes" : "No") << "
";
        else
            union_sets(parent.data(), rank.data(), x, y);
    }
}
// incremental connectivity
using namespace std;
int root(int arr[], int i){
    while(arr[i] != i){
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void weightUnion(int arr[], int Rank[], int a, int b){
    int rootA = root(arr, a);
    int rootB = root(arr, b);
    if(Rank[rootA] < Rank[rootB]){
        arr[rootA]  = arr[rootB];
        Rank[rootB] += Rank[rootA];
    }
    else{
        arr[rootB] = arr[rootA];
        Rank[rootA] += Rank[rootB];
    }
}
bool Equal(int arr[], int a, int b){
    return (root(arr, a) == root(arr, b));
}
void query(int type, int x, int y, int arr[], int Rank[]){
    if(type == 1){
        (Equal(arr, x, y)) ? cout << "Yes\n" : cout << "No\n";
    }
    else if(type == 2){
        if(!Equal(arr, x, y))
            weightUnion(arr, Rank, x, y);
    }
}
int main(){
    int n = 7;
    int arr[n], Rank[n];
    for(int i = 0; i < n; i++){
        arr[i] = i;
        Rank[i] = 1;
    }
    int q = 11;
    query(1, 0, 1, arr, Rank);
}
#define nd 8
bool BFS(vector <vector <int>> grid, int src, int trg, vector <int> parent) {
    vector <bool> vis(nd, false);
    queue <int> q; q.push(src); 
    vis[src] = true; parent[src] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v = 0; v < nd; v++) {
            if(!vis[v] && grid[u][v] > 0) {
                q.push(v); parent[v] = u;
                vis[v] = true;
                // if(v == trg) return true;
            }
        }
    }
    // return false;
    return vis[trg];
}
// Returns max number of edge‑disjoint paths from src to trg
int finddisjoinpath(vector <vector <int>> graph, int src, int trg) {
    /* int graph[nd][nd] = { 
    {0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},{ 0, 0, 0, 0, 0, 0 } };
    cout << findisdisjoint(graph, 0, 5); */
    vector <vector <int>> grid(nd, vector <int>(nd));
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < nd; j++) grid[i][j] = graph[i][j];
    }
    vector <int> parent(nd); int maxflow = 0;
    while(BFS(grid, src, trg, parent)) {
        int pathflow = INT_MAX;
        for(int v = trg; v != src; v = parent[v]) {
            int u = parent[v];
            pathflow = min(pathflow, grid[u][v]);
        }
        for(int v = trg; v != src; v = parent[v]) {
            int u = parent[v];
            grid[u][v] -= pathflow; 
            grid[v][u] += pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
// all‑pairs shortest paths
int dist[x][x];
void floydWarshall(int nd, int edg) {
    for(int i = 1; i <= nd; i++) {
        for(int j = 1; j <= nd; j++)
            dist[i][j] = (i == j) ? 0 : x;
    }
    for(int i = 0; i < edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int k = 1; k <= nd; k++) {
        for(int u = 1; u <= nd; u++) {
            for(int v = 1; v <= nd; v++) {
                if(dist[u][k] < x && dist[k][v] < x)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    } /*
    for(int i = 1; i <= nd; i++) {
        for(int j = 1; j <= nd; j++)
            cout << (dist[i][j] == x ? -1 : dist[i][j]) << " ";
    } */
    int query; cin >> query;
    for(int i = 0; i < query; i++) {
        int u, v; cin >> u >> v;
        cout << (dist[u][v] == x ? -1 : dist[u][v]) << " ";
    }
} 
#define nd 4
const int x = 1e9;
void warshall(int grid[][nd]) {
    // int graph[V][V] = {{0, 5, x, 10}, {x, 0, 3, x}, {x, x, 0, 1}, {x, x, x, 0}};
    int dist[nd][nd];
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < nd; j++)
            dist[i][j] = grid[i][j];
    }
    for(int k = 0; k < nd; i++) {
        for(int i = 0; i < nd; i++) {
            for(int j = 0; j < nd; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < nd; j++)
            if(dist[i][j] == x) cout << "INF";
            else cout << dist[i][j] << " ";
    }
}
//Find the sortest route between cities
void sortestroute(int nd, int edg) {
    vector <vector <int>> dist(nd, vector <int> (nd + 1, INT_MAX));
    for(int i = 0; i < nd; i++) dist[i][i] = 0;
    for(int i = 0; i < edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        // assume cities are connected 1th based idx
        dist[u - 1][v - 1] = w;
        dist[v - 1][u - 1] = w;
    }
    for(int k = 0; k < nd; k++) {
        for(int u = 0; u < nd; u++) {
            for(int v = 0; v < nd; v++) {
                if(dist[u][k] != INT_MAX && dist[k][v] != INT_MAX && dist[u][k] + dist[k][v] < dist[u][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }
    int q; cin >> q;
    while(q--) {
        int src, dst; cin >> src >> dst;
        if(dist[src - 1][dst - 1] != INT_MAX) cout << dist[src - 1][dst - 1] << endl;
        else cout << "Not Connected";
    }
}
//check if there is a negative weight cycle & min dist using Floyd Warshall Algorithm
#define nd 4
bool negcycle(int grid[nd][nd]) {
    /* int graph[nd][nd] = 
    {{0, 1, x, x}, {x, 0, -1, x},
    {x, x, 0, -1}, {-1, x, x, 0}};
    (negcycle(graph)) ? cout << "Yes" : cout << "No"; */
    int dist[nd][nd];
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < nd; j++) dist[i][j] = grid[i][j];
    }
    for(int k = 0; k < nd; k++) {
        for(int i = 0; i < nd; i++) {
            for(int j = 0; j < nd; j++) {
                if(dist[i][k] != x && dist[k][j] != x)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    } /*
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < nd; j++) 
            cout << (dist[i][j] == x ? -1 : dist[i][j]) << " ";
    } */
    // If any diagonal element is negative, there is a negative cycle
    for(int i = 0; i < nd; i++) {
        if(dist[i][i] < 0) return true;
    }
    return false;
}
// print Eulerian circuit in given directed graph using Hierholzer algorithm
void printcircuit(vector <vector <int>> &adj) {
    int n = adj.size(), src = 0;
    if(n == 0) return;
    stack <int> path; vector <int> circuit;
    int curr = 0; path.push(curr);
    while(!path.empty()) {
        if(!adj[curr].empty()) {
            int val = adj[curr].back();
            adj[curr].pop_back();
            path.push(curr); curr = val;
        }
        else {
            circuit.push_back(curr);
            curr = path.top(); path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    for(int i = 0; i < circuit.size(); i++) cout << circuit[i] << " ";
}
void printcircuit(vector <int> adj[], int n) {
    if(n == 0) return;
    vector <int> path; path.push_back(0);
    vector <int> circuit;
    while(path.size() > 0) {
        int curr = path[path.size() - 1];
        if(adj[curr].size() > 0) {
            int next = adj[curr].back();
            adj[curr].pop_back();
            path.push_back(next);
        }
        else {
            circuit.push_back(path.back());
            path.pop_back();
        }
    }
    for(int i = circuit.size() - 1; i >= 0; i--) cout << circuit[i] << " ";
}
