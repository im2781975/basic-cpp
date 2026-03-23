#include<bits/stdc++.h>
using namespace std;
int dp[101];
void fib(int n) {
    if(n <= 2) return 1;
    memset(dp, -1, sizeof(dp));
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
    /*
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n]; */
}
int fib(int n) {
    if(n <= 1) return n;
    vector <int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
// frog can jump on stone i..i+2..i+k.here |hi-hj| will be incurred where j is 
// the stone where landed.find min possible total cost reaching nth stone.
int height[101];
void frogJump(int n, int k, int *height) {
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= k; j++) {
            int rockfrom = i - j;
            if(rockfrom <= 0) break;
            int res = dp[rockfrom] + abs(height[i] - height[rockfrom]);
            dp[i] = min(dp[i], res);
        }
    } /*
    for(int i = 2; i <= n; i++) {
        int x = dp[i - 1] + abs(height[i] - height[i - 1]);
        if(i == 2) {
            dp[i] = x; continue;
        }
        int y = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(x, y);
    } */
    cout << dp[n];
}
void fromJump(int n) {
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    int res = INT_MAX, k = 3;
    for(int j = 1; j <= k; j++) {
        if(n - j >= 1) {
            int ans = frogJump(n - j) + abs(h[n] - h[n - j]);
            res = min(res, ans);
        }
    }
    dp[n] = res; return res;
}
//choose item from n items.weight of a knapsack is W.find how many items you can choose.
const int x = 1e6;
int dp[102][x], wt[102], val[102];
void knapsack(int n, int cap) {
    for(int i = 1; i <= n; i++) cin >> wt[i] >> val[i];
    for(int i = 0; i <= cap; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= cap; j++) {
            if(j < wt[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
        }
    }
    cout << dp[n][cap];
}
int knapsack(int n, int cap) {
    if(n == 0) return 0;
    if(dp[n][cap] != -1) return dp[n][cap];
    if(cap < wt[n]) int res = knapsack(n - 1, cap);
    int a = val[n] + knapsack(n - 1, cap - wt[n]);
    int b = knapsack(n - 1, cap);
    int res = max({a, b}); dp[n][cap] = res; return res;
}
//how many ways we can reach from top_left corner to bottom_right corner.
int dp[102][102];
int movegrid(int row, int col) {
    dp[0][0] = 1;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) continue;
            int res = 0;
            if(i > 0) res += dp[i - 1][j];
            if(j > 0) res += dp[i][j - 1];
            dp[i][j] = res;
        }
    }
    return dp[row - 1][col - 1];
}
int movegrid(int row, int col) {
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    int res = 0;
    if(row > 0) res += movegrid(row - 1, col);
    if(col > 0) res += movegrid(row, col - 1);
    dp[row][col] = res; return res;
}
int arr[102];
int subsetsum(int n, int trg) {
    if(n == 0) {
        if(trg == 0) return 1;
        return 0;
    }
    if(dp[n][trg] != -1) return dp[n][trg];
    int a = subsetsum(n - 1, trg);
    if(trg < arr[n]) {
        dp[n][trg] = a; return a;
    }
    int b = subsetsum(n - 1, trg - arr[n]);
    int res = a || b;
    dp[n][trg] = res; return res;
}
int subsetsum(int n, int trg, int *arr) {
    vector <bool> dp(trg + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = trg; j >= arr[i]; j--) {
            if(dp[j - arr[i]]) dp[j] = true;
        }
    }
    return dp[trg];
}
//count maximum happiness
const int N = 1005;
int happiness[N][4], dp[N][4];
void maxhappiness(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) cin >> happiness[i][j];
    }
    for(int task = 1; task <= 3; task++)
        dp[1][task] = happiness[1][task];
    for(int day = 2; day <= n; day++) {
        for(int cur = 1; cur <= 3; cur++) {
            int maxprofit = 0;
            for(int last = 1; last <= 3; last++) {
                if(last != cur) {
                    int curprofit = dp[day - 1][last] + happiness[day][cur];
                    maxprofit = max(maxprofit, curprofit);
                }
            }
            dp[day][cur] = maxprofit;
        } 
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
}
void maxhappiness(int day, int task) {
    /*int max_happiness = 0;
    for (int i = 1; i <= 3; i++) {
        max_happiness = max(max_happiness,maxhappiness(n, i));
    } */
    if(day == 1) return happiness[day][task];
    if(dp[day][task] != -1) return dp[day][task];
    int max_profit = 0;
    for (int last = 1; last <= 3; last++) {
        if (last != task) {
            int candidate_profit = maxhappiness(day - 1, last) + happiness[day][task];
            max_profit = max(max_profit, candidate_profit);
        }
    }
    dp[day][task] = max_profit;
    return max_profit;
}
// count one's in a boolean array
int cntOnes(bool *arr, int low, int high) {
    if(high >= low) {
        int mid = low + (high - low) >> 1;
        if((mid == high || arr[mid + 1] == 0) && arr[mid] == 1) return mid + 1;
        if(arr[mid] == 1) return cntOnes(arr, mid + 1, high);
        return cntOnes(arr, low, mid - 1);
    }
    return 0;
}
int countOnes(bool arr[], int n) {
    /* auto ptr = upper_bound(arr, arr + n, 1, greater <int> ());
    cout << (ptr - arr); */
    int low = 0, high = n - 1, res;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < 1) high = mid - 1;
        else if (arr[mid] > 1) low = mid + 1;
        else {
            if (mid == n - 1 || arr[mid + 1] != 1) return mid + 1;
            else low = mid + 1;
        }
    }
}
// Find the val greater than all values to its left and smaller than all values to its right.
bool check(int *arr, int n, int idx) {
    int i = idx - 1, j = idx + 1;
    while(i >= 0) {
        if(arr[i] > arr[idx]) return false;
        i--;
    }
    while(j < n) {
        if(arr[j] < arr[idx]) return false;
        j++;
    }
    return true;
}
int findval(int *arr, int n) {
    int left[n]; left[0] = INT_MIN;
    for(int i = 1; i < n; i++)
        left[i] = min(left[i - 1], arr[i - 1]);
    int right = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        if(left[i] < arr[i] && right > arr[i]) return i;
        right = min(right, arr[i]);
    }
    return -1;
}
int findval(int *arr, int n) {
    if(n <= 2) return -1;
    int maxleft = arr[0], candid = -1;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > maxleft) {
            maxleft = arr[i]; continue;
        }
        bool rightgreater = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] <= arr[i]) {
                rightgreater = false; break;
            }
        }
        if(rightgreater) return i;
    }
    return -1;
}
// Calculate stock span for each day: number of consecutive previous days 
// (including today) where price ≤ current day's price
int calculatespan(int *price, int n, int *res) {
    res[0] = 1;
    for(int i = 1; i < n; i++) {
        int counter = 1;
        while ((i - counter) >= 0 && price[i] >= price[i - counter])
            counter += res[i - counter];
        res[i] = counter;
    }
}
// calculate stock span values
void calculatespan(int *price, int n, int *span) {
    span[0] = 1;
    for(int i = 1; i < n; i++) {
        span[i] = 1;
        for(int j = i - 1; (j >= 0 && (price[i] >= price[j])); j++) {
                span[i]++;
        }
    }
    
    stack <int> st; st.push(0);
    span[0] = 1;
    for(int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i]) st.pop();
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
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
//Function to get index of ceiling of val in arr[]
int ceilsearch(int *arr, int low, int high, int val) {
    int i;
    if(val <= arr[low]) return low;
    for(int i = low; i < high; i++) {
        if(arr[i] == val) return i;
        if(arr[i] < val && arr[i + 1] >= val) return i + 1;
    }
    return -1;
}
int ceilsearch(int *arr, int low, int hight, int val) {
    if(val <= arr[low]) return low;
    if(val > arr[high]) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == val) return mid;
    else if (arr[mid] < val) {
        if (mid + 1 <= high && val <= arr[mid + 1]) return mid + 1;
        return ceilsearch(arr, mid + 1, high, val);
    }
    if (arr[mid - 1] >= val) return ceilsearch(arr, low, mid - 1, val);
    return mid;
}
int ceilsearch(int *arr, int low, int high, int val) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) return mid;
        else if (val < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
void ceilsearch(vector <int> arr, int val) {
    auto it = lower_bound(arr.begin(), arr.end(), val);
    int idx = it - arr.begin();
    if(idx == arr.size()) cout << "ceil val doesn't exits";
    else cout << val << " " << arr[idx] << endl;
}
// Find celebrity in party: person known by everyone else but knows no one
int celebrity(vector <vector <int>> grid) {
    int n = grid.size(), cand = 0;
    for(int i = 0; i < n; i++) {
        if(grid[cand][i] == 0) cand = i;
    }
    for(int i = 0; i < n; i++) {
        if(grid[cand][i] == 1) return -1;
    }
    for(int i = 0; i < n; i++) {
        if(i != cand && grid[i][cand] == 0) return -1;
    }
    return cand;
}
// Find celebrity in party: person known by everyone else 
//but knows no one (given adjacency matrix M where M[i][j]=1 means i knows j).
bool grid[8][8]{ {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
bool knows(int a, int b) {return grid[a][b];}
int celebrity(int n) {
    int cand = 0;
    for (int i = 0; i < n; i++) {
        if (knows(cand, i) == 0) cand = i;
    }
    for (int i = 0; i < n; i++) {
        if (knows(cand, i)) return -1;
    }
    for (int i = 0; i < n; i++) {
        if (i != cand && !knows(i, cand)) return -1;
    }
    return cand;
}
int findCelebrity(int n) {
    int arr[n] = {0}, ray[n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = knows(i, j);
            ray[i] += x; arr[j] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == n - 1 && ray[i] == 0) return i;
    }
    return -1;
}
int findcelebrity(int n) {
    stack <int> st; int cand;
    for(int i = 0; i < n; i++) st.push(i);
    while(st.size() > 1) {
        int x = st.top(); st.pop(); 
        int y = st.top(); st.pop();
        if(knows(x, y)) st.push(y);
        else st.push(x);
    }
    cand = st.top(); st.pop();
    for (int i = 0; i < n; i++) {
        if ((i != cand) && (knows(cand, i) || !knows(i, cand)))
            return -1;
    }
    for(int i = 0; i < n; i++) {
        if(i != cand && (knows(cand, i) || !knows((i, cand)))) return -1;
    }
    return cand;
}
int celebrity(int n) {
    int id = find(n);
    if (id == -1) return id;
    else {
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(i != id) {
                x += knows(id, i);
                y += knows(i, id);
            }
        }
        if(x == 0 && y == n - 1) return id;
    }
    return -1;
}
int find(int n) {
    if(n == 0) return -1;
    int id = find(n - 1);
    if(id == -1) return n - 1;
    else if(knows(id, n - 1)) return n - 1;
    else if(knows(n - 1, id)) return id;
    return -1;
}
int celebrity(int grid[4][4], int n) {
    int cand = 0;
    for(int i = 1; i < n; i++) {
        if(grid[cand][i] == 1) cand = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            if (grid[cand][i] == 1 || grid[i][cand] == 0) return -1;
        }
    }
    return cand;
}
