#include <bits/stdc++.h>
using namespace std;

int main()
{
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

