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
void BFSpath(int nd, int src, int dest) {
    /* while(edg--) {
        int u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src, dest; cin >> src >> dest;
    BFSpath(nd, src, dest); */
    vector <bool> vis(nd, false);
    vector <int> parent(nd, -1);
    queue <int> q; q.push(src);
    vis[src] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == dest) break;
        for (int v : adj_list[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u; q.push(v);
            }
        }
    }
    if(!vis[dest]) return;
    vector<int> path;
    for (int it = dest; it != -1; it = parent[at])
        path.push_back(it);
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
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
// traverse way
const int x = 1e6;
bool seen[x + 1]; vector <int> adj[x + 1];
stack <int> st;
void DFS(int src) {
    cout << src << " ";
    vis[src] = true;
    for(int v : adj[src]) {
        if(!vis[v]) DFS(v);
    }
    st.push(src);
}
void traverse(int nd, int edg) {
    fill(seen, seen + nd, false);
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    } /*
    for(int i = 1; i <= nd; i++) {
        for(auto v : adj[i]) cout << v << " "; 
    } */
    DFS(0);
}
void traverse(int nd, int edg) {
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    } 
    for(int i = 1; i <= nd; i++) {
        if(!seen[i]) DFS(i);
    }
    while(!st.empty()) {
        cout << st.top(); st.pop();
    }
}
void DFS(int src, vector <vector <int>> &adj, int nd) {
    vector <bool> vis(nd, false);
    stack <int> st; st.push(src);
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(vis[u]) continue;
        vis[u] = true; cout << u << " ";
        for(int v = nd - 1; v >= 0; v--) {
            if(adj[u][v] && !vis[v]) st.push(v);
        }
    }
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
// calculate how many times a particular node gets checked
void checkcount(vector <vector <int>> graph, int src) {
    vector <int> cnt(graph.size(), 0);
    vector <bool> vis(graph.size(), false);
    stack <int> st; st.push(src);
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int v : graph[u]) {
            cnt[v]++; 
            if(!vis[v]) st.push(v);
        }
        cout << u << " " << cnt[u] << endl;
    }
}
vector <bool> isAp;
vector <int> vis, low; int timer;
// vis -> dicovery time
//low -> lowest reachable discovery time
void DFS(vector <vector <int>> adj, int u, int parent) {
    int child = 0;
    vis[u] = low[u] = timer++;
    for(auto v : adj[u]) {
        if(vis[v] == -1) {
            child++; DFS(adj, v, u);
            low[u] = min(low[u], low[v]);
            if(parent == -1 && child > 1) isAp = true;
            if(parent != -1 && low[v] >= vis[u]) isAp = true;
        }
        else if(v != parent) low[u] = min(low[u], vis[v]);
    }
}
void findAp(vector <vector <int>> adj, int nd) {
    vis.assign(nd, -1), low.assign(nd, -1);
    isAp(nd, false); timer = 0;
    for(int i = 0; i < nd; i++) {
        if(vis[i] == -1) DFS(adj, i, -1);
    }
    for(int i = 0; i < nd; i++) {
        if(isAp[i]) cout << i << " ";
    }
    cout << endl;
}
void DFS(vector <int> adj[], vector <int> vis[], int u) {
    vis[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v]) DFS(adj, vis, v);
    }
}
void findAp(vector <int> adj[], int nd) {
    for(int i = 1; i <= nd; i++) {
        int unit = 0; vector <int> vis(nd + 1, 0);
        for(int j = 1; j <= nd; j++) {
            if(int j != i && !vis[j]) {
                unit++; DFS(adj, vis, j);
            }
        }
        if(unit > 1) cout << i << " ";
    }
}
// DFS to check path from curr to des
bool dfs(int curr, int des, const vector<vector<int>>& adj, vector<int>& vis) {
    if (curr == des) return true;
    vis[curr] = 1;
    for (int x : adj[curr]) {
        if (!vis[x] && dfs(x, des, adj, vis)) return true;
    }
    return false;
}
// Check if path exists from src to des
bool ispath(int src, int des, const vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    return dfs(src, des, adj, vis);
}
// find all strongly connected components
vector <vector <int>> joinparts(int n, vector <vector <int>>grid) {
    /*;int nd = 5;
    vector<vector<int>> edges = {{1,3}, {1,4}, {2,1}, {3,2}, {4,5}};
    
    auto ans = findSCC(nd, edges); */
    vector <vector <int>> adj(n + 1);
    for(auto edg : grid)
        adj[edg[0]].push_back(edg[1]);
    vector <int> res;
    vector <int> islinked(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!islinked[i]) {
            vector <int> tmp = {i};
            islinked[i] = 1;
            for(int j = i + 1; j <= n; ++j) {
                if(!islinked[j] && ispath(i, j, adj) && ispath(j, i, adj)) {
                    tmp.push_back(j);
                    islinked[j] = 1;
                }
            }
            res.push_back(tmp);
        }
    }
    return res;
}
