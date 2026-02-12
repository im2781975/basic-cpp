#include<bits/stdc++.h>
using namespace std;
//Find negcycle
void negCycle(int node, int edge) {
    vector <tuple <int, int, int>> adj;
    for(int i = 0; i < edge; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj.emplace_back(u, v, w);
    }
    vector <int> dist(node + 1, INT_MAX);
    int src = 1; dist[src] = 0;
    for(int i = 1; i < node; i++) {
        for(auto [u, v, w] : adj) {
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    bool negcycle = false;
    for(int i = 0; i < adj.size(); i++) {
        int u = adj[i].first;
        int v = adj[i].second.first;
        int w = adj[i].second.second;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            negcycle = true;
    }
    if(negcycle) cout << "detected";
    for(int i = 1; i <= nd; i++) cout << i << " " << src << " " << dist[i] << endl;
}
// Find a simple cycle in an undirected graph
#define x 1004
vector <int> adj, vector <int> path;
vector <bool> vis;
bool hascycle(int src, int parent) {
    vis[src] = true;
    path.push_back(src);
    for(int child : adj[src]) {
        if(child == parent) continue;
        if(!vis[child]) {
            if(hascycle(child, src) return true;
        }
        else if(find(path.begin(), path.end(), child) != path.end()) {
            auto it = find(path.begin(), path.end(), child);
            cout << path.end() - it << " ";
            for(auto i = it; i != path.end(); ++i)
                cout << *i << " ";
            return true;
        }
    }
    path.pop_back(); return false;
}
void cntcycle(int node, int edge) {
    for(int i = 0; i < edge; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= node && !path.size(); i++) {
        if(!vis[i]) {
            path.clear(); if(hascycle(i, -1)) return 0;
        }
    }
    cout << "Immpossible";
}
// count cycles of length n in a given graph.
const int nd = 5
void DFS(bool graph[][nd], bool vis[], int len, int cur, int start, int cnt) {
    if(len == 0) {
        if(graph[cur][start]) cnt++;
    }
    vis[cur] = true;
    for (int next = 0; next < nd; next++) {
        if (!vis[next] && graph[cur][next])
            DFS(graph, vis, len - 1, next, start, count);
    }
    vis[cur] = false;
}
int cntcycle(bool graph[][nd], int n) {
    // n -> cycle length
    bool vis[nd] = {false}; int cnt = 0;
    for(int start = 0; start < nd - (n - 1); ++start) {
        DFS(graph, vis, n - 1, start, start, cnt);
        vis[start] = true;
    }
    return cnt / 2;
}


