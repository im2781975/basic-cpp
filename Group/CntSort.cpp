#include<bits/stdc++.h>
using namespace std;
void cntsort(int *arr, int n, int x){
    vector <int> res(n), cnt(n, 0);
    for(int i = 0; i < n; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++)
        cnt[(arr[i] / x) % n]++;
    for(int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
    for(int i = n - 1; i >= 0; i--){
        res[cnt[(arr[i] / x) % n] - 1] = arr[i];
        cnt[(arr[i] / x) % n]--;
    }
    for(int i = 0; i < n; i++)
        arr[i] = res[i];
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {40, 12, 45, 32, 33, 1, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    cntsort(arr, n, 1); 
    cntsort(arr, n, n);
    print(arr, n);
}
