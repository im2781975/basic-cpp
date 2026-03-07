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
