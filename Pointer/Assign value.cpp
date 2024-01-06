#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=10;
    int *ptr;
    ptr = &x;
    int *ptr1 = ptr +5;
    cout << "\nSubtracted value is: " << ptr1 - ptr;
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
