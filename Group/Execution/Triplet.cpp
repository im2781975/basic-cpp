#include<bits/stdc++.h>
using namespace std;
// find three elements whose sum is equal to zero
void findTriplets(int arr[], int n){
    bool found = false;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    found = true;
                }
            }
        }
    }
    if (found == false) cout << " not exist " << endl;
}
void findTriplets(int *arr, int n) {
    bool found = false;
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (arr[i] + arr[l] + arr[r] == 0) {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                l++; r--; found = true;
            }
            else if (x + arr[l] + arr[r] < 0) l++;
            else r--;
        }
    }
}
void findTriplets(int *arr, int n) {
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        unordered_set <int> st;
        for (int j = i + 1; j < n; j++) {
            int x = -(arr[i] + arr[j]);
            if (st.find(x) != st.end()) {
                cout << x << " " << arr[i] << " " << arr[j] << endl;
                found = true;
            }
            else st.insert(arr[j]);
        }
    }
    if(!found) cout << "No Triplet found";
}
void Triple(int *arr, int n, int sum) {
    for(int i = 0; i < n - 2; i++) {
        unordered_set <int> st;
        int curr = sum - arr[i];
        for(int j = i + 1; j < n; j++) {
            int req = cur - arr[j];
            if(st.find(req) != st.end()) {
                cout << arr[i] << " " << arr[j] << " " << req << endl;
                return true;
            }
            st.insert(arr[j]);
        }
    }
    return false;
}
int maximum(int a, int b, int c) {
    return max(max(a, b), c);
}
int minimum(int a, int b, int c) {
   return min(min(a, b), c);
}
void TripletDiff(int *a, int *b, int *c, int n) {
    sort(a, a + n); sort(b, b + n), sort(c, c + n);
    int mini, maxi, mid, i = 0, j = 0, k = 0;
    int diff = INT_MAX;
    while (i < n && j < n && k < n){
        int sum = a[i] + b[j] + c[k];
        int mx = maximum(a[i], b[j], c[k]);
        int mn = minimum(a[i], b[j], c[k]);
        if (mx == a[i]) i++;
        else if (mn == b[j]) j++;
        else k++;
        if (diff > (mx - mn)){
            diff = mx - mn;
            maxi = mx;
            mid = sum - (mx + mn);
            mini = mn;
        }
    }
    cout << maxi << " " << mini << " " << mid << endl;
}
