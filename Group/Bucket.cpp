#include<bits/stdc++.h>
using namespace std;
bool cmp(pair <int, pair <int, int>> a, pair <int, pair <int, int>> b){
    if(a.second.second != b.second.second)
        return (a.second.second > b.second.second);
    else return (a.second.first < b.second.first);
}
void ByFreq(int *arr, int n){
    unordered_map <int, pair <int, int>> hash;
    for(int i = 0; i < n; i++){
        if(hash.find(arr[i]) != hash.end())
            hash[arr[i]].second++;
        else    hash[arr[i]] = make_pair(i, 1);
    }
    vector <pair <int, pair <int, int>>>vec;
    for(auto it = hash.begin(); it != hash.end(); ++it)
        vec.push_back(make_pair(it->first, it->second));
    sort(vec.begin(), vec.end(), cmp); 
    for(auto &p : vec) {
        int value = p.first;
        int freq = p.second.second;
        while(freq--) 
            cout << value << " ";
    }
}
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
    int ar[]{ 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(ar) / sizeof(ar[0]);
    ByFreq(ar, n);
    float arr[] = {-0.897, 0.565, 0.656,-0.1234, 0, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    mixed(arr, n);
    print(arr, n);
}
