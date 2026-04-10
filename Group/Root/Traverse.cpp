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
// BFS code on an adjacency matrix
const int x = 1e3;
int graph[x][x];
void BFS(int nd) {
    bool vis[nd] = {false};
    for(int i = 0; i < nd; i++) {
        if(vis[i]) continue;
        queue <int> q; q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for(int v = 0; v < nd; v++) {
                if(graph[u][v] == 1 && !vis[v]) {
                    vis[v] = true; q.push(v);
                }
            }
        }
    }
}
void Helper(int nd, int edg) {
    if(edg == 0) {
        for(int i = 0; i < nd; i++) cout << i << " ";
        return;
    }
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1;
    }
    BFS(nd);
}
// solves a maze pathfinding problem from point 'A' (start) to 'B' (end).
void traverse(int row, int col) {
    vector <string> grid(row);
    pair <int, int> src, dst;
    for(int i = 0; i < row; i++) {
        cin >> grid[i];
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 'A') src = {i, j};
            if(grid[i][j] == 'B') dst = {i, j};
        }
    }
    vector <vector <int>> dist(row, vector <int> (col, -1));
    queue <pair <int, int>> q; q.push(src);
    dist[src.first][src.second] = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && 
               grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int ans = dist[dst.first][dst.second];
    cout << (ans == -1 ? "No" : "Yes " + to_string(ans));
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
void DFsearch(int src){
     visited[src] = true;
     for(int child : adj[src]){
         if(!visited[child]) DFsearch(child);
     }
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
    /* vector <int> res;
    for(int i = 1; i <= nd; i++){
        if(!seen[i]){ 
           res.push_back(i); DFsearch(i);
        }
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " "; */
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
#include<bits/stdc++.h>
using namespace std;
// circle of 14 people labeled 0 to 13.each round, count 2 people and remove the 2nd one, continuing until only one is left.
// find the 0-th Idx where josephus should stand to survive
void josephusCircle(int n, int k) {
    list <int> l;
    for(int i = 0; i < n; i++) l.push_back(i);
    auto it = l.begin();
    while(l.size() > 1) {
        for(int i = 1; i < k; ++i) {
            ++it;
            if(it == l.end()) it = l.begin();
        }
        it = l.erase(it);
        if(it == l.end()) it = l.begin();
    }
    return l.front();
}
// selects k best‑placement cities as centers so that no city is “too far” from a center,
//and the maximum distance to the nearest center is as small as possible
int maxIdx(int *dist, int n) {
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] > dist[idx]) idx = i;
    } return idx;
}
void select(int n, int k, int grid[][4]) {
    int dist[n]; vector <int> center;
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    // city with max distance to closest center
    int farst = 0;
    for(int rnd = 0; rnd < k; ++rnd) {
        center.push_back(farst);
        for(int j = 0; j < n; ++j)
            dist[j] = min(dist[j], grid[farst][j]);
        farst = maxIdx(dist, n);
    } 
    cout << dist[farst] << endl;
    for(auto c : center) cout << c << " ";
}
// find the maximum number of packets that can be sent in parallel (in one time slot) from the senders 
//to the receivers, satisfying the one‑packet‑per‑sender‑and‑receiver constraint?”
const int r = 3, c = 4;
bool ismatch(int table[r][c], int u, bool vis[c], int receiver[c]) {
    // returns true if sender u can be matched to some receiver
    for(int v = 0; v < c; ++v) {
        if(table[u][v] > 0 !vis[v]) {
            vis[v] = true;
            if(receiver[v] < 0 || ismatch(table, receiver[v], vis, receiver)) {
                receiver[v] = u; return true;
            }
        }
    } return false;
}
void maxpacket(int table[r][c]) {
// Returns max number of packets that can be sent in 1 time slot
    int receiver[c]; memset(receiver, -1, sizeof(receiver));
    int res = 0
    for(int u = 0; u < r; u++) {
        bool vis[r];
        memset(vis, 0, sizeof(vis));
        if(ismatch(table, u, vis, receiver)) res++;
    }
    cout << res << endl;
    for(int v = 0; v < c; v++) {
        if(receiver[v] != -1) cout << receiver[v] + 1 << " " << v + 1 << endl;
    }
}
//There has nd cities, and edg roads between them.goal is to reach from city 1 to n.Print "YES" if  goal is possible else "NO"
const int maxi = 1e3;
bool visited[maxi]; vector <int> adj[maxi];
void DFS(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) DFS(v);
    }
}
void printpath(int nd, int edg) {
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= nd; i++) vis[i] = false;
    DFS(1);
    if(vis[nd]) cout << "Yes";
    else cout << "No";
}
//Count rooms
const int dx[]{0, 0, -1, 1};
const int dy[]{-1, 1, 0, 0};
void DFS(int x, int y, vector <vector <char> > &mp, vector <vector <bool> > &visited){
    visited[x][y] = true;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && nx < mp.size() && ny >= 0 && ny < mp[0].size() && !visited[nx][ny] && mp[nx][ny] == '.')
            DFS(nx, ny, mp, visited);
    }
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > > mp(n, vector <char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> mp[i][j];
    }
    int roomCnt = 0;
    vector <vector <bool> > visited(n, vector <bool> (m, false));
    for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[0].size(); j++){
            if(mp[i][j] == '.' && !visited[i][j]){
                DFS(i, j, mp, visited);
                roomCnt++;
            }
        }
    }
    cout << roomCnt;
}
//count the number of rooms and the length of the longest room.
//length of the longest room means that room which contain maximum floor
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int DFS(vector <vector <char > > &Building, int x, int y){
    if(x < 0 || x >= Building.size() || y < 0 || y >= Building[x].size() || Building[x][y] == '#')
        return 0;
    int size = 1;
    Building[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += DFS(Building, nx, ny);
    }
    return size;
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > >Building(n, vector <char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> Building[i][j];
    }
    int roomCnt = 0, LongestRoom = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(Building[i][j] == '.'){
                int roomSize = DFS(Building, i, j);
                roomCnt++;
                LongestRoom = max(LongestRoom, roomSize);
            }
        }
    }
    cout << roomCnt << " " << LongestRoom << '\n';
}
//count the number of connected components in an undirected graph
void addedg(vector <int> adj[], int u, int v) {
    adj[u].push_back(v); adj[v].push_back(u);
}
void DFS(vector <int> adj[], int u, vector <bool> vis) {
    vis[u] = true;
    for(int v = 0; v < adj[u].size(); v++) {
        if(!vis[adj[u][v]]) DFS(adj, adj[u][v], vis);
    }
}
void connected(int nd) {
    vector <int> adj[nd];
    addedg(adj, 0, 1); addedg(adj, 0, 2);
    addedg(adj, 0, 3); addedg(adj, 3, 4);
    vector <bool> vis(nd, false);
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(!vis[i]) {
            DFS(adj, i, vis); cnt++;
        }
    } cout << cnt;
}
//count the number of distinct clusters (connected components) of 1s in a 2D grid (forest)
typedef pair <int, int> pii;
void BFS(vector <vector <int>> forest, pii start, vector <vector <bool>> vis) {
    queue <pii> q; q.push(start);
    vis[start.first][start.second] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    while(!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < forest.size() && ny >= 0 && ny < forest[0].size() &&
                forest[nx][ny] == 1 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
void connect(vector <vector <int>> forest) { /*
    vector<vector<int>> forest = {
        {0,1,1,0,0}, {0,0,0,0,0},
        {0,0,0,0,0}, {0,0,0,0,1},
        {0,0,0,0,0}
    }; */
    int n = forest.size(), m = forest[0].size(), cnt = 0;
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(forest[i][j] == 1 && !vis[i][j]) {
                BFS(forest, {i, j}, vis); ++cnt;
            }
        }
    } cout << cnt;
}
// counts the number of separate rooms in a grid-based map
void cntroom(int r, int c) {
    int r, c; cin >> r >> c;
    vector <vector <int>> grid(r, vector <int> (c));
    for(int i = 0; i < r; i++) {
        string str; cin >> str;
        for(int j = 0; j < c; j++) 
            grid[i][j] = (str[j] == '#') ? -1 : 0;
    }
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    int rooms = 0;
    auto bfs = [&](auto&& self, int x, int y) -> void {
        queue<pair<int,int>> q;
        q.push({x,y}); vis[x][y] = true;
        
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && 
                    grid[nx][ny] != -1 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 0 && !vis[i][j]) {
                bfs(bfs, i, j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;
}
// count number of islands in a graph.
int countIslands(vector<vector<int>>& grid) {
    vector <vector <int>> grid = {
        {1,1,0,0,0}, {0,1,0,0,1}, {1,0,0,1,1}, 
        {0,0,0,0,0}, {1,0,1,0,1}};
    int n = grid.size(), m = grid[0].size();
    vector <vector<bool>> vis(n, vector<bool>(m, false));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int islands = 0;
    auto bfs = [&](auto&& self, int x, int y) -> void {
        queue<pair<int,int>> q;
        q.push({x, y}); vis[x][y] = true;
        
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1 && !vis[i][j]) {
                bfs(bfs, i, j);
                islands++;
            }
    
    return islands;
}
// Checks if there's a path from sender(7) to receiver(9) in an undirected graph using DFS
bool dfs(int u, int v, vector<vector<int>>& adj, vector<bool>& vis) {
    if (u == v) return true;
    vis[u] = true;
    for (int nei : adj[u])
        if (!vis[nei])
            if (dfs(nei, v, adj, vis))
                return true;
    
    return false;
}
int main() {
    vector<vector<int>> adj = {{}, {}, {}, {}, {}};
    vector<pair<int,int>> edges = {{2,9}, {7,2}, {7,9}, {9,5}};
    
    for (auto [u,v] : edges)
        adj[u].push_back(v);
    
    vector<bool> vis(10, false);
    cout << dfs(7, 9, adj, vis) << endl;  
}
