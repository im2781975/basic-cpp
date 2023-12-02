#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {1, 2, 4, 5, 6};

    cout << "\nAddress of a: "<< a ;
    
    cout << "\nAddress of (a+1): "<<(a+1) ;
    
    cout<< "\nValue of a[4] is: "<< a[4] ;
    
    cout << "\nValue of a[4]+1 is: "<< a[4]+1 ;
    
    //out of bound
    cout<< "\nValue of a[5] is: "<< a[5] ;
    
    cout << "\nValue of a[5]+1 is: "<< a[5]+1 ;
    return 0;
}
