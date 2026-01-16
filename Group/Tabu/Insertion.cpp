#include<bits/stdc++.h>
using namespace std;
void Insert(int *arr, int n){
    int j, key;
    for(int i = 1; i < n; i++){
        key = arr[i]; j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Insert(arr, n); print(arr, n);
}
