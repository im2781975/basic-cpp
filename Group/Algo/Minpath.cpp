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
