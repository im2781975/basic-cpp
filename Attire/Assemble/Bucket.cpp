#include<bits/stdc++.h>
using namespace std;
void bucket(vector <float> &arr, int n){
    vector <vector <float>> pail(n);
    for(int i = 0; i < n; i++){
        int x = n * arr[i];
        pail[x].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++)
        sort(pail[i].begin(), pail[i].end());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < pail[i].size(); j++)
            arr.push_back(pail[i][j]);
    }
}
void mixed(float *arr, int n){
    vector <float> neg, pos;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0) neg.push_back((-1) * arr[i]);
        else pos.push_back(arr[i]);
    }
    bucket(pos, pos.size());
    bucket(neg, neg.size());
    for(int i = 0; i < neg.size(); i++)
        arr[i] = (-1) * neg[neg.size() - 1 - i];
    for(int i = neg.size(); i < n; i++)
        arr[i] = pos[i - neg.size()];
}
void print(float *arr, int n){
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}
int main(){
    float arr[] = {-0.897, 0.565, 0.656,-0.1234, 0, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    mixed(arr, n);
    print(arr, n);
}
