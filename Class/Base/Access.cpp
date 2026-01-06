#include<bits/stdc++.h>
using namespace std;
class base {
    public:
};
class A : public base {
    public:
    A() { cout << "class A\n"; }
};
class B : public A { };
class C : public A {
    public:
    C() { cout << "class C\n"; }
};
class D : public A {
    public:
    A a;
    D() { cout << "class D\n"; }
};
class text {
    protected: int x;
    public:
    text(int i):x(i){}
    void fun() const{
        cout << "\nconst called";
    }
    void fun(){
        cout <<"\nFun called";
    }
};
class parent { public : int pid; };
class child : public parent { public : int id; };
int main(){
    A a; B b; C c; D d;
    text tx(20); tx.fun();
    const text x = 30; x.fun();
    
    child cd; cd.id = 8; cd.pid = 20;
    cout << "\n" << cd.id << " " << cd.pid << "\n";
}
