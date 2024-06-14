//given an array of n positive integers. task is to remove the element 
//from the range a position to b position.After removing print the all elements left.
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    vector <int> arr;
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    int s, f;
    cin >> s >> f;
    for(int i = 0 ;i < (f - s) + 1; i++)
        arr.erase(arr.begin() + s-1);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i]<<" ";
}
