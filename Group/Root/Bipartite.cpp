#include<bits/stdc++.h>
using namespace std;
bool dfs(int u, int cl, vector <int> &color, vector <vector <int>> &adj) {
    color[u] = cl;
    for(auto &v : adj[u]) {
        if(color[v] == -1) {
            if(!dfs(v, 1 - cl, color, adj)) return false;
        }
        else if(color[v] == cl) return false;
    }
    return true;
}
bool isbipartite(int nd, vector <vector <int>> &edges) {
    vector <vector <int>> adj(nd);
    for(auto &edg : edges) {
        adj[edg[0]].push_back(edg[1]);
        adj[edg[1]].push_back(edg[0]);
    }
    vector <int> colors(nd, -1);
    /* function<bool(int, int)> dfs = [&](int u, int color) -> bool {
        colors[u] = color;
        
        for(int v : adj[u]) {
            if(colors[v] == -1) {
                if(!dfs(v, 1 - color)) return false;
            } else if(colors[v] == color) {
                return false;
            }
        }
        return true;
    };
    for(int i = 0; i < nd; i++) {
        if(colors[i] == -1) {
            if(!dfs(i, 0)) return false;
        }
    }
    return true; */
    for(int i = 0; i < nd; i++) {
        if(colors[i] == -1) {
            if(!dfs(i, 0, colors, adj)) return false;
        }
    }
    return true;
}
bool isbipartite(int nd, vector <vector <int>> &edges) {
    vector <vector <int>> adj(nd);
    for(auto &edg : edges) {
        adj[edg[0]].push_back(edg[1]);
        adj[edg[1]].push_back(edg[0]);
    }
    vector <int> colors(nd, -1);
    queue <int> q;
    for(int i = 0; i < nd; i++) {
        if(colors[i] == -1) {
            colors[i] = 0; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(auto &v : adj[u]) {
                    if(colors[v] == -1) {
                        colors[v] = 1 - colors[u]; q.push(v);
                    }
                    else if(colors[v] == colors[u]) return false;
                }
            }
        }
    }
    return true;
}
//find out whether a given graph is Bipartite or not
bool IsBaipartite(int graph[][node], int src){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    color[src] = 1;
    queue <int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        //Return false if there is a self-loop 
        if(graph[u][u] == 1)
            return false;
        for(int v = 0; v < node; v++){
            if(graph[u][v] == 1 && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(graph[u][v] == 1 && color[u] == color[v])
                return false;
        }
    }
    return true;
}
bool IsBipartite(int node, vector <int> adj[]){
    vector <int> color(node, -1);
    queue <pair<int, int> >q;
    for(int u = 0; u < node; u++){
        if(color[u] == -1){
            color[u] = 0;
            q.push({u, 0});
            while(!q.empty()){
                pair <int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for(int j : adj[v]){
                    if(color[j] == c)
                        return 0;
                    if(color[j] == -1){
                        color[j] = (c) ? 0 : 1;
                        q.push({j, color[j]});
                    }
                        
                }
            }
        }
    }
    return 1;
}
#define node 4
bool colorGraph(int graph[][node], int color[], int u, int c){
    if(color[u] != -1 && color[u] != c)
        return false;
    //color this pos as c and all its neighbours and 1-c
    color[u] = c;
    bool ans = true;
    for(int v = 0; v < node; v++){
        if(graph[u][v]){
            if(color[v] == -1)
                ans &= colorGraph(graph, color, v, 1 - c);
            if(color[v] != -1 && color[v] != 1 - c)
                return false;
        }
        if(!ans)
            return false;
    }
    return true;
}
bool IsBipartite(int graph[][node]){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    int src = 0;
    return colorGraph(graph, color, src, 1);
}
bool isbipartite(vector <vector <int>> &grid) {
    int n = grid.size();
    vector <int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue <int> q; q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : grid[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]) return false;
                }
            }
        }
    }
    return true;
}
using namespace std;
const int n = 1e5;
int visited[n + 1];
int color[n];
vector <int> adj[n + 1];
bool DFS(int u, int type){
    visited[u] = 1;
    color[u] = type;
    for(int v : adj[u]){
        if(!visited[v]){
            if(!DFS(v, 3 - type))
                return false;
        }
        else if(color[v] == color[u])
            return false;
    }
    return true;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool IsBicolorable = true;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool ok = DFS(i, 1);
            if(!ok){
                IsBicolorable = false;
                break;
            }
        }
    }
    if(!IsBicolorable)
        cout << "Impossible";
    else{
        for(int i = 1; i <= node; i++)
            cout << color[i] << " ";
    }
}
