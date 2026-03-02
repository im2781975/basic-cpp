#include<bits/stdc++.h>
using namespace std;
int recursiveMin(const vector<int> &arr, int l, int r) {
    if (l == r) return arr[l];
    else {
        int mid = (l + r) / 2;
        return min(recursiveMin(arr, l, mid), recursiveMin(arr, mid + 1, r));
    }
}
void initialize() {
    typedef vector <int> vec;
    vec v;
    for(int i = 1; i <= 10; i += 2) v.push_back(i * 2);
    for(int x : v) cout << x << " ";
}
