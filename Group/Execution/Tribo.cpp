#include<bits/stdc++.h>
using namespace std; 
char arr[] = {'S', 'A', 'D'};
vector <stack <int>> st(3);
void move(int a, int b) {
    if(st[b].empty() || (!st[a].empty() && st[a].top() < st[b].top())) {
        cout << st[a].top() << " " << arr[a] << " " << arr[b] << endl;
        st[b].push(st[a].top()); st[a].pop();
    }
    else move(b, a);
}
void Hanoi(int n) {
    int src = 0, aux = 1, dst = 2;
    for(int i = n; i > 0; i--) st[src].push(i);
    int moves = (1 << n) - 1;
    if(n % 2 == 0) swap(aux, dst);
    for(int i = 1; i <= moves; i++) {
        if(i % 3 == 0) move(aux, dst);
        else if(i % 3 == 1) move(src, dst);
        else move(src, aux);
    }
} 
stack <int> S, A, D;
void move(stack <int> &from, stack <int> &to, char start, char end) {
    if(from.empty()) return;
    int disk = from.top();
    if(to.empty() || disk < to.top()) {
        cout << disk << " " << start << " " << end << endl;
        to.push(disk);
        from.pop();
    }
}
void Hanoi(int n) {
    cout << n << "\n";
    for(int i = n; i >= 1; --i) S.push(i);
    int moves = (1 << n) - 1;
    for(int i = 1; i <= moves; ++i) {
        if(i % 3 == 1) move(S, D, 'S', 'D');
        else if(i % 3 == 2) move(S, A, 'S', 'A');
        else move(A, D, 'A', 'D');
    }
} 
bool issortable(int *arr, int n) {
    stack <int> st; int assume = 1;
    for(int i = 0; i < n; i++) {
        st.push(arr[i]);
        while(!st.empty() && st.top() == assume) {
            st.pop(); assume++;
        }
    }
    return st.empty();
}
// Find Intersection of three pointer
void findcommon(vector <int> vec, vector <int> ect, vector <int> tor) {
    unordered_set <int> st1(vec.begin(), vec.end());
    unordered_set <int> st2(ect.begin(), ect.end());
    for(int x : tor) {
        if(st1.count(x) && st2.count(x)) cout << x << " ";
    }
    cout << endl;
} 
int findcommon(int *arr, int *ray, int *grp, int n, int m, int l) {
    int i = 0, j = 0, k = 0;
    while(i < n && j < m && k < l) {
        if(arr[i] == ray[j] && ray[j] == grp[l]) {
            cout << arr[i] << " "; i++; j++; k++;
        }
        else if(arr[i] < ray[j]) i++;
        else if(ray[j] < grp[k]) j++;
        else k++;
    }
} 
void generateBin(int n) {
    for(int i = 1; i <= n; i++) {
        string str = ""; int tmp = i;
        if(tmp == 0) {
            cout << "0" << endl; continue;
        }
        while(tmp > 0) {
            if(tmp & 1) str = "1" + str;
            else str = "0" + str;
            tmp = tmp >> 1;
        }
        cout << str << " ";
        // cout << bitset<4>(i) << endl;
    }
} 
void generateBin(int n) {
    queue <string> q; q.push("1");
    while(n--) {
        string str = q.front(); q.pop();
        cout << str << " ";
        string ing = str;
        q.push(str.append("0"));
        q.push(ing.append("1"));
    }
}
// Function to get index of floor of x in arr
int searchfloor(int *arr, int n, int val) {
    if(val >= arr[n - 1]) return n - 1;
    if(val < arr[0]) return -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > val) return i - 1;
    }
    return -1;
} 
int searchfloor(int *arr, int low, int high, int val) {
    if(low > high) return -1;
    if(val >= arr[high]) return high;
    int mid = (low + high) >> 1;
    if(arr[mid] == val) return mid;
    if(mid > 0 && arr[mid - 1] <= val && val < arr[mid]) return mid - 1;
    if(val < arr[mid]) return searchfloor(arr, low, mid - 1, val);
    else return searchfloor(arr, mid + 1, high, val);
}
// find maximum of all minimums of windows of different sizes
void printMaxofmin(int *arr, int n) {
    vector <int> left(n), right(n);
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int min_val = arr[0];
    for(int i = 1; i < n; i++) min_val = min(min_val, arr[i]);
    vector<int> res(n + 1, min_val - 1);
    for(int i = 0; i < n; i++) {
        int slidelen = right[i] - left[i] - 1;
        res[slidelen] = max(res[slidelen], arr[i]);
    }
    for(int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
} 
void printMaxofMin(int *arr, int n) {
    for(int k = 1; k <= n; k++) {
        int maxofmin = INT_MIN;
        deque <int> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && arr[dq.front()] >= arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        maxofmin = arr[dq.front()];
        for(int i = k; i < n; i++) {
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while(!dq.empty() && arr[dq.front()] >= arr[i]) dq.pop_back();
            dq.push_back(i);
            maxofmin = max(maxofmin, arr[dq.front()]);
        }
        cout << maxofmin << " ";
    }
    cout << endl;
}
// find index of closing bracket for given opening bracket.
void findIdx(string str, int idx) {
    // findIdx("[ABC[23]][89]", 0); 
    if(str[idx] != '[') {
        cout << str << " " << idx << endl;
        return;
    }
    stack <int> st;
    for(int i = if; i < str.length(); i++) {
        if(str[i] == '[') st.push(str[i]);
        else if(str[i] == ']') {
            st.pop();
            if(st.empty()) {
                cout << str << " " << idx << endl;
                return;
            }
        }
    }
    cout << str << " " << idx << endl;
}
// find the difference b/w left & right smaller element of every element in array
void maxDiff(int *arr, int n) {
    stack <int> st;
    vector <int> left(n), right(n);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = st.empty() ? 0 : st.top();
        st.push(arr[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = st.empty() ? 0 : st.top();
        st.push(arr[i]);
    }
    int maxdiff = 0;
    for(int i = 0; i < n; i++)
        maxdiff = max(maxdiff, abs(left[i] - right[i]));
    cout << maxdiff << endl;
} 
vector <int> dp(100, -1);
int tribonacci(int n) {
    if(n <= 0) return 0;
    if(n <= 2) return 1; /*
    vector <int> dp(n + 1, 0);
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= n; i++) 
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n]; */
    if(dp[n] != -1) return dp[n];
    dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return dp[n];
}
// Count ways to get target using + or - before each number in nums
int findtargetways(vector <int> nums, int trg) {
    unordered_map <int, int> dp;
    dp[nums[0]] = dp[-nums[0]] = 1; /*
    for(int i = 1; i < nums.size(); i++) {
        unordered_map <int, int> mp;
        for(const auto &pair : dp) {
            mp[pair.first + nums[i]] += pair.second;
            mp[pair.first - nums[i]] += pair.second;
        }
        dp = mp;
    } */
    for(int i = 1; i < nums.size(); i++) {
        for(auto [sum, cnt] : dp)
            dp[sum + nums[i]] += cnt, dp[sum - nums[i]] += cnt;
    }
    return dp[trg];
}
// find two values (at distinct positions) whose sum is trg
pair <int, int> findtwosum(vector <int> &nums, int trg) { /*
    pair <int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "Indices: " << result.first << " and " << result.second ;
        cout << "Values: " << nums[result.first] << " and " << nums[result.second] ;
    } */
    unordered_map <int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(trg - nums[i])) 
            return {mp[trg - nums[i]], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}
// return true if you can partition array into two subsets such that the 
// sum of the elements in both subsets is equal or false otherwise.
bool Ispartitionable(vector <int> nums) {
    int sum = accumulate(num.begin(), nums.end(), 0);
    if(sum % 2 == 1) return false;
    int mid = sum / 2; /*
    int n = nums.size();
    vector <vector <bool>> dp(n + 1, vector <bool> (mid + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mid; j++) {
            if (j >= nums[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][mid]; */
    vector <bool> dp(mid + 1, false);
    for(auto x : nums) {
        for(int j = mid; j >= x; j--)
            dp[j] = dp[j] || dp[j - x];
    }
    return dp[mid];
}
