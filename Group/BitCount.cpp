#include<bits/stdc++.h>
using namespace std;
int cntBits(int num){
    int cnt = 0;
    while(num){
        if(num & 1) cnt++; 
        num >>= 1;
    }
    return cnt;
} 
void ByBitcnt(int *arr, int n){
    int tmp[n];
    for(int i = 0; i < n; i++)
        tmp[i] = cntBits(arr[i]);
    Insertion(arr, tmp, n);
}
void Insertion(int *arr, int *tmp, int n){
    for(int i = 1; i < n; i++){
        int key1 = arr[i];
        int key2 = tmp[i];
        int j = i - 1;
        while(j >= 0 && key1 > tmp[j]){
            tmp[j + 1] = tmp[j];
            arr[j + 1] = arr[j];
            j -= 1;
        }
        tmp[j + 1] = key1;
        arr[j + 1] = key2;
    }
}
void ByBitcnt(int *arr, int n){
    stable_sort(arr, arr + n, cmp);
}
int cmp(int a, int b){
    int cnt1 = cntBits(a);
    int cnt2 = cntBits(b);
    if(cnt1 <= cnt2) return false;
    return true;
}
void ByBitcnt(int *arr, int n){
    multimap <int, int> mp;
    for(int i = 0; i < n; i++)
        mp.insert({(-1) * cntBits(arr[i]), arr[i]});
    multimap <int, int> ::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it)
        cout << it -> first << " " << it -> second << endl;
} 
void ByBitcnt(int *arr, int n){
    vector <vector <int>> mec(32);
    for(int i = 0; i < n; i++){
        int cnt = cntBits(arr[i]);
        mec[cnt].push_back(arr[i]);
    }
    int idx = 0;
    for(int i = 31; i >= 0; i--){
        vector <int> &vec = mec[i];
        for(int j = 0; j < vec.size(); j++)
            arr[idx++] = vec[j];
    }
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[]{1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    ByBitcnt(arr, n); print(arr, n);
}
