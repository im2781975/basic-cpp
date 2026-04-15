#include <bits/stdc++.h>
using namespace std;
// Count the number of connected components  and check if pairs of nodes 
// are in the same connected component in an undirected graph.
const int N = 100009;
bool visited[N]; vector <int> adj[N];
int element[N], compId = 0;
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor);
    }
}
void DFS(int node, int id) {
    element[node] = id;
    for (int neighbor : adj[node]) {
        if (element[neighbor] == 0)
            DFS(neighbor, id);
    }
}
void cntcomponents(int nd, int edg) {
    for(int i = 0; i < edg; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < nd; i++) {
        if (!visited[i]) {
            int edgcnt = 0; DFS(i, edgcnt);
            components++; dfs(i);
        }
    }
    cout << components << endl;
    for (int i = 0; i < nd; i++) {
        if (element[i] == 0) {
            compId++; DFS(i, compId);
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (element[a] == element[b]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
// Calculate the number of edges WITHIN each connected component separately.
void dfs(int node, int edgcnt) {
    visited[node] = true;
    edgcnt += adj[node].size();
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor, edgcnt);
    }
}
void cntedges(int nd, int edg) {
    for(int i = 0; i < edg; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    for (int i = 0; i < nd; i++) {
        if (!visited[i]) {
            int edgcnt = 0;
            dfs(i, edgcnt); cout << edgcnt / 2;
        }
    }
}
// connected components with size ≥ x.
void largestcomponent(int nd, int edg, int x) {
    for(int i = 0; i < edg; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    int largecomponent = 0;
    for(int i = 0; i < nd; i++) {
        if(!visited[i]) {
            int componentsz = 0;
            function <void(int)> dfs = [&](int nd) {
                visited[nd] = true;
                componentsz++;
                for (int neighbor : adj[nd]) {
                    if (!visited[neighbor])
                        dfs(neighbor);
                }
            }; dfs(i);
            if(componentsz >= x) largecomponent += 1;
        }
    } cout << largecomponent;
}
// Finds the maximum value in each connected component of an undirected graph and sums them up.
void findmax(int nd, int edg) {
    vector<vector<int>> graph(nd);
    for (int i = 0; i < edg; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> arr(nd);
    for (int i = 0; i < nd; i++) cin >> arr[i];
    vector<bool> visited(n, false);
    int sum = 0, max_val = 0;
    function<void(int)> dfs = [&](int nd) {
        visited[nd] = true;
        max_val = max(max_val, arr[nd]);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor])
                dfs(neighbor);
        }
    };
    for (int i = 0; i < nd; i++) {
        if (!visited[i]) {
            max_val = 0; dfs(i); sum += max_val;
        }
    }
    cout << sum << endl;
}
// Counts connected components of '.' cells in a grid (4-directional connectivity, '*' are walls).
void connectedcomponents(int n, int m) {
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int components = 0;
    auto dfs = [&](auto&& self, int x, int y) -> void {
        visited[x][y] = true;
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == '.' && !visited[nx][ny]) {
                self(self, nx, ny);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(dfs, i, j);
                components++;
            }
        }
    }
    cout << components << endl;
}
