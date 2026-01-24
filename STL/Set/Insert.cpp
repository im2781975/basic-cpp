#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n;
    set<int> s;

    for(int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x;
        s.insert(x);
    }

    for(int x : s)
        cout << x << " ";

    return 0;
}

