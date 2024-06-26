#include<bits/stdc++.h>
using namespace std;
class A{
    int x;
    public:
    void setX(int a){
        x = a;
    }
    void show(){
        cout << "\nElements are: " << x;
    }
};
class B:public A{
    public:
    B(){
        setX(10);
    }
};
class C:public A{
    public:
    C(){
        setX(20);
    }
};
class D:public B, public C{};
class A{
    int x;
    public:
    A(int i):x(i){}
    void print(){
        cout << x;
    }
};
//B is derived from A using virtual inheritance 
//This ensures that if A is inherited multiple times 
//through different paths, only one instance of A is created.
class B:virtual public A{
    public:
    B():A(10){}
};
class C:virtual public A{
    public:
    C():A(10){}
};

class D:public B, public C{
    public:
    D():A(10),B(),C(){}
    void print_call(){
        print();
    }
};
int main(){
    D d;
    d.B::show();
    d.C::show();
    //
    D d;
    d.print_call();
}
