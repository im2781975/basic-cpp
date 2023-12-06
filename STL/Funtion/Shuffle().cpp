//Shuffle() 
#include<bits/stdc++.h>
using namespace std;
void suffle(int arr[], int n)
{
    random_shuffle(arr,arr+n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int ar[]{10,20,30,40,50};
    int n=sizeof(ar)/sizeof(ar[0]);
    suffle(ar,n);
}
