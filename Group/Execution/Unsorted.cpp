#include<bits/stdc++.h>
using namespace std;
//find the minimum and maximum values that can be calculated by summing exactly 
// four of the five integers. print the respective minimum and maximum values
void maxmin(int *arr, int n){
    int tmp[n], sum;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j];
        }
        tmp[i] = sum;
    }
    int duo = tmp[0];
    for(int i = 1; i < n; i++){
        if(duo < tmp[i]) duo = tmp[i];
    } 
    cout << tmp[0] << " " << tmp[n - 1] << endl;
}
int poslt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] >= key)  rt = mid;
        else    lt = mid;
    }
    return rt;
}
int posrt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] <= key)  lt = mid;
        else    rt = mid;
    }
    return lt;
}
int cntfreq(int *arr, int n, int key){
    int lt = poslt(arr, -1, n - 1, key);
    int rt = posrt(arr, 0, n - 1, key);
    return (arr[lt] == key && key == arr[rt]) ? (rt - lt + 1) : 0;
}
// Deleteval
int Binsearch(int *arr, int l, int r, int key){
    if(r < l) return -1;
    int mid = (l + r) / 2;
    if(key == arr[mid]) return mid;
    else if(key > arr[mid]) return  Binsearch(arr, mid + 1, r, key);
    else return Binsearch(arr, l, mid - 1, key);
}
int deleteval(int *arr, int n, int key){
    int pos = Binsearch(arr, 0, n - 1, key);
    if(pos == -1) return n;
    for(int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}
// find the Minimum length Unsorted Subarray, 
// sorting which makes the complete array sorted
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
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    cout << cntfreq(arr, n, key) << endl;
    maxmin(arr, n);
    n = deleteval(arr, n, key);
    for(int i = 0; i < n; i++)
        cout<< arr[i] << " ";
    unsorted(arr, n);
    findsurpassar(arr, n);
}
void cntsurpasser(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) cnt++;
        }
        cout << cnt;
    }
}
