#include<bits/stdc++.h>
using namespace std;
vector<int>merged(vector<int>a, vector<int>b)
{
    vector<int>output;
    int idx1 = 0, idx2 = 0;
    int n = a.size() + b.size();

    for(int i=0; i<n; i++)
    {
        if(idx1 == a.size())
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else if(idx2 == b.size())
        {
            output.push_back(a[idx1]);
            idx1++;
        }
        else if(a[idx1] > b[idx2])
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else
        {
            output.push_back(a[idx1]);
            idx1++;
        }
    }
    return output;
}
vector<int>devide(vector<int>p)
{
    vector<int>b, c;
    if(p.size() <= 1)
        return p;
    int len = p.size();
    for(int i =0; i<len/2; i++)
        b.push_back(p[i]);
        
    for(int i=len/2; i<len; i++)
        c.push_back(p[i]);
    vector<int>Sorted_b = devide(b);
    vector<int>Sorted_c = devide(c);
    return merged(Sorted_b, Sorted_c);
}
int main()
{
    int r, x;
    vector <int> p;
    cin >> r;
    for(int i = 0; i < r; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    vector<int>ans = devide(p);
    for(int i = 0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
