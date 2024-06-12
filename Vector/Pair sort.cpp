//sorting in vector of pair according to 2nd element of pair in descending order
#include<bits/stdc++.h>
using namespace std;
bool sortby(const pair<int, int> a, const pair <int, int> b)
{
    return a.second < b.second;
}
bool sortby(const pair<int, int> a, const pair <int, int> b)
{
    return a.second > b.second;
}
int main()
{
    vector <pair <int, int> >vect;
    int a[]{1, 2, 3, 4};
    int b[]{4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < n; i++)
        vect.push_back(make_pair(a[i], b[i]));
        
    vect.resize(n);
    sort(vect.begin(), vect.end(), sortby);
    
    for(int i = 0; i < vect.size(); i++)
        cout << vect[i].first << " " << vect[i].second << "\n";
}
