// count number of islands in a graph.
#include <bits/stdc++.h>
using namespace std;
// R x C matrix
#define R 5
#define C 5
// check if a given cell (u, v) can be included in DFS
bool isSafe(int mat[R][C], int i, int j, bool vis[R][C])
{
    return (i >= 0) && (i < R) && 
           (j >= 0) && (j < C) && 
           (mat[i][j] && !vis[i][j]);
}
void BFS(int mat[R][C], bool vis[R][C],
         int si, int sj)
{
    // These arrays are used to get row & column numbers of 8 neighbours of a given cell
    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Simple BFS first step, we enqueue source and mark it as visited
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    // Next step of BFS. We take out items one by one from queue and enqueue their unvisited adjacent
    while (!q.empty()) {
 
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        // Go through all 8 adjacent
        for (int k = 0; k < 8; k++) {
            if (isSafe(mat, i + row[k],
                       j + col[k], vis)) {
             vis[i + row[k]][j + col[k]] = true;
             q.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }
}
int countIslands(int mat[R][C])
{
    // Mark all cells as not visited
    bool vis[R][C];
    memset(vis, 0, sizeof(vis));
    // Call BFS for every unvisited vertex Whenever we see an univisted vertex, we increment res (number of islands) also.
    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] && !vis[i][j]) {
                BFS(mat, vis, i, j);
                res++;
            }
        }
    }
    return res;
}
int main()
{
    int mat[][C] = { { 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1 },{ 1, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 0 },{ 1, 0, 1, 0, 1 } };
    cout << countIslands(mat);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> adj[100000];
bool visited[100000];
 
bool dfs(int start, int end)
{
    if (start == end)
        return true;
    visited[start] = 1;
    for (auto x : adj[start]) {
        if (!visited[x])
            if (dfs(x, end))
                return true;
    }
    return false;
}
int main()
{
    int V = 4;
    vector<ll> members = { 2, 5, 7, 9 };
 
    int E = 4;
    vector<pair<ll, ll> > connections
        = { { 2, 9 }, { 7, 2 }, { 7, 9 }, { 9, 5 } };
 
    for (int i = 0; i < E; i++)
        adj[connections[i].first].push_back(
            connections[i].second);
 
    int sender = 7, receiver = 9;
 
    if (dfs(sender, receiver))
        cout << "1";
    else
        cout << "0";
 
    return 0;
}
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
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <vector <int>> edgeList(4);
    edgeList[0].push_back(0);
    edgeList[0].push_back(1);
    edgeList[1].push_back(2);
    edgeList[1].push_back(1);
    edgeList[2].push_back(1);
    edgeList[2].push_back(3);
    edgeList[3].push_back(2);
    edgeList[3].push_back(3);
    for(int i = 0; i < edgeList.size(); i++){
        for(int j = 0; j < edgeList[i].size(); j++)
            cout << edgeList[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    vector <vector <int> >edgeList 
    {{1, 2, 3}, {4, 5, 6}, 
    {7, 8, 9}, {10, 11, 12},};
    edgeList.push_back({13, 14, 15});
    for(int i = 0; i < edgeList.size(); i++){
        cout << edgeList[i][0] << " " << edgeList[i][1] << " " << edgeList[i][2] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    int node, edge; cin >> node >> edge;
    cout << "Maximum number of edges that can be added to maintain DAG is: " << (node * (node - 1) /2) - edge;
}
#include<bits/stdc++.h>
//find transpose of a graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}
void Display(vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void TransposeGraph(vector <int> transpose[], vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    vector <int> transpose[node];
    
    TransposeGraph(transpose, adj, node);
    //Display(adj, node);
    Display(transpose, node);
}
//Finds the representative of the set that i is an element of
using namespace std;
const int maxn = 1005;
int parent[maxn];
int Find(int i){
    if(parent[i] == i)
        return i;
    return Find(parent[i]);
}
int main(){
    for(int i = 0; i < maxn; i++)
        parent[i] = i;
    int rep1 = Find(1);
    int rep2 = Find(2);
    if(rep1 != rep2)
        parent[rep1] = rep2;
    int val = 1;
    int rep = Find(val);
    cout << "The representative of element " << val << " is: " << rep;
}
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m || 
        image[row][col] != oldColor || image[row][col] == newColor)
        return;
    
    // Change color
    image[row][col] = newColor;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        dfs(row + dr[i], col + dc[i], image, newColor, oldColor, n, m);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    /* int x = 1, y = 1, newC = 3;
    vector <vector <int>> res = floodFill(image, x, y, newC); */
    int n = image.size(), m = image[0].size();
    int oldColor = image[sr][sc];
    
    if (oldColor != newColor)
        dfs(sr, sc, image, newColor, oldColor, n, m);
    return image;
}
// Function that returns true if the given pixel is valid
bool isValid(int screen[][8], int m, int n, int x, int y,
             int prevC, int newC)
{
    if (x < 0 || x >= m || y < 0 || y >= n
        || screen[x][y] != prevC || screen[x][y] == newC)
        return false;
    return true;
}
void floodFill(int screen[][8], int x, int y, int prevC, int newC) {
   /* int m = screen.size(), n = screen[0].size();
    int x = 4, y = 4;
    int prevC = screen[x][y];
    // New color that has to be filled
    int newC = 3;
    floodFill(screen, m, n, x, y, prevC, newC); */
    queue<pair<int, int> > queue;
    pair<int, int> p(x, y);
    queue.push(p);
    // Color the pixel with the new color
    screen[x][y] = newC;
    while (queue.size() > 0) {
        pair<int, int> currPixel = queue.front();
        queue.pop();
 
        int posX = currPixel.first;
        int posY = currPixel.second;
        if (isValid(screen, m, n, posX + 1, posY, prevC,
                    newC)) {
            screen[posX + 1][posY] = newC;
            p.first = posX + 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX - 1, posY, prevC,
                    newC)) {
            screen[posX - 1][posY] = newC;
            p.first = posX - 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX, posY + 1, prevC,
                    newC)) {
            screen[posX][posY + 1] = newC;
            p.first = posX;
            p.second = posY + 1;
            queue.push(p);
        }
 
        if (isValid(screen, m, n, posX, posY - 1, prevC,
                    newC)) {
            screen[posX][posY - 1] = newC;
            p.first = posX;
            p.second = posY - 1;
            queue.push(p);
        }
    }
}
//find a path from start to end. You can walk left, right, up and down. First print "YES", if there is a path, and "NO" otherwise.
//If there is a path, print the length of the shortest such path
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int MAX_N = 100;  // Adjust this according to the size of your labyrinth
const char WALL = '#';
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char moves[] = "RULD";
int n, m;
char labyrinth[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != WALL;
}
void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == end) {
            return; 
        }
        for (int i = 0; i < 4; i++) {
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];

            if (is_valid(new_x, new_y) && dist[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                dist[new_x][new_y] = dist[cur.first][cur.second] + 1;
                parent[new_x][new_y] = cur;
            }
        }
    }
}

