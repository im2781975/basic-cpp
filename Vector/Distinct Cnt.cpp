#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int>vec;
    vec.resize(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= n; i++)
    {
        if(i == 0)
        {
            ans++;
            continue;
        }
        if(vec[i]!=vec[i - 1])
            ans++;
    }
    cout << ans;
}
