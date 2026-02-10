#include<bits/stdc++.h>
using namespace std;
//you have k types coins with amount of n.have to make target with these coins
int fun(int n, int trg) {
    if (n == 0) {
        if (trg == 0) return 1;
        return 0;
    }
    if (dp[n][trg] != -1) return dp[n][trg];
    int ans = fun(n - 1, trg);
    for (int i = 1; i <= limit[n]; i++) {
        if (trg - i * coin[n] < 0) break;
        int ret = fun(n - 1, trg - i * coin[n]);
        ans = (ans + ret) % MOD;
    }
    dp[n][trg] = ans;
    return ans;
}
void arrangeCoin() {
    int n, trg; cin >> n >> trg;
    vector <int> coin(n + 1), limit(n + 1);
    for(int i = 1; i <= n; i++) cin >> coin[i];
    for(int i = 1; i <= n; i++) cin >> limit[i];
    vector <vector <int>> dp(n + 1, vector <int> (trg + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int amt = 0; amt <= trg; amt++) {
            dp[i][amt] = dp[i - 1][amt];
            for(int cnt = 1; cnt <= limit[i] && amt >= cnt * coin[i]; cnt++) {
                dp[i][amt] = (dp[i][amt] + dp[i - 1][amt - cnt * coin[i]]) % 1000000007;
            }
        }
    }/*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= trg; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= trg; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int l = 1; l <= limit[i]; l++) {
                if (j < l * coin[i]) {
                    break;
                }
                int ret = dp[i - 1][j - l * coin[i]];
                dp[i][j] = (dp[i][j] + ret) % MOD;
            }
        }
    } */
    cout << dp[n][trg];
}
// permutation
int n; vector <vector <int>> res;
void backtrack(vector <int> vec, vector <bool> vis) {
    if(vec.size() == n) {
        res.push_back(vec); return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            vec.push_back(i);
            backtrack(vec, vis);
            vec.pop_back();
            vis[i] = false;
        }
    }
}
int main() {
    cin >> n; vector <int> vec;
    vector <bool> vis(n + 1, false);
    backtrack(vec, vis);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
