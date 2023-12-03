//partial_sort()
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = { 11, 65, 193, 36, 209, 664, 32 };
    partial_sort(v.begin(), v.begin() + 3, v.end(), greater<int>());
    
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
