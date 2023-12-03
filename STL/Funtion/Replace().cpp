// replace() | replace_if() | replace_copy()
#include <bits/stdc++.h>
using namespace std;

 bool IsOdd(int i)
{ 
  return ((i % 2) == 1); 
}
void print(int arr[],int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]{ 10, 20, 30, 30, 20, 10, 10, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int Old = 20, New = 99;
 
    cout <<"\nBefore replace arr is:";
    print(arr,n);
 
    replace(arr, arr + n, Old, New);
    cout<<"\nAfter replace arr is:";
    print(arr,n);
 
    replace_if(arr, arr + n, IsOdd, New);

    cout<<"\nAfter replace_if arr is: ";
    print(arr,n);
    
    vector<char>vect;
    for(int i=0; i<n; i++)
        vect.push_back('A'+i);
        
    cout<<"\nBefore replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
        
    replace_copy(vect.begin(), vect.begin()+1,vect.begin(), 'A', 'Z' );
    
    cout<<"\nAfter replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
    
    return 0;
}
