// find the k-th smallest element within a specified subarray 
// of an array, given a set of queries.
#include<bits/stdc++.h>
using namespace std;
void valspot(vector <int> vec, vector <int> tor){
    if(tor[1] > vec.size()) return;
    else if((tor[1] - tor[0] + 1) < tor[2]){
        cout << "kth val isn't present"; return;
    }
    else {
        auto first = vec.begin() + tor[0] - 1;
        auto last = vec.begin() + tor[1];
        vector <int> tmp(first, last);
        sort(tmp.begin(), tmp.end());
        cout << tmp[tor[2] - 1] << endl;
    }
}
int main(){
    vector <int> vec{ 3, 2, 5, 1, 8, 9};
    vector <int> tor{ 2, 5, 2};
    valspot(vec, tor);
}
