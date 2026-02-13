#include<bits/stdc++.h>
using namespace std;
int dp[101];
void fib(int n) {
    if(n <= 2) return 1;
    memset(dp, -1, sizeof(dp));
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
    /*
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n]; */
}
int fib(int n) {
    if(n <= 1) return n;
    vector <int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
// frog can jump on stone i..i+2..i+k.here |hi-hj| will be incurred where j is 
// the stone where landed.find min possible total cost reaching nth stone.
int height[101];
void frogJump(int n, int k, int *height) {
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= k; j++) {
            int rockfrom = i - j;
            if(rockfrom <= 0) break;
            int res = dp[rockfrom] + abs(height[i] - height[rockfrom]);
            dp[i] = min(dp[i], res);
        }
    } /*
    for(int i = 2; i <= n; i++) {
        int x = dp[i - 1] + abs(height[i] - height[i - 1]);
        if(i == 2) {
            dp[i] = x; continue;
        }
        int y = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(x, y);
    } */
    cout << dp[n];
}
void fromJump(int n) {
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    int res = INT_MAX, k = 3;
    for(int j = 1; j <= k; j++) {
        if(n - j >= 1) {
            int ans = frogJump(n - j) + abs(h[n] - h[n - j]);
            res = min(res, ans);
        }
    }
    dp[n] = res; return res;
}
//choose item from n items.weight of a knapsack is W.find how many items you can choose.
const int x = 1e6;
int dp[102][x], wt[102], val[102];
void knapsack(int n, int cap) {
    for(int i = 1; i <= n; i++) cin >> wt[i] >> val[i];
    for(int i = 0; i <= cap; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= cap; j++) {
            if(j < wt[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
        }
    }
    cout << dp[n][cap];
}
int knapsack(int n, int cap) {
    if(n == 0) return 0;
    if(dp[n][cap] != -1) return dp[n][cap];
    if(cap < wt[n]) int res = knapsack(n - 1, cap);
    int a = val[n] + knapsack(n - 1, cap - wt[n]);
    int b = knapsack(n - 1, cap);
    int res = max({a, b}); dp[n][cap] = res; return res;
}
//how many ways we can reach from top_left corner to bottom_right corner.
int dp[102][102];
int movegrid(int row, int col) {
    dp[0][0] = 1;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) continue;
            int res = 0;
            if(i > 0) res += dp[i - 1][j];
            if(j > 0) res += dp[i][j - 1];
            dp[i][j] = res;
        }
    }
    return dp[row - 1][col - 1];
}
int movegrid(int row, int col) {
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    int res = 0;
    if(row > 0) res += movegrid(row - 1, col);
    if(col > 0) res += movegrid(row, col - 1);
    dp[row][col] = res; return res;
}
int arr[102];
int subsetsum(int n, int trg) {
    if(n == 0) {
        if(trg == 0) return 1;
        return 0;
    }
    if(dp[n][trg] != -1) return dp[n][trg];
    int a = subsetsum(n - 1, trg);
    if(trg < arr[n]) {
        dp[n][trg] = a; return a;
    }
    int b = subsetsum(n - 1, trg - arr[n]);
    int res = a || b;
    dp[n][trg] = res; return res;
}
int subsetsum(int n, int trg, int *arr) {
    vector <bool> dp(trg + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = trg; j >= arr[i]; j--) {
            if(dp[j - arr[i]]) dp[j] = true;
        }
    }
    return dp[trg];
}
//count maximum happiness
const int N = 1005;
int happiness[N][4], dp[N][4];
void maxhappiness(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) cin >> happiness[i][j];
    }
    for(int task = 1; task <= 3; task++)
        dp[1][task] = happiness[1][task];
    for(int day = 2; day <= n; day++) {
        for(int cur = 1; cur <= 3; cur++) {
            int maxprofit = 0;
            for(int last = 1; last <= 3; last++) {
                if(last != cur) {
                    int curprofit = dp[day - 1][last] + happiness[day][cur];
                    maxprofit = max(maxprofit, curprofit);
                }
            }
            dp[day][cur] = maxprofit;
        } 
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
}
void maxhappiness(int day, int task) {
    /*int max_happiness = 0;
    for (int i = 1; i <= 3; i++) {
        max_happiness = max(max_happiness,maxhappiness(n, i));
    } */
    if(day == 1) return happiness[day][task];
    if(dp[day][task] != -1) return dp[day][task];
    int max_profit = 0;
    for (int last = 1; last <= 3; last++) {
        if (last != task) {
            int candidate_profit = maxhappiness(day - 1, last) + happiness[day][task];
            max_profit = max(max_profit, candidate_profit);
        }
    }
    dp[day][task] = max_profit;
    return max_profit;
}
