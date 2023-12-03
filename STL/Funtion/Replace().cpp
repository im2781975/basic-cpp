// replace() | replace_if() | replace_copy() | replace_copy_if()
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
void print(vector<int>vect)
{
    int len=vect.size();
    for(int i=0; i<len; i++)
        cout<<vect[i]<<" ";
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
    
    vector<int>vec(arr,arr+n);
    vector<int>cev ;
    for(int i=0; i<n; i++)
        cev.push_back(i);
        
    cout<<"\nBefore replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nBefore replace_copy_if vec is : ";
    print(vec);
    
    replace_copy_if(vec.begin(),vec.end(),cev.begin(),IsOdd,-1);
            
    cout<<"\nAfter replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nAfter replace_copy_if vec is : ";
    print(vec);
    return 0;
}
