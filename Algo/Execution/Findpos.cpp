#include<bits/stdc++.h>
using namespace std;
// find length of the longest valid substring
int findlen(string str) {
    // string str = "((()()";
    int len = str.length();
    stack <int> st; st.push(-1);
    int res = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') st.push(i);
        else {
            if(!st.empty()) st.pop();
            if(!st.empty()) res = max(res, i - st.top());
            else st.push(i);
        }
    }
    return res;
}
int findMaxLen(string s) {
    if (s.length() <= 1) return 0;
    vector<int> dp(s.size(), 0);
    int maxLen = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i-1] + 2 + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0);
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    return maxLen;
}
int peakparen(int i, string str, vector <int> vec) {
    if (i <= 0) return 0;
    if (vec[i] != -1) return vec[i];
    if(str[i] == '(') return vec[i] = 0;
    if(str[i] == ')') {
        if(i > 0 && str[i - 1] == '(') {
            return vec[i] = (i >= 2 ? preakparen(i - 2, str, vec) : 0) + 2;
        }
        int prv = peakparen(i - 1, str, vec);
        if(i - 1 - prv >= 0 && str[i - 1 - prv] == '(')
            return vec[i] = prv + 2 + (i - prv - 2 >= 0 ? peakparen(i - prv - 2, str, vec) : 0);
    }
    return vec[i] = 0;
}
int longestvalidparenthesis(string str) {
    int len = str.size(), maxLen = 0;
    vector <int> vec(n, -1);
    for(int i = 0; i < len; i++) 
        maxLen = max(maxLen, peakparen(i, str, vec));
    return maxLen;
}
int longestValidParentheses(string s) {
    int n = s.size();
    int maxLen = 0;
    int left = 0, right = 0;
    for (char c : s) {
        if (c == '(') left++;
        else right++;
        
        if (left == right)
            maxLen = max(maxLen, 2 * left);
        if (right > left)
            left = right = 0; 
    }
    reverse(s.begin(), s.end());
    left = right = 0;
    for (char c : s) {
        if (c == '(') left++;
        else right++;
        
        if (left == right)
            maxLen = max(maxLen, 2 * left);
        if (left > right)
            left = right = 0;
    }
    return maxLen;
}
// find the maximum element 
int findMax(int arr[], int low, int high) { 
    int max = arr[low]; 
    for (int i = low + 1; i <= high; i++) { 
        if (arr[i] > max) max = arr[i];
        else break; 
    }
    return max; 
}
// find the minimum value
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int findMin(vector <int>& arr, int low, int high) {
    if (arr[low] <= arr[high]) return arr[low];
    while (low <= high) {
        int mid = (low + high) / 2;
        if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]) return arr[mid];
        if(arr[mid] > arr[high]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
void nxtsmallerofnxtgreater(int *arr, int n) {
    vector <int> res(n, -1); stack <int> st;
    for(int i = n - 1; i >= 0; i--) { 
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty())
            res[i] = arr[st.top()];
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        int nextIdx = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nextIdx = j;
                break;
            }
        }
        if (nextGreaterIdx != -1) 
            res[i] = result[nextIdx];
    }
    for (int x : res) cout << x << " ";
    cout << endl;
}
vector<int> nextSmallerOfNextGreater(int arr[], int n) {
    vector<int> result(n, -1);
    vector<int> rightSmaller(n, -1);
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && arr[j] >= arr[i]) {
            j = (rightSmaller[j] != -1 ? rightSmaller[j] : n);
        }
        if (j < n) rightSmaller[i] = j;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                int rs = rightSmaller[j];
                if (rs != -1) result[i] = arr[rs];
                break;
            }
        }
    }
    return result;
}
// find if there exists a pair of elements in the array whose difference is x
void findPair(int arr[], int n, int diff){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if((arr[j] - arr[i]) == diff) cout << arr[i] << " " << arr[j] << endl;
        }
    }
    cout << "No such pair";
}
bool findpair(int *arr, int n, int x) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
        if(x == 0 && mp[arr[i]] > 1) return true;
    }
    if(x == 0) return false;
    for(int i = 0; i < n; i++) {
        if(mp.find(x + arr[i]) != mp.end()) {
            cout << arr[i] << " " << x + arr[i] << endl;
            return true;
        }
    }
    return false;
}
bool findPair(int arr[], int n, int x) {
    sort(arr, arr + n);
    while(i < n && j < n) {
        if(i != j && (arr[j] - arr[i] == x || arr[i] - arr[j] == x)) {
            cout << arr[i] << " " << arr[j] << endl;
            return true;
        }
        else if(arr[j] - arr[i] < x) j++;
        else i++;
    }
    cout << "No such pair"; 
    return false; 
}
// check redundant brackets in a balanced expression
bool checkRedundancy(string str) {
    stack<char> st;
    for (auto& ch : str) {
        if (ch == ')') {
            char top = st.top(); st.pop();
            bool flag = true;
            while (!st.empty() and top != '(') {
                if (top == '+' || top == '-' || 
                    top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if (flag == true) return true;
        }
        else st.push(ch);
    }
    return false;
}
// finds an element in an array of infinite size
int binarySearch(int arr[], int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        if (target < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}
int searchInfinite(int arr[], int target) {
    int start = 0, end = 1;
    while (target > arr[end]) {
        int newStart = end + 1;
        end = end + (end - start + 1) * 2;
        start = newStart;
    }
    return binarySearch(arr, target, start, end);
}
