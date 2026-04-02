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
//find out whether a given graph can be converted to two Cliques or not
const int node = 5;
bool IsBipartite(int graph[][node], int src, int color[]){
    color[src] = 1;
    queue <int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 0; v < node; v++){
            if(graph[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(graph[u][v] && color[u] == color[v])
                return false;
        }
    }
    return true;
}
bool IsBicolorable(int graph[][node]){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    for(int i = 0; i < node; i++){
        if(color[i] == -1){
            if(!IsBipartite(graph, i, color))
                return false;
        }
    }
    return true;
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
// Function to convert an adjacency matrix to an adjacency list
vector <vector <int>> matrixToList(vector <vector <int>> matrix) {
    int n = matrix.size();
    vector <vector <int>> adjList(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; i++) {
            if(matrix[i][j] == 1) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
}
// Function to convert an adjacency list to an adjacency matrix
vector <vector <int>> ListTomatrix(vector <vector <int>> adjList) {
    int n = adjList.size();
    vector <vector <int>> matrix(n, vector <int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j : adjList[i]) {
            matrix[i][j] = 1; matrix[j][i] = 1;
        }
    }
    return matrix;
}
void grid(int n) {
    vector <vector <int>> vec(n, vector <int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) vec[i][j] = i + j;
    }
    vector <int> tor[n];
    tor[1].push_back(12); tor[1].push_back(14);
    tor[1].push_back(16); tor[2].push_back(18);
    tor[2].push_back(20); tor[3].push_back(22);
    // tor[1] = {12, 14, 16}; tor[2] = {18, 20}; tor[3] = {22};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < tor[i].size(); j++)
            cout << tor[i][j] << " ";
        cout << endl;
    }
}
void graph() {
    int nd, edg; cin >> nd >> edg;
    vector <int> adj[nd + 1];
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}
void graph() {
    int node, edge; cin >> node >> edge;
    vector <pair<int, int> >adj[node];
    for(int i = 1; i <= edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= adj[i].size(); j++)
            cout << adj[i][j].first << " " << adj[i][j].second; << endl;
    }
}
void grid(int n) {
    vector <pair <int, int>> adj[n];
    adj[0] = {{1, 2}}; adj[1] = {{3, 4}};
    adj[2] = {{5, 6}}, adj[3] = {{7, 8}, {9, 10}};
    adj[0].push_back({11, 12});
    adj[1].push_back({13, 14});
    adj[2].push_back({15, 16});

    adjList[0] = {{1, 2}}; adjList[1] = {{3, 4}};
    adjList[2] = {{1, 7}, {2, 3}}; adjList[3] = {{9, 6}};
    /*
    vector <vector <pair <int, int>>> adj(n); 
    adj[0] = {{1, 2}}; adj[1] = {{3, 4}};
    adj[2] = {{1, 7}, {2, 3}}; adj[3] = {{9, 6}}; */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j].first << " " << adj[i][j].second << endl;
    }
}
