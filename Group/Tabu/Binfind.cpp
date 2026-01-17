#include<bits/stdc++.h>
using namespace std;
int binfind(vector <int> vec, int key){
    int n = (int)vec.size();
    int lg = log2(n - 1) + 1;
    //while ((1 << lg) < n - 1); lg += 1;
    int pos = 0;
    for (int i = lg ; i >= 0; i--) {
        if (vec[pos] == key) return pos;
        int idx = pos | (1 << i);
        if ((idx < n) && (vec[idx] <= key))
            pos = idx;
    }
    // if element found return pos otherwise -1
    return ((vec[pos] == key) ? pos : -1);
}
int expfind(int arr[], int n, int x){
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < n && arr[i] <= x) i = i * 2;
    return binary(arr, i / 2, min(i, n - 1), x);
}
int binary(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x)
            return binary(arr, l, mid - 1, x);
        return binary(arr, mid + 1, r, x);
    }
    return -1;
}
int expfind(vector <int> vec, int x){
    int n = vec.size();
    if(n == 0) return -1;
    int i = 1;
    while(i < n && vec[i] < x) i *= 2;
    int left = i / 2, right = min(i, n - 1);
    while(left <= right){
        int mid = (left + right) / 2;
        if(vec[mid] == x) return mid;
        else if(vec[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
//pivot binary search
int findPivot(int arr[], int low, int high){
    if (high < low) return -1;
    if (high == low) return low;
    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
// Searches an element key in a pivoted sorted array arr[] of size n
int pivbinfind(int *arr, int n, int key){
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binary(arr, 0, n - 1, key);
    if (arr[pivot] == key) return pivot;
    if (arr[0] <= key)
        return binary(arr, 0, pivot - 1, key);
 
    return binary(arr, pivot + 1, n - 1, key);
}
int main(){
    vector<int> arr{2, 3, 4, 10, 40};
    int x = 10;
    cout << expfind(arr, x) << "\n";
    cout << binfind(arr, 10);
}
