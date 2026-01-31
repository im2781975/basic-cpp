#include<bits/stdc++.h>
using namespace std;
int minlength(vector <int> vec) {
    vector <int> tmp(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    int start = 0, end = 0;
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i] != tmp[i]) {
            start = i; break;
        }
    }
    for(int i = vec.size() - 1; i >= 0; i--) {
        if(vec[i] != tmp[i]) {
            end = i; break;
        }
    }
    return (end - start + 1);
}
// Returns max profit with two transactions on a given list of stock prices
int func(int idx, int buy, int *prices, vector <vector <vector <int>>> dp, int cap, int n) {
    if(cap == 0 || idx == n) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    int profit = 0;
    if(buy == 0)
        dp[idx][buy][cap] = profit = max(-prices[idx] + func(idx + 1, 1, prices, dp, cap, n), func(idx + 1, 0, prices, dp, cap, n));
    else dp[idx][buy][cap] = profit = max(prices[idx] + func(idx + 1, 0, prices, dp, cap - 1, n), func(idx + 1, 1, prices, dp, cap, n));
    return dp[idx][buy][cap];
}
int func(int idx, int buy, int *prices, int cap, int n){
    if(cap == 0 || idx == n) return 0;
    int profit = 0;
    if(buy == 0) profit = max(-prices[idx] + func(idx + 1, 1, prices, cap, n), func(idx + 1, 0, prices, cap, n);
    
    else profit = max (prices[idx] + func(idx + 1, 0, prices, cap - 1, n), func(idx + 1, 1, prices, cap, n));
}
int maxprofit(int *prices, int n) {
    vector <vector <vector <int>>> dp(n, vector <vector <int>>(2, vector <int>(3, -1)));
    return func(0, 0, prices, dp, 2, n);
    // return func(0, 0, prices, 2, n);
}
int maxprofit(int *arr, int n) {
    int buy1 = buy2 = INT_MIN;
    int sell1 = sell2 = 0;
    for(int i = 0; i < n; ++i) {
        int buy1 = max(buy1, -arr[i]);
        int sell1 = max(sell1, buy1 + arr[i]);
        int buy2 = max(buy2, sell1 - arr[i]);
        int sell2 = max(sell2, buy2 + arr[i]);
    }
    return sell2;
}
int maxprofit(int *price, int n) {
    int profit[n];
    for(int i = 0; i < n; i++) profit[i] = 0;
    int maxprice = price[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(price[i] > maxprice) maxprice = price[i];
        profit[i] = max(profit[i + 1], maxprice - price[i])
    }
    int minprice = price[0];
    for(int i = 1; i < n; i++) {
        if(price[i] < minprice) minprice = price[i];
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - minprice));
    }
    return profit[n - 1];
}
// LCM Queries
int gcd(int a, int b){
    int (b == 0) return a;
    return(b, a % b);
}
int lcm(int a, int b){ return a * b / gcd(a, b); }
vector <int> Query(vector <int> vec, vector <pair <int, int>> Qry) {
    vector <int> res;
    for(const auto &q : Qry) {
        int l = q.first; r = q.second;
        int val = vec[l];
        for(int i = l + 1; i <= r; i++) 
            val = lcm(val, vec[i]);
        res.push_back(res);
    }
    return res;
}
void bound(vector <int> vec, int val) {
    cout << lower_bound(vec.begin(), vec.end(), val) - vec.begin();
    cout << upper_bound(vec.begin(), vec.end(), val) - vec.begin();
}
void intersection(vector <int> vec, vector <int> tor) {
    unordered_set <int> st(vec.begin(), vec.end());
    vector <int> res;
    for(int i = 0; i < tor.size(); ++i) {
        if(st.find(tor[i]) != st.end()) res.push_back(tor[i]);
    }
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
}
//check whether permutation of two arrays satisfy the condition a[i] + b[i] >= k
bool checkcond(vector <int> vec, vector <int> ray, int n, int k) {
    sort(arr, arr + n), sort(ray, ray + n, greater <int> ());
    for(int i = 0; i < n; i++) {
        if(arr[i] + ray[i] < k) return false;
    }
    return true;
}
void cyclesum(int *arr, int n) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < n; ++j) {
            int idx = (i + j) % n; sum += j * arr[idx];
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}
// Returns max possible value of i*arr[i]
void maxsum(int *arr, int n) {
    int sum = 0, cur = 0;
    for(int i = 0; i < n; ++i) {
        sum += arr[i]; cur += (i * arr[i]);
    }
    int maxi = cur;
    for(int j = 1; j < n; j++) {
        cur = cur + sum - (n * arr[n - j]);
        if(cur > maxi) maxi = cur;
    }
    return maxi;
}
// Program to make all array equal
bool ispairsum(int *arr, int n, int x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(arr[i] + arr[j] == x) return true;
            if(arr[i] + arr[j] > x) break;
        }
    }
    return false;
}
// find if there is a pair in arr with a given sum.
int ispairsum(vector <int> vec, int n, int x) {
    int i = 0, j = n - 1;
    while(i < j) {
        if(arr[i] + arr[j] == x) return 1;
        else if(arr[i] + arr[j] > x) j--;
        else i++;
    }
    return 0;
}
// function for calculating min operations
int minoperation(int *arr, int n, int x) {
    int mx = *max_element(arr, arr + n);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        if((mx - arr[i]) % x != 0) return -1;
        else res += (mx - arr[i]) / x;
    }
    return res;
}
#include<bits/stdc++.h>
using namespace std;
void Missing(int *arr, int n) {
    sort(arr, arr + n);
    for(int x = 1; x <= 10; ++x) {
        auto it = lower_bound(arr, arr + n, x);
        if(it == arr + n || *it != x) cout << x << " ";
    }
}
void Missing(int *arr, int n) {
    for(int i = 1; i <= 10; i++) {
        bool found = false;
        for(int j = 1; j <= n; j++) {
            if(arr[j] == i) {
                found = true; break;
            }
        }
        if(!found) cout << i << " ";
    } /*
    unordered_set <int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    for(int i = 1; i <= 10; i++) {
        if(st.find(i) == st.end()) cout << i << " ";
    } */
}
void Missing(int *arr, int n) {
    int low = 1, high = 10;
    bool range[high - low + 1] = {false};
    for(int i = 0; i < n; i++) {
        if(low <= arr[i] && high >= arr[i])
            range[arr[i] - low] = true;
    }
    for(int x = 0; x <= high - low; x++) {
        if(!range[x]) cout << low + x << " ";
    }
}
int Missing(int *arr, int start, int end) {
    if(start > end) return end + 1;
    if(start != arr[start]) return start;
    int mid = (start + end) / 2;
    if(mid == arr[mid]) return Missing(arr, mid + 1, end);
    else return Missing(arr, start, mid);
}
int Missing(vector <int> arr, int low, int high, int val) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == mid) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
void smallestMissing(vector <int> arr) {
    if(arr.empty() || arr[0] != 0) return 0;
    if(arr.back() == static_cast <int> (arr.size() - 1)) return arr.size();
    return Missing(arr, 0, arr.size() - 1, arr[0]);
}
//Find missing in range
int Missing(int *arr, int n, int range) {
    vector <int> vec(range, 0);
    for(int i = 0; i < n; i++) vec[arr[i]] = 1;
    for(int i = 0; i < range; i++) {
        if(vec[i] == 0) return i;
    }
}
int Missing(vector <int> arr, int low, int high, int val) {
    if(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] != mid + val)
            return Missing(arr, low, mid, val);
        else return Missing(arr, mid + 1, high, val);
    }
    return low + val;
}
int nthMissing(int *arr, int n, int idx) {
    sort(arr, arr + n);
    if(idx < arr[0]) return idx;
    if(idx == arr[0]) return arr[0] + 1;
    if(idx > arr[n - 1]) return idx + n;
    if(arr[0] == 1) idx--;
    else idx -= (arr[0] - 1);
    for(int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1] - 1;
        if(idx <= diff) return arr[i - 1] + idx;
        else idx -= diff;
    }
    return arr[n - 1] + idx;
}
#define x 1e8
int nthMissing(int *arr, int n, int idx) {
    bool vis[x + 1] = {false};
    for(int i = 0; i < n; ++i) {
        if(arr[i] > 0 && arr[i] <= x) vis[arr[i]] = true;
    }
    for(int i = 1; i <= x; i++) {
        if(!vis[i] && idx-- == 1) return i;
    }
    return -1;
}
int nthMissing(int *arr, int n, int idx) {
    unordered_set <int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    int val = 1;
    while(idx > 0) {
        if(st.count(val) == 1) val++;
        else {
            val++; idx--;
        }
    }
    return val - 1;
}
int nthMissing(int *arr, int n, int idx) {
    int mx = *max_element(arr, arr + n);
    vector <int> vec(mx + 2, 0);
    for(int i = 0; i < n; i++) vec[arr[i]]++;
    int val = 1;
    while(idx > 0) {
        if(vec[val] == 0) idx--;
        else vec[val]--;
        val++;
        if(idx == 0) return val - 1;
    }
}
void nthMissing(int *arr, int n, int k) {
    priority_queue <int> pq;
    for(int i = 0; i < k; i++) pq.push(arr[i]);
    for(int i = k; i < n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop(); pq.push(arr[i]);
        }
    }
    vector <int> res;
    while(!pq.empty()) {
        res.push_back(pq.top()); pq.pop();
    }
    for(int i = 0; i < k; i++) cout << res[k - 1 - i] << " ";
    cout << endl;
}
bool cmp(int a, int b) { return a < b; }
void opr(int *arr, int n) {
    nth_element(arr, arr + 3, arr + n);
    sort(arr, arr + n, greater <int> ());
    nth_element(arr, arr + 3, arr + n, cmp);
}
