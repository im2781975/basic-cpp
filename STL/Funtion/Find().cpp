#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> vect{3, 4, 5};
    vector<int>::iterator it;
    vector<int>::iterator ip;
    vector<int>::iterator pt;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        ip = vect.begin();
        pt = it;

        while (pt != arr.end() && ip != vect.end() && *pt == *ip)
        {
            pt++;
            ip++;
        }
        if (ip == vect.end())
        {
            cout << it - arr.begin();
            return 0;
        }
    }
    cout << "Subsequence not found";
    return 0;
}
