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
}


