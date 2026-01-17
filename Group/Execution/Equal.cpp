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
void applyEquation(int arr[], int n, int a, int b, int c){
    for(int i = 0; i < n; i++)
        arr[i] = a * arr[i] * arr[i] + b * arr[i] + c;
}
int main(){
    int arr[] = {55, 52, 52, 49, 52};
    int n = sizeof(arr) / sizeof(arr[0]);
    canEqualize(arr, n);
    int A = -6, B = -7, C = 2;
    state(arr, A, B, C, n);
    // apply(arr, n, A, B, C);
}