string find_shortest_path(pair<int, int> start, pair<int, int> end) {
    if (dist[end.first][end.second] == -1) {
        return "NO";
    }
    string path;
    while (end != start) {
        pair<int, int> prev = parent[end.first][end.second];
        for (int i = 0; i < 4; i++) {
            int new_x = end.first + dx[i];
            int new_y = end.second + dy[i];
            if (new_x == prev.first && new_y == prev.second) {
                path = moves[i] + path;
                break;
            }
        }
        end = prev;
    }
    return "YES\n" + to_string(dist[start.first][start.second]) + "\n" + path;
}
int main() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            dist[i][j] = -1;
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    bfs(start, end);
    cout << find_shortest_path(start, end) << endl;
    return 0;
}
//find the length of the largest region in boolean 2D-matrix
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 & not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL)
           && (M[row][col] && !visited[row][col]);
}
// DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,bool visited[][COL], int& count)
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Mark this cell as visited
    visited[row][col] = true;
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k) {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],visited)) {
            // Increment region length by one
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}
//returns largest  length region of a given boolean 2D matrix
int largestRegion(int M[][COL])
{
    // Make a bool array to mark visited cells. Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    // Initialize result as 0 and travesle through the all cells of given matrix
    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new region found
                int count = 1;
                DFS(M, i, j, visited, count);
                // maximum region
                result = max(result, count);
            }
        }
    }
    return result;
}
int main()
{
    int M[][COL] = { { 0, 0, 1, 1, 0 },
     { 1, 0, 1, 1, 0 },
     { 0, 1, 0, 0, 0 },
     { 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//find unit area of the largest region of 1s.
int largestRegion(vector<vector<int> >& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // creating a queue that will help in bfs traversal
    queue<pair<int, int> > q;
    int area = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if the value at any particular cell is 1 then
            // from here we need to do the BFS traversal
            if (grid[i][j] == 1) {
                ans = 0;
                // pushing the pair<i,j> in the queue
                q.push(make_pair(i, j));
                // marking the value 1 to -1 so that we
                // don't again push this cell in the queue
                grid[i][j] = -1;
                while (!q.empty()) {
 
                    pair<int, int> t = q.front();
                    q.pop();
                    ans++;
                    int x = t.first;
                    int y = t.second;
                    // now we will check in all 8 directions
                    if (x + 1 < m) {
                        if (grid[x + 1][y] == 1) {
                            q.push(make_pair(x + 1, y));
                            grid[x + 1][y] = -1;
                        }
                    }
                    if (x - 1 >= 0) {
                        if (grid[x - 1][y] == 1) {
                            q.push(make_pair(x - 1, y));
                            grid[x - 1][y] = -1;
                        }
                    }
                    if (y + 1 < n) {
                        if (grid[x][y + 1] == 1) {
                            q.push(make_pair(x, y + 1));
                            grid[x][y + 1] = -1;
                        }
                    }
                    if (y - 1 >= 0) {
                        if (grid[x][y - 1] == 1) {
                            q.push(make_pair(x, y - 1));
                            grid[x][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y + 1 < n) {
                        if (grid[x + 1][y + 1] == 1) {
                            q.push(make_pair(x + 1, y + 1));
                            grid[x + 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y + 1 < n) {
                        if (grid[x - 1][y + 1] == 1) {
                            q.push(make_pair(x - 1, y + 1));
                            grid[x - 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        if (grid[x - 1][y - 1] == 1) {
                            q.push(make_pair(x - 1, y - 1));
                            grid[x - 1][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y - 1 >= 0) {
                        if (grid[x + 1][y - 1] == 1) {
                            q.push(make_pair(x + 1, y - 1));
                            grid[x + 1][y - 1] = -1;
                        }
                    }
                }
 
                area = max(ans, area);
                ans = 0;
            }
        }
    }
    return area;
}
int main()
{
    vector<vector<int> > M = 
    { { 0, 0, 1, 1, 0 },{ 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },{ 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, int M, int N, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (dp[x][y] != -1)
        return dp[x][y];
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        
        if (X < 0 || X >= N || Y < 0 || Y >= M)
            continue;
        if (mat[x][y] >= mat[X][Y])
            continue;
        ans = max(ans, 1 + dfs(X, Y, M, N, mat, dp));
    }
    return dp[x][y] = ans;
}

int LongestIncrPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0; 
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j, m, n, matrix, dp));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Length of the longest increasing path: " << LongestIncrPath(matrix) << endl;
    return 0;
}
//find longest lath in DAG.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent_list[N];
int dp[N];

int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}
//You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
//Your task is to walk from room 1 to room n. What is the maximum score you can get?
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_N = 105;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> tunnels[MAX_N];
int dp[MAX_N][MAX_N];

int maxScore(int curRoom, int remainingRooms) {
    if (remainingRooms == 0) {
        if (curRoom == n) {
            return 0;
        } else {
            return -INF; // It's not possible to reach room n in the given number of moves.
        }
    }
    if (dp[curRoom][remainingRooms] != -1) {
        return dp[curRoom][remainingRooms];
    }
    int maxScore = -INF;
    for (auto tunnel : tunnels[curRoom]) {
        int nextRoom = tunnel.first;
        int score = tunnel.second;

        int result = maxScore(nextRoom, remainingRooms - 1);
        if (result != -INF) {
            maxScore = max(maxScore, result + score);
        }
    }
    return dp[curRoom][remainingRooms] = maxScore;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        tunnels[u].push_back({v, x});
    }
    memset(dp, -1, sizeof(dp));
    int result = maxScore(1, n);
    if (result == -INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
//Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
//If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route and path.print all valid solution.
//If there are no routes, print "IMPOSSIBLE".
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1005;  
// Maximum number of computers
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> path;
bool found = false;
void dfs(int u, int destination) {
    if (found) return;
    visited[u] = true;
    path.push_back(u);

    if (u == destination) {
        found = true;
        cout << path.size() << " ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, destination);
        }
    }
    path.pop_back();
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    // Build the graph
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int Uolevi, Maija;
    cin >> Uolevi >> Maija;
    dfs(Uolevi, Maija);
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int solve(int n, int m, vector<vector<char>>& grid, vector<vector<ll>>& dp) {
    if (n < 0 || m < 0 || grid[n][m] == '#') {
        return 0;
    }
    if (n == 0 && m == 0) {
        return 1;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    int ans = 0;
    if (n > 0) {
        ans += solve(n - 1, m, grid, dp);
    }
    if (m > 0) {
        ans += solve(n, m - 1, grid, dp);
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, -1));

    cout << solve(n - 1, m - 1, grid, dp) << endl;
    return 0;
}
//find out minimum cost path to connect all the cities
#include <bits/stdc++.h>
using namespace std;
// Function to find out minimum valued node among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
  int mini = numeric_limits<int>::max();
  int mini_index;
 
  // Loop through all the values of the nodes which are not yet included in MST and find
  // the minimum valued one.
    for (int i = 0; i < n; i++) {
        if (mstset[i] == false && keyval[i] < mini) {
            mini = keyval[i], mini_index = i;
        }
    }
  return mini_index;
}
// Function to find out the MST and the cost of the MST.
void findcost(int n, vector<vector<int>> city) {
    int parent[n];
    int keyval[n];
 
  // Boolean Array to hold bool values whether
  // a node is included in MST or not.
  bool mstset[n];
 
  // Set all the key values to infinite and none of the nodes is included in MST.
    for (int i = 0; i < n; i++) {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }
 
    // Start to find the MST from node 0.Parent of node 0 is none so set -1.
    // key value or minimum cost to reach 0th node from 0th node is 0.
    parent[0] = -1;
    keyval[0] = 0;
 
    // Find the rest n-1 nodes of MST
    for (int i = 0; i < n - 1; i++)
    {
        // First find out the minimum node among the nodes which are not yet included in MST.
        int u = minnode(n, keyval, mstset);
 
        // Now the uth node is included in MST.
    mstset[u] = true;
 
        // Update the values of neighbor nodes of u which are not yet included in MST.
    for (int v = 0; v < n; v++) {
 
        if (city[u][v] && mstset[v] == false && city[u][v] < keyval[v]) 
        {
            keyval[v] = city[u][v];
            parent[v] = u;
        }
    }
  }
  // Find out the cost by adding
  // the edge values of MST.
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += city[parent[i]][i];
    cout << cost << endl;
}
int main() {
  int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},{1, 0, 5, 0, 7},
    {2, 5, 0, 6, 0},{3, 0, 6, 0, 0}, {4, 7, 0, 0, 0}};
  findcost(n1, city1);

  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0}, 
  {1, 0, 1, 0, 0, 0},{1, 1, 0, 0, 0, 0},   
    {100, 0, 0, 0, 2, 2},{0, 0, 0, 2, 0, 2},  
    {0, 0, 0, 2, 2, 0}};
  findcost(n2, city2);
  return 0;
}
// finding minimum cut using Ford-Fulkerson
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
#define V 6
//Returns true if there is a path from source 's' to sink 't' in residual graph. Also fills parent[] to store the path
int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return true, else false
    return (visited[t] == true);
}
 
// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
// Prints the minimum s-t cut
void minCut(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities in residual graph
    int rGraph[V][V];
    // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V]; 
    // This array is filled by BFS and to store path
 
    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // update residual capacities of the edges and reverse edges along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    // Flow is maximum now, find vertices reachable from s
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
 
    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout << i << " - " << j << endl;
 
    return;
}
int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}};
    minCut(graph, 0, 5);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// find the minimum Groups
