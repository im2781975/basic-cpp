#include <bits/stdc++.h>
using namespace std;
class A{
    protected: int a;
    public:
    void GetA(){
        cout << "\nValue Of A is: ";
        cin >> a;
    }
};
class B:public A{
    protected: int b;
    public:
    void GetB(){
        cout << "\nValue Of B is: ";
        cin >> b;
    }
};
class C{
    protected: int c;
    public:
    void GetC(){
        cout << "\nValue Of C is: ";
        cin >> c;
    }
};
class D:public B,public C{
    protected: int d;
    public:
    void Mult(){
        GetA(); GetB(); GetC();
        cout << "Multiplication is: " << a * b * c;
    }
};
//Multilevel Inheritance
class A{
    public: int a;
    void GetA(){
        cout << "Value Of A is: ";
        cin >> a;
    }
};
class B:public A{
    public: int b;
    void GetB(){
        cout << "\nValue Of B is: ";
        cin >> b;
    }
};
class C:public B{
    int c;
    public:
    void GetC(){
        cout << "\nValue Of C is: ";
        cin >> c;
    }
    void sum(){
        cout << "\nsum is: " << a + b + c;
    }
};
int main(){
    D d;
    d.Mult();
    //
    C c;
    c.GetA(); c.GetB(); c.GetC();
    c.sum();
}

