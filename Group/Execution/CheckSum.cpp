#include<bits/stdc++.h>
using namespace std;
vector <int> merged(vector <int> vec, vector <int> tor) {
    vector <int> res;
    int idx1 = 0, idx2 = 0;
    int n = vec.size() + tor.size();
    for(int i = 0; i < n; i++) {
        if(idx1 == vec.size())
            res.push_back(tor[idx2++]);
        else if(idx2 == tor.size())
            res.push_back(vec[idx1++]);
        else if(vec[idx1] > tor[idx2])
            res.push_back(tor[idx2++]);
        else res.push_back(vec[idx1++]);
    }
    return res;
}
vector <int> divide(vector <int> arr) {
    vector <int> x, y;
    if(arr.size() <= 1) return arr;
    int len = arr.size();
    for(int i = 0; i < len / 2; i++) x.push_back(arr[i]);
    for(int i = len / 2; i < len; i++) y.push_back(arr[i]);
    vector <int> vec = divide(x);
    vector <int> tor = divide(y);
    return merged(vec, tor);
}
//checks if there are two numbers in the array which sums to trg
bool twoPoint(vector <int> arr, int trg) {
    int n = arr.size();
    int idx1 = 0, idx2 = arr.size() - 1;
    while(idx1 < idx2) {
        if(arr[idx1] + arr[idx2] == trg) return true;
        else if(arr[idx1] + arr[idx2] > trg) idx2--;
        else if(arr[idx1] + arr[idx2] < trg) idx1++;
    }
    return false;
}
//check if there exist two distinct elements in the sorted array whose sum is equal to trg
vector<int> merge(vector<int> arr) {
    if(arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    vec = merge(vec);
    tor = merge(tor);
    vector <int> res;
    int i = 0, j = 0;
    while(i < vec.size() && j < tor.size()) {
        if(vec[i] < tor[j]) res.push_back(vec[i++]);
        else res.push_back(tor[j++]);
    }
    while(i < vec.size()) res.push_back(vec[i++]);
    while(j < tor.size()) res.push_back(tor[j++]);
    return res;
}
vector<int> twosum(vector<int>& arr, int trg) {
    int l = 0, r = arr.size()-1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == trg) return {l, r};
        else if(sum < trg) l++;
        else r--;
    }
    return {};
}
vector <int> RemoveDup(vector <int> vec) {
    int n = vec.size();
    vector <int> res = merge(vec);
    vector <int> Dup;
    for(int i = 1; i <= n; i++) {
        if(res[i] != res[i - 1]) Dup.push_back(res[i - 1]);
    }
    return Dup;
}
bool Bsearch(vector <int> vec, int l, int r, int trg) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(vec[mid] == trg) return true;
        if(vec[mid] < trg) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int pairsum(vector <int> vec, int n, int trg) {
    sort(vec.begin(), vec.end());
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int val = trg - vec[i];
        if(Bsearch(vec, i + 1, n - 1, trg)) cnt++;
    }
    return cnt / 2;
}
// counts the number of inversions in the array using Merge.
//number of inversions in an array is a measure of how far the array is from being sorted.
int cnt = 0;
long long invcnt(vector<int> &a, vector<int> &b, vector<int> &v) {
    int i = 0, j = 0, k = 0;
    long long inv = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) v[k++] = a[i++];
        else {
            v[k++] = b[j++];
            inv += (a.size() - i);
        }
    }
    while (i < a.size()) v[k++] = a[i++];
    while (j < b.size()) v[k++] = b[j++];
    return inv;
}
void merg(vector <int> arr) {
    if(arr.size() <= 1) return;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    merg(vec); merg(tor);
    cnt += invcnt(vec, tor, arr);
}
