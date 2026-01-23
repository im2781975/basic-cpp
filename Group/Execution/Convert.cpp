#include<bits/stdc++.h>
using namespace std;
//find an element that can be used to operate on an array & get equal elements
void canEqualize(int *arr, int n){
    set <int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    if(st.size() == 1) cout << "Yes";
    else if(st.size() == 2){
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        cout << *y << " " << *x << " Yes " << (*y - *x);
    }
    else if(st.size() == 3){
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        auto z = st.begin(); st.erase(z);
        if((*z - *y) == (*y - *x)) cout << "Yes " << (*z - *y);
        else cout << "No";
    }
    else cout << "No";
}
// sort an array after applying equation A*x*x + B*x + C
void state(int *arr, int n, int A, int B, int C){
    for (int i = 0; i < n; i++)
        arr[i] = A * arr[i] * arr[i] + B * arr[i] + C;
    int idx, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(maxi < arr[i]){
            idx = i; maxi = arr[i];
        }
    }
    int i = 0, j = n - 1;
    int ray[n], k = 0;
    while(i < idx && j > idx){
        if(arr[i] < arr[j]) ray[k++] = arr[i++];
        else ray[k++] = arr[j--];
    }
    while (i < idx) ray[k++] = arr[i++];
    while (j > idx) ray[k++] = arr[j--];
    ray[n - 1] = maxi;
    for(int i = 0; i < n; i++) arr[i] = ray[i];
}
void apply(int arr[], int n, int a, int b, int c){
    for(int i = 0; i < n; i++)
        arr[i] = a * arr[i] * arr[i] + b * arr[i] + c;
}
//minimum swap required to convert binary tree to binary search tree
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
int func(int x, int y) {
    return x + y;
}
void fun(int x, int y) {
	return x * y;
}
void sum(int *arr, int val, int n) {
    cout << accumulate(arr, arr + n, val) << endl;
    cout << accumulate(arr, arr + n, val, func) << endl;
    cout << accumulate(arr, arr + n, val, minus <int> ()) << endl;
    int ray[n];
    adjacent_difference(arr, arr + n, ray);
    print(ray, n);
    adjacent_difference(arr, arr + n, ray, func); 
    print(ray, n);
    adjacent_difference(arr, arr + n, ray, multiplies <int> ());
    print(ray, n);
    cout << inner_product(arr, arr + n, ray, val) << endl;
	//a[0]*b[0] +a[1]*b[1].. +var
    cout << inner_product(arr, arr + n, ray, val, minus <int> (), divides <int> ()) << endl;
    cout << inner_product(arr, arr + n, ray, val, func, fun) << endl;
	partial_sum(arr, arr + n, ray);
    print(ray, n);
    partial_sum(arr, arr + n, ray, fun);
    print(ray, n);
}
int main(){
    int arr[] = { 5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    canEqualize(arr, n);
    int A = -6, B = -7, C = 2;
    state(arr, A, B, C, n);
    // apply(arr, n, A, B, C);
    vector <int> vec;
    inorder(arr, vec, n, 0);
    minswap(vec);
    convert(arr, n);
    print(arr, n);
}
