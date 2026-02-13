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
// Return the minimum cost to reach the top of the floor
int mincostclimbstair(vector <int> cost) {
    int n = cost.size(); 
    vector <int> dp(n, 0);
    dp[0] = cost[0]; dp[1] = cost[1];
    for(int i = 2; i < n; i++)
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    return min(dp[n - 1], dp[n - 2]);
    /*for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n]; */
}
// Count ways to climb n stairs taking 1-6 steps at a time.
void climbstair() {
    int n; cin >> n;
    vector <int> dp(n + 1, 0); dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int step = 1; step <= 6 && step <= i; step++) {
            dp[i] += dp[i - step];
        }
    }
    cout << dp[n];
}
// Count coin combinations to make exact amount
int coinchange(int amt, vector <int> coin) {
    vector <int> dp(amt + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < coin.size(); i++) {
        int val = coin[i];
        for(int j = val; j <= amt; j++)
            dp[j] += dp[j - val];
    }
    return dp[amt];
}
int coinchange(vector <int> coin, int amt) {
    vector <int> dp(amt + 1, amt + 1);
    dp[0] = 0;
    for(int i = 1; i <= amt; i++) {
        for(int j = 0; j < coin.size(); j++) {
            if(i >= coin[j])
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    return dp[amt] > amt ? -1 : dp[amt];
}
// calculate the number of distinct ways you can produce a money sum amount
int cntways(vector <int> coin, int amt) {
    vector <int> dp(amt + 1, 0); dp[0] = 1;
    for(int i = 0; i < coin.size(); i++) {
        for(int j = coin[i]; j <= amt; j++)
            dp[j] += dp[j - coin[i]];
    }
    return dp[amt];
}
// find all money sums can create using these coin array
void moneySum(vector <int> coin) {
    set <int> sums; sums.insert(0);
    for(int i = 0; i < coin.size(); i++) {
        int n = sums.size(); sums.resize(n * 2);
        for(int j = 0; j < n; j++) 
            sums[n + j] = sums[j] + coin[i];
    }
    for(int res : sums) cout << res << " ";
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
// Max coins from monsters, but can't take from 2 adjacent ones.
int maxGold(vector <int> monsterGold) {
    int n = monsterGold.size();
    vector <int> dp(n + 2, 0);
    for(int i = n - 1; i >= 0; i--)
        dp[i] = max(monsterGold[i] + dp[i + 2], dp[i + 1]);
    return dp[0];
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
// Max money from circular houses without robbing adjacent ones (first+last adjacent).
int robRange(vector<int>& nums, int start, int end) {
    int prev1 = 0;  
    int prev2 = 0; 
    for (int i = start; i <= end; i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1; prev1 = current;
    }
    return prev1;
}
int rob(vector <int> houses) {
    int n = houses.size();
    if (n == 1) return houses[0];
    int robFirst = robRange(nums, 0, n - 2);
    int robLast = robRange(nums, 1, n - 1);
    return max(robFirst, robLast);
}
// Max money from houses without robbing adjacent ones.
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int money : nums) {
        int temp = max(prev1, prev2 + money);
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> robHouse(n);
    vector<int> skipHouse(n);
    robHouse[0] = nums[0];
    skipHouse[0] = 0;
    for (int i = 1; i < n; ++i) {
        robHouse[i] = skipHouse[i - 1] + nums[i];
        skipHouse[i] = max(robHouse[i - 1], skipHouse[i - 1]);
    }
    return max(robHouse[n - 1], skipHouse[n - 1]);
}
