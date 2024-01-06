#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x = 10;
    int& ref = x;
    ref = 20;
    cout << "x = " << x << '\n';
    // Value of x is now changed to 30
    x = 30;
    cout << "ref = " << ref << '\n';
    return 0;
}
