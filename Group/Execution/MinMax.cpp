#include<bits/stdc++.h>
using namespace std;
//find the minimum and maximum values that can be calculated by summing exactly 
// four of the five integers. print the respective minimum and maximum values
void maxmin(int *arr, int n){
    int tmp[n], sum;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j];
        }
        tmp[i] = sum;
    }
    int duo = tmp[0];
    for(int i = 1; i < n; i++){
        if(duo < tmp[i]) duo = tmp[i];
    } 
    cout << tmp[0] << " " << tmp[n - 1] << endl;
}
int poslt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] >= key)  rt = mid;
        else    lt = mid;
    }
    return rt;
}
int posrt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] <= key)  lt = mid;
        else    rt = mid;
    }
    return lt;
}
int cntfreq(int *arr, int n, int key){
    int lt = poslt(arr, -1, n - 1, key);
    int rt = posrt(arr, 0, n - 1, key);
    return (arr[lt] == key && key == arr[rt]) ? (rt - lt + 1) : 0;
}
// Deleteval
int Binsearch(int *arr, int l, int r, int key){
    if(r < l) return -1;
    int mid = (l + r) / 2;
    if(key == arr[mid]) return mid;
    else if(key > arr[mid]) return  Binsearch(arr, mid + 1, r, key);
    else return Binsearch(arr, l, mid - 1, key);
}
int deleteval(int *arr, int n, int key){
    int pos = Binsearch(arr, 0, n - 1, key);
    if(pos == -1) return n;
    for(int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}
int main(){
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    cout << cntfreq(arr, n, key) << endl;
    maxmin(arr, n);
    n = deleteval(arr, n, key);
    for(int i = 0; i < n; i++)
        cout<< arr[i] << " ";
}
