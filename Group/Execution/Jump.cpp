#include<bits/stdc++.h>
using namespace std
//Find Minimum number of jumps to reach end
int minJumps(int arr[], int l, int h) { 
    if (h == l)  return 0; 
    if (arr[l] == 0) return INT_MAX; 
    int min = INT_MAX; 
    for (int i = l + 1; i <= h && i <= l + arr[l]; i++) { 
        int jumps = minJumps(arr, i, h); 
        if (jumps != INT_MAX && jumps + 1 < min) min = jumps + 1; 
    } 
    return min; 
}
int minJumps(int arr[], int n) { 
    int* jumps = new int[n]; 
    int i, j; 
    if (n == 0 || arr[0] == 0) return INT_MAX; 
    jumps[0] = 0; 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
}
int jump(vector<int>& nums, int idx, int end, vector<int>& memo) {
    if (idx == end) return 0; 
    if (memo[idx] != -1) return memo[idx]; 
    int min_jumps =INT_MAX - 1; 
    for (int j = nums[idx]; j >= 1; --j) {
        if (idx + j <= end) { 
            min_jumps = min(min_jumps, 1 + jump(nums, idx + j, end, memo)); 
            } 
        } 
        return memo[idx] = min_jumps; 
    } 
int minJumps(vector<int>& nums) { 
    vector<int> memo(nums.size(), -1); 
    return jump(nums, 0, nums.size() - 1, memo); 
}
// make an array sorted using array minimum number of swap 
int minswap(int arr[],int n) { 
    pair <int, int> pos[n]; 
    for (int i = 0; i < n; i++) { 
        pos[i].first = arr[i]; 
        pos[i].second = i; 
    } 
    // get right position of every element as second element of pair. 
    sort(pos, pos + n); 
    vector<bool> vis(n, false); 
    int ans = 0; 
    for (int i = 0; i < n; i++) { 
        //already swapped and corrected || already present at correct pos 
        if (vis[i] || pos[i].second == i)  continue; 
        int cycle = 0, j = i;
        while (!vis[j]) { 
            vis[j] = 1; 
            j = pos[j].second; cycle++; 
        } 
        ans += (cycle - 1); 
    } 
    return ans; 
} 
// Fills element in arr[] from its pair sum array pair[]. 
void construct(int *arr, int *pair, int n){
    arr[0] = (pair[0] + pair[1] - pair[n - 1]) / 2;
    for(int i = 1; i < n; i++) arr[i] = pair[i - 1] - arr[0];
}
// print all possible subarrays for given array using recursion
void subarr(vector<int> arr, int start, int end){
    if (end == arr.size()) return;
    else if (start > end) subarr(arr, 0, end + 1);
    else {
        for (int i = start; i <= end; i++)
            cout << arr[i] << " ";
        subarr(arr, start + 1, end);
    }
    return;
}
//print all distinct elements in a given array
void distinct(int *arr, int n){
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < i; j++){
            if(arr[i] == arr[j]) break;
        }
        if(i == j) cout << arr[i] << " ";
    }
}
void distinct(int *arr, int n){
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        while(i < n - 1; && arr[i] == arr[i + 1]) i++;
        cout << arr[i] << " ";
    }
}
void distinct(int *arr, int n){
    unordered_set <int> st;
    for(int i = 0; i < n; i++){
        if(!st.count(arr[i])){
            st.insert(arr[i]);
            cout << arr[i] << " ";
        }
    }
}
