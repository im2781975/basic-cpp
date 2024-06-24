#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    void call(){
        print();
    }
    void print(){
        cout << "Base call\n";
    }
};
class Derieved:public base{
    public:
    void print(){
        cout << "Derieved call\n";
    }
};
int main()
{
    base b;
    b.call();
    Derieved d;
    d.call();
    d.print();
    Derieved::base x;
    x.call();
}
