// transform()
#include <bits/stdc++.h>
using namespace std;
  
int increment(int x)
    {  return (x+1); }
  
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    transform(arr, arr+n, arr, increment);
    
    cout<<"\nAfter transform array is: ";
    for (int i=0; i<n; i++)
        cout << arr[i] <<" ";
        
    int arr2[] = {4, 5, 6};
    int res[n];
  
   transform(arr, arr+n, arr2, res, plus<int>());
 
  cout<<"\nAfter transform result is: ";
  for (int i=0; i<n; i++)
    {cout << res[i] << " ";}
    
  // Code to add two arrays
  for (int i=0; i<n; i++)
    res[i] = arr[i] + arr2[i];
 
  cout<<"\nSum is: ";
  for (int i=0; i<3; i++)
    {cout << res[i] << " ";}
    cout<<"\n";
    return 0;
}
