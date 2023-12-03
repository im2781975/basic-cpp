// working of at() | get() | front() | back()  | size() | max_size() 
#include<iostream>
#include<array> 
#include<tuple> 
using namespace std;
int main()
{
    array<int,6> ar = {1, 2, 3, 4, 5, 6};
    int n= sizeof (ar) /sizeof (ar[0]) ;
    
    // Printing array elements using at()
    cout << "Array elements are (using at()) : ";
    for ( int i=0; i<n; i++)
    cout << ar.at(i) << " ";
 
    // Printing array elements using get()
    cout << "\nArray elements are (using get()) : ";
    cout << get<0>(ar) << " " << get<1>(ar) << " " << get<2>(ar) << " " << get<3>(ar) << " " << get<4>(ar) << " " << get<5>(ar) << " ";
 
    // Printing number of array elements
    cout << "\nArray size is  : ";
    cout << ar.size();
 
    // Printing maximum elements array can hold
    cout << "\nMaximum elements array can hold is : ";
    cout << ar.max_size() ;
 
    // Printing array elements using operator[]
    cout << "\nArray elements are (using operator[]) : ";
    for ( int i=0; i<n; i++)
    cout << ar[i] << " ";
 
    cout << "\nFirst element of array is : ";
    int &a=ar.front();
    cout <<a ;
 
    cout << "\nLast element of array is : ";
    int &b=ar.back();
    cout << b ;
      
    a=10; 
    b=60; 
     
    cout<<"\nArray after updating first and last element :";
    for (auto x: ar)
    {
      cout<<x<<" ";
    }
    return 0;
}