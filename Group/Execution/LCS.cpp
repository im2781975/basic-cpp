#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
// Minimum number of steps required two make strings same
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans=1;
    int LCS=dp[n][m];
    int ans = (n + m) - (LCS*2);
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
#include<cstring>
#include<iostream>
using namespace std;
const int M = 3, N = 3;
string dic[]{ "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dic) / sizeof(dic[0]);
// A given function to check if a given string is present in dictionary
bool IsWord(string &str){
    for(int i = 0; i < n; i++){
        if(str.compare(dic[i]) == 0)
            return true;
    }
    return false;
}
void FindWords(char Boggle[M][N], bool visited[M][N], int i, int j, string str){
    visited[i][j] = true;
    str += Boggle[i][j];
    if(IsWord(str))
        cout << str << " ";
    // Traverse 8 adjacent cells of boggle[i][j]
    for(int row = i - 1; row <= i + 1 && row < M; ++row){
        for(int col = j - 1; col <= j + 1 && col < N; ++col){
            if(row >= 0 && col >= 0 &&! visited[row][col])
                FindWords(Boggle, visited, row, col, str);
        }
    }
    // Erase current character from string and mark visited of current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}
int main(){
    char Boggle[M][N] = {
        {'G','I','Z'},{'U','E','K'}, {'Q','S','E' } };
    bool visited[M][N] = { {false} };
    //Consider every character and look for all words starting with this character
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            string str = "";
            FindWords(Boggle, visited, i, j, str);
        }
    }
}
#include <iostream>
#include <string>
using namespace std;

const int M = 3, N = 3;
string dic[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = 4;  // size of dic

// Check if word exists in dictionary
bool IsWord(const string &str) {
    for (int i = 0; i < n; i++) {
        if (str == dic[i])
            return true;
    }
    return false;
}

// DFS from cell (i, j) in Boggle grid
void FindWords(char Boggle[M][N], bool visited[M][N], int i, int j, string &str) {
    visited[i][j] = true;
    str += Boggle[i][j];

    if (IsWord(str))
        cout << str << " ";

    // 8 directions around (i, j)
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < M && nj >= 0 && nj < N && !visited[ni][nj]) {
                FindWords(Boggle, visited, ni, nj, str);
            }
        }
    }

    // backtrack
    str.pop_back();
    visited[i][j] = false;
}

int main() {
    char Boggle[M][N] = {
        {'G','I','Z'},
        {'U','E','K'},
        {'Q','S','E'}
    };

    bool visited[M][N] = {{false}};

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            string str;
            FindWords(Boggle, visited, i, j, str);
        }
    }

    cout << endl;
    return 0;
}
using namespace std;
bool DFS(vector <vector <char> >&matrix, string str, int i, int j, int n, int m, int idx){
    if((i < 0 || i >= n || j < 0 || j >= m))
        return false;
    if(str[idx]!= matrix[i][j])
        return false;
    if(idx == str.size() - 1)
        return true;
    char tmp = matrix[i][j];
    matrix[i][j] = '*';
    //Explore 8 direction
    bool a = DFS(matrix, str, i, j + 1, n, m, idx + 1);
    bool b = DFS(matrix, str, i, j - 1, n, m, idx + 1);
    bool c = DFS(matrix, str, i + 1, j, n, m, idx + 1);
    bool d = DFS(matrix, str, i - 1, j, n, m, idx + 1);
    bool e = DFS(matrix, str, i + 1, j + 1, n, m, idx + 1);
    bool f = DFS(matrix, str, i + 1, j - 1, n, m, idx + 1);
    bool g = DFS(matrix, str, i - 1, j + 1, n, m, idx + 1);
    bool h = DFS(matrix, str, i - 1, j - 1, n, m, idx + 1);
    matrix[i][j] = tmp;
    return (a || b || c || d || e || f || g || h);
}
void FindWord(vector <vector <char> >&matrix, vector <string> &dic){
    //int n = matrix.size(), m = matrix[0].size();
    vector <string> ans;
    set <string> store;
    for(int i = 0; i < dic.size(); i++){
        string str = dic[i];
        for(int j = 0; j < matrix.size(); j++){
            for(int k = 0; k < matrix[0].size(); k++){
                if(DFS(matrix, str, j, k, matrix.size(), matrix[0].size(), 0))
                    store.insert(str);
            }
        }
    }
    for(const string &word : store)
        cout << word << " ";
}
int main(){
    vector <vector <char> >Boggle { { 'G', 'I', 'Z' }, { 'U', 'E', 'K' }, { 'Q', 'S', 'E' }
    };
    vector <string> Dic{ "GEEKS", "FOR", "QUIZ", "GO" };
    FindWord(Boggle, Dic);
}
