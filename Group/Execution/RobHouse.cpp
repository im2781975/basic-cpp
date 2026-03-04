#include<bits/stdc++.h>
using namespace std;
string firstDup(string str) {
    int cnt[26] = {};
    queue <char> q; string res = "";
    for(char ch : str) {
        int idx = ch - 'a'; cnt[idx]++;
        q.push(ch);
        while (!q.empty() && cnt[q.front() - 'a'] > 1) q.pop();
        res += q.empty() ? '#' : q.front();
    }
    return res;
}
string firstDup(string str) {
    // string str = "geeksforgeeksandgeeksquizfor";
    unordered_map <char, int> mp; string res = ""; /*
    for(int i = 0; i < str.length(); i++) {
        if(mp.find(str[i]) == mp.end()) {
            mp[str[i]] = 1; res += str[i];
        }
        else res += '#';
    } */
    queue <char> q;
    for(int i = 0; i < str.length(); i++) {
        if(mp.find(str[i]) == mp.end()) q.push(str[i]);
        mp[str[i]]++;
        while(!q.empty() && mp[q.front()] > 1) q.pop();
        if(!q.empty()) res += q.front();
        else res += '#';
    }
    return res;
}
// returns true if arr[] has a pair with sum equals to x
bool pairfind(int *arr, int n, int x) {
    int i;
    for(i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) break;
    }
    int l = (i + 1) % n, r = i;
    while(l != r) {
        if(arr[l] + arr[r] == x) return true;
        if(arr[l] + arr[r] < x) l = (l + 1) % n;
        else r = (n + r - 1) % n;
    }
    return false;
}
bool pairfind(int *arr, int n, int x) {
    int piv = 0;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            piv = i + 1; break;
        }
    }
    int left = piv, right = piv - 1;
    while(left != right) {
        if(arr[left] + arr[right] == x) return true;
        else if(arr[left] + arr[right] < x) left = (left + 1) % n;
        else right = (n + right - 1) % n;
    }
    return false;
}
// Given two arrays, check if one array is stack permutation of other.
bool stackpermutation(int *arr, int *grp, int n) {
    queue <int> que, ue;
    for(int i = 0; i < n; i++) que.push(arr[i]);
    for(int i = 0; i < n; i++) ue.push(grp[i]);
    stack <int> tmp;
    while(!que.empty()) {
        int val = que.front(); que.pop();
        if(val == ue.front()) {
            ue.pop();
            while(!tmp.empty()) {
                if(tmp.top() == ue.front()) {
                    tmp.pop(); ue.pop();
                }
                else break;
            }
        }
        else tmp.push(val);
    }
    return (que.empty() && tmp.empty());
}
bool checkpermutation(int *arr, int *grp, int n) {
    stack <int> st; int j = 0;
    for(int i = 0; i < n; i++) {
        st.push(arr[i]);
        while(!st.empty() && st.top() == grp[j]) {
            st.pop(); j++;
        }
    }
    return st.empty();
}
void slidemax(int *arr, int n, int k) {
    for(int i = 0; i <= n - k; i++) {
        int maxi = *max_element(arr + i, arr + i + k); 
        cout << maxi << " ";
    }
}
// finds the largest value in every contiguous subarray of fixed size k
vector <int> maxslidingwindow(vector <int> arr, int k) {
    vector <int> res;
    priority_queue <pair <int, int>> pq;
    for(int i = 0; i < k; i++) pq.push({arr[i], i});
    res.push_back(pq.top().first);
    for(int i = k; i < arr.size(); i++) {
        pq.push({arr[i], i});
        while(!pq.empty() && pq.top().second <= i - k) pq.pop();
        res.push_back(pq.top().first);
    }
    return res;
}
vector <int> maxslidingwindow(vector <int> arr, int k) {
    vector <int> res;
    set <pair <int, int>, greater <pair <int, int>>> st;
    for(int i = 0; i < k; i++) st.insert({arr[i], i});
    res.push_back(st.begin() -> first);
    for(int i = k; i < arr.size(); i++) {
        st.insert({arr[i], i});
        auto it = st.begin();
        while(it != st.end() && it -> second <= i - k) it = st.erase(it);
        res.push_back(st.begin() -> first);
    }
    return res;
}
void maxslidingwindow(int *arr, int n, int k) {
    deque <int> dq;
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && arr[i]] >= arr[dq.front()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
    for(int i = k; i < n; i++) {
        if(dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && arr[i] >= arr[dq.front()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}
int maxInbitonic(int *arr, int low, int high) {
    while(low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if(arr[mid1] < arr[mid2]) low = mid1 + 1;
        else high = mid2 - 1;
    }
    return arr[low];
}
int findmax(int *arr, int n) {
    stack <int> st;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[i] > arr[st.top()]) {
            maxi = max(maxi, arr[st.top()]); st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        maxi = max(maxi, arr[st.top()]); st.pop();
    }
    return maxi;
}
int findMaximum(int arr[], int low, int high) {
    if (low == high) return arr[high];
    int mid = low + (high - low) / 2;
    if (mid > low && mid < high && arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid];
    if (mid < high && arr[mid] < arr[mid + 1])
        return findMaximum(arr, mid + 1, high);
    else return findMaximum(arr, low, mid);
}
// Max money from houses without robbing adjacent ones
int rob(vector <int> nums) {
    int n = nums.size(); 
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    vector <int> robhose(n), skiphouse(n);
    robhouse[0] = nums[0]; skiphouse[0] = 0;
    for(int i = 1; i < nums.size(); ++i) {
        robhouse[i] = skiphouse[i - 1] + nums[i];
        skiphouse[i] = max(robhouse[i - 1], skiphouse[i - 1]);
    }
    return max(robhouse[n - 1], skiphouse[n - 1]);
}
int rob(vector <int> nums) {
    int prv1 = prv2 = 0;
    for(int money : nums) {
        int tmp = max(prv1, prv2 + money);
        prv2 = prv1;
        prv1 = tmp;
    }
    return prv1;
}
// Max money from circular houses without robbing adjacent ones (first+last adjacent).
int robrange(vector <int> nums, int start, int end) {
    int prv1 = prv2 = 0;
    for(int i = start; i <= end; i++) {
        int cur = max(prv1, prv2 + nums[i]);
        prv2 = prv1; prv1 = cur;
    }
    return prv1;
}
int rob(vector <int> houses) {
    int n = houses.size();
    if(n == 1) return houses[0];
    return max(robrange(houses, 0, n - 1), robrange(houses, 0, n - 2));
}
// Max coins from monsters, but can't take from 2 adjacent ones.
int maxgold(vector <int> demongold) {
    int n = demongold.size();
    vector <int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--)
        dp[i] = max(demongold[i] + dp[i + 2], dp[i + 1]);
    return dp[0];
}
void moneysum(vector <int> coin) {
    int n = coin.size(); set <int> st;
    // (1 << n) -> modified to binary bits
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) sum += coin[j];
        }
        st.insert(sum);
    }
    for(int res : st) cout << res << " ";
}
void moneysum(vector <int> coin, int i, int sum, set <int> st) {
    if(i == coin.size()) {
        st.insert(sum); return;
    }
    moneysum(coin, i + 1, sum + coin[i], st);
    moneysum(coin, i + 1, sum, st);
}
// calculate the number of distinct ways you can produce a money sum amount
int cntways(vector <int> coin, int amt) {
    vector <int> dp(amt + 1, 0); dp[0] = 1;
    for(int i = 0; i < coin.size(); i++) {
        for(int j = coin[i]; j <= amt; j++)
            dp[j] += dp[j - coin[i]];
    }
    return dp[amt];
}
// Count coin combinations to make exact amount
int coinchange(int amt, vector <int> coin) {
    vector <int> dp(amt + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < coin.size(); i++) {
        int val = coin[i];
        for(int j = val; j <= amt; j++)
            dp[j] += dp[j - val];
    }
    return dp[amt];
}
int coinchange(vector <int> coin, int amt) {
    vector <int> dp(amt + 1, amt + 1);
    dp[0] = 0;
    for(int i = 1; i <= amt; i++) {
        for(int j = 0; j < coin.size(); j++) {
            if(i >= coin[j])
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    return dp[amt] > amt ? -1 : dp[amt];
}
// Count ways to climb n stairs taking 1-6 steps at a time
int climbstair(int n) {
    vector <int> dp(n + 1, 0); dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int step = 1; step <= 6 && step <= i; step++)
            dp[i] += dp[i - step];
    }
    return dp[n];
}
// Return the minimum cost to reach the top of the floor
int mincostclimbstair(vector <int> cost) {
    int n = cost.size(); 
    vector <int> dp(n, 0);
    dp[0] = cost[0]; dp[1] = cost[1];
    for(int i = 2; i < n; i++)
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    return min(dp[n - 1], dp[n - 2]);
    /*for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n]; */
}
