// working of at() | get() | front() | back()  | size() | max_size() 
//empty() | fill() | swap() 
#include<iostream>
#include<array> 
using namespace std;
void print(array<int, 6>ar)
{
    for(int i=0; i<6; i++)
        cout<<ar.at(i)<<" ";
        //cout<<ar[i] <<" ";
        
}
int main()
{
    array<int,6> a;
    array<int,0> ar1;
 
    ar1.empty()? cout << "\nArray empty":cout << "\nArray not empty";
 
    a.fill(0);
    cout << "\nArray after filling operation is : ";
    print(a);
    
    array<int,6> ar = {1, 2, 3, 4, 5, 6};
    int n= sizeof (ar) /sizeof (ar[0]) ;
    
    // Printing array elements using at()
    cout << "\nArray elements are (using at()) : ";
    print(a);
 
    cout << "\nArray elements are (using get()) : ";
    cout << get<0>(ar) << " " << get<1>(ar) << " " << get<2>(ar) << " " << get<3>(ar) << " " << get<4>(ar) << " " << get<5>(ar) << " ";
 
    cout << "\nArray size is  : ";
    cout << ar.size();
 
    cout << "\nMaximum elements array can hold is : " << ar.max_size() ;
 
    // Printing array elements using operator[]
    cout << "\nArray elements are (using operator[]) : ";
    print(ar);
 
    cout << "\nFirst element of array is : ";
    int &arr=ar.front();
    cout <<arr ;
 
    cout << "\nLast element of array is : ";
    int &b=ar.back();
    cout << b ;
      
    arr=10; 
    b=60; 
     
    cout<<"\nArray after updating first and last element :";
    print(ar);
    
    a.swap(ar);
    cout<<"\nArray 'a' after swap: ";
    print(a);
    cout<<"\nArray 'ar' after swap: ";
    print(ar);
    return 0;
}
