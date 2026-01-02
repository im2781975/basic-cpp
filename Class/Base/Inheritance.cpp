#include<bits/stdc++.h>
using namespace std;
class A{
    protected: int x;
    public: A() { x = 10;}
};
class B{
    protected: int x;
    public: B() { x = 10;}
};
class C : public A, public B{
    public:
    void func(){
        cout << A::x << " " << B::x << "\n";
    }
};
int main(){
    C c; c.func();
}
