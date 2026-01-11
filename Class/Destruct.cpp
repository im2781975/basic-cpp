#include<bits/stdc++.h>
using namespace std;
class base {
    public:
    base(){ cout << "BASE()\n";}
    virtual ~base() = 0;
    // virtual ~base(){ cout << "Destructor\n"; }
};
base :: ~base(){ cout << "~BASE()\n";}
class derived : public base{
    public:
    derived(){ cout << "DERIVED()\n";}
    ~derived(){ cout << "~Derived()\n"; }
};
class parent {
    ~parent(){ cout << "Destructor\n"; }
    public:
    parent(){ cout << "Constructor\n"; }
    friend void destruct(parent*);
    // void destruct(){ delete this; }
};
void destruct(parent *ptr){ delete ptr; }
class Toy {
    public: int id;
    Toy() { cout << "Default\n"; id = 1; }
    Toy(int x) { cout << "parameterized\n"; id = x; }
    ~Toy() { cout << "Destructor " << id << "\n";}
};
int main(){
    derived *d = new derived();
    base *b = d; 
    // base *b = new derived();
    delete b;
    
    parent *ptr = new parent;
    // ptr -> destruct();
    destruct(ptr);
    Toy a, x(9); cout << a.id << " " << x.id << "\n";
    int i = 0;
    while(i < 4) {
        Toy c(i); cout << c.id << " ";
        i++;
    }
}
using namespace std;
class Abstract {
    int a, b;
    public:
    Abstract(){}
    Abstract(int x, int y): a(x), b(y){}
    void set(int x, int y) { a = x; b = y; }
    Abstract(const Abstract &p) { a = p.a; b = p.b; }
    int getX() { return a; }
    int getY() { return b; } 
    void disp() { cout << a << " " << b << "\n"; }
};
int main(){
    Abstract at; at.disp();
    Abstract bt(30, 60); bt.disp();
    Abstract ct = bt; ct.disp();
    at.set(9, 6); cout << at.getX() << " " << at.getY();
}
using namespace std;
class base {
    public:
    void func(){ cout << "Base Func\n";}
    virtual void func1(){ cout << "Base Func-1\n";}
    virtual void func2(){ cout << "Base Func-2\n";}
    virtual void func3(){ cout << "Base Func-3\n";}
};
class derived: public base {
    public:
    void func(){ cout << "Derived\n";}
    void func1(){ cout << "Func-1\n";}
    void func3(int x){ cout << "Func-3\n";}
};
int main(){
    base *b; derived d;
    b = &d; b->func(); b->func3();
}
