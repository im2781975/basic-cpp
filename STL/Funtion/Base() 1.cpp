//iota() | min_element() | search() 
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <algorithm>  // Add this line for min_element and search
using namespace std;

bool comp(int a, int b)
{
    return a < b;
}

int main()
{
    int ar[6] = {0};
    // Using iota() to assign values
    iota(ar, ar + 6, 20);
    cout << "\narray after using iota:";
    for (int i = 0; i < 6; i++)
        cout << ar[i] << " ";

    int *pt;
    pt = min_element(ar, ar + 6, comp);
    cout << "\nAfter impose min_element: " << *pt;

    vector<int> vect(ar, ar + 6);
    vector<int> cev{22, 23};
    vector<int>::iterator it;

    it = search(vect.begin(), vect.end(), cev.begin(), cev.end());
    if (it != vect.end())
    {
        cout << "\nFirst idx where the other idx found: " << it - vect.begin();
    }
    else
    {
        cout << "cev isn't present in vect";
    }
}