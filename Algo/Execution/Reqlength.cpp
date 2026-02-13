#include<bits/stdc++.h>
using namespace std;
// Max knapsack value with capacity W using unlimited copies of each item
void knapsack(int W, vector <int> wt, vector <int> val) {
    vector <int> dp(W + 1, 0);
    for(int i = 0; i < wt.size(); i++) {
        for(int j = wt[i]; j <= W; j++) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
int knapsack(int N, int W, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W + 1, 0);
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < N; i++) {
            if (weights[i] <= w)
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}
//"Find largest connected water volume (4-dir) in grid where >0 cells form lakes
int n, m;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m;
bool isvalid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(vector <vector <int>> grid, vector <vector <bool>> vis, int x, int y, int curvlm) {
    vis[x][y] = true;
    curvlm += grid[x][y];
    for(int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(isvalid(newx, newy) && grid[newx][newy] > 0 && !vis[newx][newy])
            dfs(grid, vis, newx, newy, curvlm);
    }
}
int findMaxLakeVlm(vector <vector <int>> grid) {
    n = grid.size(); m = grid[0].size();
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    int mxvlm = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] > 0 && !vis[i][j]) {
                int curvlm = 0;
                dfs(grid, vis, i, j, curvlm);
                mxvlm = max(mxvlm, curvlm);
            }
        }
    }
}
int largestLake(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    int maxVol = 0;
    
    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]) return 0;
        vis[i][j] = true;
        return grid[i][j] + dfs(i-1,j) + dfs(i+1,j) + dfs(i,j-1) + dfs(i,j+1);
    };
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && grid[i][j] > 0)
                maxVol = max(maxVol, dfs(i,j));
    
    return maxVol;
}
// Min operations to reach n from 1 using: ÷2, ÷3, or -1
int minOpr(int n) {
    vector <int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    return dp[n];
}
int minOpr(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1; 
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    return dp[n];
}
int n_bonacci(int n, int k) {
    if (k <= 0) return 0;
    if (k <= n) return 1;
    vector <int> seq(k);
    for(int i = 0; i < k; i++) {
        if(i < n) seq[i] = 1;
        else {
            for(int j = i - 1; j >= i - n; --j) seq[i] += seq[j];
        }
    }/*
    for (int i = 0; i < n; ++i) seq[i] = 1;
    int window_sum = 0;
    for (int i = 0; i < n; ++i)
        window_sum += sequence[i];
    for (int i = n; i < k; ++i) {
        seq[i] = window_sum;
        window_sum = window_sum + seq[i] - seq[i - n];
    } */
    return seq[k - 1];
}
// Given n nodes (1-n), directed edges times[i] = {u,v,w}, return min time for signal from k to reach ALL nodes, or -1 if impossible
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>> graph(n + 1);
    for (const auto& edge : times) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        graph[u].push_back({v, w});
    }
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node k with time 0.
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curTime = pq.top().first;
        pq.pop();
        for (const auto& neighbor : graph[curNode]) {
            int nextNode = neighbor.first;
            int nextTime = neighbor.second;

            // Relaxation step.
            if (dist[curNode] + nextTime < dist[nextNode]) {
                dist[nextNode] = dist[curNode] + nextTime;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    int ans = *max_element(dist.begin()+1, dist.end());
    return ans == INT_MAX ? -1 : ans;
}
int main() {
    int n = 5, k = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int result = networkDelayTime(times, n, k);
    cout << "Minimum time to reach all nodes: " << result ;
}
// return the least number of perfect square numbers that sum to n
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    // dp[0] = 0, since it takes 0 perfect squares to sum to 0.
    dp[0] = 0; /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    } */
    vector<int> perfectSqr;
    for (int i = 1; i * i <= n; i++)
        perfectSqr.push_back(i * i);
    for (int i = 1; i <= n; i++) {
        for (int square : perfectSqr) {
            if (i - square >= 0)
                dp[i] = min(dp[i], dp[i - square] + 1);
        }
    }
    return dp[n];
}
// find minimum steps to reduce number n to 0 by subtracting any digit from its current decimal representation each step.
const int x = 1e5;
vector <int> dp(x, INT_MAX);
int removeDig(int i) {
    if(i == 0) return 0;
    if(dp[i] != INT_MAX) return dp[i];
    /*
    for (char c : to_string(i))
        dp[i] = min(dp[i], solve(i - (c - '0')) + 1); */
    vector <int> vec;
    for(auto j : to_string(i)) vec.push_back(j - '0');
    for(auto val : vec) 
        dp[i] = min(dp[i], removeDig(i - val) + 1);
    return dp[i];
}
// Min operations to make x have exactly n digits by multiplying x by any of its current digits each step
int reqLen() {
    int n, x; cin >> n >> x;
    string ing = to_string(x); 
    int opr = 0;
    while (ing.length() < n) {
        char digit_to_multiply = ing[0]; 
        ing = ing.substr(1);
        // Remove the first digit.
        x *= (digit_to_multiply - '0');
        // Convert char to int and multiply.
        ing = to_string(x) + ing;
        opr++;
    } /*
    while (ing.size() < n) {
        x *= s[0] - '0';
        ing = to_string(x);
        opr++;
    } */
    cout << opr;
}

