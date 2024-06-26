//ambiguity in Multipath Inheritance
#include<bits/stdc++.h>
using namespace std;
class A{
    public: int a;
};
class B:public A{
    public: int b;
};
class C:public A{
    public: int c;
};
class D: public B, public C{
    public: int e;
};
int main(){
    D d;
    d.B::a = 10;
    d.C::a = 100;
    //d.B::a = 10; and d.C::a = 100;. These statements specify that
    // want to access the member a from class A as inherited through classes B and C, respectively. 
    d.b = 20;
    d.c = 30;
    d.e = 40;
    cout << "\na from class B: " << d.B::a;
    cout << "\na from class C: " << d.C::a;
    cout << "\nValue of b is: " << d.b;
    cout << "\nValue of c is: " << d.c;
    cout << "\nValue of c is: " << d.c;
}
