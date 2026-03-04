#include<bits/stdc++.h>
//return the len of the longest increasing path in matrix
using namespace std;
int dfs(vector <vector <int>> grid, int x, int y, vector <vector <int>> tmp) {
    if(tmp[x][y] != 0) return tmp[x][y];
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxPath = 1;
    for(const auto &dir : direct) {
        int newx = x + dir[0]; int newy = y + dir[1];
        if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] > grid[x][y])
            maxpath = max(maxpath, 1 + dfs(grid, newx, newy, tmp));
    }
    
}
int pathincreasing(vector <vector <int>> grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    vector <vector <int>>tmp(n, vector <int>(m, 0));
    int maxpath = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            maxpath = max(maxpath, dfs(grid, i, j, tmp));
    }
    return maxpath;
}

// Given rival pairs (Lykan vs Vampire fights), find maximum number that can be all Vampires OR all Lykans."
bool dfs(int u, vector<vector<int>>& adj, vector<int>& match, vector<bool>& vis) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v], adj, match, vis)) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxSameTeam(int n, vector<pair<int,int>>& fights) {
    int N = *max_element(fights.begin(), fights.end(), [](auto& a, auto& b){
        return max(a.first, a.second) < max(b.first, b.second);
    }) + 1;  // Auto-detect max fighter ID
    vector<vector<int>> adj(N);
    for (auto [u, v] : fights) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> match(N, -1);
    int matching = 0;
    for (int i = 0; i < N; i++) {
        if (match[i] == -1) {
            vector<bool> vis(N, false);
            if (dfs(i, adj, match, vis)) matching++;
        }
    }
    return N - matching;  // Max same-team fighters
}
int main() {
    int n; cin >> n;
    vector<pair<int,int>> fights(n);
    for (int i = 0; i < n; i++)
        cin >> fights[i].first >> fights[i].second;
    cout << maxSameTeam(n, fights) << endl;
}
// Count right/down paths from (0,0) to (n-1,n-1) avoiding traps.
int countPaths(int n, vector<vector<int>>& trap) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = trap[0][0] ? 0 : 1;
    for (int i = 1; i < n; i++) dp[i][0] = trap[i][0] ? 0 : dp[i - 1][0];
    for (int j = 1; j < n; j++) dp[0][j] = trap[0][j] ? 0 : dp[0][j - 1];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (!trap[i][j])
                dp[i][j] = (dp[i - 1][j] + dp[0][j - 1]) % MOD;
    return dp[n - 1][n - 1];
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(trap[i][j]) dp[i][j] = 0;
            else if(i || j) dp[i][j] = ((i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0)) % MOD;
        }
    } */
}
// Min path sum from top-left to bottom-right (right/down moves only)
int minPathsum(vector <vector <int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector <vector <int>> dp(n, vector <int> (m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) 
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}
