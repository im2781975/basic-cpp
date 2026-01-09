#include<bits/stdc++.h>
using namespace std;
class A {
    public: A(){
        int a = 15, b = 20; cout << a + b << endl;
    }
};
class B {
    public: B(){
        int x = 50, y = 20; cout << x - y << endl;
    }
};
class C : public A, virtual public B {
    public: C() : A(), B() {
        int r = 40, s = 8; cout << r * s << endl;
    }
};
class X {
    public: void showX(){ cout << "X\n"; }
};
class Y : public X {
    public: void showY(){ cout << "Y\n"; }
};
class Z : public X {
    public : void showZ(){ cout << "Z\n"; }
};
class vehicle{
    public: vehicle(){ cout << "vehicle\n"; }
};
class Fare{
    public: Fare(){ cout << "Fare\n";}
};
class car : public vehicle {};
class bus : public vehicle, public Fare {};
int main(){ 
    bus b;  C obj;
    Y y; y.showX(); y.showY();
}
using namespace std;
class A {
    protected : int a;
    public:
    void getA() { cin >> a; }
};
class B : virtual public A {
    protected : int b;
    public:
    void getB() { cin >> b; }
};
class C : virtual public B{
    protected : int c, res;
    public:
    void getC() { cin >> c; }
    void wer() { getA(); getB(); getC(); res = a * b * c; cout << res << "\n"; }
};
class D : virtual public B, virtual public C {
    protected : int d;
    public:
    void getD() { cin >> d; }
    void mul() {
        getA(); getB(); getC(); getD(); cout << a * b * c * d << "\n";
    }
    void sum() { cout << a + b + c + d << "\n"; }
};
int main(){
    D d; d.mul(); d.sum();
    C c; c.wer();
}
using namespace std;
class A {
    protected: int x;
    public:
    void setA(int a){ x = a;}
    void showA(){ cout << x << "\n";}
};
class B: public A {
    int y, prod;
    public:
    void setB(int a, int b){ y = b; setA(a);}
    void showB(){ showA(); cout << y << "\n";}
    void mul(){ cout << x * y << "\n";}
};
class C: virtual public A {
    public: C(){ setA(20); }
};
class D: virtual public A {
    public: D(){ setA(40); }
};
class E: public C, public D {
    public: E(){ setA(200); }
};
int main(){
    B b; b.setB(6, 9); b.mul();
    E c; c.showA();
}
class A{
    int x;
    public:
    A(int a): x(a){}
    void print(){ cout << x << "\n"; }
    void call(){ cout << "calling\n"; }
};
class B: virtual public A{
    public: B(): A(10){}
};
class C: public B{
    public:
    C(): A(20), B(){}
    void call(){ print();}
};
int main(){
    C c; c.call();
    c.B :: call();
}
