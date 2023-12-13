//iota() | min_element() | search()
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <algorithm> 
using namespace std;

bool comp(int a, int b)
{
    if(a > b)
        return 1
    return 0;
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
    
    int *it;
    cout<<"\nImposed is_sorted until: ";
    it = is_sorted_until(v, v + 9, comp);
 
    cout << "\nThere are " << (ip - v)
         << " sorted elements in "
         << "the list and the first unsorted element is "
         << *ip;
         
    vector<int> vect(ar, ar + 6);
    vector<int> cev{22, 23};
    vector<int>::iterator it;

    it = search(vect.begin(), vect.end(), cev.begin(), cev.end(),comp);
    if (it != vect.end())
    {
        cout << "\nFirst idx where the other idx found: " << it - vect.begin();
    }
    else
    {
        cout << "cev isn't present in vect";
    }
}
