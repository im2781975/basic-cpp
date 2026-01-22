#include<bits/stdc++.h>
using namespace std;
int findone(int *arr, int n){
    int idx = 0, cnt = 1;
    for(int i = 1; i < n; i++){
        if(arr[idx] == arr[i]) cnt++;
        else cnt--;
        if(cnt == 0){
            idx = i; cnt = 1;
        }
    }
    return arr[idx];
}
//Function to check if the candidate occurs more than n/2 times
bool ismajority(int *arr, int n, int val){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == val) cnt++;
    }
    if(cnt > n / 2) return true;
    else return false;
}
void print(int *arr, int n){
    int cnd = findone(one);
    if(ismajority(arr, n, cnd)) cout << "Yes";
    else cout << "No";
}
void majority(int *arr, int n){
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    int cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second > n / 2){
            cnt = 1; cout << it->first << endl;
            break;
        }
    }
    if(cnt == 0)
        cout << "doesn't found\n";
}
//find majority elements
int majority(int *arr, int n){
    if(n == 1) return arr[0];
    int cnt = 1; sort(arr, arr + n);
    for(int i = 1; i <= n; i++){
        if(arr[i - 1] == arr[i]) cnt++;
        else{
            if(cnt > n / 2) return arr[i - 1];
            cnt = 1;
        }
    }
    return -1;
}
int cntoccurance(int *arr, int n, int val){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == val) cnt++;
    }
    return cnt;
}
int util(int *arr, int low, int high){
    if(low == high) return arr[low];
    int mid = (low + high) / 2;
    int left = util(arr, low, mid);
    int right = util(arr, mid + 1, right);
    if(left == right) return left;
    int leftcnt = cntoccurance(arr, high - low + 1, left);
    int rightcnt = cntoccurance(arr, high - low + 1, right);
    // Return the element that occurs more than n/2 times
    if (leftCount > (high-low+1) / 2)
        return leftMajority;
    if (rightCount > (high-low+1) / 2)
        return rightMajority;
    if(leftcnt > (high - low + 1) / 2) return left;
    
    return -1;
}
void majority(int *arr, int n){
    int mj = utile(arr, 0, n - 1);
    if(mj != -1) cout << mj;
    else cout << "No value found";
}
void majority(int *arr, int n){
    int maxcnt = 0, idx = -1;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt > maxcnt){
            maxcnt = cnt; idx = i;
        }
    }
    if(maxcnt > n / 2) cout << maxcnt;
    else cout << -1;
}
