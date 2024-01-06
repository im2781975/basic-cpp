#include<bits/stdc++.h>
using namespace std;
void square (int *x)
{
    //*x = (*x)++ * (*x);
    *x = (*x) * (*x);
}
void square (int *x, int *y)
{
    *x = (*x) * --(*y);
    //*x = (*x) * (*y);
}
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
    
    int number = 30;
    square(&number, &number);
    cout << "\nsquare base double number is: " <<number;
    int n=30;
    square(&n);
    cout << "\nSquare base single  number is: " << n;
}
