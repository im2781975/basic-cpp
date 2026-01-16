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
int invmerge(int *arr, int *tmp, int l, int r){
    int mid, cntinv = 0;
    if(r > l){
        mid = l + (l + r) / 2;
        cntinv += invmerge(arr, tmp, l, mid);
        cntinv += invmerge(arr, tmp, mid + 1, r);
        cntinv += merge(arr, tmp, l, mid + 1, r);
    }
    return cntinv;
}
int merge(int *arr, int *tmp, int l, int mid, int r){
    int cntinv = 0;
    int i = l, j = mid, k = l;
    while((i <= mid - 1) && (j <= r)){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
            cntinv += mid - i;
        }
    }
    while(i <= mid - 1) tmp[k++] = arr[i++];
    while(j <= right) tmp[k++] = arr[j++];
    for(int i = l; i <= r; i++)
        arr[i] = tmp[i];
    return cntinv;   
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {40, 12, 45, 32, 33, 1, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cntsort(arr, n, 1); 
    // cntsort(arr, n, n);
    int tmp[n];
    Invmerge(arr, tmp, 0, n - 1);
    print(arr, n);
}
