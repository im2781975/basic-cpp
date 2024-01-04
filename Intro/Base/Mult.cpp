#include<bits/stdc++.h>
using namespace std;
int sum=0, mult=1;
void mult_digit(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
            mult *=arr[i];
    }
    cout << mult;
}
void sum_digit(int arr[], int n)
{
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
}
