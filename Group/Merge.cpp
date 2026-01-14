#include<bits/stdc++.h>
using namespace std; /*
void merge(int *arr, int *ray, int n, int m){
    int i = 0, j = 0, k = n - 1;
    while(i <= k && j < m){
        if(arr[i] < ray[j]) i++;
        else swap(ray[j++], arr[k--]);
    }
    sort(arr, arr + n);
    sort(ray, ray + n);
} */
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
