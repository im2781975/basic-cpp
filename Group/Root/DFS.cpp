#include<bits/stdc++.h>
using namespace std;
void DFS(int start, vector <vector <int>> adj, int n) {
    vector <bool> vis(n, false);
    stack <int> st; st.push(start);
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(vis[u]) continue;
        vis[u] = true;
        cout << u << " ";
        for(int v = n - 1; v >= 0; v--) {
            if(adj[u][v] && !vis[v]) st.push(v);
        }
    }
}
// calculate how many times a particular node gets “checked”
void checkcnt(vector <vector <int>> graph, int start) {
    vector <int> cnt(graph.size(), 0);
    vector <bool> vis(graph.size(), false);
    stack <int> st; st.push(start);
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
vector<int> adg[100005]; 
void Dfs(int u, vector <bool> &vis) {
    vis[u] = true;
    for (int v : adg[u]) {
        if (!vis[v]) dfs(v, vis);
    }
}
vector <bool> isAp;
vector <int> vis, low; int timer;
//low -> smallest vis time reachable from the subtree rooted at each vertex.
void util(vector <vector <int>>adj, int u, int parent) {
    int child = 0;
    vis[u] = low[u] = timer++;
    for(auto v : adj[u]) {
        if(vis[v] == -1) {
            child++; util(adj, v, u);
            low[u] = min(low[u], low[v]);
            if(parent == -1 && child > 1) isAp[u] = true;
            if(parent != -1 && low[v] >= vis[u]) isAp[u] = true;
        }
        else if(v != parent) low[u] = min(low[u], vis[v]);
    }
}
void findAp(vector <vector <int>> adj, int node) {
    vis.assign(node, -1); low.assign(node, -1);
    isAp(node, false); timer = 0;
    for(int i = 0; i < node; i++) {
        if(vis[i] == -1) util(adj, i, -1);
    }
    for(int i = 0; i < node; i++) {
        if(isAp[i]) cout << i << " ";
        cout << endl;
    }
}
void DFS(vector <int> adj[], vector <int> vis[], int cur) {
    vis[cur] = 1;
    for(int v : adj[cur]) {
        if(!vis[v]) DFS(adj, vis, v);
    }
}
void artpoint(vector <int> adj[], int n) {
    for(int i = 1; i <= n; i++) {
        int unit = 0; vector <int> vis(n + 1, 0);
        for(int j = 1; j <= n; j++) {
            if(j != i && !vis[j]) {
                unit++; DFS(adj, vis, j);
            }
        }
        if(unit > 1) cout << i << " ";
    }
}
int main(){
    int n = 6;
    vector <vector <int>> adj(n, vector <int>(n, 0));
    auto addEdge = [&](int u, int v) { adj[u][v] = adj[v][u] = 1;};
    addEdge(0,1); addEdge(0,2);
    addEdge(1,3); addEdge(1,4); 
    addEdge(2,4); addEdge(3,5);
    DFS(0, adj, n);
    checkcnt(adj, 0);
    // determine whether nodes 2 and 6 are connected using DFS.
    vector <bool> vis(n + 1, false);
    Dfs(1, vis);
    if(vis[2] && vis[6]) cout << "connected";
    else cout << "not connected";
    artpoint(adj, n);
}


