#include<bits/stdc++.h>
using namespace std;
class A{
    int x;
    public:
    A() { cout << 10 << " ";}
};
class B {
    static A a;
    public:
    B() { cout << 20 << " ";}
    static A getA() { return a; }
};
//A B::a defines the static member a of class B. This tells the compiler to allocate storage for a.
A B::a = A();
int main(){
    B b; 
    // A a = b.getA();
    A a = B :: getA();
}
