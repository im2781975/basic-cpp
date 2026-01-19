#include<bits/stdc++.h>
using namespace std;
// find equilibrium index of an array
int equilibrium(int arr[], int n){
    int left, right;
    for(int i = 0; i < n; i++){
        left = 0;
        for(int j = 0; j < i; j++) left += arr[j];
        right = 0;
        for(int j = i + 1; j < n; j++)
            right += arr[j];
        if(left == right) return i;
    }
    return -1;
}
int equilibrium(int *arr, int n){
    int sum = 0, left = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    for(int i = 0; i < n; i++){
        sum -= arr[i];
        if(left == sum) return i;
        left += arr[i];
    }
    return -1;
}
int equilibrium(int *arr, int n){
    if (n == 1) return 0;
    int forward[n] = {0};
    int rev[n] = {0};
    forward[0] = arr[0];
    rev[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
            forward[i] = forward[i - 1] + a[i];
    }
    for(int i = 1; i < n; i++)
        forward[i] = forward[i - 1] + arr[i];
    for(int i = n - 2; i >= 0; i--)
        rev[i] = rev[i + 1] + arr[i];
    for(int i = 0; i < n; i++){
        if(forward[i] == rev[i]) return i;
    }
    return -1;
}
int eqbIdx(vector <int> &nums){
    int left = 0, pivot = 0, right = 0;
    for(int i = 1; i < nums.size(); i++)
        right += nums[i];
    while(pivot < nums.size() - 1 && right != left){
        pivot++;
        right -= nums[pivot];
        left += nums[pivot - 1];
    }
    return (left == right) ? pivot : -1;
}
//find maximum diff between freq of any two element such that element with greater freq is also greater in value.
int maxdiff(int *arr, int n) {
    unordered_map <int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(freq[arr[i]] > freq[arr[j]] && arr[i] > arr[j])
                res = max(res, freq[arr[i]] - freq[arr[j]])
            else if(freq[arr[i]] < freq[arr[j]] && arr[i] < arr[j])
                res = max(res, freq[arr[j]] - freq[arr[i]])
        }
    }
    return res;
}
int maxdiff(int *arr, int n){
    unordered_map <int, int> freq;
    int dist[n];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(freq.find(arr[i]) == freq.end()) dist[j++] = arr[i];
        freq[arr[i]]++;
    }
    sort(dist, dist + j);
    int min_freq = n + 1;
    int res = 0;
    for(int i = 0; i < j; i++){
        int cur_freq = freq[dist[i]];
        res = max(res, cur_freq - min_freq)
        min_freq = min(min_freq, cur_freq);
    }
    return res;
}
// Returns minimum difference between max & min values of distribution in m students
int minDiff(int *arr, int n, int m){
    // Check if there are no students or no chocolates
    if(m == 0 || n == 0) return 0;
    sort(arr, arr + n);
    // Number of students cannot be more than the number of packets
    if(n < m) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0; i + m - 1 < n; i++){
        int diff = arr[i + m - 1] - arr[i];
        mini = min(mini, diff); 
        maxi = max(maxi, diff); 
    }
    cout << mini << " " << maxi << endl;
}
//find minimum difference of maximum & minimum of K number. 
int minDiff(int *arr, int n, int k){
    int res = INT_MAX;
    sort(arr, arr + n);
    // Find minimum value among all K size subarray. 
    for(int i = 0; i <= n - k; i++)
        res = min(res, arr[i + k - 1] - arr[i]);
    return res;
}

