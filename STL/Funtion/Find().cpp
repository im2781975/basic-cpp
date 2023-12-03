#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> vect{3, 4, 5};
    vector<int>::iterator it;
    vector<int>::iterator pi;
    vector<int>::iterator pt;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        pi = vect.begin();
        pt = it;

        while (pt != arr.end() && pi != vect.end() && *pt == *pi)
        {
            pt++;
            pi++;
        }

        if (pi == vect.end())
        {
            cout << it - arr.begin();
            return 0;
        }
    }

    cout << "Subsequence not found";
    return 0;
}

