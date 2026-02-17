#include<bits/stdc++.h>
using namespace std;
string firstDup(string str) {
    // string str = "geeksforgeeksandgeeksquizfor";
    unordered_map <char, int> mp;
    string res = ""; /*
    queue <char> q;
    for(int i = 0; str[i]; i++) {
        if(mp.find(str[i]) == mp.end()) q.push(str[i]);
        mp[str[i]]++;
        while(!q.empty() && mp[q.front()] > 1) q.pop();
        if(!q.empty()) res += q.front();
        else res += '#';
    } */
    vector <char> vec
    for(int i = 0; str[i]; i++) {
        if(mp.find(str[i]) == mp.end()) {
            vec.push_back(str[i]);
            mp[str[i]] = 1;
        }
        else {
            int idx = find(vec.begin(), vec.end(), str[i]) - vec.begin();
            if(idx < vec.size()) 
                vec.erase(vec.begin() + idx);
        }
        res += (vec.empty() ? '#' : vec.front());
    }
    return res;
}
string firstDup(string str) {
    int cnt[26] = {};
    queue <char> q; string res = "";
    for(char ch : str) {
        int idx = ch - 'a';
        cnt[idx]++; q.push(ch);
        while (!q.empty() && cnt[q.front() - 'a'] > 1) q.pop();
        res += q.empty() ? '#' : q.front();
    }
    return res;
}
// Recursive solution for finding bitonic point
int findMaximum(int arr[], int low, int high) {
    if (low == high) return arr[high];
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid];
    else if (arr[mid] < arr[mid + 1])
        return findMaximum(arr, mid + 1, high);
    else return findMaximum(arr, low, mid - 1);
}
int findMax(int *arr, int n) {
    stack <int> st;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(!st.empty() && arr[i] >= arr[st.top()]) {
            maxi = max(maxi, arr[st.top()]);
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        maxi = max(maxi, arr[st.top()]);
        st.pop();
    }
    return maxi;
}
int maxInbitonic(int *arr, int low, int high) {
    int n = high + 1;
    while(low <= high) {
        int mid = low + (high - low) >> 1;
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return arr[mid];
        else if(arr[mid] < arr[mid + 1]) low = mid + 1;
        else high = mid - 1;
    }
    return arr[high];
}
// method for printing maximum element of all subarrays of size k
void printKMax(int arr[], int n, int k) {
    deque <int> q;
    for(int i = 0; i < k; i++) {
        while(!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
    for(int i = k; i < n; i++) {
        cout << arr[q.front()] << " ";
        if(q.front() <= i - k) q.pop_front();
        while(!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
    }
}
vector <int> maxslidingwindow(vector <int> arr, int k) {
    vector <int> res;
    set <pair <int, int>, greater <pair <int, int>>> st;
    for (int i = 0; i < k; i++) st.insert({arr[i], i});
    res.push_back(st.begin() -> first);
    for (int i = k; i < arr.size(); i++) {
        st.insert({arr[i], i});
        st.erase({arr[i - k], i - k}); 
        res.push_back(st.begin() -> first);
    }
    return res;
}
void printKMax(int arr[], int n, int k) {
    for (int i = 0; i <= n - k; i++) {
        int max_val = *max_element(arr + i, arr + i + k);
        cout << max_val << " ";
    }
}
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < k; i++) pq.push({arr[i], i});
    ans.push_back(pq.top().first);
    
    for (int i = k; i < arr.size(); i++) {
        pq.push({arr[i], i});
        while (pq.top().second <= i - k) pq.pop();
        ans.push_back(pq.top().first);
    }
    return ans;
}
// Given two arrays, check if one array is stack permutation of other.
#include<bits/stdc++.h>
bool checkpermutation(int *in, int *out, int n) {
    stack <int> st; int j = 0;
    for(int i = 0; i < n; i++) {
        st.push(in[i]);
        while(!st.empty() && st.top() == out[j]) {
            st.pop(); j++;
        }
    }
    return st.empty();
}
bool checkStackPermutation(int ip[], int op[], int n) {
    queue<int> input;
    for (int i=0;i<n;i++)
        input.push(ip[i]);
    queue<int> output;
    for (int i=0;i<n;i++)
        output.push(op[i]);
    // stack to be used for permutation
    stack <int> tempStack;
    while (!input.empty())
    {
        int ele = input.front();
        input.pop();
        if (ele == output.front())
        {
            output.pop();
            while (!tempStack.empty())
            {
                if (tempStack.top() == output.front())
                {
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else
            tempStack.push(ele);
    }
    // If after processing, both input queue and stack are empty then the input queue is permutable otherwise not.
    return (input.empty()&&tempStack.empty());
}
bool findPair(int arr[], int n, int x) {
    int pivot = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            pivot = i + 1;
            break;
        }
    }
    int left = pivot;
    int right = pivot - 1;
    while (left != right) {
        if (arr[left] + arr[right] == x) 
            return true;
        else if (arr[left] + arr[right] < x) 
            left = (left + 1) % n;
        else 
            right = (right - 1 + n) % n;
    }
    return false;
}
// returns true if arr[] has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x){
    // Find the pivot element
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;
    // l is now index of smallest element
    int l = (i + 1) % n;
    // r is now index of largest element
    int r = i;
    // Keep moving either l or r till they meet
    while (l != r) {
        // If we find a pair with sum x, we return true
        if (arr[l] + arr[r] == x)
            return true;
        // If current pair sum is less, move to the higher sum
        if (arr[l] + arr[r] < x)
            l = (l + 1) % n;
        // Move to the lower sum side
        else
            r = (n + r - 1) % n;
    }
    return false;
}