int dfsheight(int u, int *vis, vector <int> &adj) {
    vis[u] = 1; int maxht = 0;
    for(auto &v : adj[u]) {
        if(vis[v] == 0) maxht = max(maxht, 1 + dfsheight(v, vis, adj));
    }
    return maxht;
}
int mingrp(vector <int> adj[], int nd) {
    int vis[nd + 1] = {0};
    int grp = INT_MIN;
    for(int i = 1; i <= nd; i++) {
        if(vis[i] == 0) {
            int ht = dfsheight(i, vis, adj);
            grp = max(ht, grp);
        }
    }
    return grp;
}
int minGroups(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    int maxHeight = 0;
    
    function<int(int)> dfsHeight = [&](int node) -> int {
        visited[node] = true;
        int height = 0;
        
        for(int child : adj[node]) {
            if(!visited[child]) {
                height = max(height, 1 + dfsHeight(child));
            }
        }
        return height;
    };
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            maxHeight = max(maxHeight, dfsHeight(i));
        }
    }
    return maxHeight;
}
// M-Coloring problem solver using backtracking
bool issafe(int src, vector <vector <int>> &grid, vector <int> &color, int m) {
    for(int v = 0; v < graph.size(); ++v) {
        if(graph[src][v] && color[v] == m) return false;
    }
    return true;
}
bool graphcolor(int src, vector <vector <int>> &grid, vector <int> &color, int m) {
    // m = number of color
    int n = grid.size(); if(src == n) return true;
    for(int i = 1; i <= m; i++) {
        if(issafe(src, grid, color, i)) {
            color[src] = i;
            if(graphcolor(src + 1, grid, color, m)) return true;
            color[src] = 0;
        }
    }
    return false;
}
// Finds maximum bipartite matching (maximum number of applicants who can get distinct jobs).
bool dfs(int u, const vector<vector<int>>& graph, vector<int>& matchR, vector<bool>& seen) {
    for(int v : graph[u]) {
        if(!seen[v]) {
            seen[v] = true;
            // Free job or recurse through current assignee
            if(matchR[v] == -1 || dfs(matchR[v], graph, matchR, seen)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(vector <vector <int>> grid) {
    // m applicants * n jobs
    int m = grid.size(), n = grid[0].size();
    vector <int> matchR(n, -1); // job applicants
    int matching = 0;
    for(int u = 0; u < m; u++) {
        vector <bool> vis(n, false);
        if(dfs(u, grid, matchR, vis)) matching++;
    }
    return matching;
}
// count walks from u to v with exactly k edges
#define nd 4
int countwalks(int graph[][nd], int u, int v, int k) {
    int count[nd][nd][k + 1];
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < nd; i++) {
            for (int j = 0; j < nd; j++) {
                count[i][j][e] = 0;
                if (e == 0 && i == j) count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
                if (e > 1) {
                    for (int a = 0; a < nd; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e - 1];
                }
            }
        }
    }
    return count[u][v][k];
}
int cntwalks(int graph[][nd], int u, int v, int k) {
    if(k == 0 && u == v) return 1;
    if(k == 1 && graph[u][v]) return 1;
    if(k <= 0) return 0;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] == 1) cnt += cntwalks(graph, i, v, k - 1);
    }
    return cnt;
}
//count walks from u to v with exactly k edges
int CountWalks(int graph[][node], int u, int v, int k){
    if(k == 0 && u == v)
        return 1;
    if(k == 1 && graph[u][v])
        return 1;
    if(k <= 0)
        return 0;
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(graph[u][i] == 1)
            cnt += CountWalks(graph,i, v, k - 1);
    }
    return cnt;
}
int main(){
    int graph[node][node] ={ { 0, 1, 1, 1 },{ 0, 0, 0, 1 },
    { 0, 0, 0, 1 },{ 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v, k);
}
//count walks from u to v with exactly k edges
using namespace std;
#define node 4
int CountWalks(int graph[][node], int u, int v, int k){
    // value count[i][j][e] will store count of possible walks from i to j with exactly k edges
    int cnt[node][node][k + 1];
    for(int e = 0; e <= k; e++){
        for(int i = 0; i < node; i++){
            for(int j = 0; j < node; j++){
                cnt[i][j][e] = 0;
                if(e == 0 && i == j)
                    cnt[i][j][e] = 1;
                if(e == 1 && graph[i][j])
                    cnt[i][j][e] = 1;
                if(e > 1){
                    // adjacent of source i
                    for(int a = 0; a < node; a++){
                        if(graph[i][a] == 1)
                        cnt[i][j][e] += cnt[a][j][e - 1];
                    }
                }
            }
        }
    }
    return cnt[u][v][k];
}
int main(){
    int graph[node][node] =
    { { 0, 1, 1, 1 },{ 0, 0, 0, 1 }
    ,{ 0, 0, 0, 1 }, { 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v , k);
}
// Check if Tree A is mirror image of Tree B
int mirrorTree(int *arr, int *ray) {
    int n = 3, e = 2;
    vector <stack <int>> st; vector <queue <int>> qe;
    for(int i = 0; i <= n; i++) {
        st.push(stack <int> ());
        queue <int> q; qe.push(q);
    }
    for(int i = 0; i < 2 * e; i += 2) {
        st[arr[i]].push(arr[i + 1]);
        qe[ray[i]].push(ray[i + 1]);
    }
    for(int i = 1; i <= n; i++) {
        while(!st[i].empty() && !qe[i].empty()) {
            int x = st[i].top(); st[i].pop();
            int y = qe[i].top(); qe[i].pop();
            if(x != y) return 0;
        }
    }
    return 1;
}
int mirrorTree(int *u1, int *v1, int *u2, int *v2) {
    int n = sizeof(u1) / sizeof(u1[0]);
    unordered_map <int, stack <int>> mp;
    for(int i = 0; i < n; i++) mp[u1[i]].push_back(v1[i]);
    for(int i = 0; i < n; i++) {
        if(mp[u2[i]].top() != v2[i]) return 0;
        mp[u2[i]].pop();
    }
    return 1;
}
// Minimum Knight Moves on chessboard
int minknightmove(int *start, int *target, int n) {
    vector <vector <bool>> vis(n + 1, vector <bool> (n + 1));
    queue <tuple <int, int, int>> q; // x, y, steps
    q.push({start[0], start[1], 0});
    vis[start[0]][start[1]] = 1;
    while(!q.empty()) {
        auto [x, y, steps] = q.front(); q.pop();
        if(x == target[0] && y == target[1]) return steps;
            
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1;
}
// find the longest distance from source to destination with at most K intermediate nodes

int longestpath(int n, vector <vector <int>> &edges, int src, int dst, int k) {
    vector <vector <pair <int, int>>> adj(n);
    for(auto &edges : edg) 
        adj[edg[0]].emplace_back(edg[1], edg[2]);
    queue <pair <int, int>> q; // {src, dist}
    unordered_map <int, int> dist;
    q.push({src, 0}), dist[src] = 0;
    int level = 0;
    while(!q.empty() && level <= k + 1) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            auto [u, d] = q.front(); q.pop();
            if(u == dst) {}
            for(auto [v, w] : adj[u]) {
                int newDist = d + w;
                if(dist.find(v) == dist.end() || newDist > dist[v]) {
                    dist[v] = newDist;
                    q.push({v, newDist});
                }
            }
        }
        level++;
    } 
    return dist[dst];
}
#define x 256
void firstunqalt() {
    int queue[x], front = -1, rear = -1, nextpos = 0;
    bool dup[x] = {false};
    string ing = "geeksforgeeksandgeeksquizfor";
    for(int i = 0; str[i]; i++) {
        char ch = str[i];
        if(!dup[ch]) {
            if(front == -1) front = rear = 0;
            else rear = (rear + 1) % x;
            queue[rear] = ch; dup[ch] = false;
        }
        else {
            int pos = (front + nextpos) % x;
            while(pos != (rear + 1) % x) {
                if(queue[pos] == ch) {
                    // shift val for remove
                    for(int j = pos; j != rear; j = (j + 1) % x)
                        queue[j] = queue[(j + 1) % x];
                    rear = (rear - 1 + x) % x;
                    break;
                }
                pos = (pos + 1) % x;
            }
        }
    }
    if (front != -1 && front <= rear)
            cout << queue[front] << endl;
    else
        cout << "No non-repeating character so far";
}
// printing Minimum Cost Simple Path between two given nodes
int mincostpath(int u, int dest, bool *vis, int graph[][nd]) {
    if(u == dest) return 0;
    vis[u] = 1; int res = INT_MAX;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] != INT_MAX && !vis[i]) {
            int curr = mincostpath(i, dest, vis, graph);
            if(curr < INT_MAX)
                res = min(res, graph[u][i] + curr)
        }
    }
    vis[u] = 0;
    return res;
}

