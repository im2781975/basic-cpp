#include<bits/stdc++.h>
using namespace std;
int square(int n)
{
    cout <<"\nAddress of a in square1(): "<< &n ;
    n *= n;
    return n;
}
// Pass-by-Reference with Pointer Arguments
void square2(int* n)
{
    cout << "\nAddress of b in square2(): " << n ;
    *n *= *n;
}
// Pass-by-Reference with Reference Arguments
void square3(int& n)
{
    cout << "\nAddress of c in square3(): " << &n ;
    n *= n;
}
int main()
{
    int a, b, c;
    cin >>a;
    cout << "\nAddress of a is: " << &a;
    cout<< "\nSquare of a is: " << square(a);
    cout << "\nValue of a is: " << a << "\n";

    cin >>b;
    cout << "\nAddress of b is: " << &b ;
    square2(&b);
    cout << "\nSquare of b is: " << b;
    cout << "\nchanged value is: " << b << "\n";
    
    cin >>c;
    cout << "\nAddress of c is: " << &c ;
    square3(c);
    cout << "\nSquare of c: " << c ;
    cout << "\nChange reflected in c: " << c ;
}
