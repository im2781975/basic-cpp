#include<bits/stdc++.h>
using namespace std;
vector <vector <int>> adj, grid;
bool dfs(int u, int cl, vector <int> color, vector <vector <int>> &adj) {
    color[u] = cl;
    for(int v : adj[u]) {
        if(color[v] == -1) {
            if(!dfs(v, 1 - cl, color, adj))
                return false;
        }
        else if(color[v] == cl) return false;
    }
    return true;
}
bool isbipartite(int nd, int edg) {
    adj.resize(nd); grid.resize(edg);
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        grid[i] = {u, v};
    }
    for(auto &duo : grid) {
        int u = duo[0], v = duo[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> color(nd, -1); /*
    function <bool(int, int)> dfs = [&](int u, int cl) -> bool{
        color[u] = cl;
        for(int v : adj[u]) {
            if(color[v] == -1) {
                if(!dfs(v, 1 - cl)) return false;
            }
            else if(color[v] == cl) return false;
        }
        return true;
    };
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0)) return false;
        }
    } */
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0, color, adj)) return false;
        }
    }
    return true;
}
bool isbipartite(int nd, vector <vector <int>> vec) {
    adj.resize(nd);
    for(auto [u, v] : vec) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> color(nd, -1); queue <int> q;
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            color[i] = 0; q.push(i);
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for(auto v : adj[curr]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[curr]; q.push(v);
                    }
                    else if(color[v] == color[curr]) return false;
                }
            }
        }
    }
    return true;
}
bool isbipartite(int grid[][nd], int nd) {
    int color[nd];
    for(int i = 0; i < nd; i++) color[i] = -1;
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            color[i] = 1;
            queue <int> q; q.push(i);
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                if(graph[u][u] == 1) return false;
                for(int v = 0; v < nd; ++v) {
                    if(graph[u][v] && color[v] == -1) {
                        color[v] = 1 - color[u]; q.push(v);
                    }
                    else if(color[u] == color[v] && graph[u][v] == 1) return false;
                }
            }
        }
    }
    return true;
}
bool isbipartite(int nd, vector <int> adj[]) {
    // vector<int> adj[4] = {{1,3}, {0,2}, {1,3}, {0,2}};
    vector <int> color(nd, -1);
    queue <pair <int, int>> q;
    for(int i = 0; i < nd; ++i) {
        if(color[i] == -1) {
            color[i] = 0; q.push({i, 0});
            while(!q.empty()) {
                auto [u, cl] = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(color[v] == cl) return false;
                    if(color[v] == -1) {
                        color[v] = 1 - cl;
                        q.push({v, color[v]});
                    }
                }
            }
        }
    }
    return true;
}
#define nd 4
bool colorgraph(int graph[][nd], int color[], int u, int cl) {
    if(color[u] != -1 && color[u] != cl) return false;
    color[u] = cl;
    for(int v = 0; v < nd; ++v) {
        if(graph[u][v]) {
            if(color[v] == -1 && !colorgraph(graph, color, v, 1 - cl)) return false;
            if(color[v] != -1 && color[v] != 1 - cl) return false;
        }
    }
    return true;
}
bool isbipartite(int graph[][nd]) {
    int color[nd];
    for(int i = 0; i < nd; i++) color[i] = -1;
    return colorgraph(graph, color, 0, 0);
}
bool isbipartite(vector <vector <int>> grid) {
    int n = grid.size(); vector <int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue <int> q; q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : grid[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u]; q.push(v);
                    }
                    else if(color[v] == color[u]) return false;
                }
            }
        }
    }
    return true;
}
const int x = 1e5:
vector <int> adj[x + 1]; int color[x + 1];
bool Isduocolor(int u, int cl) {
    /* for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i <= nd && ok; i++) {
        if(color[i] == 0) {
            if(!Isduocolor(i, 1)) ok = false;
        }
    }
    if(!ok) cout << "Impossible";
    else {
        for(int i = 1; i <= nd; i++) cout << color[i] << " ";
    } */
    color[u] = cl;
    for(int v : adj[u]) {
        if(color[v] == 0) {
            if(!Isduocolor(v, 3 - cl)) return false;
            else if(color[v] == cl) return false;
        }
    }
    return true;
}
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
