#include<bits/stdc++.h>
using namespace std;
class base{
    public:
};
class A:public base{
    public:
    A(){
        cout << "\nUser defined Data Type";
    }
};
class B:public A{};
// The constructor of A is implicitly called before the constructor of C
// Constructor prints "\nC constructor" in addition 
//to "\nUser defined Data Type" (due to A's constructor).
class C:public A{
    public:
    C(){
        cout << "\nC constructor";
    }
};
//Constructor prints "D constructor" in addition to "\nUser defined Data Type"
//(twice: once for the inherited part and once for the member object).
class D:public A{
     A a;
    public:
    D(){
        cout << "\nD constructor";
    }
};
int main(){
    A a;
    B b;
    C c;
    D d;
}

