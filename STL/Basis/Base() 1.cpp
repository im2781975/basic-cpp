//iota() | min_element() | min() | max_element() | search() is_sorted_until()
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <algorithm> 
using namespace std;

bool comp(int a, int b)
{
    return a > b; 
}
bool pred(int a, int b)
{
    return a < b;
}
int main()
{
    int ar[6] = {0};
    // Using iota() to assign value
    iota(ar, ar + 6, 20);
    cout << "\narray after using iota:";
    for (int i = 0; i < 6; i++)
        cout << ar[i] << " ";

    int *it;
    it = is_sorted_until(ar, ar + 6, comp); 
    cout << "\nImposed is_sorted_until: "<<*it<<" ";
    
    int *pt;
    pt = min_element(ar, ar + 6, comp);
    cout << "\nAfter impose min_element: " << *pt;
    
    cout<<"\nMin element is: "<< min({7, 5, 9, 2, -1, 5});
    int* i1; 
    i1 = max_element(ar, ar + 6, pred); 
    cout << "\nImposed max_element: "<< *i1;

    cout << "\nThere are " << (it - ar) << " sorted elements in the list and the first unsorted element is "
         << *it;

    vector<int> vect(ar, ar + 6);
    vector<int> cev{22, 23};
    vector<int>::iterator vit; 

    vit = search(vect.begin(), vect.end(), cev.begin(), cev.end(), comp);
    if (vit != vect.end())
    {
        cout << "\nFirst idx where the other idx found: " << vit - vect.begin();
    }
    else
    {
        cout << "cev isn't present in vect";
    }
}
