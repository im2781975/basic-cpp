#include<bits/stdc++.h>
using namespace std;
int getInv(vector <int> &vec){
    int n = vec.size();
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> ist;
    int res = 0;
    for(int i = 0; i < n; i++)
        ist.push(make_pair(vec[i], i));
    vector <int> tmp;
    while(!ist.empty()){
        int v = ist.top().first;
        int i = ist.top().second;
        ist.pop();
        int y = upper_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
        res += i - y;
        tmp.insert(upper_bound(tmp.begin(), tmp.end(), i), i);
    }
    return res;
}
// Minimum length of subarray
int minlen(vector <int> &vec){
    vector <int> tmp = vec;
    sort(tmp.begin(), tmp.end());
    int l = 0, r = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] != tmp[i]){
            l = i; break;
        }
    }
    for(int i = vec.size() - 1; i >= 0; i--){
        if(vec[i] != tmp[i]){
            r = i; break;
        }
    }
    return (r - l + 1);
}
int main(){
    vector<int> vec{1, 20, 6, 4, 5};
    cout << getInv(vec);
    cout << minlen(vec);
}
