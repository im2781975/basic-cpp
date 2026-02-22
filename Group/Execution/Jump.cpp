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
