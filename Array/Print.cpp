#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[20], int n)
{
    cout << "\nAfter operation array is : ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}
void array_unsized(int arr[],int n)
{
    cout << "\nArray as Unsized Argument: ";
    for (int i = 0; i < n; i++) 
        cout << *(arr + i) << " ";

}
void array_pointer(int* ptr, int n)
{
    cout << "\nArray as Pointer Argument: ";
    for (int i = 0; i < n; i++) 
        cout << ptr[i] << " ";

}

int main()
{
    int a[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    
    int n= sizeof(a)/ sizeof(a[0]);
    
    print_array (a, n);
    
    array_unsized (a, n);
    
    array_pointer (a, n);
    
    sort(a, a+ n);
    print_array (a, n);
    
    if (binary_search(a, a + n, 6))
    cout << "\nElement found in the array";
    else
    cout << "\nElement doesn't exist";
    
    cout << "\nAddress of a: "<< a ;
    
    cout << "\nAddress of (a+1): "<<(a+1) ;
    
    cout<< "\nValue of a[4] is: "<< a[4] ;
    
    cout << "\nValue of a[4]+1 is: "<< a[4]+1 ;
    
    //out of bound
    cout<< "\nValue of a[5] is: "<< a[5] ;
    
    cout << "\nValue of a[5]+1 is: "<< a[5]+1 ;
    return 0;
}
