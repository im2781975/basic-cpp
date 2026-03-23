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
