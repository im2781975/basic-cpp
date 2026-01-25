 //takes n integer numbers and an integer k, and how many pairs of numbers in the array which sums to k.
#include<bits/stdc++.h>
using namespace std;
vector<int>marge_sort(vector<int>&a,int k)
{
    if(a.size()<=1)
    return a;
    int mid = a.size()/2;
    vector<int> b,c;
    for(int i=0;i<mid;i++){
        b.push_back(a[i]);
    }
    for(int i=mid;i<a.size();i++)
    {
        c.push_back(a[i]);
    }
    vector<int> sorted_b = marge_sort(b,k);
    vector<int> sorted_c = marge_sort(c,k);
    vector<int> sorted_a;
    int indx1 = 0;
    int indx2 = 0;
    for (int i=0; i<a.size();i++)
    {
        if(indx1 == b.size())
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
        else if(indx2== c.size())
        {
            sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        if(sorted_b[indx1] < sorted_c[indx2])
        {
        sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
    }
    return sorted_a;
}
bool binarySearch(vector<int> X, int l, int r, int key)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (X[mid] == key)
            return true;
        if (X[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
int checkPairSum(vector<int> X, int n, int targetSum)
{
    int count=0;
    for(int i = 0; i < n; i++)
    {
        int k=false;
     // For each element X[i], calculate its complement (targetSum - X[i]). Use the binarySearch function to check if this complement exists in the array X
        k = binarySearch(X, 0, n - 1, targetSum - X[i]);
        if (k == true)
            count++;
    }
    return count/2;
}
vector<int> marge_sort(vector<int>&a)
{
    if(a.size()<=1)
    return a;
    int mid = a.size()/2;
    vector<int> b,c;
    for(int i=0;i<mid;i++)
    {
        b.push_back(a[i]);
    }
    for(int i=mid;i<a.size();i++)
    {
        c.push_back(a[i]);
    }
    vector<int> sorted_b = marge_sort(b);
    vector<int> sorted_c = marge_sort(c);
    vector<int> sorted_a;
    int indx1 = 0;
    int indx2 = 0;
    for (int i=0;i<a.size();i++)
    {
        if(indx1 == b.size())
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
        else if(indx2 == c.size())
        {
            sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        if(sorted_b[indx1] < sorted_c[indx2])
        {
            sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
    }
    return sorted_a;
}
vector<int> RemoveDup(vector<int> &a,int n)
{
vector<int> sorted = marge_sort(a);
    vector<int> dup;
    for(int i=1;i<=n;i++)
    {
       if(sorted[i]!=sorted[i-1])
       dup.push_back(sorted[i-1]);
    }
    return dup;
}
int main ()
{
    int n,target;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    cin>>target;
    vector<int> sorteded = marge_sort(num, target);
    cout << checkPairSum(sorteded, n, target)<<endl;
    vector<int>RemoveDuplicates = RemoveDup(num,n);
    for(int i=0;i<RemoveDuplicates.size();i++)
    {
        cout<<RemoveDuplicates[i]<<" ";
    }
}
