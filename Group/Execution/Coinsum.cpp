#include<bits/stdc++.h>
using namespace std;
//you have k types coins with amount of n.have to make target with these coins
// coin[] is used for coins & limits[] for not exceed
const int x = 10005, cointp = 105;
int dp[x][cointp], coin[x], limit[x];
int coinsum(int n, int trg) {
    if(n == 0) {
        if(trg == 0) return 1;
        return 0;
    }
    if(dp[n][trg] != -1) return dp[n][trg];
    int res = coinsum(n - 1, trg);
    int maxcnt = min(limit[n], trg / coin[n]);
    for(int i = 1; i <= maxcnt; i++) 
        res = (res + coinsum(n - 1, trg - i * coin[n])) % x;
    return dp[n][trg] = res;
}
void coinsum(int n, int trg) {
    vector <int> coin(n + 1), limit(n + 1);
    for(int i = 1; i <= n; i++) cin >> limit[i];
    for(int i = 1; i <= n; i++) cin >> coin[i];
    vector <vector <int>> dp(n + 1, vector <int> (trg + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int amt = 0; amt <= trg; ++amt) {
            dp[i][amt] = dp[i - 1][amt];
            for(int cnt = 1; cnt <= limit[i] && amt >= cnt * coin[i]; ++cnt)
                dp[i][amt] = (dp[i][amt] + dp[i - 1][amt - cnt * coin[i]]) % 1000000007;
        }
    } /*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= trg; j++) dp[i][j] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= trg; j++) {
            dp[i - 1][j] = dp[i][j];
            for(int l = 1; l <= limit[i]; l++) {
                if(j < l * coin[i]) break;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l * coin[i]]) % 1000000007;
            }
        }
    } */
    return dp[n][trg];
}
// generates all permutations of numbers 1 to n 
int n, vector <vector <int>> res;
void exibitorder(vector <int> vec, vector <bool> vis) { /*
    vector <bool> vis(n + 1, false);
    backtrack(vec, vis);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) 
            cout << res[i][j] << " ";
        cout << endl;
    } */
    if(vec.size() == n) {
        res.push_back(vec); return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true; vec.push_back(i);
            backtrack(vec, vis);
            vec.pop_back(); vis[i] = false;
        }
    }
}
void exibitorder(vector <int> vec) {
    res.push_back(vec);
    int arr[n] = {0}, i = 0; // count arr
    while(true) {
        int idx = 0;
        while(idx < n && arr[idx] == 0) idx++;
        if(idx == n) break;
        swap(vec[i], vec[idx]); arr[i]++;
        i = 0;
        res.push_back(vec);
        if(arr[i] % 2 == 0) {
            swap(vec[0], vec[i + 1]); i += 1;
        }
    }
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) 
            cout << res[i][j] << " ";
        cout << endl;
    }
}
int digsum(int n) {
    if(n < 10) return n;
    else return (n % 10 + digsum(n / 10));
}
int power(int n, int m) {
    if(m == 0) return 1;
    return n * power(n, m - 1);
}
// checks if a queue can be sorted in ascending order
bool checksorted(int n, queue <int> &q) {
    stack <int> st; int except = 1;
    while(!q.empty()) {
        int tmp = q.top(); q.pop();
        if(tmp == except) except++;
        else {
            if(st.empty()) st.push(tmp);
            else if(!st.empty() && st.top() < tmp) st.pop();
            else st.push(tmp);
        }
    }
    while(!st.empty() && st.top() == except) {
        st.pop(); except++;
    }
    if(except - 1 == n && st.empty()) return true;
    return false;
}
bool Ispalindrome(string str) {
    deque <char> dq;
    for(char ch : str) {
        if(isalnum(ch)) dq.push_back(tolower(ch));
    }
    while(dq.size() > 1) {
        if(dq.front() != dq.back()) return false;
        dq.pop_front(); dq.pop_back();
    }
    return true;
}
// Queue 
void print(queue <int> &q) {
    while(!q.empty()) {
        cout << q.front() << " "; q.pop();
    }
}
void reverse(queue <int> &q) {
    if(q.size() == 0) return;
    int tmp = q.front(); q.pop();
    reverse(q); q.push(tmp);
}
void reverse(queue <int> &q) {
    stack <int> st;
    while(!q.empty()) {
        st.push(q.front()); q.pop();
    }
    while(!st.empty()) {
        q.push(st.top()); st.pop();
    }
}
// reverse first k elements of a queue
void reverseFirstk(queue <int> &q, int k) {
    if(q.empty() || k > q.size() || k <= 0) return;
    stack <int> st;
    for(int i = 0; i < k; i++) {
        st.push(q.front()); q.pop();
    }
    while(!st.empty()) {
        q.push(st.top()); st.pop();
    }
    for(int i = 0; i < q.size() - k; i++) {
        q.push(q.front()); q.pop();
    }
}
void revK(queue <int> &q, int k) {
    if(k == 0) return;
    int tmp = q.front(); q.pop();
    revK(q, k - 1); q.push(tmp);
}
void reversefirstk(queue <int> q, int k) {
    revK(q, k); int sz = q.size() - k;
    while(--sz > 0) {
        int x = q.front(); q.pop();
        q.push(x);
    }
    return q;
}
// Function to check if brackets are balanced
bool Isbalanced(string str) {
    stack <char> st;
    for(int i = 0; i < str.length(); i++) {
        if(st.empty()) st.push(str[i]);
        else {
            if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']')) st.pop();
            else st.push(str[i]);
        }
    }
    if(st.empty()) return true;
    return false;
}
bool IsBalanced(string str){
    int i = -1;
    for(auto &ch : str) {
        if(ch == '(' || ch == '{'|| ch == '[') str[++i] = ch;
        else {
            if(i >= 0 && ((str[i] == '(' && ch == ')') || (str[i] == '{' && ch == '}') || (str[i]== '[' && ch == ']')))
                return true;
            return false;
        }
    }
    return i == -1;
}
// Function to build Monotonic increasing stack
void Increasing(int *arr, int n) {
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(st.size() > 0 && st.top() > arr[i]) st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int res[sz], j = sz - 1;
    while(!st.empty()) {
        res[j--] = st.top(); st.pop();
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    for(int i = 0; i < sz; i++) cout << res[i] << " ";
    cout << endl;
}
void Decreasing(int *arr, int n) {
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(st.size() > 0 && st.top() < arr[i]) st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int res[sz], j = sz - 1;
    while(!st.empty()) {
        res[j--] = st.top(); st.pop();
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    for(int i = 0; i < sz; i++) cout << res[i] << " ";
    cout << endl;
}
void InsertBottom(stack <int> &st, int x) {
    if(st.size() == 0) st.push(x);
    else {
        int tmp = st.top(); st.pop();
        InsertBottom(st, x); st.push(tmp);
    }
}
void reverse(stack <int> &st) {
    if(st.size() > 0) {
        int tmp = st.top(); st.pop();
        reverse(st); InsertBottom(st, tmp);
    }
}
void reverse(stack <int> &st) {
    stack <int> ck;
    while(!st.empty()) {
        ck.push(st.top()); st.pop();
    }
    while(!ck.empty()) {
        st.push(ck.top()); ck.pop();
    }
}
// reverse the number using a stack
stack <int> st;
void pushdig(int dig) {
    while(dig != 0) {
        st.push(dig % 10); dig /= 10;
    }
}
int reverse(int dig) {
    pushdig(dig);
    int rev = 0, i = 1;
    while(!st.empty()) {
        rev = rev + (st.top() * i);
        st.pop(); i *= 10;
    }
    return  rev;
}
stack <int> sortstack(stack <int> st) {
    stack <int> ck;
    while(!st.empty()) {
        int tmp = st.top(); st.pop();
        while(!ck.empty() && ck.top() < tmp) {
            st.push(ck.top()); ck.pop();
        }
        ck.push(tmp);
    }
    return ck;
}
string rev(string str) {
    if(str.empty()) return "";
    char ch = str[0];
    string res = str.substr(1);
    return (rev(res) + ch);
}
string rev(string str) {
    stack <char> st; string res;
    for(char ch : str) st.push(ch);
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
void decreasesz(stack <int> &st) {
    int sz = st.size();
    stack <int> ck;
    while(!st.empty()) {
        ck.push(st.top()); st.pop(); sz++;
    }
    if(sz < cap / 2) {
        cap /= 2; stack <int> ct;
        while(!ck.empty() && ct.size() < cap) {
            ct.push(ck.top()); ck.pop();
        }
        while(!ct.empty()) {
            st.push(ct.top()); ct.pop();
        }
    }
}
void decreasesz(stack <int> &st) {
    size_t sz = st.size();
    if(sz > 0 && sz < st.capacity() / 2) {
        size_t cap = st.capacity() / 2;
        stack <int> ck;
        while(!st.empty()) {
            ck.push(st.top()); st.pop();
        }
        st.resize(cap);
        while(!ck.empty()) {
            st.push(ck.top()); ck.pop();
        }
    }
}
int func(char ch) {
    if(ch == '+' || ch == '-') return 1;
    return 0;
}
void conversion(string str, stack <char> st) {
    string res = "";
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch >= 'a' && ch <= 'z') res += ch;
        else {
            while(st.size() && func(st.top()) >= func(ch)) {
                res += st.top(); st.pop();
            }
            st.push(ch);
        }
    }
    while(st.size()) {
        res += st.top(); st.pop();
    }
    cout << res;
}

