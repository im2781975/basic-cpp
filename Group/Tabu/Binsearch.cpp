#include<bits/stdc++.h>
using namespace std;
void sentinel(int *arr, int n, int key){
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while(arr[i] != key)    i++;
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == key))
        cout << key << " is present at index " << i;
    else cout <<"Element Not found";
} /*
int sentinel(vector <int> vec, int key){
    int n = vec.size();
    int last = vec[n - 1];
    vec[n - 1] = key;
    int i = 0;
    while(vec[i] != key)    i++;
    vec[n - 1] = last;
    if ((i < n - 1) || (vec[n - 1] == key))
        cout << key << " is present at index " << i;
    else cout <<"Element Not found";
} */
int linear(int *arr, int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x) return i;
    }
    return -1;
}
int jump(int *arr, int n, int k){
    int step = sqrt(n), prv = 0;
    while(arr[min(step, n) - 1] < k){
        prv = step;
        step += sqrt(n);
        if(prv >= n) return -1;
    }
    while (arr[prv] < k) {
        prv++;
        if (prv == min(step, n))
            return -1;
    }
    if (arr[prv] == k) return prv;
    return -1;
}
int Ternary(int *arr, int l, int r, int key){ 
    while(r >= l){
        int mid = l + (r - l) / 3;
        int cent = r - (r - l) / 3;
        if(arr[mid] == key) return mid;
        if(arr[cent] == key) return cent;
        if(key < arr[mid]) r = mid - 1;
        else if (key > arr[cent]) l = cent + 1;
        else {
            l = mid + 1; r = cent - 1;
        }
    } 
    if(r >= l){
        int mid = l + (r - l) / 3;
        int cent = r - (r - l) / 3;
        if(arr[mid] == key) return mid;
        if(arr[cent] == key) return cent;
        if(key < arr[mid]) 
            return Ternary(arr, l, mid - 1, key);
        else if (key > arr[cent])
            return Ternary(arr, cent + 1, r, key);
        else {
            return Ternary(arr, mid + 1, cent - 1, key);
        }
    }
    return -1;
}/*
int interpolation(int *arr, int lo, int hi, int x){
    int pos;
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo]))* (x - arr[lo]));
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) return interpolation(arr, pos + 1, hi, x);
        if (arr[pos] > x) return interpolation(arr, lo, pos - 1, x);
    }
    return -1;
}*/
int interpolation(int *arr, int n, int x){
    int low = 0, high = (n - 1);
    while (low <= high && x >= arr[low] && x <= arr[high]){
        if (low == high){
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / 
        (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}
int main(){
    int arr[]{ 10, 20, 180, 30, 60, 50, 110, 100, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 180; sentinel(arr, n, key);
    cout << linear(arr, n, key) << "\n";
    sort(arr, arr + n);
    cout << jump(arr, n, key) << "\n";
    cout << interpolation(arr, n, key) << "\n";
    //cout << interpolation(arr, 0, n - 1  key) << "\n";
    cout << Ternary(arr, 0, n - 1, key) << endl;
}
