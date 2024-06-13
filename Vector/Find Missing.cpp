#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> k;
        a[k] = 1; 
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) 
            cout << i << " \n";
    }
    return 0;
}
