#include<bits/stdc++.h>
using namespace std;
//Find Minimum number of jumps to reach end
void minJump(int *arr, int l, int r) {
    if(l == r) return 0;
    if(arr[l] == 0) return INT_MAX;
    int mini = INT_MAX;
    for(int i = l + 1; i <= r && i <= l + arr[l]; i++) {
        int jump = minJump(arr, i, r);
        if(jump != INT_MAX && jump + 1 < mini) mini = jump + 1;
    }
    return mini;
}
int minJump(int *arr, int n) {
    int jump[n]; jump[0] = 0;
    if(n == 0 || arr[0] == 0) return INT_MAX;
    for(int i = 1; i < n; ++i) {
        jump[i] = INT_MAX;
        for(int j = 0; j < i; j++) {
            if(i <= j + arr[j] && jump[j] != INT_MAX) {
                jump[i] = min(jump[i], jump[j] + 1); break;
            }
        }
    }
    return jump[n - 1];
}
int minJump(vector <int> arr, int l, int r, vector <int> res) {
    /* vector <int> res(vec.size(), -1);
    return minJump(vec, 0, vec.size() - 1, res); */
    if(l == r) return 0;
    if(res[l] != -1) return res[l];
    int mini = INT_MAX;
    for(int j = arr[l]; j >= 1; j--) {
        if(l + j <= r) mini = min(mini, 1 + minJump(arr, l + j, r, res));
    }
    return res[l] = mini;
}
int minjump(int *arr, int l, int r) {
    vector<int> dp(r - l + 1, INT_MAX);
    dp[0] = 0;  
    for(int i = 1; i <= r - l; i++) {
        if(arr[l + i - 1] == 0) continue;
        for(int j = max(0, i - arr[l + i - 1]); j < i; j++) {
            if(dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[r - l];
}
int minjump(int *arr, int l, int r) {
    int jumps = 0, farthest = 0, current_end = 0;
    for(int i = l; i < r && i <= current_end; i++) {
        farthest = max(farthest, i + arr[i]);
        if(i == current_end) {
            jumps++;
            current_end = farthest;
            if(current_end >= r) break;
        }
    }
    return current_end >= r ? jumps : INT_MAX;
}
// make an array sorted using array minimum number of swap
int minswap(int *arr, int n) {
    pair <int, int> pos[n];
    for(int i = 0; i < n; i++) {
        pos[i].first = arr[i]; pos[i].second = i;
    }
    sort(pos, pos + n); int cnt = 0;
    vector <bool> vis(n, false);
    for(int i = 0; i < n; ++i) {
        //already swapped and corrected || already present at correct pos
        if(vis[i] || pos[i].second == i) continue;
        int cycle = 0, j = i;
        if(!vis[j]) {
            vis[j] = 1;
            j = vis[j].second; cycle++;
        }
        cnt += (cycle - 1);
    }
    cout << cnt << endl;
}
int minswap_direct(int *arr, int n) {
    vector<pair<int,int>> pos(n);
    for(int i = 0; i < n; i++) 
        pos[i] = {arr[i], i};
    sort(pos.begin(), pos.end());
    int swaps = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != pos[i].first) {
            int target_pos = -1;
            for(int j = i+1; j < n; j++) {
                if(arr[j] == pos[i].first) {
                    target_pos = j; break;
                }
            }
            swap(arr[i], arr[target_pos]);
            swaps++;
        }
    }
    return swaps;
}
// Fills element in arr[] from its pair sum array pair[]
void construct(int *arr, int *pair, int n) {
    arr[0] = (pair[0] + pair[1] - pair[n - 1]) / 2;
    for(int i = 1; i < n; ++i)
        arr[i] = pair[n - 1] - arr[0];
}
void subarr(vector <int> vec, int start, int end) {
    if(end == vec.size()) return;
    else if(start > end) subarr(vec, 0, end + 1);
    else {
        for(int i = start; i <= end; i++) 
            cout << vec[i] << " ";
        cout << endl;
        subarr(vec, start + 1, end);
    }
    return;
}
// Boyer-Moore Majority Vote Algorithm
// Function to check if the candidate occurs more than n/2 times
bool ismajority(int *arr, int val, int n) {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == val) cnt++;
    }
    if(cnt > n / 2) return true;
    return false;
}
void majority(int *arr, int n) {
    int idx = 0, cnt = 1;
    for(int i = 1; i < n; i++) {
        if(arr[idx] == arr[i]) ++cnt;
        else --cnt;
        if(cnt == 0) {
            idx = i; cnt = 1;
        }
    }
    cout << ismajority(arr, arr[idx], n) ? "Yes" : "No";
}
void majority(int *arr, int n) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; ++i) mp[arr[i]]++;
    int cnt = 0;
    for(auto it = mp.begin(); it!= mp.end(); ++it) {
        if(it -> second > n / 2) {
            cnt = 1; cout << it -> first;
            break;
        }
    }
    if(cnt == 0) cout << "doesn't found";
}
int majority(int *arr, int n) {
    if(n == 1) return arr[0];
    sort(arr, arr + n); int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) cnt++;
        else {
            if(cnt > n / 2) return arr[i - 1];
            cnt = 1;
        }
    }
    if(cnt > n / 2) return arr[n - 1];
    return -1;
}
int cntOccur(int *arr, int n, int val) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == val) cnt++;
    }
    return cnt;
}
int utile(int *arr, int low, int high) {
    /*;int mj = utile(arr, 0, n - 1);
    if(mj != -1) cout << mj;
    else cout << "No value found"; */
    if(arr[low] == arr[high]) return arr[low];
    int mid = low + (high - low) / 2;
    int left = utile(arr, low, mid);
    int right = utile(arr, mid + 1, right);
    if(left == right) return left;
    int x = high - low + 1;
    int leftOccur = cntOccur(arr, x, left);
    int rightOccur = cntOccur(arr, x, right);
    if(leftOccur > x / 2) return left;
    if(rightOccur > x / 2) return right;
    return -1;
}
void majority(int *arr, int n) {
    int maxcnt = 0, idx = -1;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) ++cnt;
        }
        if(cnt > maxcnt) {
            maxcnt = cnt; idx = i;
        }
    }
    if(maxcnt > n / 2) cout << maxcnt;
    else cout << -1;
}
void maxguest(int *enter, int *out, int n) {
    sort(enter, enter + n), sort(out, out + n);
    int maxguest = 1, guestin = 1, time = enter[0];
    int i = 1, j = 0;
    while(i < n && j < n) {
        if(enter[i] <= out[j]) {
            guestin++;
            if(guestin > maxguest) {
                maxguest = guestin;
                time = enter[i];
            } i++;
        }
        else {
            guestin--; j++;
        }
    }
    cout << maxguest << " " << time;
}
void maxoverlap(vector <int>start, vector <int> end) {
    int gianta = *max_element(start.begin(), start.end());
    int giantb = *max_element(end.begin(), end.end());
    int giantc = max(gianta, giantb);
    vector <int> arr(giantc + 2, 0);
    int cur = 0, idx = -1, maxi = INT_MIN;
    int n = start.size();
    for(int i = 0; i < n; i++) {
        arr[start[i]]++;
        arr[end[i] + 1]--;
    }
    for(int i = 0; i <= giantc; i++) {
        cur += arr[i];
        if(cur > maxi) {
            maxi = cur; idx = i;
        }
    }
    cout << maxi << " " << cur
}
int recursiveMin(const vector<int> &arr, int l, int r) {
    if (l == r) return arr[l];
    else {
        int mid = (l + r) / 2;
        return min(recursiveMin(arr, l, mid), recursiveMin(arr, mid + 1, r));
    }
}
void initialize() {
    typedef vector <int> vec;
    vec v;
    for(int i = 1; i <= 10; i += 2) v.push_back(i * 2);
    for(int x : v) cout << x << " ";
}
bool Isoperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%') return true;
    return false;
}
bool Isoperand(char ch) {
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) return true;
    return false;
}
string prefixToinfix(string str) {
    // string str = "*-A/BC-/AKL";
    stack <string> st;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(Isoperator(str[i])) {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x +  ")");
        }
        else st.push(string(1, str[i]));
    }
    return st.top();
}
string postfixToinfix(string str) {
    // string str ="ab*c+";
    stack <string> st;
    for(int i = 0; i < str.length(); i++) {
        if(Isoperand(str[i])) st.push(string(1, str[i]));
        else {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x + );
        }
    }
    return st.top();
}
bool Isoperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
    return false;
}
string prefixTopostfix(string str) {
    // string str = "*-A/BC-/AKL";
    stack <string> st;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(Isoperator(str[i])) {
            if(st.size() < 2) return "Invalid";
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push(x + y + str[i]);
        }
        else st.push(string(1, str[i]));
    }
    return st.top();
}
string postfixToprefix(string str) {
    stack <string> st;
    for(int i = 0; i < str.size(); i++) {
        if(Isoperator(str[i])) {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push(str[i] + y + x);
        }
        else st.push(string(1, str[i]));
    }
    string res = "";
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
// Function to return precedence of operators
int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}
bool Isoperator(char ch){
    return (!isalpha(ch) && !isdigit(ch));
}
void infixTopostfix(string str) {
    // string str = "a+b*(c^d-e)^(f+g*h)-i"
    stack <char> st; string res;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // if(isalpha(ch) || isdigit(ch)) res += ch;
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) res += ch;
        else if(ch == '(') st.push(ch);
        else if(ch == ')') {
            while(st.top() != '(') {
                res += st.top(); st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && priority(ch) <= priority(st.top())) {
                res += st.top(); st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
string infixToprefix(string str) {
    // string str = "x+y*z/w+u" 
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] == '(';
    }
    string prefix = infixTopostfix(str);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
// evaluate value of a postfix expression having multiple digit operands
int postfix(string str) {
    stack <int> st;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') continue;
        if(isdigit(str[i])) {
            int num = 0;
            while(isdigit(str[i])) {
                num = num * 10 + (str[i++] - '0');
            }
            i--;
            if(st.size() < 1) return -1;
            st.push(num);
        }
        else {
            if(st.size() < 2) return -1;
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]) {
                case '+' : st.push(x + y); break;
                case '-' : st.push(y - x); break;
                case '*' : st.push(x * y); break;
                case '/' : st.push(y / x); break;
            }
        }
    }
    if(st.size() != 1) return -1;
    return st.top();
}
// print next greater number of Q queries
void nextGreater(int *arr, int *next, int n) { 
    // int nxt[4]; nextGreater(arr, nxt, n);
    // cout << Query(arr, nxt, 4, 3) << " ";
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            next[st.top()] = i; st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        next[st.top()] = -1; st.pop();
    }
}
int Query(int *arr, int *next, int idx) {
    return next[idx] == -1 ? -1 : arr[next[idx]];
}
void nextgreater(int *arr, int *next, int n, int order) {
    stack <int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && (order == 'G'? arr[st.top()] <= arr[i] : arr[st.top()] >= arr[i]))
            st.pop();
        next[i] = st.empty() ?  -1 : st.top();
        st.push(i);
    }
}
// find Right smaller element of next greater element
void miniOfnextTall(int *arr, int n) {
    int NG[n], RS[n]; // next greater right smaller
    nextgreater(arr, NG, n, 'G');
    nextgreater(arr, RS, n, 'S');
    for(int i = 0; i < n; i++) {
        int idx = -1;
        if(NG[i] != -1 && RS[NG[i]] != -1)
            idx = RS[NG[i]];
    }
    cout << (idx == -1 ? -1 : arr[idx]) << " ";
}
//print next greater number of Q queries 
void nextGreater(int *arr, int *Query, int n, int q) {
    for(int i = 0; i < q; i++) {
        bool found = false
        int k = Query[i];
        for(int j = k + 1; j < n; j++) {
            if(arr[j] > arr[k]) {
                cout << arr[j] << " ";
                found = true; break;
            }
        }
        if(!found) cout << -1 << endl;
    }
}
vector <int> nextGreater(vector <int> arr) {
    vector <int> res; stack <int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        res.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end()); return res;
}
void nextGreaterfreq(int *arr, int *res, int n) {
    unordered_map <int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    stack <pair <int, int>> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().second <= freq[arr[i]]) st.pop();
        res[i] = st.empty() ? -1 : st.top().first;
        st.push({arr[i], freq[arr[i]]});
    }
}
void nextGreater(int *arr, int n) {
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            arr[st.top()] = arr[i]; st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        arr[st.top()] = -1; st.pop();
    }
}
void nextGreater(int *arr, int n) {
    stack <int> st; st.push(arr[0]);
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(arr[i]); continue;
        }
        while(!st.empty() && st.top() < arr[i]) {
            cout << st.top() << " " << arr[i] << endl; st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        cout << st.top() << " " << -1 << endl; st.pop();
    }
}
void nextGreater(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int next = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                next = arr[j]; break;
            }
        }
        cout << arr[i] << " " << next << endl;
    }
}
void nextgreater(int *arr, int n) {
    vector <int> res(n, -1); stack <int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(!st.empty()) res[i] = arr[st.top];
        st.push(i);
    }
    for(int i = 0; i < n; i++) {
        int idx = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                idx = j; break;
            }
        }
        if(idx != -1) res[i] = res[idx];
    }
    for(int x : res) cout << x << " ";
}
vector <int> nextlowerofnextupper(int *arr, int n) {
    vector <int> res(n, -1), rightlower(n, -1);
    for(int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while(j < n && arr[j] >= arr[i])
            j = (rightlower[j] != -1 ? rightlower[j] : n);
        if(j < n) rightlower[i] = j;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                int idx = rightlower[j];
                if(idx != -1) res[i] = arr[idx];
                break;
            }
        }
    }
    return res;
}
