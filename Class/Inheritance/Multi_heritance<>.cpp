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
int main(){
    D d;
    d.B::show();
    d.C::show();
}
