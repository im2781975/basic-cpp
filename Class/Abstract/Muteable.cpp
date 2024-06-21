#include <bits/stdc++.h>
using namespace std;
class Base{
    public:
    int x;
    mutable int y;
    Base():x(10), y(12){}
};
int main(){
    const Base b;
    b.y = 29;
    cout << b.y;
}
