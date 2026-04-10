#include<bits/stdc++.h>
using namespace std;
const int x = 1e5;
int dist[x]; vector <pair <int, int>> adj[x], parent[n];
bool vis[x];
void Dijkstra(int src) {
    /* for(int i = 1; i <= edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(1); */
    fill(dist, dist + nd, x);
    dist[src] = 0;
    for(int i = 0; i < nd; i++) {
        int tmp = -1;
        for(int j = 1; j <= nd; j++) {
            if(vis[j]) continue;
            if(tmp == -1 || dist[tmp] > dist[j]) tmp = j;
        }
        if(tmp == -1) break;
        vis[tmp] = 1;
        for(auto [v, w] : adj[tmp]) {
            if(dist[tmp] + w < dist[v])
                dist[v] = dist[tmp] + w;
        }
    }
    for(int i = 0; i < n; i++) 
        cout << i << " " << dist[i] << endl;
}
void dijkstra(int src, int nd) {
    /* for(int i = 1; i <= edg; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1, nd); */
    fill(dist, dist + nd, x);
    fill(vis, vis + nd, false);
    dist[src] = 0; // min heap
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if(vis[u]) continue; vis[u] = true;
        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(!vis[nd]) {
        cout << -1; return 0;
    }
    int curr = nd; vector <int> path;
    while(true) {
        path.push_back(curr);
        if(curr == src) break;
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for(auto way : path) cout << way << " ";
}
void sortestway(int n, int src, vector <vector <int>> graph) {
    // graph-> 2D matrix
    vector <int> dist(n, INT_MAX);
    vector <bool> vis(n, false); dist[src] = 0;
    for(int cnt = 0; cnt < n - 1; ++cnt) {
        // find unvisited node using mindist
        int u = -1, mindist = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(!vis[i] && dist[i] < mindist) {
                mindist = dist[i]; u = i;
            }
        }
        if(u == -1) break;
        vis[u] = break;
        for(int v = 0; v < n; v++) {
            if(!vis[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
                
        }
    }
    for(int i = 0; i < n; i++) 
        cout << i << " " << dist[i] << endl;
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
