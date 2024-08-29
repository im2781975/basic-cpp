//Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction on a new line with  places after the decimal.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n+2];
    int neg=0;
    int pos=0;
    int zero=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            pos+=1;
        }
        else if(arr[i]<0)
        {
            neg+=1;
        }
        else
        zero+=1;
    }
    double p=(double)pos/n;
    double ne=(double)neg/n;
    double z=(double)zero/n;
    
    cout<<fixed<<setprecision(6)<<p<<"\n"<<ne<<"\n"<<z;
    
}
