#include<bits/stdc++.h>
using namespace std;
void primes(int n) {
    vector <int> prime;
    vector <bool> flag(n + 1);
    for(int i = 2; i <= n; i++) {
        if(flag[i] == false) {
            prime.push_back(i);
            for(int x = 2; i * x <= n; x++){
                flag[i * x] = true;
            }
        }
    }
    for(int i = 0; i < prime.size(); i++)
        cout << prime[i] << " ";
}
int recusive(int *arr, int n, int l, int r) {
    if(l == r) return arr[l];
    else {
        int mid = l + (r - l) / 2;
        return min(recursive(arr, n, l, mid - 1), recursive(arr, n, mid + 1, r));
    }
}
void cntzero(int *arr, int n, int q) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] != 0) cnt++;
    }
    while(q--) {
        int type, idx; cin >> type >> idx;
        if(type == 2) {
            if(arr[idx] == 0) arr[idx]++;
        }
        else if(type == 1) {
            if(arr[idx] > 0) {
                arr[idx]--;
                if(arr[idx] == 0) cnt--;
            }
        }
    }
    cout << cnt;
}
