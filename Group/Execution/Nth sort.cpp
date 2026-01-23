#include<bits/stdc++.h>
using namespace std; 
#define x 1000000
int kthsmallest(int *arr, int n, int k){
    sort(arr, arr + n);
    if(k < arr[0]) return k;
    if(k == arr[0]) return arr[0] + 1;
    if(k > arr[n - 1]) return k + n;
    if(arr[0] == 1) k--;
    else k-= (arr[0] - 1);
    for(int i = 1; i < n; i++){
        int c = arr[i] - arr[i - 1] - 1;
        if(k <= c) return arr[i - 1] + k;
        else k -= c;
    }
    return arr[n - 1] + k;
}
int kthsmallest(int *arr, int n, int k){
    int ray[x + 1];
    memset(ray, 0, sizeof ray);
    for(int i = 0; i < n; i++) ray[arr[i]] = 1;
    for(int i = 1; i <= x; i++){
        if(ray[i] != 1) k--;
        if(k == 0) return i;
    }
    return -1;
}
int ksmallest(int arr[], int n, int k) {
    unordered_set <int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    int num = 1;
    while(k > 0) {
        if(st.count(num) == 1) num++;
        else { k--; num++; }
    }
    return num - 1;
}
int ksmallest(int arr[], int n, int k) {
    int mx = *max_element(arr, arr + n);
    int* count = new int[mx + 2]();
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int num = 1; 
    while (k > 0) {
        if (count[num] > 0) count[num]--;
        else k--;
        num++;
    }
    delete[] count;
    return num - 1;
}
void nthlargest(int *arr, int n) {
    priority_queue <int> maxheap;
    for(int i = 0; i < k; i++) maxheap.push(arr[i]);
    for (int i = k; i < n; i++) {
        if (arr[i] > maxheap.top()) {
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }
    vector<int> largestK;
    while (!maxheap.empty()) {
        largestK.push_back(maxheap.top());
        maxheap.pop();
    }
    for (int i = k - 1; i >= 0; i--) {
        cout << largestK[i] << " ";
    }
}
bool cmp(int a, int b){
    return a < b;
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = { 30, 20, 10, 40, 60, 50, 70, 80 }, i;
    int n = sizeof(arr) / sizeof(arr[0]);
    nth_element(arr, arr + 3, arr + n);
    print(arr, n);
    sort(arr, arr + n, greater <int> ());
    print(arr, n);
    sort(arr, arr + n, greater <int> ());
    print(arr, n);
    nth_element(arr, arr + 3, arr + n, cmp);
    print(arr, n);
}
