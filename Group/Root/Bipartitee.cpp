#include<bits/stdc++.h>
using namespace std;
vector <vector <int>> adj, grid;
bool dfs(int u, int cl, vector <int> color, vector <vector <int>> &adj) {
    color[u] = cl;
    for(int v : adj[u]) {
        if(color[v] == -1) {
            if(!dfs(v, 1 - cl, color, adj))
                return false;
        }
        else if(color[v] == cl) return false;
    }
    return true;
}
bool isbipartite(int nd, int edg) {
    adj.resize(nd); grid.resize(edg);
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        grid[i] = {u, v};
    }
    for(auto &duo : grid) {
        int u = duo[0], v = duo[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> color(nd, -1); /*
    function <bool(int, int)> dfs = [&](int u, int cl) -> bool{
        color[u] = cl;
        for(int v : adj[u]) {
            if(color[v] == -1) {
                if(!dfs(v, 1 - cl)) return false;
            }
            else if(color[v] == cl) return false;
        }
        return true;
    };
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0)) return false;
        }
    } */
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0, color, adj)) return false;
        }
    }
    return true;
}
bool isbipartite(int nd, vector <vector <int>> vec) {
    adj.resize(nd);
    for(auto [u, v] : vec) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> color(nd, -1); queue <int> q;
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            color[i] = 0; q.push(i);
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for(auto v : adj[curr]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[curr]; q.push(v);
                    }
                    else if(color[v] == color[curr]) return false;
                }
            }
        }
    }
    return true;
}
bool isbipartite(int grid[][nd], int nd) {
    int color[nd];
    for(int i = 0; i < nd; i++) color[i] = -1;
    for(int i = 0; i < nd; i++) {
        if(color[i] == -1) {
            color[i] = 1;
            queue <int> q; q.push(i);
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                if(graph[u][u] == 1) return false;
                for(int v = 0; v < nd; ++v) {
                    if(graph[u][v] && color[v] == -1) {
                        color[v] = 1 - color[u]; q.push(v);
                    }
                    else if(color[u] == color[v] && graph[u][v] == 1) return false;
                }
            }
        }
    }
    return true;
}
bool isbipartite(int nd, vector <int> adj[]) {
    // vector<int> adj[4] = {{1,3}, {0,2}, {1,3}, {0,2}};
    vector <int> color(nd, -1);
    queue <pair <int, int>> q;
    for(int i = 0; i < nd; ++i) {
        if(color[i] == -1) {
            color[i] = 0; q.push({i, 0});
            while(!q.empty()) {
                auto [u, cl] = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(color[v] == cl) return false;
                    if(color[v] == -1) {
                        color[v] = 1 - cl;
                        q.push({v, color[v]});
                    }
                }
            }
        }
    }
    return true;
}
#define nd 4
bool colorgraph(int graph[][nd], int color[], int u, int cl) {
    if(color[u] != -1 && color[u] != cl) return false;
    color[u] = cl;
    for(int v = 0; v < nd; ++v) {
        if(graph[u][v]) {
            if(color[v] == -1 && !colorgraph(graph, color, v, 1 - cl)) return false;
            if(color[v] != -1 && color[v] != 1 - cl) return false;
        }
    }
    return true;
}
bool isbipartite(int graph[][nd]) {
    int color[nd];
    for(int i = 0; i < nd; i++) color[i] = -1;
    return colorgraph(graph, color, 0, 0);
}
bool isbipartite(vector <vector <int>> grid) {
    int n = grid.size(); vector <int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue <int> q; q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : grid[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u]; q.push(v);
                    }
                    else if(color[v] == color[u]) return false;
                }
            }
        }
    }
    return true;
}
const int x = 1e5:
vector <int> adj[x + 1]; int color[x + 1];
bool Isduocolor(int u, int cl) {
    /* for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i <= nd && ok; i++) {
        if(color[i] == 0) {
            if(!Isduocolor(i, 1)) ok = false;
        }
    }
    if(!ok) cout << "Impossible";
    else {
        for(int i = 1; i <= nd; i++) cout << color[i] << " ";
    } */
    color[u] = cl;
    for(int v : adj[u]) {
        if(color[v] == 0) {
            if(!Isduocolor(v, 3 - cl)) return false;
            else if(color[v] == cl) return false;
        }
    }
    return true;
}
