#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=10;
    int *ptr;
    ptr = &x;
    if( ptr==NULL)
        cout<<"\nNo value pointed";
    else
        cout<<"\nValue pointed is: " << *ptr;
    cout<< "\nBefore increament: " << ptr;
    ptr++;
    cout<< "\nAfter increment: " << ptr;
    cout<< "\nBefore decreament: " << ptr;
    ptr--;
    cout<< "\nAfter decrement: " << ptr;
    
}
