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
int main(){
    vector<int> vec{1, 20, 6, 4, 5};
    cout << getInv(vec);
}
