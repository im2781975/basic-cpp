#include<bits/stdc++.h>
using namespace std;
// find length of the longest valid substring
int findlen(string str) {
    // string str = "((()()"
    int len = str.length(), res = 0;
    stack <int> st; st.push(-1);
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') st.push(i);
        else {
            st.pop();
            if(!st.empty()) res = max(res, i - st.top());
            else st.push(i);
        }
    }
    return res;
}
int findmaxlen(string str) {
    if(str.length() <= 1) return 0;
    vector <int> dp(str.size(), 0);
    int maxlen = 0;
    for(int i = 1; i < str.length(); i++) {
        if(str[i] == ')') {
            if(str[i - 1] == '(') dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            else if(i - dp[i - 1] - 1 >= 0 && str[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            maxlen = max(maxlen, dp[i]);
        }
    }
    return maxlen;
}
int peakpair(int i, string str, vector <int> dp) {
    if(i <= 0) return 0;
    if(dp[i] != -1) return dp[i];
    if(str[i] == '(') dp[i] = 0;
    if(str[i] == ')') {
        if(i > 0 && str[i - 1] == '(') {
            return dp[i] = (i >= 2 ? preakpair(i - 2, str, dp) : 0) + 2;
        }
        int prv = peakpair(i - 1, str, dp);
        if(i - 1 - prv >= 0 && str[i - 1 - prv] == '(')
            return dp[i] = prv + 2 + (i - prv - 2 >= 0 ? peakpair(i - prv - 2, str, dp) : 0);
    }
    return dp[i] = 0;
}
int findmaxlen(string str) {
    int len = str.size(), maxlen = 0;
    vector <int> dp(n, -1);
    for(int i = 0; i < len; i++) maxlen = max(maxlen, peakpair(i, str, dp));
    return maxlen;
}
int findmaxlen(string str) {
    int left = 0, right = 0, maxlen = 0, len = str.size();
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') left++;
        else {
            right++;
            if(left >= right) maxlen = max(maxlen, 2 * right);
            else left = right = 0;
        }
    }
    left = right = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == ')') right++;
        else {
            left++;
            if(left >= right) maxlen = max(maxlen, 2 * left);
            else left = right = 0;
        }
    }
    return maxlen;
}
int findmaxlen(string str) {
    int len = str.size(), maxlen = 0, left = 0, right = 0;
    for(char ch : str) {
        if(ch == '(') left++;
        else right++;
    }
    if(left == right) maxlen = max(maxlen, 2 * left);
    if(right > left) left = right = 0;
    reverse(str.begin(), str.end());
    left = 0; right = 0;
    for(char ch : str) {
        if(ch == '(') left++;
        else right++;
    }
    if(left == right) maxlen = max(maxlen, 2 * left);
    if(left > right) left = right = 0;
}
// check redundant brackets in a balanced expression
bool checkexcess(string str) {
    stack <char> st;
    for(auto &ch: str) {
        if(ch == ')') {
            char tp = st.top(); st.pop();
            bool flag = true;
            if(tp == '(') return true;
            while(!st.empty() && tp != '(') {
                tp = st.top(); st.pop();
                if(tp == '+' || tp == '-' || tp == '*' || tp == '/') flag = false;
            }
            st.pop();
            if(flag == true) return true;
        }
        else st.push(ch);
    }
    return false;
}
// finds an element in an array of infinite size
int Bsearch(int *arr, int l, r, trg) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == trg) return mid;
        if(trg < arr[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int searchInfinite(int *arr, int trg) {
    int l = 0, r = 1;
    if(trg > arr[r]) {
        int newl = r + 1;
        r = r + (r - l + 1) * 2;
        l = newl;
    }
    return Bsearch(arr, l, r, trg);
}
// finds the minimum number of dice rolls needed to 
// reach position 30 on a 5x6 board (30 squares)
int tmp[35];
int mincnt(int pos, unordered_map <int, int> &board) {
    if(pos >= 30) return 0;
    if(tmp[pos]!= -1) return tmp[pos];
    int minthrow = INT_MAX;
    for(int dice = 1; dice <= 6; ++dice) {
        int next = dice + pos;
        if(board.count(next)) {
            if(board[next] < next) continue;
            next = board[next];
        }
        int throws = mincnt(next, baord);
        if(throws != INT_MAX) minthrow = min(minthrow, throws + 1);
    }
    return tmp[pos] = minthrow;
}
int minthrow(int n, vector <int> arr) {
    /* int n = 8; 
    vector <int> arr{3, 22, 5, 8, 11, 26, 20, 29, 17, 4, 19, 7, 27, 1, 29, 9 };
    cout << minthrow(n, arr) << endl; */
    for(int i = 0; i < 31; i++) tmp[i] = -1;
    unordered_map <int, int> board;
    for(int i = 0; i < 2 * n; i += 2) 
        board[arr[i]] = arr[i + 1];
    return mincnt(1, board);
}
// find the maximum rectangular area under given histogram with n bars 
int maxarea(int *arr, int n) {
    stack <int> st; st.push(-1);
    vector <int> left(n, -1), right(n, n);
    int i = 0, maxarea = 0;
    while(i < n) {
        while(!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i]) {
            right[st.top()] = i; st.pop();
        }
        if(i > 0 && arr[i] == arr[i - 1]) left[i] = left[i - 1];
        else left[i] = st.top();
        st.push(i++);
    }
    while(st.top() != -1) {
        right[st.top()] = n; st.pop();
    }
    for(int i = 0; i < n; i++) 
        maxarea = max(maxarea, arr[i] * (right[i] - left[i] + 1));
    return maxarea;
}
int maxarea(int *arr, int n) {
    stack <int> st;
    int maxarea = 0, tp, i = 0;
    while(i < n) {
        if(st.empty() || arr[st.top()] <= arr[i]) st.push(i++);
        else {
            tp = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxarea = max(maxarea, arr[tp] * width);
        }
    }
    while(!st.empty()) {
        tp = st.top(); st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxarea = max(maxarea, arr[tp] * width);
    }
    return maxarea;
}
// finds the maximum profit path from src to dst node using at 
// most K edges in a graph where edges have negative costs (profits).
int maxcost(int n, vector <vector <int>> adj, int src, int dst, int k) {
    vector <int> tmp(n, INT_MAX);
    tmp[src] = 0;
    for(int i = 0; i <= k; i++) {
        vector <int> cpy = tmp;
        for(auto &v : adj) {
            int a = v[0], b = v[1], c = v[2];
            if(cpy[a] != INT_MAX) {
                tmp[b] = min(tmp[b], cpy[a] - c);
            }
        }
    }
    return tmp[dst] == INT_MAX ? -1 : -tmp[dst];
}
int getmedian(int *arr, int *grp, int n, int m) {
    int i = 0, j = 0, cnt;
    int mid1 = -1, mid2 = -1;
    for(int cnt = 0; cnt <= (m + n) / 2; cnt++) {
        mid2 = mid1;
        if(i != n && j != m) 
            mid1 = (arr[i] > grp[j]) ? grp[j++] : arr[i++];
        else if(i < n) mid1 = arr[i++];
        else mid1 = grp[j++];
    }
    if((m + n) % 2 == 1) return mid1;
    else return (mid1 + mid2) / 2;
}
int getmedian(int *arr, int n) {
    if(n % 2 == 0) {
        int mid = n / 2, val = arr[mid];
        int prv = arr[mid - 1];
        return ((val + prv) >> 1);
    }
    else return arr[round(n / 2)];
}
double medianOfsorted(vector <int> vec, vector <int> tor) {
    if(vec.size() > tor.size()) return medianOfsorted(tor, vec);
    int n = vec.size(), m = tor.size();
    int half = (n + m + 1) / 2;
    int l = 0, r = n;
    while(l <= r) {
        int mid1 = (l + r) / 2;
        int mid2 = half - mid1;
        int l1 = (mid1 = 0 ? INT_MIN : vec[mid1 - 1]);
        int r1 = (mid1 = n ? INT_MAX : vec[mid1]);
        int l2 = (mid2 = 0 ? INT_MIN : tor[mid2 - 1]);
        int r2 = (mid2 = m ? INT_MAX : tor[mid2]);
        if(l1 <= r2 && l2 <= r1) {
            if((n + m) % 2 == 1) return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1 > r2) r = mid1 - 1;
        else l = mid1 + 1;
    }
    return 0.0;
}
double median(vector <int> vec, vector <int> tor) {
    priority_queue <int, vector <int>, greater <int>> pq;
    for(int x : vec) pq.push(x);
    for(int x : tor) pq.push(x);
    int n = vec.size() + tor.size();
    int mid1 = n / 2, mid2 = (n - 1) / 2;
    for(int i = 0; i <= mid2; i++) pq.pop();
    if(n % 2 == 1) return pq.top();
    int x = pq.top(); pq.pop();
    int y = pq.top();
    return (x + y) / 2.0;
}
int findmedian(int *arr, int *grp, int n) {
    int l = 0, r = n - 1;
    vector <int> vec(arr, arr + n);
    vector <int> tor(grp, grp + n);
    while(r >= 0 && l < n && vec[r] > tor[l]) swap(vec[r--], tor[l++]);
    sort(vec.begin(), vec.end());
    sort(tor.begin(), tor.end());
    return (vec[n - 1] + tor[0]) / 2.0;
}
double findMedian(int arr1[], int n, int arr2[], int n2) {
    int total = n + n2;
    auto kthSmallest = [&](int k) -> int {
        int low = -1e9, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            count += upper_bound(arr1, arr1 + n, mid) - arr1;
            count += upper_bound(arr2, arr2 + n2, mid) - arr2;
            if (count >= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    };
    if (total % 2 == 1)
        return kthSmallest(total / 2 + 1);
    return (kthSmallest(total / 2) + kthSmallest(total / 2 + 1)) / 2.0;
}

