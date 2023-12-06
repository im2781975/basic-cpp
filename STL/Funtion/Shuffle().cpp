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
int random_suffle(int j)
{
    return rand()%j;
}
int main()
{
    //srand(unsigned(time(0)));
    int ar[]{10,20,30,40,50};
    int n=sizeof(ar)/sizeof(ar[0]);
    suffle(ar,n);
    
    vector<int>arr(ar,ar+n);
    vector<int>::iterator it;
    //random_shuffle(arr.begin(),arr.end());
    random_shuffle(arr.begin(),arr.end(),random_suffle);
    for(it=arr.begin(); it!=arr.end(); it++)
    {
        cout<<*it<<" ";
    }
}
