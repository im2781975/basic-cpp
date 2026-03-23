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
// count cycles of length n in a given graph.
const int nd = 5
void DFS(bool graph[][nd], bool vis[], int len, int cur, int start, int cnt) {
    if(len == 0) {
        if(graph[cur][start]) cnt++;
    }
    vis[cur] = true;
    for (int next = 0; next < nd; next++) {
        if (!vis[next] && graph[cur][next])
            DFS(graph, vis, len - 1, next, start, count);
    }
    vis[cur] = false;
}
int cntcycle(bool graph[][nd], int n) {
    // n -> cycle length
    bool vis[nd] = {false}; int cnt = 0;
    for(int start = 0; start < nd - (n - 1); ++start) {
        DFS(graph, vis, n - 1, start, start, cnt);
        vis[start] = true;
    }
    return cnt / 2;
}
// cycle detection in undirected graph
bool IsCyclicJoined(vector <int> adj[], int x, vector <bool> vis, int nd) {
    vector <int> parent(nd, -1);
    queue <int> q; vis[x] = true;
    q.push(x); parent[x] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int child : adj[u]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
                parent[child] = u;
            }
            else if (parent[u] != child) return true;
        }
    }
    return false;
}
bool IsCyclicLeaved(vector <int> adj[], int nd) {
    /*vector <int> adj[node];
    for(int i = 0; i < edge; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    (IsCyclicLeaved(adj, node)) ? cout << "Yes" << endl : cout << "No" << endl; */
    vector <bool> vis(nd, false);
    for(int i = 0; i < nd; i++) {
        if(!vis[i] && IsCyclicJoined(adj, i, vis, nd)) return true;
    }
    return false;
}
bool IsCyclicConnected(const vector<vector<int>>& adj, int v, vector<bool>& visited, vector<int>& parent) {
    queue<int> q;
    visited[v] = true;
    q.push(v);
    parent[v] = -1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int child : adj[u]) {
            if (!visited[child]) {
                visited[child] = true;
                parent[child] = u;
                q.push(child);
            } else if (parent[u] != child) {
                return true;
            }
        }
    }
    return false;
}
const int n = 1e5;
int visited[n];
vector <int> adj[n];
bool DetectCycle(int node){
    visited[node] = 1;
    for(int child : adj[node]){
        // visited[0] = unexplored
        // visited[1] = paused | cycle detected
        // visited[2] = done | continue
        if(!visited[child]){
            bool gotCycle = DetectCycle(child);
            if(gotCycle)
                return true;
        }
        else if(visited[child] == 1)
            return true;
    }
    visited[node] = 2;
    return false;
}
bool DetectCycle(int node, int parent = -1) {
    visited[node] = 1;  
    // 0 = unexplored, 1 = paused, 2 = done
    for (int child : adj[node]) {
        if (child == parent) continue;
        if (visited[child] == 1) return true;  
        if (visited[child] == 0) {
            if (DetectCycle(child, node)) return true;
        }
    }
    visited[node] = 2;
    return false;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool CycleExits = false;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool gotCycle = DetectCycle(i);
            if(gotCycle){
                CycleExits = true;
                break;
            }
        }
    }
    (CycleExits)?cout << "Cycle Exits" : cout << "Doesn't exits";
    
    bool CycleExists = false;
    for (int i = 1; i <= node; i++) {
        if (visited[i] == 0) {
            if (DetectCycle(i)) {
                CycleExists = true;
                break;
            }
        }
    }
    cout << (CycleExists ? "Cycle Exists" : "No Cycle") << endl; 
}
// Detect Cycle
const int N = 2e5;
vector <int> adj[N];
int parent[N], vis[N];
bool findcycle(int u, int eltern) {
    vis[u] = 1; parent[u] = eltern;
    for(int v : adj[u]) {
        if(v == eltern) continue;
        if(vis[v] == 1) return true;
        if(vis[v] == 0 && findcycle(v, u)) return true;
    }
    vis[u] = 2; return false;
}
int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cyclestart = -1;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            if(findcycle(i, -1)) {
                cyclestart = i; break;
            }
        }
    }
    if(cyclestart == -1) {
        cout << "IMPOSSIBLE"; return 0;
    }
    vector <int> path;
    int curr = cyclestart;
    while(true) {
        path.push_back(curr);
        curr = parent[curr];
        if(curr == cyclestart) {
            path.push_back(curr); break;
        }
    }
    cout << path.size() << " ";
}
using namespace std;
vector <int> parent;
int find(int x) {
    return parent[x] == -1 ? x : parent[x] = find(parent[x]); 
}
void union_set(int a, int b) {
    parent[find(a)] = find(b);
}
int main() {
    int n, m; cin >> n >> m;
    parent.assign(n, -1);
    bool hasCycle = false;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(find(u) == find(v)) {
            hasCycle = true; break;
        }
        union_set(u, v);
    }
    cout << (has_Cycle ? "Yes" : "No");
}
#include<bits/stdc++.h>
using namespace std;
#define row 12
#define col 10
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
bool issafe(int grid[row][col], int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col && grid[x][y] = 1;
}
int sortestpath(int grid[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 0) {
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < row && nj >= 0 && nj < col ) grid[ni][nj] = 0;
                }
            }
        }
    }
    queue <tuple <int, int, int>> q; // row, col, dist
    bool vis[row][col] = {0};
    for(int i = 0; i < row; i++) {
        if(mat[i][col - 1] == 1) {
            q.push({i, col - 1, 1});
            vis[i][col - 1] = 1;
        }
    }
    while(!q.empty()) {
        auto[x, y, d] = q.front(); q.pop();
        if(y == 0) return d;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[x];
            int ny = y + dy[y];
            if(issafe(grid, nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny, d + 1});
            }
        }
    }
    return -1;
}
#define ROW 9
#define COL 10
int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool valid(int r, int c) {
    return r>=0 && r<ROW && c>=0 && c<COL;
}

int bfs(int mat[ROW][COL], int sx, int sy, int dx, int dy) {
    if (!mat[sx][sy] || !mat[dx][dy]) return -1;
    
    bool vis[ROW][COL] = {0};
    queue<tuple<int,int,int>> q;  // r, c, dist
    
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;
    
    while (!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();
        
        if (r == dx && c == dy) return d;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + row[i];
            int nc = c + col[i];
            
            if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                q.push({nr, nc, d+1});
            }
        }
    }
    return -1;
}
bool safe(vector<vector<int>>& mat, vector<vector<bool>>& vis, int x, int y) {
    int r = mat.size(), c = mat[0].size();
    return x>=0 && x<r && y>=0 && y<c && mat[x][y] && !vis[x][y];
}

void dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis, int x, int y, int dx, int dy, int& ans, int d) {
    if (x == dx && y == dy) { ans = min(ans, d); return; }
    vis[x][y] = 1;
    
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    for (auto& dir : dirs)
        if (safe(mat, vis, x+dir[0], y+dir[1]))
            dfs(mat, vis, x+dir[0], y+dir[1], dx, dy, ans, d+1);
    
    vis[x][y] = 0;  // backtrack
}

int shortest(vector<vector<int>>& mat, int sx, int sy, int dx, int dy) {
    if (!mat[sx][sy] || !mat[dx][dy]) return -1;
    
    int r = mat.size(), c = mat[0].size();
    vector<vector<bool>> vis(r, vector<bool>(c, 0));
    int ans = INT_MAX;
    
    dfs(mat, vis, sx, sy, dx, dy, ans, 0);
    return ans == INT_MAX ? -1 : ans;
}
