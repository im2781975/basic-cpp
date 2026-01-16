// sort array containing 0, 1 and 2
#include<bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n){
    int l = 0, r = n - 1;
    for(int i = 0; i < n && i <= r;){
        if(arr[i] == 0){
            swap(arr[l], arr[i]); l++; i++;
        }
        else if(arr[i] == 2){
            swap(arr[r], arr[i]); r--; i++;
        }
        else    i++;
    }
}
void sort012(int *arr, int n){
    int l = 0, r = n - 1, mid = 0;
    while(mid <= r){
        switch(arr[mid]){
            case 0: 
                swap(arr[l++], arr[mid++]); break;
            case 1: mid++; break;
            case 2: 
                swap(arr[mid], arr[r--]);
        }
    }
}
void sort012(int *arr, int n){
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(i = 0; i < n; i++){
        switch(arr[i]){
            case 0: cnt0++; break;
            case 1: cnt1++; break;
            case 2: cnt2++; break;
        }
    }
    i = 0;
    while(cnt0 > 0){ arr[i++] = 0; --cnt0;}
    while(cnt1 > 0){ arr[i++] = 1; --cnt1;}
    while(cnt2 > 0){ arr[i++] = 2; --cnt2;}
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[]{2, 1, 0, 2, 1, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n); print(arr, n);
}
