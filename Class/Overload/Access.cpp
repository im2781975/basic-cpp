#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    void fun(){
        cout << "Base Func()";
    }
};
class derieved{
    public:
    void g(){
        base b;
        b.fun();
    }
};
int main(){
    derieved d;
    d.g();
}