int minCost = INT_MAX;
void findMinPath(unordered_map<int, vector<pair<int,int>>>& graph,
     vector<bool>& visited, vector<int>& required,
    int curr, int dest, int cost) {
    if(curr == dest) {
        bool allVisited = true;
        for(int node : required) {
            if(!visited[node]) {
                allVisited = false;
                break;
            }
        }
        if(allVisited) minCost = min(minCost, cost);
        return;
    }
    visited[curr] = true;
    for(auto [next, weight] : graph[curr]) {
        if(!visited[next]) {
            findMinPath(graph, visited, required, next, dest, cost + weight);
        }
    }
    visited[curr] = false; 
}
int main() {
    unordered_map<int, vector<pair<int,int>>> graph = {
        {0, {{1,2},{2,3},{3,2}}},
        {1, {{4,4},{0,1}}},
        {2, {{4,5},{5,6}}},
        {3, {{5,7},{0,1}}},
        {4, {{6,4}}},
        {5, {{6,2}}},
        {6, {{7,11}}}
    };
    int src = 0, dst = 6;
    vector<int> required = {2, 4};
    vector<bool> visited(8, false);
    findMinPath(graph, visited, required, src, dst, 0);
    cout << (minCost == INT_MAX ? -1 : minCost) << endl;
}
int minDistance(vector<string>& grid) {
    // vector<string> grid = {
        "0*s", "*0**", "0***", "d***" };
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<tuple<int,int,int>> q;  // r, c, dist
    
    // Find start position
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 's') {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }
    
    int dr[] = {-1, 1, 0, 0};  // up, down, left, right
    int dc[] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [r, c, dist] = q.front(); q.pop();
        
        if(grid[r][c] == 'd') return dist;
        
        // 4 directions
        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
               grid[nr][nc] != '0' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }
    return -1;
}
//find a path from start to end. You can walk left, right, up and down. First print "YES", if there is a path, and "NO" otherwise.
//If there is a path, print the length of the shortest such path
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int MAX_N = 100;  // Adjust this according to the size of your labyrinth
const char WALL = '#';
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char moves[] = "RULD";
int n, m;
char labyrinth[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != WALL;
}
void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == end) {
            return; 
        }
        for (int i = 0; i < 4; i++) {
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];

            if (is_valid(new_x, new_y) && dist[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                dist[new_x][new_y] = dist[cur.first][cur.second] + 1;
                parent[new_x][new_y] = cur;
            }
        }
    }
}

