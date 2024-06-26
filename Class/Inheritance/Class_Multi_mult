#include <bits/stdc++.h>
using namespace std;
class A{
    protected:
    int a;
    public:
    void GetA(){
        cout << "\nValue Of A is: ";
        cin >> a;
    }
};
class B:public A{
    protected:
    int b;
    public:
    void GetB(){
        cout << "\nValue Of B is: ";
        cin >> b;
    }
};
class C{
    protected:
    int c;
    public:
    void GetC(){
        cout << "\nValue Of C is: ";
        cin >> c;
    }
};
class D:public B,public C{
    protected:
    int d;
    public:
    void Mult(){
        GetA(); GetB(); GetC();
        cout << "Multiplication is: " << a * b * c;
    }
};
int main(){
    D d;
    d.Mult();
}
