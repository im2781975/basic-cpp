#include<bits/stdc++.h>
using namespace std;
void Bywave(int *arr, int n) {
    for(int i = 0; i < n; i += 2){
        if(i > 0 && arr[i - 1] > arr[i]) swap(arr[i - 1], arr[i]);
        if(i < n - 1 && arr[i] < arr[i + 1]) swap(arr[i + 1], arr[i]);
    }
}
void Bywave(int *arr, int n){
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i += 2) swap(arr[i], arr[i + 2]);
}
// sort even-placed elements in increasing & odd-placed in decreasing order
void bitonic(int *arr, int n){
    vector <int> even, odd;
    for(int i = 0; i < n; i++){
        if(!(i % 2)) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater <int> ());
    int j = 0;
    for(int i = 0; i < even.size(); i++) arr[j++] = even[i];
    for(int i = 0; i < odd.size(); i++) arr[j++] = odd[i];
}
void bitonic(int *arr, int n){
    int i = 1, j = n - 1;
    if(j % 2 != 0) j--;
    while(i < j) {
        swap(arr[i], arr[j]); i += 2; j -= 2;
    }
    sort(arr, arr + (n + 1) / 2);
    sort(arr + (n + 1) / 2, arr + n, greater <int> ());
}
void bitonic(int *arr, int n){
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) arr[i] = (-1) * arr[i];
    }
    sort(arr, arr + n);
    int mid = (n - 1) / 2;
    for(int i = 0; i <= mid; i++)
        arr[i] = (-1) * arr[i];
    reverse(arr, arr + mid + 1);
    reverse(arr + mid + 1, arr + n);
}
void bucket(int *arr, int n){
    int mx = *max_element(arr, arr + n);
    vector <vector <int>> pail(mx + 1);
    for(int i = 0; i < n; i++){
        int x = arr[i];
        pail[x].push_back(arr[i]);
    }
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < pail[i].size(); j++)
            arr[idx++] = pail[i][j];
    }
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    Bywave(arr, n); 
    bitonic(arr, n);
    bucket(arr, n);
    print(arr, n);
}
