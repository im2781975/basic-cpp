//check if there exist two distinct elements in the sorted array whose sum is equal to 'k'.
//If such elements exist, output "Yes"; otherwise, output "No".
#include<bits/stdc++.h>
using namespace std;
bool found = false;
int k;
vector<int> merge(vector<int> a)
{
    int n = a.size();
    if (a.size() <= 1)
        return a;
    
    vector<int> b, c;
    int mid = a.size() / 2;
    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);
    
    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);
    
    vector<int> sorted_b = merge(b);
    vector<int> sorted_c = merge(c);
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
        else if (sorted_b[idx1] > sorted_c[idx2])
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
    if (sorted_a.size() == n)
    {
        int i = 0, j = n - 1;
        if (sorted_a[i] + sorted_a[j] > k)
            j--;
        else if (sorted_a[i] + sorted_a[j] < k)
            i++;
        else
            found = true;
    }
    return sorted_a;
}
void print(vector<int> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cin >> k;
    vector<int> ar(arr, arr + n);
    vector<int> ans = merge(ar);
    if (found == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
