#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n % 2 == 0) 
        goto label1;
    else
        goto label2;
 
    label1:
        cout << "Even" << "\n";
        return 0;
    label2:
        cout << "Odd" << "\n";
    //increament
    int z=5;
    int x = 5,y=10;
    
    cout << "x++ is : " << x++ ;
    cout << "\n++x is : " << ++x;
    
    cout << "\ny-- is : " << y-- ;
    cout << "\n--y is : " << --y ;
    
    cout <<"\nlocal access of z is: " << z;
    cout <<"\nGlobal access of z is: " <<::z;
    //Build in
    int a, b, c, d;
    cout << "\nEnter elements: ";
    cin >> a >> b >> c >> d;

    swap(a, b);
    cout << "\nafter swap : " << a << " " << b << " " << c << " " << d ;
    
    int maximum = max({a, b, c, d});
    cout << "\nMaximum is: " << maximum ;

    int minimum = min({a, b, c, d});
    cout << "\nMinimum is: " << minimum ;
}
