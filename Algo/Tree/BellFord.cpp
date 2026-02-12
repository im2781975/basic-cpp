#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;
int parent[n], dist[n];
vector <pair <int, int>> adj[n];
void BellFord() {
    int nd, edg; cin >> nd >> edg;
    for(int i = 0; i < nd; i++) dist[i] = INT_MAX;
    for(int i = 0; i < edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src = 1; dist[src] = 0;
    for(int i = 1; i < nd; i++) {
        for(int u = 0; u < nd; u++) {
            for(pair <int, int> cd : adj[u]) {
                int v = cd.first, w = cd.second;
                if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 1; i < nd; i++) cout << dist[i] << " ";
}
struct Edg {
    public: int src, dest;
};
void BellFord(vector <Edg> edg, int node, int src) {
    vector <int> dist(node, INT_MAX); dist[src] = 0;
    for(int i = 1; i < nd; i++) {
        for(const Edg &e : edg) {
            if(dist[e.src]!= INT_MAX && dist[e.src] + 1 < dist[e.dest])
                dist[e.dest] = dist[e.src] + 1;
        }
    }
    for(int i = 0; i < nd; i++)
        cout << src << " " << i << " " << dist[i] << endl;
}
struct Edg {
    public : int src, dest, wt;
};
void BellFord(vector <Edg> edg, int node, int src) {
    vector <int> dist(node, INT_MAX); dist[src] = 0;
    for(int i = 1; i < node; i++) {
        for(const Edg &e : edg) {
            if(dist[e.src] != INT_MAX && dist[e.src] + e.wt < dist[e.dest])
                dist[e.dest] = dist[e.src] + e.wt;
        }
    }
    for(const Edg &e : edg) {
        if(dist[e.src] != INT_MAX && dist[e.src] + e.wt < dist[e.dest])
            cout << "Contain neg weight cycle"; return;
            
    }
    for(int i = 0; i < node; i++) cout << i << " " << dist[i] << endl;
}
