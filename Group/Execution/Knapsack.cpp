#include<bits/stdc++.h>
using namespace std;
// Max knapsack value with capacity W using unlimited copies of each item
int kpansack(int W, vector <int> wt, vector <int> val) {
    vector <int> dp(W + 1, 0);
    for(int i = 0; i < wt.size(); i++) {
        for(int j = wt[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
    return dp[W];
}
int knapsack(int N, int W, vector <int> &wt, vector <int> &val) {
    vector <int> dp(W + 1, 0);
    for(int w = 1; w <= W; w++) {
        for(int i = 1; i <= N; i++) {
            if(wt[i] <= W) dp[w] = max(dp[w], dp[W - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include<bits/stdc++.h>
using namespace std;
const int N = 25;
const int W = 105;
int dp[N][W];

int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(dp[size][weight]!=-1)
        return dp[size][weight];
    if(wt[size-1] <=weight)
      return dp[size][weight] = max(val[size - 1]+ maxSum(wt, val, size -1,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
       return dp[size][weight] = maxSum(wt, val, size -1, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int>wt, val;
    for(int i=1; i<=n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        wt.push_back(weight);
        val.push_back(value);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
            dp[i][j] = -1;
    }
    cout << maxSum(wt, val, n, w);
}
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(wt[size-1] <=weight)
        return max(val[size - 1]+ maxSum(wt, val, size -1,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
        return maxSum(wt, val, size -1, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int>wt, val;
    for(int i=1; i<=n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        wt.push_back(weight);
        val.push_back(value);
    }
    cout << maxSum(wt, val, n, w);
}
#include<bits/stdc++.h>
using namespace std;
const int N=25;
const int W=105;
int dp[N][W];
int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(dp[size][weight]!=-1)
        return dp[size][weight];
    if(wt[size-1] <=weight)
        return dp[size][weight] = max(val[size - 1]+ maxSum(wt, val, size -1,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
        return dp[size][weight] = maxSum(wt, val, size -1, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int>wt(n), val(n);
    for(int i=1; i<=n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        wt.push_back(weight);
        val.push_back(value);
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
            dp[i][j] = -1;
    }
    cout << maxSum(wt, val, n, w);
}
// A iron rod was cut into pieces.each pieces have some values.what is the maximum value.
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(wt[size-1] <=weight)
        return max(val[size - 1]+ maxSum(wt, val, size,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
        return maxSum(wt, val, size -1, weight);
}
int main()
{
    int n ;
    cin >> n ;
    vector<int>wt(n), val(n);
    for(int i=0; i<n; i++)
    {
        wt[i] = i + 1;
        cin >> val[i];
    }
    cout << maxSum(wt, val, n, n);
}
// coin count
#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& val, int size, int weight) {
    if (weight == 0 || size == 0)
        return 0;
    if (val[size - 1] <= weight)
        return max(val[size - 1] + maxSum(val, size, weight - val[size - 1]), maxSum(val, size - 1, weight));
    else
        return maxSum(val, size - 1, weight);
}
int main() {
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << maxSum(val, n, n);
    return 0;
}
void effectmin(int n) {
    vector <int> dp(n + 1, INT_MAX); dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        // dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    return dp[n];
}
int n_bonacci(int n, int k) {
    if(k <= 0) return 0;
    if(k <= n) return n;
    vector <int> seq(k);
    for(int i = 0; i < k; i++) {
        if(i < n) seq[i] = 1;
        else {
            for(int j = i - 1; j >= i - n; --j) seq[i] += seq[j];
        }
    } /*
    for(int i = 0; i < n; ++i) seq[i] = 1;
    int slidesum = 0;
    for(int i = 0; i < n; ++i) slidesum += seq[i];
    for(int i = n; i < k; i++) {
        seq[i] = slidesum;
        slidesum += seq[i] - seq[i - n];
    } */
    return seq[k - 1];
}
// return the least number of perfect square numbers that sum to n 
int numsqr(int n) {
    vector <int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    vector <int> idealsqr;
    for(int i = 1; i * i <= n; i++) idealsqr.push_back(i * i);
    /*
    for(int i = 1; i <= n; i++) {
        for(auto x : idealsqr) {
            if(i - x >= 0) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    } */
    for(int i = 1; i <= n; i++) {
        for(int j = idealsqr.size() - 1; j >= 0; --j) {
            int x = idealsqr[j];
            if(i >= x) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }/*
    for(int i = 1; i * i <= n; ++i) {
        for(int j = 1; j * j <= n; ++j)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    } */
    return dp[n];
}
// find minimum steps to reduce number n to 0 by subtracting any digit from its current decimal representation each step.
const int x = 1e5;
vector <int> dp(x, INT_MAX);
int removedig(int idx) {
    if(idx == 0) return 0;
    if(dp[idx] != INT_MAX) return dp[idx];
    /* dp[idx] = INT_MAX;
    for(char ch : to_string(idx))
        dp[idx] = min(dp[idx], removedig(idx - (ch - '0')) + 1);
    return dp[idx]; */
    vector <int> vec;
    for(auto i : to_string(idx)) vec.push_back(i - '0');
    for(auto val : vec)
        dp[idx] = min(dp[idx], removedig(idx - val) + 1);
    return dp[idx];
}
// Min operations to make x have exactly n digits by multiplying x by any of its current digits each step
int effectmin(int n, int x) {
    string str = to_string(x);
    int cnt = 0;
    while(str.length() < n) {
        char dig = str[0];
        str = str.substr(1);
        x -= (dig - '0'); // remove first dig
        str = to_string(x) + str; cnt++;
    } /*
    while(str.length < n) {
        x -= str[0] - '0';
        str = to_string(x); cnt++;
    } */
    return cnt;
}
void grid() {
    int res = 0, sum = 0, grid[10][10] = {0};
    for(int i = 0; i < 10; i++) {
        sum += i; grid[i][i] = sum;
    }
    for(int j = 0; j < 10; j++) {
        res += 2 * j; cout << res << " ";
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
void func(int l, int r) {
    int mid = l + (r - l) / 2;
    for(int i = l; i <= r; i++) cout << i << " ";
    cout << endl;
    if(l < r) {
        func(l, mid); func(mid + 1, r);
    }
}
void recurs() {
    int n; cin >> n; func(0, n - 1); 
    for(int i = 1; i < n / 2; i++) {
        for(int j = 1; j <= n; j++)
            cout << i << " " << j << endl;
    }
}
void recur(int n) {
    if(n > 0) {
        recur(n - 1); cout << n << " ";
        recur(n - 2);
    }
}
// find dup idx of string
void dupidx() {
    map <string, int> mp;
    int n; cin >> n; string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(mp.find(str[i]) == mp.end()) cout << -1 << endl;
        else cout << mp[str[i]] << endl;
        mp[str[i]] = i;
    }
}
//valid bracket sequence
void seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else {
            if(ch == ')' && st.top() == '(') st.pop();
            else if(ch == '}' && st.top() == '{') st.pop();
            else if(ch == ']' && st.top() == '[') st.pop();
            else {
                cout << "Invalid"; return 0;
            }
        }
    }
    if(st.empty()) cout << "valid";
    else cout << "Not valid";
}
bool seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(st.empty()) return false;
            char tp = st.top(); st.pop();
            if((ch == ')' && tp != '(') || (ch == ']' && tp != '[') || (ch == '}' && tp != '{')) return false;
        }
    }
    return st.empty();
}
bool seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        switch(ch) {
            case '(' :
            case '{' :
            case '[' :
                st.push(ch); break;
            case ')' :
            case '}' :
            case ']' :
                if(st.empty() || (ch == ')' && st.top() != '(' ) || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '[')) return false;
                st.pop(); break;
        }
    }
    return st.empty();
}
void showOccur(string str) {
    map <char, vec <int>> mp;
    for(int i = 0; i < str.size(); i++)
        mp[str[i]].push_back(i);
    for(auto it : mp) {
        char ch = it.first; cout << ch << " ";
        vector <int> vec = it.second;
        for(auto val : vec) cout << val << " ";
    }
}
bool IsPalindrome(string str) {
    deque <char> dq;
    for(int i = 0; i < dq.size(); i++) 
        dq.push_back(str[i]);
    while(dq.size() > 1) {
        if(dq.front() != dq.back()) return false;
        dq.pop_front(); dq.pop_back();
    }
    return false;
}
void finddup(vector <int> arr) {
    map <int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        if(mp.find(arr[i]) != mp.end()) cout << mp[arr[i]] << " " << arr[i] << endl; break;
        else mp[arr[i]] = i;
    }
}
string rev(string str) {
    stack <char> st;
    for(int i = 0; i < str.length(); ++i) st.push(str[i]);
    string rev = "", tmp = "";
    while(!st.empty()) {
        if(isalpha(st.top())) tmp += st.top();
        else {
            rev = "" + tmp + rev; tmp = "";
        }
        st.pop();
    }
    if(!tmp.empty()) rev = rev + tmp;
    return rev;
}
bool caselower(char a, char b) { return (tolower(a) <= tolower(b);) }
bool ifsorted(string str) {
    return is_sorted(str.begin(), str.end(), caselower);
}
void maxOccur(string str) {
    map <string, int> mp;
    istringstream x(str); string word;
    while(x >> word) {
        for(char &ch : word) 
            ch = ispunct(ch) ? ' ' : tolower(ch)
        mp[word]++;
    }
    auto it = *max_element(mp.begin(), mp.end(), [](const auto a, const auto b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first); });
    cout << it -> second << " " << it -> first << endl;
}
// find no of swaps required to sort the array 
int minswap(vector <int> arr) {
    int n = arr.size(); bool vis[n] = {0};
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]] = i;
    sort(arr.begin(), arr.end());
    int swaps = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] || mp[arr[i]] == i) continue;
        int j = i, cyclesz = 0;
        while(!vis[j]) {
            vis[j] = true;
            j = mp[arr[j]]; cyclesz++;
        }
        if(cyclesz > 0) swaps += cyclesz - 1;
    }
    return swaps;
}
int minswap(vector <int> arr) {
    vector <int> tmp(arr.begin(), arr.end());
    sort(tmp.begin(), tmp.end());
    unordered_map <int, int> mp;
    for(int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
    int swap = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(tmp[i] != arr[i]) {
            int idx = mp[tmp[i]];
            swap(arr[i], arr[idx]);
            mp[arr[i]] = i;
            mp[arr[idx]] = idx;
            swap++;
        }
    }
    return swap;
}
