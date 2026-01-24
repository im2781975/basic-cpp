#include<bits/stdc++.h>
using namespace std;
void rearrange(int *arr, int n) {
    for(int i = 0; i < n - 2; i += 2) {
        if(arr[i] < arr[i + 1]) swap(arr[i], arr[i + 1])
    }
}
// Prints max at odd position, min at even position 
void rearrange(int *arr, int n) {
    int tmp[n], l = 0, r = n - 1;
    bool found = true;
    for(int i = 0; i < n; i++) {
        if(flag) tmp[i] = arr[r--];
        else tmp[i] = arr[l++];
        flag = false;
    }
    for(int i = 0; i < n; i++) arr[i] = tmp[i];
}
void assign(int *arr, int n) {
    sort(arr, arr + n); int res[n];
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 == 0) res[i] = arr[r--];
        else res[i] = arr[l++];
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}
void fixarr(int *arr, int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[j] == i){
                swap(arr[j], arr[i]); break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] != i) arr[i] = -1;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void fixarr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1 && arr[i] != i) {
            int x = arr[i];
            while (arr[x] != -1 && arr[x] != x)  swap(arr[x], x);
            arr[x] = x;
            if(arr[i] != i) arr[i] = -1;
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
//rearrange an array such that arr[i] = i.
int fixarr(int *arr, int n) {
    vector <int> vec(n, -1);
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) vec[arr[i]] = arr[i];
    }
    for(int i = 0; i < n; i++) arr[i] = vec[i];
}
void fixarr(int *arr, int n) {
    int i = 0;
    while(i < n) {
        int val = arr[i]; 
        if(arr[i] != -1 && arr[i] != arr[val]) swap(arr[i], arr[val]);
        else i++;
    }
    return arr;
}
void fixarr(int *arr, int n) {
    unordered_set <int> st;
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) st.insert(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(st.find(i) != st.end()) arr[i] = i;
        else arr[i] = -1;
    }
}
void shiftzeros(vector <int> vec) {
    int cnt = 0, n = vec.size();
    for(int i = 0; i < n; i++) {
        if(vec[i] == 0) {
            count++;
            vec.erase(vec.begin() + i);
            i--; n--;
        }
    }
    for(int i = 0; i < count; i++) vec.push_back(0);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}
void shiftzeros(int *arr, int n, int *ray) {
    int j = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) ray[j++] = arr[i];
        else count++;
    }
    while(count > 0) {
        ray[j] = 0; count--; j++;
    }
    for(int i = 0; i < n; i++) arr[i] = ray[i];
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void shiftzeros(int *arr, int n) {
    int j = 0;
    for(int = 0; i < n; i++) {
        if(arr[i] != 0) swap(arr[j++], arr[i]);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void slidewindow(vector <int> &vec, int n, int k) {
    int l = 0, r = 0, sum = 0, res = -1;
    while(r < n) {
        sum += vec[r];
        if(r - l + 1 < k) r++;
        else if(r - l + 1 == k) {
            res = max(res, sum);
            sum -= vec[l];
            l++; r++;
        }
    }
    cout << res;
}
