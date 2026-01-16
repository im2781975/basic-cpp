#include<bits/stdc++.h>
using namespace std; 
void merge(int *arr, int *ray, int n, int m){
    for(int i = m - 1; i >= 0; i--){
        int j, last = arr[n - 1];
        for (j = n - 2; j >= 0 && arr[j] > ray[i]; j--)
            arr[j + 1] = arr[j];
        if (last > ray[i]) {
            arr[j + 1] = ray[i];
            ray[i] = last;
        }
    }
}
void swapIfgreater(int *arr, int *ray, int i, int j){
    if(arr[i] > ray[j]) swap(arr[i], ray[j]);
}
void merge(int *arr, int *ray, int n, int m){
    int len = m + n;
    int gap = (len / 2) + (len % 2);
    while(gap > 0){
        int l = 0, r = l + gap;
        while(r < len){
            if(l < n && r >= n)
                swapIfgreater(arr, ray, l, r - n);
            else if(l >= n && r >= n)
                swapIfgreater(ray, ray, l - n, r - n);
            else swapIfgreater(arr, arr, l, r);
            l++; r++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}
void merge(int *arr, int *ray, int n, int m){
    int i = 0, j = 0, k = n - 1;
    while(i <= k && j < m){
        if(arr[i] < ray[j]) i++;
        else swap(ray[j++], arr[k--]);
    }
    sort(arr, arr + n);
    sort(ray, ray + n);
} 
void merge(int *arr, int *ray, int n, int m){
    int i = 0;
    while(arr[n - 1] > ray[0]){
        if(arr[i] > ray[0]){
            swap(arr[i], ray[0]);
            sort(ray, ray + m);
        }
        i++;
    }
}
void merge(int *arr, int *ray, int n, int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr[i] <= ray[j]) i++;
        else if(arr[i] > ray[j]){
            swap(arr[i], ray[j]); i++;
            if (j < m - 1 && ray[j + 1] < ray[j]) {
                int temp = ray[j];
                int tempj = j + 1;
                while (ray[tempj] < temp && tempj < m) {
                    ray[tempj - 1] = ray[tempj];
                    tempj++;
                }
                ray[tempj - 1] = temp;
            }
        }
    }
} 
int main(){
    int arr[] = { 1, 5, 9, 10, 15, 20 };
    int ray[] = { 2, 3, 8, 13 };
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(ray) / sizeof(ray[0]);
    merge(arr, ray, m, n);
    for(int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << ray[i] << " ";
    cout << endl;
}
