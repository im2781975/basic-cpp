#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *x =new int[n];
    for(int i =0; i< n; i++)
        cin >>x[i];
    cout << "\nAddress of array is: " << x;
    cout<< "\nElements of array is: ";
    for(int i =0; i< n; i++)
        cout <<x[i] <<" ";
    cout << "\nAddress of array is: " << x;
    delete []x;
}
