#include<bits/stdc++.h>
using namespace std;
//Minimum swap required to convert binary tree to binary search tree
void inorder(int *arr, vector <int> vec, int n, int idx){
    if(idx >= n) return;
    inorder(arr, vec, n, 2 * idx + 1);
    vec.push_back(arr[idx]);
    inorder(arr, vec, n, 2 * idx + 2);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
// Function to find minimum swaps to sort an array
void minswap(vector <int> vec){
    vector <pair <int, int>> tmp(vec.size());
    int res = 0;
    for(int i = 0; i < vec.size(); ++i){
        tmp[i].first = vec[i];
        tmp[i].second = i;
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); ++i){
        if(i == tmp[i].second) continue;
        else{
            swap(tmp[i].first, tmp[tmp[i].second].first);
            swap(tmp[i].second, tmp[tmp[i].second].second);
        }
        if(i != tmp[i].second) --i;
        ++res;
    }
    cout << res << endl;
    for(int i = 0; i < tmp.size(); ++i)
        cout << tmp[i].first << " " << tmp[i].second << endl;
}
//Converted to idx
void convert(int *arr, int n){
    int ray[n];
    copy(arr, arr + n, ray);
    sort(ray, ray + n);
    
    unordered_map <int, int> mp;
    for (int i = 0; i < n; i++)
        mp[ray[i]] = i;
    for (int i = 0; i < n; i++) 
        arr[i] = mp[arr[i]];
}
void convert(int *arr, int n){
    vector <pair <int, int >> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(make_pair(arr[i], i));
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
        arr[vec[i].second] = i;
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
int main(){
    int arr[] = { 5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector <int> vec;
    inorder(arr, vec, n, 0);
    minswap(vec);
    convert(arr, n);
    print(arr, n);
}
