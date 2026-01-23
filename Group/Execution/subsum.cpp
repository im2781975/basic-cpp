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
