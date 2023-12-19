#include<bits/stdc++.h>
using namespace std;
void Unsized_array(int arr[])
{
    cout << "\nsize of Unsized []: ";
    cout << sizeof(arr) ;
}
void Referenced_array(int (&arr)[10])
{
    cout << "\nsize of Referenced[]: ";
    cout << sizeof(arr) ;
}
void Sized_array(int arr[], int n)
{
    cout << "\nsizeof(int) * n : ";
    cout << sizeof(int) * n ;
}
void aDecay(int *p)
{
    // prints the size of a pointer
    cout << "\nsize of array is by passing by value: ";
    cout << sizeof(p) ;
}
void pDecay(int (*p)[10])
{
    // prints the size of the array
    cout << "\nModified size of array by passing by pointer: ";
    cout << sizeof(*p) ;
}
void mDecay(int *p)
{
    // prints the size of the array
    cout << "\nModified size of array by passing by pointer: ";
    cout << sizeof(*p) ;
    
}
int main()
{
    int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n =sizeof(a) /sizeof(a[0]);
    
    cout << "size of []: "<< sizeof(a) ;
    
    Unsized_array(a);
    Referenced_array(a);
    Sized_array(a,n);
    aDecay(a);
    pDecay(&a);
    mDecay(a);
    
    return 0;
}
