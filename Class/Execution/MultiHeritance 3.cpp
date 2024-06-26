#include<bits/stdc++.h>
using namespace std;
class A{
    protected: int a;
    public:
    void setA(){
        cout << "\nValue Of A is: ";
        cin >> a;
    }
    void GetA(){
        cout << "\nValue Of A is: " << a;
    }
};
class B:public A{
    protected: int b;
    public:
    void setB(){
        cout << "\nValue Of B is: ";
        cin >> b;
    }
    void GetB(){
        cout << "\nValue Of B is: " << b ;
    }
};
class C:public B{
    protected:
    int c, product;
    public:
    void setC(){
        cout << "\nValue Of C is: ";
        cin >> c;
    }
    void GetC(){
        cout << "\nValue Of C is: " << c << " ";
    }
    void pro(){
        product = a * b * c;
        cout << "\nproduct Of A, B, C is: " << product;
    }
};
class A{
    protected: int a;
    public:
    void setA(int x){
        a = x;
    }
    void showA(){
        cout << "\nValue of A is: " << a;
    }
};
class B:public A{
    int b, pro;
    public:
    void setB(int x, int y){
        b = y;
        setA(x);
    }
    void showB(){
        showA();
        cout << "\nValue Of B: " << b;
    }
    void product(){
        pro = a * b;
        cout << "Product Of "  << a << " & " << b << " is: " << pro;
    }
};
int main(){
    C c;
    c.setA();
    c.setB();
    c.setC();
    c.GetA();
    c.GetB();
    c.GetC();
    c.pro();
    //
    B b;
    b.setB(6, 9);
    b.product();
}
