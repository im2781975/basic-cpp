#include<bits/stc++.h>
using namespace std;
int rotationsum(int *arr, int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            int idx = (i + j) % n;
            sum += j * arr[idx];
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}
// Returns max possible value of i*arr[i]
void maxsum(int *arr, int n){
    int sum = 0, cur = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        cur += (i * arr[i]);
    }
    int maxi = cur;
    for(int j = 1; j < n; j++){
        cur = cur + sum - (n * arr[n - j]);
        if(cur > maxi) maxi = cur;
    }
    return maxi;
}
// Function to find maximum equilibrium sum
int maxsum(int *arr, int n){
    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        int prefix = arr[i];
        for(int j = 0; j < i; j++) prefix += arr[j];
        int suffix = arr[i];
        for(int j = n - 1; j > i; j--) suffix += arr[j];
        if(suffix == prefix) res = max(res, prefix);
    }
    return res;
}
int maxsum(int *arr, int n){
    int prefix[n], suffix[n];
    int res = INT_MIN;
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];
    suffix[n - 1] =  arr[n - 1];
    if(suffix[n - 1] == prefix[n - 1]) res = max(res, prefix[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        suffix[i] = suffix[i + 1] + arr[i];
        if (suffix[i] == prefix[i]) 
            res = max(res, prefix[i]);     
    }
    return res;
}
int maxsum(int *arr, int n){
    int sum = accumulate(arr, arr + n, 0);
    int prefix = 0, res = INT_MIN;
    for(int i = 0; i < n; i++){
        prefix += arr[i];
        if(prefix == sum) res = max(res, prefix);
        sum -= arr[i];
    }
    return res;
}
// Program to make all array equal
bool ispairsum(int *arr, int n, int x){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(arr[i] + arr[j] == x) return true;
            if(arr[i] + arr[j] > x) break;
        }
    }
    return false;
}
// function for calculating min operations
int minoperation(int *arr, int n, int k){
    int mx = *max_element(arr, arr + n);
    int res = 0;
    for(int i = 0; i < n; i++){
        if ((mx - arr[i]) % k != 0) return -1;
        else res += (max - arr[i]) / k;
    }
    return res;
}
int main(){
    int ar[] = { 2, 3, 5, 8, 9, 10, 11 };
    int val = 17, n = *(&ar + 1) - ar;
    sort(ar, ar + n);
    cout << isPairSum(ar, n, val);
}
