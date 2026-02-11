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
#define x 100
int graph[x][x]; bool vis[x];
void path(int parent[], int start, int end) {
    if(start == end) {
        cout << start << " "; return;
    }
    path(parent, start, parent[end]);
}
void BFS(int start, int end, int node) {
    queue <int> q;  bool flag = false;
    int parent[x];
    q.push(start);
    for(int i = 0; i < node; i++) {
        parent[i] = -1; vis[i] = false;
    }
    vis[start] = true; q.push(start);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < node; i++) {
            if(graph[u][i] == 1 && !vis[i]) {
                vis[i] = true; parent[i] = u;
                q.push(i);
                if(i == end) {
                    flag = true; break;
                }
            }
        }
        if(flag) break;
    }
    if(found) cout << path(parent, start, end);
    else cout << "No path Exits";
}
void BfS(vector <int> adj[], vector <int> &vis, int src, int *lev) {
    queue <int> q; q.push(src);
    vis[src] = 1; lev[src] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]) {
            if(vis[v] == 0) {
                vis[v] = 1; q.push(v);
                lev[v] = lev[u] + 1;
            }
        }
    }
}
vector <vector <pair <int, int>>> graph;
void Join(int u, int v, int w) {
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}
void BFs(int src, int trg, int node) {
    vector <bool> vis(node, false);
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push(make_pair(0, src));
    int u = src; vis[u] = true;
    while(!pq.empty()) {
        int v = pq.top().second;
        cout << v << " "; pq.pop();
        if(v == trg) break;
        for(int i = 0; i < graph[v].size(); i++){
            if(!vis[graph[v][i].second]){
                vis[graph[v][i].second] = true;
                pq.push(make_pair(graph[v][i].first, graph[v][i].second));
            }
        }
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> visited(node, 0);
    vector <int> adj[node], int lev[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BfS(adj, visited, 0, lev);
    for(int i = 0; i < node; i++) cout << i << " " << lev[i] << endl;
    graph.resize(node);
    Join(0, 1, 3);    Join(0, 2, 6);
    Join(0, 3, 5);    Join(1, 4, 9);
    Join(1, 5, 8);
    int src = 0, trg = 9;
    BFs(src, trg, node);
}
const int maxn = 1005;
vector <int> adj[maxn];
int dist[maxn];
void BFS(int src){
    queue <int> q;
    q.push(src); dist[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    int src; cin >> src;
    BFS(src);
    for(int i = 1; i <= node; i++)
        cout << dist[i] << " ";
}
