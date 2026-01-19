#include<bits/stdc++.h>
using namespace std;
void Missing(int *arr, int n){
    sort(arr, arr + n);
    int low = 1, high = 10;
    int* ptr = lower_bound(arr, arr + n, low);
    int idx = ptr - arr;
    int i = idx, x = low;
    while (i < n && x <= high) {
        if (arr[i] != x) cout << x << " ";
        else i++;
        x++;
    }
    while (x <= high) cout << x++ << " ";
}
void Missing(int *arr, int n) {
    int low = 1, high = 10;
    for (int i = low; i <= high; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found)
            cout << i << " ";
    }
}
void missing(int *arr, int n){
    int low = 1, high = 10;
    unordered_set <int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    for (int x = low; x <= high; x++)
        if (s.find(x) == s.end())
            cout << x << " ";
}
void Missing(int *arr, int n){
    bool range[high - low + 1] = { false };
    for (int i = 0; i < n; i++) {
        if (low <= arr[i] && arr[i] <= high)
            range[arr[i] - low] = true;
    }
    for (int x = 0; x <= high - low; x++) {
        if (range[x] == false)
            cout << low + x << " ";
    }
}
int Missing(int *arr, int start, int end){
    if (start > end) return end + 1; 
    if (start != arr[start]) return start; 
    int mid = (start + end) / 2; 
    if (arr[mid] == mid) return Missing(arr, mid + 1, end); 
    return Missing(arr, start, mid); 
}
int findSmallestMissinginSor(vector<int> arr) 
{ 
    // Check if 0 is missing in the array 
    if(arr[0] != 0) 
    return 0; 
  
  // Check is all numbers 0 to n - 1 are present in array 
    if(arr[arr.size() - 1] == arr.size() - 1) 
    return arr.size(); 
  
    int first = arr[0]; 
    return findFirstMissing(arr, 0, arr.size() - 1, first); 
} 
int Missing(vector <int> arr){
    if(arr[0] != 0) return 0;
    if(arr[arr.size() - 1] == arr.size() - 1) return arr.size();
    int first = arr[0]; 
    return Missing(arr, 0, arr.size() - 1, first); 
}
// find missing in range
int Missing(int *arr, int n, int m){
    vector <int> vec(m, 0);
    for(int i = 0; i < n; i++) vec[arr[i]] = 1;
    for(int i = 0; i < m; i++){
        if(vec[i] == 0) return i;
    }
}
int Missing(vector <int> arr, int start, int end, int val){
    if(start < end){
        int mid = (start + end) / 2;
        if(arr[mid] != mid + val)
            return Missing(arr, start, mid, val);
        else return Missing(arr, mid + 1, end, val);
    }
    return start + val;
}
