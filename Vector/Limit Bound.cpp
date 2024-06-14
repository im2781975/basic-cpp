//given an array of n integers & q queries.in each query given a type and an integer k.
//If the type is 1 then perform lower bound & if type is 2 then perform upper bound.
//If the element is not found in any query print -1
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    while (q--){
        int type, k;
        cin >> type >> k;
        if (type == 1){
            auto it = lower_bound(v.begin(), v.end(), k);
            if (it != v.end()){
                int idx = it - v.begin(), value = *it;
                cout << idx << " -> " << value << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else{
            auto it = upper_bound(v.begin(), v.end(), k);
            if (it != v.end()){
                int idx = it - v.begin(), value = *it;
                cout << idx << " -> " << value << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }
    return 0;
}
