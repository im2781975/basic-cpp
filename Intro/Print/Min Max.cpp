#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum=0; 
    cin >>n;
    vector <int>vec(n+1);
    for(int i =0; i <n; i++)
    {
        cin >>vec[i];
    }
    int mini = vec[0];
    int maxi = vec[0];
    for(int i=0; i<vec.size(); i++)
    {
        if(mini >vec[i])
            mini = vec[i];
        
        if(maxi <vec[i])
            maxi = vec[i];
        
        sum+= vec[i];
       // mini=min(mini, vec[i]);
       // maxi=max(maxi, vec[i]);
    }
    cout<<"Minimum is: " <<mini;
    cout<<"\nMaximu is: " <<maxi;
    cout<<"\nSum is: "<<sum;
}
