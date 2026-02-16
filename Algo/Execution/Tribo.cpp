// return true if you can partition array into two subsets such that the 
// sum of the elements in both subsets is equal or false otherwise.
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2; /*
    int n = nums.size();
    vector <vector <bool>> dp(n + 1, vector <bool> (trg + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= nums[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target]; */
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int j = target; j >= num; j--)
            dp[j] = dp[j] || dp[j - num];
    }
    return dp[target];
}
// find two values (at distinct positions) whose sum is trg
pair <int, int> findTwoSum(vector <int> & nums, int target) { /*
    pair <int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "Indices: " << result.first << " and " << result.second ;
        cout << "Values: " << nums[result.first] << " and " << nums[result.second] ;
    } */
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(target - nums[i]))
            return {mp[target - nums[i]], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}
// Count ways to get target using + or - before each number in nums
int findTargetWays(vector <int>& nums, int target) {
    unordered_map <int, int> dp;
    dp[nums[0]] = dp[-nums[0]] = 1; /*
    for (int i = 1; i < nums.size(); i++) {
        unordered_map <int, int> next_dp;
        for (const auto& pair : dp) {
            next_dp[pair.first + nums[i]] += pair.second;
            next_dp[pair.first - nums[i]] += pair.second;
        }
        dp = next_dp;
    } */
    for (int i = 1; i < nums.size(); i++)
        for (auto [sum, cnt] : dp)
            dp[sum + nums[i]] += cnt, dp[sum - nums[i]] += cnt;
    
    return dp[target];
}
vector <int> dp(100, -1);
void Tribonacci(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1; /*
    vector <int> dp(n + 1, 0);
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n]; */
    if (dp[n] != -1) return dp[n];
    dp[n] = Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
    return dp[n];
}
#include<bits/stdc++.h>
using namespace std;
// find the difference b/w left & right smaller element of every element in array 
int MaxDiff(int arr[], int n) {
    stack <int> s;
    vector <int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) s.pop();
        left[i] = s.empty() ? 0 : s.top();
        s.push(arr[i]);
    }
    while (!s.empty()) s.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() >= arr[i]) s.pop();
        right[i] = s.empty() ? 0 : s.top();
        s.push(arr[i]);
    }
    int maxDiff = 0;
    for (int i = 0; i < n; i++)
        maxDiff = max(maxDiff, abs(left[i] - right[i]));
    return maxDiff;
}
// find index of closing bracket for given opening bracket.
void test(string expr, int idx){
    // test("[ABC[23]][89]", 0); 
    if(expr[idx]!='['){
        cout << expr << " " << idx << endl;
        return;
    }
    stack <int> st;
    for(int i = idx; i < expr.length(); i++){
        if(expr[i] == '[') st.push(expr[i]);
        else if(expr[i] == ']'){
            st.pop();
            if(st.empty()){
                cout << expr << " " << idx << " " << i << endl;
                return;
            }
        }
    }
    cout << expr << " " << idx << endl;
}
#include <bits/stdc++.h>
using namespace std;
// find maximum of all minimums of windows of different sizes
void printMaxOfMin(int arr[], int n) {
    for (int k = 1; k <= n; k++) {
        int maxOfMin = INT_MIN;
        deque<int> dq; 
    
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        maxOfMin = arr[dq.front()];
        for (int i = k; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();
            dq.push_back(i);
            
            maxOfMin = max(maxOfMin, arr[dq.front()]);
        }
        cout << maxOfMin << " ";
    }
    cout << endl;
}
void printMaxOfMin(int *arr, int n) {
    vector <int> left(n), right(n);
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    vector <int> res(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int windwlen = right[i] - left[i] - 1;
        res[windwlen] = max(res[windwlen], arr[i]);
    }
    for(int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
}
// Function to get index of floor of x in arr[] 
int searchfloor(int *arr, int low, int high, int val) {
    if(low > high) return -1;
    if (x >= arr[high]) return high;
    int mid = (low + high) >> 1;
    if(arr[mid] == val) return mid;
    if (mid > 0 && arr[mid - 1] <= val && val < arr[mid])
        return mid - 1;
    if (val < arr[mid])
        return searchfloor(arr, low, mid - 1, val);
    return searchfloor(arr, mid + 1, high, val);
} 
int searchfloor(int arr[], int n, int val) {
    if (val >= arr[n - 1]) return n - 1;
    if (val < arr[0]) return -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > val) return (i - 1);
    }
    return -1;
}
void generateBinary(int n) {
    queue <string> q; q.push("1");
    while(n--) {
        string str = q.front(); q.pop();
        cout << str << endl;
        string ing = str;
        q.push(str.append("0"));
        q.push(ing.append("1"));
    }
}
void generateBinary(int n) {
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
// Find Intersection of three pointer
int findCommon(int *ar1, int *ar2, int *ar3, int n, int m, int l) {
    int i = 0, j = 0, k = 0;
    while(i < n && j < m && k < l) {
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            cout << ar1[i] << " ";
            i++; j++; k++;
        }
        else if(ar1[i] < ar2[j]) i++;
        else if(ar2[j] < ar3[k]) j++;
        else k++;
    }
}
void findCommon(vector<int>& ar1, vector<int>& ar2, vector<int>& ar3) {
    unordered_set<int> s1(ar1.begin(), ar1.end());
    unordered_set<int> s2(ar2.begin(), ar2.end());
    for(int x : ar3) {
        if(s1.count(x) && s2.count(x)) {
            cout << x << " ";
        }
    }
    cout << endl;
}
bool issortable(int *arr, int n) {
    stack <int> st;
    int expect = 1;
    for(int i = 0; i < n; i++) {
        st.push(arr[i]);
        while(!st.empty() && st.top() == expect) {
            st.pop(); except++;
        }
    }
    return st.empty();
}

char rod[] = {'S', 'A', 'D'};
vector <stack <int>> st(3);
void moveDisk(int a, int b) {
    if(st[b].empty() || (!st[a].empty() && st[a].top() < st[b].top())) {
        cout << st[a].top() << " " << rod[a] << " " << rod[b] << endl;
        st[b].push(st[a].top());
        st[a].pop();
    }
    else moveDisk(b, a);
}
// HaNoi Tower
void Hanoi(int n) {
    int src = 0, mid = 1, dst = 2;
    for(int i = n; i > 0; i++)
        st[src].push(i);
    int totalmov = (1 << n) - 1;
    if (n % 2 == 0) swap(mid, dst);
    for (int i = 1; i <= totalmov; i++) {
        if (i % 3 == 0) moveDisk(mid, dst);
        else if (i % 3 == 1) moveDisk(src, dst);
        else moveDisk(src, mid);
    }
}
stack<int> S, A, D;  // Source, Aux, Destination
void move(stack<int>& from, stack<int>& to, char fromRod, char toRod) {
    if (from.empty()) return;
    int disk = from.top();
    if (to.empty() || disk < to.top()) {
        cout << "Move disk " << disk << " from " << fromRod << " to " << toRod << '
';
        to.push(disk);
        from.pop();
    }
}
void towerOfHanoi(int n) {
    cout << n << " disks:
";
    for (int i = n; i >= 1; --i) S.push(i);
    
    int moves = (1 << n) - 1;
    
    for (int i = 1; i <= moves; ++i) {
        if (i % 3 == 1)        move(S, D, 'S', 'D');
        else if (i % 3 == 2)   move(S, A, 'S', 'A');
        else                    move(A, D, 'A', 'D');
    }
}

