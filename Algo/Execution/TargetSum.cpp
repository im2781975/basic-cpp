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