string find_shortest_path(pair<int, int> start, pair<int, int> end) {
    if (dist[end.first][end.second] == -1) {
        return "NO";
    }
    string path;
    while (end != start) {
        pair<int, int> prev = parent[end.first][end.second];
        for (int i = 0; i < 4; i++) {
            int new_x = end.first + dx[i];
            int new_y = end.second + dy[i];
            if (new_x == prev.first && new_y == prev.second) {
                path = moves[i] + path;
                break;
            }
        }
        end = prev;
    }
    return "YES\n" + to_string(dist[start.first][start.second]) + "\n" + path;
}
int main() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            dist[i][j] = -1;
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    bfs(start, end);
    cout << find_shortest_path(start, end) << endl;
    return 0;
}
//find the length of the largest region in boolean 2D-matrix
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 & not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL)
           && (M[row][col] && !visited[row][col]);
}
// DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,bool visited[][COL], int& count)
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Mark this cell as visited
    visited[row][col] = true;
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k) {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],visited)) {
            // Increment region length by one
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}
//returns largest  length region of a given boolean 2D matrix
int largestRegion(int M[][COL])
{
    // Make a bool array to mark visited cells. Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    // Initialize result as 0 and travesle through the all cells of given matrix
    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new region found
                int count = 1;
                DFS(M, i, j, visited, count);
                // maximum region
                result = max(result, count);
            }
        }
    }
    return result;
}
int main()
{
    int M[][COL] = { { 0, 0, 1, 1, 0 },
     { 1, 0, 1, 1, 0 },
     { 0, 1, 0, 0, 0 },
     { 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//find unit area of the largest region of 1s.
int largestRegion(vector<vector<int> >& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // creating a queue that will help in bfs traversal
    queue<pair<int, int> > q;
    int area = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if the value at any particular cell is 1 then
            // from here we need to do the BFS traversal
            if (grid[i][j] == 1) {
                ans = 0;
                // pushing the pair<i,j> in the queue
                q.push(make_pair(i, j));
                // marking the value 1 to -1 so that we
                // don't again push this cell in the queue
                grid[i][j] = -1;
                while (!q.empty()) {
 
                    pair<int, int> t = q.front();
                    q.pop();
                    ans++;
                    int x = t.first;
                    int y = t.second;
                    // now we will check in all 8 directions
                    if (x + 1 < m) {
                        if (grid[x + 1][y] == 1) {
                            q.push(make_pair(x + 1, y));
                            grid[x + 1][y] = -1;
                        }
                    }
                    if (x - 1 >= 0) {
                        if (grid[x - 1][y] == 1) {
                            q.push(make_pair(x - 1, y));
                            grid[x - 1][y] = -1;
                        }
                    }
                    if (y + 1 < n) {
                        if (grid[x][y + 1] == 1) {
                            q.push(make_pair(x, y + 1));
                            grid[x][y + 1] = -1;
                        }
                    }
                    if (y - 1 >= 0) {
                        if (grid[x][y - 1] == 1) {
                            q.push(make_pair(x, y - 1));
                            grid[x][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y + 1 < n) {
                        if (grid[x + 1][y + 1] == 1) {
                            q.push(make_pair(x + 1, y + 1));
                            grid[x + 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y + 1 < n) {
                        if (grid[x - 1][y + 1] == 1) {
                            q.push(make_pair(x - 1, y + 1));
                            grid[x - 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        if (grid[x - 1][y - 1] == 1) {
                            q.push(make_pair(x - 1, y - 1));
                            grid[x - 1][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y - 1 >= 0) {
                        if (grid[x + 1][y - 1] == 1) {
                            q.push(make_pair(x + 1, y - 1));
                            grid[x + 1][y - 1] = -1;
                        }
                    }
                }
 
                area = max(ans, area);
                ans = 0;
            }
        }
    }
    return area;
}
int main()
{
    vector<vector<int> > M = 
    { { 0, 0, 1, 1, 0 },{ 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },{ 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, int M, int N, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (dp[x][y] != -1)
        return dp[x][y];
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        
        if (X < 0 || X >= N || Y < 0 || Y >= M)
            continue;
        if (mat[x][y] >= mat[X][Y])
            continue;
        ans = max(ans, 1 + dfs(X, Y, M, N, mat, dp));
    }
    return dp[x][y] = ans;
}

int LongestIncrPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0; 
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j, m, n, matrix, dp));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Length of the longest increasing path: " << LongestIncrPath(matrix) << endl;
    return 0;
}
//find longest lath in DAG.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent_list[N];
int dp[N];

int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}
//find shortest distance in a multistage graph.
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 8
int shortestDist(int graph[N][N]){
    int dist[N]; dist[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        dist[i] = INF;
        for(int j = i; j < N; j++){
            if(graph[i][j] == INF)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}
int main(){
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
    cout << shortestDist(graph);
}
using namespace std;
//find the shortest path using multistage graph
using ump = pair <int, unordered_map<int, int> >;
int shortestPath(vector <ump> &graph, int src, int trg, int k){
    vector <int> dist(graph.size(), INT_MAX);
    dist[trg] = 0;
    //Loop over each stage from k-1 to 1
    for(int i = k - 1; i >= 0; i--){
        //Loop over all vertices in the current stage
        for(int u = 0; u < graph.size(); u++){
            if(graph[u].first != i)
                continue;
            for(const auto &v: graph[u].second){
                if(dist[v.first] != INT_MAX)
                     dist[u] = min(dist[u], v.second + dist[v.first]);
            }
        }
    }
    //Return the shortest path distance from source to target
    return dist[src];
}
int main(){
    //Each stage represented a level of nodes
    vector <ump> graph = {
        {0, {{1, 2}, {2, 9}}},
        {1, {{3, 6}, {4, 3}}},  
        {2, {{4, 1}}},          
        {3, {{5, 7}, {6, 2}}},  
        {4, {{5, 1}, {6, 5}}},  
        {5, {{7, 4}}},          
        {6, {{7, 6}}},          
        {7, {}}
    };
    cout << shortestPath(graph, 0, 7, 4) << " ";
}
#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
int level[n];
int parent[n];
vector<int> adj_list[n];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    
    parent[src]=-1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                parent[adj_node]=head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int nodes, edges; // Changed variable name from "node" to "nodes" and "edge" to "edges".
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    bfs(src);

    vector<int>path;
    int dst=node;
    if(visited[dst]==0)
    {
        cout<<"Impossible";
    }
    cout<<level[dst]<<"\n";
    int selected_node=dst;
    while(true)
    {
        path.push_back(selected_node);
        if(selected_node==src)
        {
            break;
        }
        selecte_node=parent[src];
    }
    reverse(path.begin(),path.end())
    for(int node:path)
    {
        cout<<node<<" ";
    }

    return 0;
}
// find the path in Peterson graph
#include <bits/stdc++.h>
using namespace std;
// path to be checked 
char S[100005]; 
// adjacency matrix. 
bool adj[10][10];
// resulted path - way 
char result[100005];
// we are applying BFS here
bool findthepath(char* S, int v)
{
    result[0] = v + '0';
    for (int i = 1; S[i]; i++) {
        // first traverse the outer graph
        if (adj[v][S[i] - 'A'] || adj[S[i] -'A'][v]) {
            v = S[i] - 'A';
        }
        // then traverse the inner graph
        else if (adj[v][S[i] - 'A' + 5] || 
         adj[S[i] - 'A' + 5][v]) {
            v = S[i] - 'A' + 5;
        }
        // if the condition failed to satisfy return false
        else
            return false;
        result[i] = v + '0';
    }
    return true;
}
int main()
{
    // here we have used adjacency matrix to make connections between the connected nodes
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = 
    adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] =
    adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] =
    adj[9][6] = adj[6][8] = adj[8][5] = true;
    // path to be checked
    char S[] = "ABB";
    if (findthepath(S, S[0] - 'A') || 
        findthepath(S, S[0] - 'A' + 5)) {
        cout << result;
    } else
        cout << "-1";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, int E, int edges[][3])
{   
    // Create an adjacency list representation of the graph
    vector<vector<int>> adj[V];
    // Fill the adjacency list with edges and their weights
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    // Create a priority queue to store edges with their weights
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Create a visited array to keep track of visited vertices
    vector<bool> visited(V, false);
    // Variable to store the result (sum of edge weights)
    int res = 0;
    // Start with vertex 0
    pq.push({0, 0});
    // Perform Prim's algorithm to find the Minimum Spanning Tree
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first; 
        // Weight of the edge
        int u = p.second;  
        // Vertex connected to the edge
        if(visited[u] == true){
            continue;  // Skip if the vertex is already visited
        }
        res += wt; 
        // Add the edge weight to the result
        visited[u] = true;
        for(auto v : adj[u]){
            // v[0] represents the vertex and v[1] represents the edge weight
            if(visited[v[0]] == false){
                pq.push({v[1], v[0]});  // Add the adjacent edge to the priority queue
            }
        }
    }
    return res;
    //Return the sum of edge weights of the Minimum Spanning Tree
}
int main()
{
    int graph[][3] = {{0, 1, 5},
    {1, 2, 3}, {0, 2, 1}};
    cout << spanningTree(3, 3, graph) << endl;
    return 0;
}
// Prim's Minimum Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;
#define V 5
//  find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
// function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
    // Key values used to pick minimum weight edge in cut
    int key[V];
    // To represent set of vertices included in MST
    bool mstSet[V];
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include 1st vertex in MST. Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    // First node is always root of MST
    parent[0] = -1;
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 },
     { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}
// Binary Search for Rational Numbers without using floating point arithmetic
#include <iostream>
using namespace std;
struct Rational{
    int p, q;
};
// Ucompare two  Rational numbers 'a' and 'b'. It returns
// 0 --> When 'a' and 'b' are same
// 1 --> When 'a' is greater
//-1 --> When 'b' is greater
int compare(struct Rational a, struct Rational b)
{
    // If a/b == c/d then a*d = b*c:
    if (a.p * b.q == a.q * b.p)
        return 0;
    if (a.p * b.q > a.q * b.p)
        return 1;
    return -1;
}
// Returns index of x in arr[l..r] if it is present, else returns -1. It mainly uses Binary Search.
int binarySearch(struct Rational arr[], int l, int r,
                 struct Rational x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (compare(arr[mid], x) == 0) 
            return mid;
        // If element is smaller than mid, then it can only be present in left subarray
        if (compare(arr[mid], x) > 0)
            return binarySearch(arr, l, mid - 1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
    struct Rational arr[] = { { 1, 5 }, { 2, 3 }, 
    { 3, 2 }, { 13, 2 } };
    struct Rational x = { 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    cout << "Element found at index "
         << binarySearch(arr, 0, n - 1, x);
}
#include<bits/stdc++.h>
using namespace std;
// Min path sum from top-left to bottom-right (right/down moves only)
int minpathsum(vector <vector <int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <int>> dp(n, vector <int> (m, 0));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for(int i = 1; i < n; i++) 
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) 
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
    return dp[n - 1][m - 1];
}
// Count right/down paths from (0,0) to (n - 1, n - 1) avoiding traps.
int cntpath(int n, vector <vector <int>> &trap) {
    vector <vector <int>> dp(n, vector <int>(n, 0));
    for(int i = 1; i < n; i++) dp[i][j] = trap[i][0] ? 0 : dp[i - 1][0];
    for(int j = 1; j < n; j++) dp[i][j] = trap[0][j] ? 0 : dp[0][j - 1];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!trap[i][j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    } /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(trap[i][j]) dp[i][j] = 0;
            else if(i || j) dp[i][j] = ((i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0)) % 10000;
        }
    } */
    return dp[n - 1][n - 1];
}
// Given rival pairs (Lykan vs Vampire fights), find maximum number that can be all Vampires OR all Lykans
bool dfs(int u, vector <vector <int>> &adj, vector <int> &match, vector <bool> &vis) {
    for(int v : adj[u]) {
        if(!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v], adj, match, vis)) {
                match[u] = v; match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxfighterteam(int n, vector <pair <int, int>> &fight) { /*
    int n; cin >> n;
    vector <pair <int, int>> fight(n);
    for(int i = 0; i < n; i++) cin >> fight[i].first >> fight[i].second;
    cout << maxfighterteam(n, flight); */
    int num = *max_element(fight.begin(), fight.end(), [](auto &a, auto &b) {
        return max(a.first, a.second) < max(b.first, b.second); }) + 1;
    vector <vector <int> adj(num);
    for(auto [u, v] : fight) {
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector <int> match(num, -1);
    int matching = 0;
    for(int i = 0; i < num; i++) {
        if(match[i] == -1) {
            vector <bool> vis(num, false);
            if(dfs(i, adj, match, vis)) matching++;
        }
    }
    return num - matching;
}
//return the len of the longest increasing path in matrix
int dfs(vector <vector <int>> &grid, int x, int y, vector <vector <int>> &tmp) {
    if(tmp[x][y] != -1) return tmp[x][y];
    int maxpath = 1;
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(const auto &dir : direct) {
        int nx = x + dir[0], ny = y + dir[1];
        if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() 
           && grid[nx][ny] > grid[x][y])
            maxPath = max(maxPath, 1 + dfs(grid, nx, ny, tmp));
    }
    tmp[x][y] = maxpath;
    return maxpath;
}
int pathIncreasing(vector <vector <int>> grid) {
    int n = grid.size(), m = grid[0].size();
    if(grid.empty() || grid[0].empty()) return 0;
    vector <vector <int>> tmp(n, vector <int> (m, -1));
    int maxpath = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            maxpath = max(maxpath, dfs(grid, i, j, tmp));
    }
    return maxpath;
}
//rot all oranges when you can move in all the four direction from a rotten orange
#include <bits/stdc++.h>
using namespace std;
const int R = 3;
const int C = 5;
// Check if i, j is under the array limits of row and column
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}
int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // Rot all other oranges present at(i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j)
                        && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1)
                        && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j)
                        && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1)
                        && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }
        // if no rotten orange found it means all oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
 
            // if any orange is found to be not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }
    // Because initial value for a rotten orange was 2
    return no - 2;
}
int main()
{
    int v[R][C] = { { 2, 1, 0, 2, 1 },
    { 1, 0, 1, 2, 1 },{ 1, 0, 0, 2, 1 } };
    cout << "Max time incurred: " << rotOranges(v);
    return 0;
}
//find minimum time required to make all oranges rotten
#include <bits/stdc++.h>
#define R 3
#define C 5
using namespace std;
// This function finds if it is possible to rot all oranges or not.
//If possible, then it returns minimum time required to rot all, otherwise returns -1
int rotOranges(vector<vector<int> >& grid)
{
    int n = grid.size();// row size
    int m = grid[0].size();
    // column size
    // delrow and delcol are used to traverse in up,right,bottom and left respectively.
    int delrow[] = { -1, 0, 1, 0 };
    int delcol[] = { 0, 1, 0, -1 };
 
    // visited matrix to keep track of the visited cell.
    int vis[n][m];
    // queue stores rowIndex,colIndex and time taken to rot respectively.
    queue<pair<pair<int, int>, int> > q;
    // counter to keep track of fresh cells.
    int cntfresh = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({ { i, j },
                         0 }); 
               // already rotten hence 0 time to rot.
                vis[i][j]
                    = 2; 
                // visited cell marked as rotten.
            }
            else {
                vis[i][j] = 0; // unvisited
            }
            if (grid[i][j] == 1)
                cntfresh++; // maintaining count for fresh oranges.
        }
    }
    int cnt = 0, tm = 0;
    while (!q.empty()) {
        int row = q.front().first.first; // row index
        int col = q.front().first.second; // col index
        int t = q.front().second; // time an orange at a cell takes to rot.
        q.pop();
        tm = max(tm, t);
        // checking for adjacent nodes in 4 directions.
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
 
            // checking the validity of a node and also vis[nrow][ncol] !=2
            if (nrow >= 0 && nrow < n && ncol >= 0
                && ncol < m && grid[nrow][ncol] == 1
                && vis[nrow][ncol] != 2) {
                vis[nrow][ncol] = 2; // adj orange is rotten
                q.push({ { nrow, ncol },
                         t + 1 }); // incrementing time for that orange by 1
                cnt++;
            }
        }
    }
    return (cnt == cntfresh) ? tm : -1;
}
int main()
{
    vector<vector<int> > arr
        = { { 0, 1, 2 }, { 0, 1, 2 }, { 2, 1, 1 } };
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rotn";
    else
        cout << "Time required for all oranges to rot => "
             << ans << endl;
    return 0;
}
// finds if it is possible to rot all oranges or not. If possible, then it returns minimum time required to rot all
int rotoranges(vector <vector <int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int directrow[]{-1, 0, 1, 0};
    int directcol[]{0, 1, 0, -1};
    queue <pair <int, int>, int> q;
    int fresh = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
        // rotten oranges (cells with value 2) and push 
        // their coordinates into the queue with time 0,
            if(grid[i][j] == 2) q.push({{i, j}, 0});
            else if(grid[i][j] == 1) fresh++;
        }
    }
    int time = 0, rotten = 0;
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            auto [pos, t] = q.front(); q.pop();
            int r = pos.first, c = pos.second;
            for(int d = 0; d < 4; d++) {
                int nr = r + directrow[d];
                int nc = c + directcol[d];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc}, t + 1);
                    rotten++;
                }
            }
        }
        if(!q.empty()) time++;
    }
    return fresh == rotten ? time : -1;
}
int rotoranges(vector <vector <int>> &grid) {
    int n = grid.size(), m = grid[0].size(), time = 0;
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // if cur cell is rotten
                if(grid[i][j] > 1) {
                    vector <pair <int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                    for(auto &d : dirs) {
                        int ni = i + d.first;
                        int nj = j + d.second;
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                            grid[ni][nj] = grid[i][j] + 1;
                            changed = true;
                        }
                    }
                    
                }
            }
        }
        if(changed) time++;
    }
    for (auto& row : grid) {
        for (int val : row) {
            if (val == 1) return -1;
        }
    }
    return time;
}
//Find largest connected water volume (4- dir) in grid where > 0 cells form lakes
void dfs(vector <vector <int>> &grid, vector <vector <bool>> &vis, int x, int y, int &curvlm) {
    
    vis[x][y] = true; curvlm += grid[x][y];
    int dx[] = {1, -1, 0, 0}; int dy[] = {0, 0, 1, -1};
    for(int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] > 0 && !vis[newx][newy])
            dfs(grid, vis, newx, newy, curvlm);
    }
}
int maxlakesize(vector <vector <int>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    int maxsz = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int curvlm = 0;
            dfs(grid, vis, i, j, curvlm);
            maxsz = max(maxsz, curvlm);
        }
    }
    return maxsz;
}
int maxlakesize(vector <vector <int> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    int maxsz = 0;
    function <int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j] = true;
        return grid[i][j] + dfs(i - 1,j) + dfs(i + 1,j) + dfs(i,j - 1) + dfs(i,j + 1);
    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] > 0) maxsz = max(maxsz, dfs(i, j));
        }
    }
    return maxsz;
}
// Given n nodes. directed edges times[i] = {u, v, w}, return min time for signal from k to reach ALL nodes, or -1 if impossible
int delayTime(vector <vector <int>> &time, int n, int k) {
    vector <int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    // Relax all edges |V|-1 times
    for(int it = 0; it < n - 1; it++) {
        for(auto &edg : time) {
            int u = edg[0], v = edg[1], w = edg[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    } /*
    vector <int> dist(n + 1, -1);
    queue <int> q; dist[k] = 0;
    q.push(k);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &edg : time) {
            if(edg[0] == u && dist[edg[1]] == -1) {
                dist[edg[1]] = dist[u] + edg[2];
                q.push(edg[1]);
            }
        }
    } */
    int res = *max_element(dist.begin() + 1, dist.end());
    return res == INT_MAX ? -1 : ans;
}
// Least Common Subsequence
void LCS() {
    string str, ing; cin >> str >> ing;
    int n = str.size(), m = ing.size();
    vector <vector <int>> dp(n + 1, vector <int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str[i - 1] == ing[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }/*
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(str[i] == ing[j]) 
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0]; */
    cout << dp[n][m];
    /*
	// minimum number of steps required to make word1 and word2 the same
	int lcs = dp[n][m];
	int minsteps = n + m - 2 * lcs;
	return minsteps; */
}
int LCS(int i, int j) {
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(str[i] == ing[j]) {
        int res = 1 + LCS(i + 1, j + 1);
        dp[i][j] = res; return res;
    }
    int res = max(LCS(i + 1, j), LCS(i, j + 1));
    dp[i][j] = res; return res;
}
// reverse string
string rev(string str) {
    if(str.empty()) return "";
    char ch = str[0];
    string res = str.substr(1);
    return rev(res) + ch;
}
string LCS() {
    string str, ing; cin >> str >> ing;
    int n = str.size(), m = ing.size();
    vector <vector <int>> dp(n + 1, vector <int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str[i - 1] == ing[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    string res;
    for(int i = n, j = m; i && j;) {
        if(str[--i] == ing[--j]) res.push_back(str[i]);
        else if(dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    reverse(res.begin(), res.end());
    return res;
}
// find the longest palindromic subsequence's length in str
int LPS(string str) {
    int n = str.size();
    vector <vector <int>> dp(n, vector <int> (n));
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if(i == j) dp[i][j] = 1;
            else if(str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
// LCM of given range queries using Segment Tree
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
// allocate space for tree
int tree[4 * MAX];
int arr[MAX];
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }
// Function to build the segment tree Node starts beginning index of current subtree.
// start and end are indexes in arr[] which is global
void build(int node, int start, int end)
{
    // If there is only one element in current subarray
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    // build left and right segments
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    // build the parent
    int left_lcm = tree[2 * node];
    int right_lcm = tree[2 * node + 1];
 
    tree[node] = lcm(left_lcm, right_lcm);
}
// Function to make queries for array range )l, r). Node is index of root of current segment in segment
// tree (Note that indexes in segment tree begin with 1 for simplicity). start and end are indexes of subarray covered by root of current segment.
int query(int node, int start, int end, int l, int r)
{
    // Completely outside the segment, returning 1 will not affect the lcm;
    if (end < l || start > r)
        return 1;
    // completely inside the segment
    if (l <= start && r >= end)
        return tree[node];

    int mid = (start + end) / 2;
    int left_lcm = query(2 * node, start, mid, l, r);
    int right_lcm = query(2 * node + 1, mid + 1, end, l, r);
    return lcm(left_lcm, right_lcm);
}
int main()
{
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 10;
    arr[5] = 12;
    arr[6] = 11;
    arr[7] = 17;
    arr[8] = 14;
    arr[9] = 1;
    arr[10] = 44;
 
    build(1, 0, 10);
    cout << query(1, 0, 10, 2, 5) << endl;
    cout << query(1, 0, 10, 5, 10) << endl;
    cout << query(1, 0, 10, 0, 10) << endl;
    return 0;
}
// minimum product spanning tree The program is for adjacency matrix
// representation of the graph
#include <bits/stdc++.h>
#define V 5
// find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
// print the constructed MST stored in parent[] and print Minimum Obtainable product
int printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    int minProduct = 1;
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d \n",
               parent[i], i, graph[i][parent[i]]);
 
        minProduct *= graph[i][parent[i]];
    }
    printf("Minimum Obtainable product is %d\n",
           minProduct);
}
 
// Function to construct and print MST for a graph
// represented using adjacency matrix representation
// inputGraph is sent for printing actual edges and
// logGraph is sent for actual MST operations
void primMST(int inputGraph[V][V], double logGraph[V][V])
{
    int parent[V]; 
    // Array to store constructed MST
    int key[V]; 
    // Key values used to pick minimum
    // weight edge in cut
    bool mstSet[V]; 
    // To represent set of vertices not
    // yet included in MST
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    key[0] = 0;
    // Make key 0 so that this vertex is
    // picked as first vertex
    parent[0] = -1; 
    // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of
        // vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            // logGraph[u][v] is non zero only for  adjacent vertices of m mstSet[v] is false
            // for vertices not yet included in MST Update the key only if logGraph[u][v] is
            // smaller than key[v]
            if (logGraph[u][v] > 0 && mstSet[v] == false && logGraph[u][v] < key[v])
 
                parent[v] = u, key[v] = logGraph[u][v];
    }
    // print the constructed MST
    printMST(parent, V, inputGraph);
}
// Method to get minimum product spanning tree
void minimumProductMST(int graph[V][V])
{
    double logGraph[V][V];
 
    // Constructing logGraph from original graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] > 0)
                logGraph[i][j] = log(graph[i][j]);
            else
                logGraph[i][j] = 0;
        }
    }
    // Applying standard Prim's MST algorithm on Log graph.
    primMST(graph, logGraph);
}
int main()
{
    /* Let us create the following graph
           2    3
       (0)--(1)--(2)
        |   / \   |
       6| 8/   \5 |7
        | /     \ |
       (3)-------(4)
             9          */
    int graph[V][V] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 },
    };
    minimumProductMST(graph);
 
    return 0;
}
#include<bits/stdc++.h> 
using namespace std; 
// find number of spanning  trees in a graph using Matrix 
// Chain Multiplication 
#define MAX 100 
#define MOD 1000000007 
// Matrix Multiplication 
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) 
{ 
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < MAX; j++) 
            for (int k = 0; k < MAX; k++) 
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;     
} 
// Function to find Nth power of A 
void power(int A[MAX][MAX], int N, int result[MAX][MAX]) 
{ 
    int temp[MAX][MAX]; 
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < MAX; j++) 
            result[i][j] = (i == j); 
    while (N>0) 
    { 
        if (N%2 == 1) 
        { 
            multiply(A, result, temp); 
            for (int i=0; i<MAX; i++) 
                for (int j=0; j<MAX; j++) 
                    result[i][j] = temp[i][j]; 
        } 
        N = N/2; 
        multiply(A, A, temp); 
        for (int i=0; i<MAX; i++) 
            for (int j=0; j<MAX; j++) 
                A[i][j] = temp[i][j]; 
    } 
} 
// Function to find number of Spanning Trees in a Graph using Matrix Chain  Multiplication. 
int numOfSpanningTree(int graph[][MAX], int V) 
{ 
    int result[MAX][MAX] = {0}; 
    int temp[MAX][MAX] = {0}; 
    // Create a copy of graph as the Adjacency matrix will be changed during the process 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            temp[i][j] = graph[i][j]; 
 
    // Find (V-2)th power of Adjacency  matrix 
    power(temp, V-2, result); 
    int ans = 0; 
    // Find sum of all elements in (V-2)th 
    // power 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            ans = (ans + result[i][j])%MOD; 
 
    return ans; 
} 
int main() 
{ 
    // Let us create the following graph 
    // 2 <-> 3 
    // | | 
    // 0 <-1-> 1 
    int V = 4; 
    int E = 5; 
    int graph[][MAX] = { 
     {0, 1, 1, 1},  {1, 0, 1, 1}, 
    {1, 1, 0, 1}, {1, 1, 1, 0} }; 
    cout << numOfSpanningTree(graph, V); 
    return 0; 
}
//printing shortest path between two vertices of unweighted graph
using namespace std;
const int n = 1e5;
int parent[n], dist[n];
bool visited[n];
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool BFS(vector <int> adj[], int src, int dst, int parent[], int dist[], int node){
    list <int> queue;
    for(int i = 0; i < node; i++){
        visited[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue.push_back(v);

                if (v == dst)
                    return true;
            }
        }
    }
    return false;
}
void sortestDist(vector <int> adj[], int src, int dst, int node){
    if(!BFS(adj, src, dst, parent, dist, node)){
        clog << "Src & dest aren't connect";
        return;
    }
    vector <int> path;
    int val = dst;
    path.push_back(val);
    while(parent[val]!= -1){
        path.push_back(parent[val]);
        val = parent[val];
    }
    cout << "Sortest pth length is: " << dist[dst];
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> adj[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        addEdge(adj, u, v);
    }
    int src, dst; cin >> src >> dst;
    sortestDist(adj, src, dst, node);
}
using namespace std;
#define node 4
int Travelling(int graph[node][node], int src){
    vector <int> vertix;
    for(int i = 0; i < node; i++){
        if(i != src)
            vertix.push_back(i);
    }
    int minPath = INT_MAX;
    do{
        int curPathWeight = 0;
        int k = src;
        for(int i = 0; i < vertix.size(); i++){
            curPathWeight += graph[k][vertix[i]];
            k = vertix[i];
        }
        curPathweight += graph[k][src];
        minPath = min(minpath, curPathWeight);
    }while(next_permutation(vertix.begin(), vertix.end()));
    return minPath;
}
int main(){
    int graph[][node] { 
        { 0, 10, 15, 20 }, { 10, 0, 35, 25 },
    { 15, 35, 0, 30 }, { 20, 25, 30, 0 } };
    cout << Travelling(graph, 0);
}

