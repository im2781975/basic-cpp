#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ary;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        ary.push_back(k);
    }
    int s, f;
    cin >> s >> f;

    // Remove elements in the specified range in a single step
    ary.erase(ary.begin() + s - 1, ary.begin() + f);

    for (int i = 0; i < ary.size(); i++)
    {
        cout << ary[i] << " ";
    }

    return 0;
}
