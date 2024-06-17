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
vector<int> merge_sort(vector<int> a)
{
    if (a.size() <= 1)
        return a;

    int mid = a.size() / 2;
    vector<int> b, c;
    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);

    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);
    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    vector<int> sorted_a;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    return sorted_a;
}
void print(vector <int> ans)
{
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
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
    //vector<int>ans = devide(p);
    vector <int> ans = merge_sort(p);
    print(ans);
    return 0;
}
