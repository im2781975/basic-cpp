//given an array of n positive integers. next q lines contains q queries, 
//in each query you will be given two values l and r(The index number, where l<r).find sum between l and r in each query.
int sum(int x,int y,float z=0, float w = 0){
    return (x + y + z + w);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> v[i];

    vector<int> pref(n + 1);
    for (int i = 1;i <= n;i++)
        pref[i] = (pref[i - 1] + v[i]);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
    
    cout << sum(10, 15, 25, 30) <<"\n";
    return 0;
}
