#include<bits/stdc++.h>
using namespace std;
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
    B b;
    b.setB(6, 9);
    b.product();
}
