#include<bits/stdc++.h>
using namespace std;
void grid() {
    int sum = 0, res = 0, grid[10][10] = {0};
    for(int i = 0; i < 10; i++) {
        sum += i; grid[i][i] = sum;
    }
    for(int j = 0; j < 10; j++) {
        res += 2 * j; cout << res << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
void recur(int n) {
    if(n > 0) {
        recur(n - 1); cout << n << " ";
        recur(n - 2);
    }
}
void func(int l, int r) {
    int mid = l + (r - l) >> 1;
    for(int i = l; i <= r; i++) cout << i << " ";
    cout << endl;
    if(l < r) {
        func(l, mid); 
        func(mid + 1, r);
    }
}
void recurs() {
    int n; cin >> n; func(0, n - 1);
    for(int i = 1; i < n / 2; i++) {
        for(int j = 1; j <= n; j++)
            cout << i << " " << j << endl;
    }
}


