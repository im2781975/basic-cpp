//The work of tie() is to unpack the tuple values into separate variables. There are two variants of tie(), with and without “ignore” , the “ignore” ignores a particular tuple element and stops it from getting unpacked.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> pair1 ={ 1, 2 };
    int a, b;
    tie(a, b) = pair1;
    cout << a << " " << b << "\n";
 
    pair<int, int> pair2 ={ 3, 4 };
    tie(a, ignore) = pair2;
    cout << a << " " << b << "\n";
 
    pair<int, pair<int, char> > pair3 = { 3, { 4, 'a' } };
    int x, y;
    char z;
 
    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
      tie(x,ignore) = pair3;
    tie(y, z) = pair3.second;
    cout << x << " " << y << " " << z << "\n";
}
