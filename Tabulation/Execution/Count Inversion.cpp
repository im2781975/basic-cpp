// takes n integer & counts the number of inversions in the array using Merge. Two elements a[i] and a[j] form an inversion if i < j and a[i] > a[j].
//number of inversions in an array is a measure of how far the array is from being sorted.
#include<bits/stdc++.h>
using namespace std;
int trg, tot_count;

int pairSum(vector<int>a, vector<int>b)
{
    //it will count unique pair sum.like vect_a={1,2,3};b={1,2,3};sum =a[i]+b[i].sum will be unique
    int n = a.size() + b.size(), ix1 = 0, ix2 = 0, sum = 0;
    for(int i = 0 ; i < n; i++) 
    {
        if(ix1==a.size()||ix2==b.size()) 
        {
            break;
        }
        if (a[ix1] <= b[ix2]) 
        {
            ix1++;
        } 
        else 
        {
            sum += a.size() - ix1;
            ix2++;
        }
    }
    return sum;
}
vector<int>merged(vector<int>a, vector<int>b)
{
    int n = a.size() + b.size(), ix1= 0, ix2 = 0;
    vector<int>v;
    for(int i = 0 ; i < n; i++) 
    {
        if(ix1 == a.size()) 
        {
            v.push_back(b[ix2]);
            ix2++;
        } 
        else if (ix2 == b.size() || a[ix1] < b[ix2]) 
        {
            v.push_back(a[ix1]);
            ix1++;
        } 
        else 
        {
            v.push_back(b[ix2]);
            ix2++;
        }
    }
    return v;
}
vector<int>merge_sort(vector<int>v)
{
    int n = v.size();
    vector<int>a,b;

    if (n <= 1) return v;

    for(int i = 0 ; i < n/2; i++)
        a.push_back(v[i]);

    for(int i = n/2; i < n; i++)
        b.push_back(v[i]);

    vector<int>sorted_a = merge_sort(a);
    vector<int>sorted_b = merge_sort(b);

    tot_count += pairSum(sorted_a, sorted_b);

    return merged(sorted_a, sorted_b);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n; i++)
        cin>>v[i];

    vector<int>ans = merge_sort(v);
    cout<< tot_count << endl;
}
/*->4
6 1 3 2
<-4 */
