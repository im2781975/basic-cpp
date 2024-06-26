//Multilevel Inheritance
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int a;
    void GetA(){
        cout << "Value Of A is: ";
        cin >> a;
    }
};
class B:public A{
    public:
    int b;
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
    C c;
    c.GetA(); c.GetB(); c.GetC();
    c.sum();
}

