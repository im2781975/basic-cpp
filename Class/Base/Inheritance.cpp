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
class user{
    protected:
    string name; int age;
};
class admin : protected user{
    private:    string desig;
    public:
    void set(string nome, int anni, string desig){
        this -> name = nome;
        this -> age = anni;
        this -> desig = desig;
    }
    void show(){
        cout << name << " " << age << "\n";
    }
};
class parent {
    protected:    int x;
};
class child : public parent {
    public:
    void set(int y) { x = y; }
    void show() { cout << x << "\n"; }
};
class base {
    private : int priv = 1;
    protected : int prot = 2;
    public : int pub = 3;
    int privget() { return priv; }
};
class derivedprot : protected base {
    public:
    int protget() { return prot; }
    int pubget() { return pub; }
};
class derivedpriv : private base {
    public:
    int protget() { return prot; }
    int pubget() { return pub; }
};
class derivedpub : public base {
    public:
    int protget() { return prot; }
};
int main(){
    C c; c.func();
    
    admin ad; ad.set("Xy", 32, "Manag");
    ad.show();
    child cd; cd.set(9); cd.show(); 
    
    base b; cout << b.privget() << "\n";
    derivedprot x; cout << x.protget() << " " << x.pubget() << "\n";
    derivedpriv y; cout << y.protget() << " " << y.pubget() << "\n";
    derivedpub z; cout << z.protget() << " " << z.privget() << "\n";
}



