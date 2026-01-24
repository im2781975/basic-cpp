#include<bits/stdc++.h>
using namespace std;
int findMax(int arr[], int n) {
    if(n == 1) return arr[0];
    else {
        int maxInRest = findMax(arr, size - 1);
        return maxInRest > arr[size - 1] ? maxInRest : arr[size - 1];
    }
}
// Odd occuring element
int findOdd(int arr[], int n){
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
void array(int *arr, int n) {
    if (n == 0) return;
    array(arr, n - 1);
    cout << arr[n - 1] << " ";
}
// For each query, print the sum of elements between indices l and r.
void sumrange(vector <int> vec, int n) {
    vector <int> pref(n + 1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + vec[i];
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }
}
