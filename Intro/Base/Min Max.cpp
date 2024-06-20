#include<bits/stdc++.h>
using namespace std;
int sum=0, mult=1;
void mult_digit(int arr[], int n)
{
    for(int i=0; i<n; i++){
        if(i%2==0)
            mult *=arr[i];
    }
    cout << mult;
}
void sum_digit(int arr[], int n){
    for(int i=0; i<n; i++)
        sum+=arr[i];
    cout << sum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n+2];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    cout<<"\nSum of digit is: ";
    sum_digit(arr, n);
    cout<<"\nMultiplication of digit is: ";
    mult_digit(arr, n);
    
// Min max
    int n, sum=0; 
    cin >>n;
    vector <int>vec(n+1);
    for(int i =0; i <n; i++)
        cin >>vec[i];
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
