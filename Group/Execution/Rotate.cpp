#include<bits/stdc++.h>
using namespace std;
//left rotation of an array K number of times
void rotateleft(int *arr, int n, int k) {
    int md = k % n;
    for(int i = 0; i < n; i++)
        cout << (arr[(md + i) % n]) << " ";
    cout << endl;
}
void rotateleft(int *arr, int n, int k){
    rotate(arr, arr + (k % n), arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void rotatek(vector <int>& arr, int k){
    int n = arr.size(); k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
void revarr(int *arr, int start, int end) {
    if (start >= end) return;
    int tmp = arr[start]; 
    arr[start] = arr[end];
    arr[end] = tmp;
    revarr(arr, start + 1, end - 1);
}
void rotateleft(int *arr, int d, int n) {
    if(d == 0) return;
    d = d % n;
    revarr(arr, 0, d - 1);
    revarr(arr, d, n - 1);
    revarr(arr, 0, n - 1);
}
void rotate(int *arr, int n, int k) {
    int i = 1;
    while(i <= k) {
        int last = arr[0];
        for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
        arr[n - 1] = last;
        i++;
    }
}
void rotate(int *arr, int n, int k) {
    int tmp[n], j = 0;
    for(int i = k; i < n; i++) tmp[j++] = arr[i];
    for(int i = 0; i < k; i++) tmp[j++] = arr[i];
    for(int i = 0; i < n; i++) arr[i] = tmp[i];
}
void rotateleft(int *arr, int n, int k) {
    k %= n;
    int gcd = __gcd(k, n);
    for(int i = 0; i < gcd; i++) {
        int tmp = arr[i];
        int j = i;
        while(1) {
            int x = j + d;
            if(x >= n) x -= n;
            if(x == i) break;
            arr[j] = arr[x];
            j = x;
        }
        arr[j] = tmp;
    }
}
