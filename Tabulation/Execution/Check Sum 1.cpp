//takes n integer & an integer k, and checks if there are two numbers in the array which sums to k.
#include<bits/stdc++.h>
using namespace std;
vector<int>merged(vector<int>a, vector<int>b)
{
    vector<int>output;
    int idx1 = 0;
    int idx2 = 0;
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

vector<int>devide_arr(vector<int>p)
{
    vector<int>part_1;
    vector<int>part_2;

    if(p.size() <= 1)
        return p;

    int len = p.size();
    for(int i =0; i<len/2; i++)
    {
        part_1.push_back(p[i]);
    }
    for(int i=len/2; i<len; i++)
    {
        part_2.push_back(p[i]);
    }

    vector<int>Sorted_part_1 = devide_arr(part_1);
    vector<int>Sorted_part_2 = devide_arr(part_2);

    return merged(Sorted_part_1, Sorted_part_2);
}

bool two_point(vector<int>arr, int fnd)
{
    int len = arr.size();
    int ix1 = 0;
    int ix2 = len - 1;


    while(ix1<ix2)
    {
        if(arr[ix1] + arr[ix2] == fnd)
            return true;
        else if(arr[ix1] + arr[ix2] > fnd)
        {
            ix2--;
        }
        else if(arr[ix1] + arr[ix2] < fnd)
        {
            ix1++;
        }

    }
    return false;

}


int main()
{
    int r, x, k;
    vector<int>p;
    cin >> r;

    for(int i=0; i<r; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    cin >> k;
    vector<int>ans = devide_arr(p);

    if(two_point(ans, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
/*->4
6 1 3 2
5
<-YES */
