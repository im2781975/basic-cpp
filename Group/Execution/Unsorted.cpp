#include<bits/stdc++.h>
// find the Minimum length Unsorted Subarray, 
// sorting which makes the complete array sorted
using namespace std;
void unsorted(int *arr, int n){
    int l = 0, r = n - 1;
    while(l < n - 1 && arr[l] <= arr[l + 1])    l++;
    if(l == n - 1) return;
    while (r > 0 && arr[r] >= arr[r - 1]) r--;
    int submin = arr[l], submax = arr[l];
    for (int i = l + 1; i <= r; i++) {
        submin = min(submin, arr[i]);
        submax = max(submax, arr[i]);
    }
    for(int i = 0; i < l; i++){
        if(arr[i] > submin){
            l = i; break;
        }
    }
    for(int i = n - 1; i > r; i--){
        if(arr[i] < submax){
            r = i; break;
        }
    }
    cout << l << " " << r << endl;
}
void merge(int *arr, int l, int m, int r, unordered_map <int, int> mp){
    int n1 = m - l + 1, n2 = r - m;
    int ar[n1], ry[n2];
    for(int i = 0; i < n1; i++)
        ar[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        ry[i] = arr[m + 1 + i];
        
    int i = 0, j = 0, k = l;
    int cnt = 0;
    while (i < n1 && j < n2) {
        if (ar[i] <= ry[j]){
            mp[ar[i]] += cnt;
            arr[k++] = ar[i++];
        }
        else {
            arr[k++] = ry[j++]; cnt++;
        }
    }
    while(i < n1){
        mp[ar[i]] += cnt;
        arr[k++] = ar[i++];
    }
    while(j < n2) arr[k++] = ry[j++];
}
void mergesort(int *arr, int l, int r, unordered_map <int, int> &mp){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m, mp);
        mergesort(arr, m + 1, r, mp);
        merge(arr, l, m, r, mp);
    }
}
void findsurpassar(int *arr, int n){
    unordered_map <int, int> mp;
    int dup[n];
    memcpy(dup, arr, n * sizeof(arr[0]));
    mergesort(dup, 0, n - 1, mp);
    for (int i = 0; i < n; i++)
        cout << (n - 1) - i - mp[arr[i]] << " ";
}
int main(){
    int arr[]{10, 12, 20, 30, 25,40, 32, 31, 35, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    unsorted(arr, n);
    findsurpassar(arr, n);
}
