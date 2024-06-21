#include <bits/stdc++.h>
using namespace std;
class Test{
    public:
    int x;
    mutable int y;
    Test():x(10), y(12){}
};
void fun(){
    static int x;
    enum { i = 1, j = 2 };
    
    class Base{
        public:
        void method(){
            cout << "static value is: " << x << "\n";
            cout << "Enum value is: " << i << "\n";
        }
    };
    Base b;
    b.method();
}
int main(){
    fun();
    const Test b;
    b.y = 29;
    cout << b.y;
    return 0;
}
