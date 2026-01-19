#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string s, string t, vector <vector <int>> &dp){
    if(t.size() - j > s.size() - i) return 0;
    if(j >= t.size()) return 1;
    if(i >= s.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[i]) return dp[i][j] = func(i + 1, j + 1, s, t, dp) + func(i + 1, j, s, t, dp);
    return dp[i][j] = func(i + 1, j, s, t, dp);
}
int cntsubseq(string s, string t){
    vector <vector <int>> dp(s.size(), vector <int>(t.size(), - 1));
    return func(0, 0, s, t, dp);
}
int cntsubseq(string s, string t){
    int m = t.length(), n = s.length();
    if (m > n) return 0;
    // mat[i][j] stores the count of occurrences of
    int mat[m + 1][n + 1];
    for (int i = 1; i <= m; i++) mat[i][0] = 0;
    for (int j = 0; j <= n; j++) mat[0][j] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i - 1] != s[j - 1])
                mat[i][j] = mat[i][j - 1];
            else
                mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= m; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";  
    //return mat[m][n];
}
int main(){
    string T = "ge", S = "geeksforgeeks";
    cout << cntsubseq(S, T);
}
