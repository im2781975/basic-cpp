#include<bits/stdc++.h>
using namespace std;
int sort(vector <int> &vec, int l, int r, int k){
    int mid = l + (r - l) / 2;
    int i = max(l, mid - k), j = i, end = min(mid + k, r);
    swap(vec[mid], vec[end]);
    while(j < end){
        if(vec[j] < vec[end])
            swap(vec[i++], vec[j]);
        j += 1;
    }
    swap(vec[end], vec[i]);
    return i;
}
void ksorter(vector <int> &vec, int l, int r, int k){
    if(l < r){
        int q = sort(vec, l, r, k);
        ksorter(vec, l, q - 1, k);
        ksorter(vec, q + 1, r, k);
    }
}
int main(){
    vector<int> array({ 3, 3, 2, 1, 6, 4, 4, 5, 9, 7, 8, 11, 12 });
    int k = 3;
    ksorter(array, 0, array.size() - 1, k);
    for (int& num : array)
        cout << num << ' ';
}
