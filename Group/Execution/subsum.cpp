#include<bits/stdc++.h>
using namespace std;
// Returns length of smallest subarray with sum greater than x. 
int subarrwithsum(int arr[], int n, int x) {
    int curr = 0, minlen = n + 1;
    int start = 0, end = 0;
    while (end < n) {
        while (curr <= x && end < n)
            curr += arr[end++];
        while (curr > x && start < n) {
            if (end - start < minlen)
                minlen = end - start;
            curr -= arr[start++];
        }
    }
    return minlen;
}
int subarrwithsum(int arr[], int n, int x){
    int minlen = n + 1;
     mfor(int i = 0; i < n; i++) {
        int curr = arr[i];
        if(curr > x) return 1;
        int j = i + 1; j < n; j++) {
            curr += arr[j];
            if (curr > x && (j - i + 1) < minlen)
                 minlen = (j - i + 1);
        }
    }
    return minlen;
}
int subarrlen(int trg, vector <int> arr){
    int n = arr.size(); 
    if(n == 0) return 0;
    int res = INT_MAX - 1;
    vector <int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
    for(int i = 1; i <= n; i++) {
        int to_find = trg + sum[i - 1];
        auto find = lower_bound(sum.begin(), sum.end(), to_find);
        if (bound != sum.end() && *bound != to_find) {
            int len = bound - (sum.begin() + i - 1);
            res = min(res, len);
        }
    }
    return (res != INT_MAX - 1? res : 0)
}
void subarrsum(int arr[], int n, int sum) {
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        if (curr == sum) {
            cout << i ; return;
        }
        else {
            for (int j = i + 1; j < n; j++) {
                curr  += arr[j];
                if (curr == sum) {
                    cout << "\nSum found between indexes "<< i << " and " << j ; return;
                }
            }
        }
    }
    return;
}
int subarrsum(int arr[], int n, int sum){
    int cur = arr[0], start = 0, i;
    for (int i = 1; i <= n; i++) {
        if (i < n) cur += arr[i];
        if (cur == sum) {
            cout << "\nSum found between indexes " << start << " & " << i - 1;
            return 1;
        }
        while (cur > sum && start < i - 1) {
            cur -= arr[start]; start++;
        }
    }
    return 0;
}
vector <int> subarraySum(const vector<int>& arr, int sum) {
    unordered_map<int, int> map;
    int curr = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr += arr[i];
        if (map.count(curr - sum)) {
            return vector<int>( arr.begin() + map[curr - sum] + 1, arr.begin() + i + 1);
        }
        map[curr] = i;
    }
    return {};
}
void arrfreq(vector<int>& arr) {
    unordered_map<int, int> freq;
    for(int i = 0; i < arr.size(); ++i) 
        freq[arr[i]]++;
    auto cmp = [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) 
            return a.second > b.second;  
        return a.first < b.first;    
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    // push (freq, value)
    for(auto it = freq.begin(); it != freq.end(); ++it)
        pq.push({it->second, it->first});

    int i = 0;
    while(!pq.empty()){
        int f = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        while(f--) arr[i++] = v;
    }
}
// Function to reorder elements of arr[] according to index[]
bool comp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}
void reorder(int *arr, int *idx, int n) {
    vector <pair <int, int>>vec(n);
    for(int i = 0; i < n; i++) {
        vec[i].first = arr[i];
        vec[i].second = idx[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; i++) 
        arr[i] = vec[i].first;
}
void reorder(int *arr, int *idx, int n) {
    for(int i = 0; i < n; i++) {
        while(idx[i] != i) {
            int dig = idx[idx[i]];
            char ch = arr[idx[i]];
            
            arr[idx[i]] = arr[i];
            idx[idx[i]] = idx[i];
            
            idx[i] = dig;
            arr[i]   = ch;
        }
    }
}
void reorder(int *arr, int *idx, int n) {
    int tmp[n];
    for(int i = 0; i < n; i++) tmp[idx[i]] = arr[i];
    for(int i = 0; i < n; i++) {
        arr[i] = tmp[i];
        idx[i] = i;
    }
}
void printSpiralMatrix(int rows, int cols, int matrix[][4]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}
