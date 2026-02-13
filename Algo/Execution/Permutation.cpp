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
#include<bits/stdc++.h>
using namespace std;
int digsum(int n) {
    if(n < 10) return n;
    else return (n % 10 + digsum(n / 10));
}
int power(int n, int m) {
    if(m == 0) return 1;
    return n * power(n, m - 1);
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
