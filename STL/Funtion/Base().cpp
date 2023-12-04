//all_of() | any_of() | copy_n() 
#include<bits/stdc++.h>
using namespace std;
void operation(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]%2==0)
        {
            arr[i] *= 2; 
        }
    }
    for (int i = 0; i < n; i++)
    {   
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[]{1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bool allpositive = all_of(arr, arr + n, [](int i) { return i>0; });
    // If all elements are positive, modify the array
    cout<<"\nAfter impose all_of: ";
    if (allpositive)
        operation(arr,n);
        
        
    bool anyEven = any_of(arr, arr + n, [](int i) { return i%2==0; });
    // If any elements is Even, modify the array
    cout<<"\nAfter impose any_of: ";
    if (anyEven)
        operation(arr,n);
    
    int ar[n];
    copy_n(arr,n,ar);
    cout<<"\nAfter impose copy_n: ";
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}
