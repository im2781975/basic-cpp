#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"\nAfter sort array is: ";
    print(arr,n);
    if(binary_search(arr,arr+n,2))
        cout<<"\nElements exits";
    else
        cout<<"\nElements doesn't exits";
}
