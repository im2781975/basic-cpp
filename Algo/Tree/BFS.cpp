#include<bits/stdc++.h>
using namespace std; 
const int x = 100;
int graph[x][x]; bool visited[x];
void BFS(int start, int nd) {
    queue <int> q; q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for(int i = 0; i < nd; i++) {
            if(graph[cur][i] && !visited[i]) {
                q.push(i); visited[i] = true;
            }
        }
    }
}
int main() {
    int nd, edg; cin >> nd >> edg;
    for(int i = 0; i < nd; i++) {
        visited[i] = false;
        for(int j = 0; j < nd; j++) graph[i][j] = 0;
    }
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1; graph[v][u] = 1;
    }
    int start; cin >> start;
    BFS(start, nd);
}
void Isconnected() {
    int nd, edg; cin >> nd >> edg;
    vector <vector <int>> adj(n + 1);
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start = 2, trg = 6;
    vector <bool> vis(n + 1, false);
    queue <int> q; q.push(start);
    vis[start] = true;
    bool linked = false;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == trg) {
            linked = true; break;
        }
        for(int v : adj[u]) {
            if(!vis[v]) {
                q.push(v); vis[v] = true;
            }
        }
    }
    if(linked) cout << "connected";
    else cout << "Disconnected";
}
// Counts how many times each node is "processed"
using namespace std;
struct grid {
    int nd; map <int, vector <int>> adj;
};
void Join(grid &graph, int u, int v) {
    graph.adj[u].push_back(v);
}
void BFS(int start, grid &graph) {
    map <int, int> viscnt;
    queue <int> q; q.push(start);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        viscnt[u]++;
        for(auto v : graph.adj[u]) {
            if(viscnt[v] == 0) q.push(v);
        }
    }
    for(auto it = viscnt.begin(); it != viscnt.end(); ++it) 
        cout << it -> first << " " << it -> second << endl;
}
int main() {
    grid graph; graph.nd = 6;
    Join(graph, 0, 1); Join(graph, 0, 2);
    Join(graph, 1, 3); Join(graph, 1, 4);
    Join(graph, 2, 4); Join(graph, 3, 5);
    Join(graph, 4, 5);
    int start = 0;
    BFS(start, graph);
}
