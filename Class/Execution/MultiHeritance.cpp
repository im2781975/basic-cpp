//implement constructors in multiple inheritance.
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    A(){
        int a = 15, b = 20, c = a + b;
        cout << "Sum of the elements are: " << c << "\n";
    }
};
class B{
    public:
    B(){
        int x = 50, y = 42, z = x - y;
        cout << "Diffrence is: " << z << "\n";
    }
};
// virtual base class is a nested inner class whose functions and member variables can be 
//overridden and redefined by subclasses of an outer class. 
class C:public A, virtual B{
    public:
    C():A(), B(){
        int r = 40, s = 8, t;
        t = r * s;
        cout << "product is: " << t;
    }
};
int main(){
    C x;
}
