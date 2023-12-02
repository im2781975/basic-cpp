// of empty() & fill()
#include<iostream>
#include<array> 
using namespace std;

int main()
{
    array<int,6> ar;
    array<int,0> ar1;
 
    ar1.empty()? cout << "Array empty":cout << "Array not empty";
 
    ar.fill(0);
 
    cout << "\nArray after filling operation is : ";
    for ( int i=0; i<6; i++)
        cout << ar[i] << " ";
 
    return 0;
}
