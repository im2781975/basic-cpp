#include<bits/stdc++.h>
using namespace std;
int dp[101];
int fib(int n) {
    memset(dp, -1, sizeof(dp));
    if(n <= 2) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);  /*
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2]; */
    if(n <= 1) return n;
    vector <int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int ht[101];
int frogjump(int n, int k, int *ht) {
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= k; j++) {
            int from = i - j;
            if(from <= 0) break;
            int res = dp[from] + abs(ht[from] - ht[i]);
            dp[i] = min(res, dp[i]);
        }
    } /*
    for(int i = 2; i <= n; i++) {
        int x = dp[i - 1] + abs(ht[i] - ht[i - 1]);
        if(i == 2) {dp[i] = x; continue;}
        int y = dp[i - 2] + abs(ht[i] - ht[i - 2]);
        dp[i] = min(x, y);
    } */
    cout << dp[n];
}
int frogjump(int n) {
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    int res = INT_MAX, k = 3;
    for(int j = 1; j <= k; j++) {
        if(n - j >= 1) res = min(res, frogjump(n - j) + abs(ht[n] - ht[n - j]));
    }
    dp[n] = res; return res;
}
//choose item from n items.weight of a knapsack is W.find how many items you can choose.
const int x = 1e6;
int dp[102][x], wt[102], val[102];
int knapsack(int n, int cap) { 
    for(int i = 1; i <= n; i++) cin >> wt[i] >> val[i];
    for(int i = 0; i <= cap; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= cap; j++) {
            if(j < wt[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
        }
    } /*
    if(n == 0) return 0;
    if(dp[n][cap] != -1) return dp[n][cap];
    if(cap < wt[n]) return dp[n][cap] = knapsack(n - 1, cap);
    int a = val[n] + knapsack(n - 1, cap - wt[n]);
    int b = knapsack(n - 1, cap);
    dp[n][cap] = max(a, b); */
    return dp[n][cap];
}
//how many ways we can reach from topleft corner to bottomright corner
int dp[102][102];
int movegrid(int row, int col) {
    dp[0][0] = 1;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) continue;
            int res = 0;
            if(i > 0) res += movegrid(i - 1, j);
            if(j > 0) res += movegrid(i, j - 1);
            dp[i][j] = res;
        }
    }
    return dp[row - 1][col - 1]; /*
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    int res = 0;
    if(row > 0) res += movegrid(row - 1, col);
    if(col > 0) res += movegrid(row, col - 1);
    return dp[row][col] = res; */
}
int dp[105][1005];
int subsetsum(int n, int trg, int *arr) {
    if(n == 0) return (trg == 0) ? 1 : 0;
    if(dp[n][trg] != -1) return dp[n][trg];
    int a = subsetsum(n - 1, trg, arr);
    if(trg < arr[n - 1]) return dp[n][trg] = a;
    int b = subsetsum(n - 1, trg - arr[n - 1], arr);
    return dp[n][trg] = a || b; /*
    vector <bool> dp(trg + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = trg; j >= arr[i - 1]; j--) {
            if(dp[j - arr[i - 1]]) dp[j] = true;
        }
    }
    return dp[trg]; */
}
const int x = 1004;
int dp[x][4], joy[x][4];
void maxjoy(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) cin >> joy[i][j];
    } // base day 1
    for(int j = 1; j <= 3; j++)
        dp[1][j] = joy[1][j];
    for(int i = 2; i <= n; i++) {
        for(int cur = 1; cur <= 3; ++cur) {
            int best = 0;
            for(int last = 1; last <= 3; ++last) {
                if(last != cur) best = max(best, dp[i - 1][last] + joy[i][cur]);
            }
            dp[i][cur] = best;
        }
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << endl;
}
void maxjoy(int day, int task) {
    if(day == 1) return joy[day][task];
    if(dp[day][task] != -1) return dp[day][task];
    int best = 0;
    for(int last = 1; last <= 3; ++last) {
        if(last != task) {
            int profit = maxjoy(day - 1, last) + joy[day][task];
            best = max(best, profit);
        }
    }
    return dp[day][task] = best;
}
// counts the number of 1s in a sorted binary array 
// in non‑increasing order. find the last index that is 1;
int cntOnes(bool *arr, int low, int high) {
    if(high >= low) {
        int mid = low + (high - low) >> 1;
        if((mid == high || arr[mid + 1] == 0) && arr[mid] == 1) return mid + 1;
        if(arr[mid] == 1) return cntOnes(arr, mid + 1, high);
        return cntOnes(arr, low, mid - 1);
    }
}
int cntOnes(bool *arr, int n) {
    /* auto ptr = upper_bound(arr, arr + n, 1, greater <int> ());
    cout << (ptr - arr); */
    int low = 0, high = n - 1, res;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(arr[mid] < 1) high = mid - 1;
        else if(arr[mid] > 1) low = mid + 1;
        else {
            if(mid == n - 1 || arr[mid + 1] != 1) return mid + 1;
            else low = mid + 1;
        }
    }
}
// Find the val greater than all values to its left and smaller than all values to its right
bool check(int *arr, int n, int idx) {
    int i = idx - 1, j = idx + 1;
    while(i >= 0) {
        if(arr[i] > arr[idx]) return false; 
        i--;
    }
    while(j < n) {
        if(arr[j] < arr[idx]) return false; 
        j++;
    } return true;
}
void findval(int *arr, int n) {
    int left[n], right[n]; left[0] = INT_MIN;
    for(int i = 1; i < n; i++) left[i] = min(left[i - 1], arr[i - 1]);
    right[n - 1] = INT_MAX;
    for(int i = n - 2; i >= 0; i--)
        right[i] = min(right[i + 1], arr[i + 1]);
    for(int i = 0; i < n; i++) {
        if(left[i] < arr[i] && arr[i] < right[i]) return i;
    } /*
    int leftmin = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > leftmin) {
            bool flag = true;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] >= arr[i]) {
                    flag = false; break;
                }
            }
            if(flag) return i;
        }
        leftmin = max(leftmin, arr[i]);
    } */
    int maxleft = arr[0];
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > maxleft && arr[i] > *max_element(arr + i + 1, arr + n)) return i;
        maxleft = max(maxleft, arr[i]);
    }
    return -1;
}
// Calculate stock span for each day: number of consecutive previous days  where price ≤ current day's price
void calculatespan(int *price, int n, int *res) {
    res[0] = 1; stack <int> st; st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() && price[st.top()] <= price[i]) st.pop();
        res[i] = i - st.empty() ? 0 : st.top();
        st.push(i);
    }
}
void calculatespan(int *price, int n, int *span) {
    stack <int> st; st.push(0);
    span[0] = 1;
    for(int i = 1; i < n; i++) {
        while(!st.empty() && price[st.top()] <= price[i]) st.pop();
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
}
vector <int> calculatespan(int *arr, int n) {
    stack <int> st; vector <int> res;
    for(int i = 0; i < n; i++) {
        while (!st.empty() and arr[st.top()] <= arr[i]) st.pop();
        if(st.empty()) res.push_back(i + 1);
        else res.push_back(i - st.top());
        st.push(i);
    }
    return res;
}
//Function to get index of ceiling of val in arr
int ceilsearch(int *arr, int low, int high, int val) { /*
    while(low <= high) {
        int mid = low + (high - low) >> 1;
        if(arr[mid] == val) return mid;
        else if (val < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return low; */
    if(val <= arr[low]) return low;
    if(val > arr[high]) return -1; /*
    for(int i = low; i < high; i++) {
        if(arr[i] == val) return i;
        if(arr[i] < val && arr[i + 1] >= val) return i + 1;
    } return -1; */
    while(low < high) {
        int mid = low + (high - low) >> 1;
        if(arr[mid] >= val) high = mid;
        else low = mid + 1;
    }
    return arr[low] >= val ? low : -1;
}
void ceilsearch(vector <int> arr, int val) {
    auto it = lower_bound(arr.begin(), arr.end(), val);
    if (it == arr.end()) cout << val << " ceil doesn't exist";
    else cout << val << " " << *it << endl;
}
// Find celebrity in party: person known by everyone else but knows no one
int celebrity(vector <vector <int>> grid) {
    int n = grid.size(), idx = 0;
    for(int i = 0; i < n; i++) { if(grid[idx][i] == 0) idx = i; }
    for(int i = 0; i < n; i++) { if(grid[idx][i] == 1) return -1; }
    for(int i = 0; i < n; i++) {
        if(i != idx && grid[i][idx] == 0) return -1;
    } return idx;
}
bool grid[8][8]{ {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
bool knows(int a, int b){ grid[a][b] = 1;}
int celebrity(int n) {
    int cand = 0;
    for(int i = 1; i < n; i++) {
        if(knows(cand, i)) cand = i;
    }
    for(int i = 0; i < n; i++) {
        if(i != cand && (knows(cand, i) || !knows(i, cand)))
            return -1;
    } return cand;
}
int celebrity(int grid[4][4], int n) {
    int cand = 0;
    for(int i = 1; i < n; i++) {
        if(grid[cand][i] == 1) cand = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != cand && (grid[cand][i] == 1 || grid[i][cand] == 0)) return -1;
    }
    return cand;
}
vector<int> merge(vector <int> arr) {
    if(arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    vector <int> left = merge(vec);
    vector <int> right = merge(tor);
    vector <int> res;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) res.push_back(left[i++]);
        else res.push_back(right[j++]);
    }
    while(i < left.size()) res.push_back(left[i++]);
    while(j < right.size()) res.push_back(right[j++]);
    return res;
}
vector <int> merged(vector <int> vec, vector <int> tor) {
    vector <int> res;
    int len = vec.size() + tor.size();
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < len; i++) {
        if(idx1 == vec.size()) res.push_back(tor[idx2++]);
        else if(idx2 == tor.size()) res.push_back(vec[idx1++]);
        else if(vec[idx1] > tor[idx2]) res.push_back(tor[idx2++]);
        else res.push_back(vec[idx1++]);
    }
    return res;
}
vector <int> divide(vector <int> arr) {
    if(arr.size() <= 1) return arr;
    int len = arr.size();
    vector <int> x, y;
    for(int i = 0; i < len / 2; i++) x.push_back(arr[i]);
    for(int i = len / 2; i < len; i++) y.push_back(arr[i]);
    vector <int> vec = divide(x);
    vector <int> tor = divide(y);
    return merged(vec, tor);
}
//checks two numbers in the array which sums to trg
bool twin_point(vector <int> arr, int trg) {
    int idx1 = 0, idx2 = arr.size() - 1;
    while(idx1 < idx2) {
        if(arr[idx1] + arr[idx2] == trg) return true;
        else if(arr[idx1] + arr[idx2] > trg) idx2--;
        else idx1++;
    }
    return false;
}
vector <int> twin_sum(vector <int> arr, int trg) {
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == trg) return {l, r};
        else if(sum > trg) r--;
        else l++;
    }
    return {};
}
vector <int> RemoveDup(vector <int> arr) {
    vector <int> tor(arr.begin(), arr.end()); arr.clear();
    arr = divide(tor);
    vector <int> Dup;
    if(!arr.empty()) Dup.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1]) Dup.push_back(arr[i]);
    }
    return Dup;
}
bool Bsearch(vector <int> arr, int low, int high, int trg) {
    while(low <= high) {
        int mid = low + (high - low) >> 1;
        if(arr[mid] == trg) return true;
        else if(arr[mid] > trg) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
int pairsum(vector <int> vec, int trg) {
    vector <int> tor(vec.begin(), vec.end()); vec.clear();
    vec = merge(tor);
    int cnt = 0;
    for(int i = 0; i < vec.size(); i++) {
        int val = trg - vec[i];
        if(Bsearch(vec, i + 1, vec.size() - 1, val)) cnt++;
    }
    return cnt;
}
// counts the number of inversions in the array using Merge.
//number of inversions in an array is a measure of how far the array is from being sorted.
int cnt = 0;
int invcnt(vector <int> vec, vector <int> tor, vector <int> res) {
    int i = 0, j = 0, inv = 0;
    while(i < vec.size() && j < tor.size()) {
        if(vec[i] <= tor[j]) res.push_back(vec[i++])
        else {
            res.push_back(tor[j++]);
            inv += vec.size() - i;
        }
    }
    while(i < vec.size()) res.push_back(vec[i++])
    while(j < tor.size()) res.push_back(tor[j++])
    return inv;
}
int merg(vector <int> arr) {
    if(arr.size() <= 1) return 1;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    merg(vec); merg(tor);
    cnt += invcnt(vec, tor, arr);
}
int cnt = 0; 
int merged(vector <int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l, inv = 0;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            inv += (n1 - i); 
        }
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
    return inv;
}
int invcnt(vector <int> arr, int l, int r) {
    // l = 0, r = arr.size() - 1;
    if(l >= r) return 0;
    int mid = l + (r - l) / 2; int inv = 0;
    inv += invcnt(arr, l, mid);
    inv += invcnt(arr, mid + 1, r);
    inv += marged(arr, l, mid, r);
    return inv;
} 
bool cmp(pair <int, int> x, pair <int, int> y) {
    if(x.first != y.first) return x.first > y.first;
    return x.second < y.second;
}
void reorder(int *arr, int *idx, int n) {
    vector <pair <int, int>> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i].first = arr[i];
        vec[i].second = idx[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; i++) arr[i] = vec[i].first;
}
void reorder(int *arr, int *idx, int n) {
    for(int i = 0; i < n; i++) {
        while(idx[i] != i) {
            int dig = idx[idx[i]];
            char ch = arr[idx[i]];
            idx[idx[i]] = idx[i];
            arr[idx[i]] = arr[i];
            idx[i] = dig;
            arr[i] = ch;
        }
    }
}
void reorder(int *arr, int *idx, int n) {
    int tmp[n];
    for(int i = 0; i < n; i++) tmp[idx[i]] = arr[i];
    for(int i = 0; i < n; i++) {
        arr[i] = tmp[i]; idx[i] = i;
    }
}
