#include<bits/stdc++.h>
using namespace std;
// traverse node
const int x = 100;
int graph[x][x]; bool vis[x]; int parent[x], lev[x];
void levelOrder(int src, int nd, int edg) {
    for(int i = 0; i < nd; i++) {
        vis[i] = false;
        for(int j = 0; j < nd; j++) graph[i][j] = 0;
    }
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1; graph[v][u] = 1;
    }
    queue <int> q; q.push(src);
    vis[src] = true; lev[src] = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for(int i = 0; i < nd; i++) {
            if(graph[curr][i] && !vis[i]) {
                q.push(i); vis[i] = true;
                lev[i] = lev[curr] + 1;
            }
        }
    }
    cout << endl;
    for(int i = 0; i < nd; i++) cout << lev[i] << " ";
}
// minimum distance
int x = 1005;
vector <int> adj[x]; int dist[x];
void BFS(int src) {
    /* int nd, src, edg; cin >> nd >> edg, src;
    while(edg--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    BFS(src); */
    queue <int> q; q.push(src); dist[src] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1; q.push(v);
            }
        }
    }
    for(int i = 1; i <= nd; i++) cout << dist[i] << " ";
}
void Isconnected(int nd, int edg) {
    vector <vector <int>> adj(nd + 1);
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <bool> vis(nd + 1, false);
    int src = 2, trg = 6;
    queue <int> q; q.push(src);
    vis[src] = true; bool linked = false;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == trg) {
            linked = true; break;
        }
        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v); vis[v] = true;
            }
        }
    }
    if(linked) cout << "connected";
    else cout << "disconnected";
} 
// Counts how many times each node is processed
void cntprocessed(int nd) { // nd = 6
    vector <vector <int>> adj(nd);
    auto join = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    join(0, 1); join(0, 2); join(1, 3); join(1, 4);
    join(2, 4); join(3, 5); join(4, 5);
    vector <bool> vis(nd, false);
    queue <int> q; q.push(0);
    vis[0] = true; int cnt = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true; cnt++; q.push(v);
            }
        }
    }
    cout << cnt;
}
void cntprocesse() {
    map <int, vector <int>> adj = {{0, {1, 2}}, {1, {3, 4}}, {2, {4}}, {3, {5}}, {4, {5}}};
    map <int, int> viscnt;
    queue <int> q; q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        viscnt[u]++;
        for(auto v : adj[u]) {
            if(viscnt[v] == 0) q.push(v);
        }
    }
    for(auto mp : viscnt) cout << mp.first << " " << mp.second << endl;
}
// finds the shortest path between two nodes in an unweighted graph
void printpath(int *parent, int end) {
    if(parent[end] == -1) return;
    printpath(parent, parent[end]);
    cout << end << " ";
}
void shortway(int src, int end, int nd, int edg) {
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    queue <int> q; bool flag = false;
    for(int i = 0; i < nd; i++) {
        parent[i] = -1; vis[i] = false;
    }
    q.push(src); vis[src] = true;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for(int i = 0; i < nd; i++) {
            if(graph[curr][i] && !vis[i]) {
                parent[i] = curr; vis[i] = true; q.push(i);
                if(i == end) {
                    flag = true; break;
                }
            }
        }
    }
    if(flag && parent[end] != -1) printpath(parent, end);
    else cout << "No path exits";
}
// distance from every path
vector <vector <pair <int, int>>> graph; // neighbour, weight
vector <bool> seen; vector <int> dist;
void addedge(int u, int v, int w ) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}
// min path
void dijkstra(int src, int nd) {
    /* int nd, edg; cin >> nd >> edg;
    for(int i = 0; i < edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        addedge(u, v, w);
    }
    dijkstra(0, 3, nd); */
    seen.assign(nd, false); dist.assign(nd, INT_MAX); graph.resize(nd);
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    dist[src] = 0; pq.push({0, src});
    while(!pq.empty()) {
        auto [cost, curr] = pq.top(); pq.pop();
        if(seen[curr]) continue; seen[curr] = true;
        cout << curr << " ";
        for(auto [v, w] : graph[curr]) {
            if(!seen[v] && dist[curr] != INT_MAX && dist[curr] + w < dist[v]) {
                dist[v] = dist[curr] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 0; i < nd; i++) cout << i << " " << dist[i] << endl;
}
// neg cycle detect
const int x = 1e9;
int dist[x / 2];
vector <tuple <int, int, int>> adj;
vector <pair <int, int>> edg;
void BellFord(int nd, int edg) {
    for(int i = 0; i < nd; i++) dist[i] = x;
    for(int i = 0; i < edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj.emplace_back(u, v, w);
        // edg[u].push_back({v, w});
    }
    dist[1] = 0;
    for(int i = 1; i < nd; i++) {
        for(auto [u, v, w] : adj) {
            if(dist[u] != x && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }/*
    int src = 1; dist[src] = 0;
    for(int iter = 1; iter < nd; ++iter) {
        for(int u = 0; u < nd; ++u) {
            for(auto [v, w] : adj[u]) {
                if(dist[u] != x && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    } */
    for(auto [u, v, w] : adj) {
        if(dist[u] != x && dist[u] + w < dist[v]) {
            cout << "Neg cycle exits"; return;
        }
    }
    for(int i = 1; i < nd; i++) 
        cout << (dist[i] == x ? -1 : dist[i]) << " ";
}
int main() {
    int nd, src, edg; cin >> nd >> src >> edg;
    levelOrder(src, nd, edg); 
    // Isconnected(nd, edg);
    //cntprocessed(nd);
    /*nt end; cin >> end;
    shortway(src, end, nd, edg);*/
}
