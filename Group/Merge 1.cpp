#include<bits/stdc++.h>
using namespace std; 
void rotate(int *arr, int n, int idx){
    for (int i = 0; i < idx / 2; i++)
        swap(arr[i], arr[idx - 1 - i]);
    for (int i = idx; i < (n + idx) / 2; i++)
        swap(arr[i], arr[n - 1 - (i - idx)]);
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - 1 - i]);
}
void func(int *ray, int *arr, int m, int n){
    int l = 0, r = n - 1, idx = 0;
    while(l <= r){
        int mid1 = (l + r) / 2;
        int mid2 = n - mid1 - 1;
        int l1 = arr[mid1], l2 = ray[mid2 - 1];
        int r1 = mid1 == n - 1 ? INT_MAX : arr[mid1 + 1];
        int r2 = mid2 == m ? INT_MAX : ray[mid2];
        if (l1 > r2) {
            r = mid1 - 1;
            if (r == -1) idx = 0;
        }
        else if (l2 > r1) {
            l = mid1 + 1;
            if (l == n - 1) idx = n;
        }
        else {
            idx = mid1 + 1;
            break;
        }
    }
    for(int i = idx; i < n; i++)
        swap(arr[i], ray[i - idx]);
    sort(arr, arr + n);
    sort(ray, ray + m);
}
void merge(int *arr, int *ray, int n, int m){
    if(n > m){
        func(ray, arr, m, n);
        rotate(arr, n, n - m);
        for (int i = 0; i < m; i++) swap(ray[i], arr[i]);
    }
    else func(arr, ray, n, m);
}
int main(){
    int arr[] = { 1, 5, 9, 10, 15, 20 };
    int ray[] = { 2, 3, 8, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(ray) / sizeof(ray[0]);
    merge(arr, ray, n, m);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < m; i++) cout << ray[i] << " ";
    cout << endl;
}
