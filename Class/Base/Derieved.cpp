#include<bits/stdc++.h>
using namespace std;
class Animal {
    public:
    virtual void speak(){ cout << "Animal Speak\n"; }
};
class Dog : public Animal {
    public:
    void speak() override{ cout << "Dog Speak\n"; }
};
class Cat : public Animal {
    public:
    void speak() override{ cout << "Cat Speak\n"; }
};
class Monk : public Animal {
    public:
};
class A{
    int x;
    public:
    A() { cout << 10 << " ";}
};
class B {
    static A a;
    public:
    B() { cout << 20 << " ";}
    static A getA() { return a; }
};
//A B::a defines the static member a of class B. This tells the compiler to allocate storage for a.
A B::a = A();
int main(){
    B b; 
    // A a = b.getA();
    A a = B :: getA();
    
    Animal *w = new Dog(); w-> speak();
    Animal *v = new Monk(); v-> speak();
    Animal *x = new Cat(); x-> speak();
    Dog *y = dynamic_cast <Dog*> (w);
    if(y)    y -> speak();
    else    cout << "Failed To Cast\n";
    Cat *z = dynamic_cast <Cat*> (x);
    if(z)    z -> speak();
    else    cout << "Failed To Cast\n";
    delete w; delete v; delete x;
}
using namespace std;
class base {
    public:
    virtual void func(int x = 0) { cout << x << "\n"; }
};
class derived : public base {
    public:
    virtual void func(int x = 10) { cout << x << "\n"; }
};
class A {
    public: 
    int sum = 0;
    A(){}
    A(int a, int x = 0) { sum = a + x; }
    void disp() { cout << sum << "\n"; }
};
int main(){
    base b; b.func();
    derived d; d.func();
    base *bp = &d; bp->func();
    A a(9); a.disp();
}
using namespace std;
class base{
    public:
    base(){ cout << "Base()\n";}
    //virtual base destructor use when you know you will inherit this class
    virtual ~base(){ cout << "~Base()\n";}
    void show(){ cout << "base show()\n";}
    virtual void print(){ cout << "Base print()\n";}
};
class derived : public base{
    void print(){ cout << "Derived-print()\n";}
    public:
    derived():base(){ cout << "Derived\n";}
    virtual ~derived(){ cout << "~Derived()\n";}
};
int main(){
    base *b = new derived();
    b->show();
    b->print();
    delete b;
}
using namespace std;
class base {
    protected : int x;
    public:
    virtual void func(){};
    base(int i) { x = i;}
    int getX(){ return x; }
};
class derived: public base {
    int y;
    public:
    derived(int i, int j): base(i), y(j){}
    void func() override{ cout << x << " " << y << "\n";}
};
int main(){
    derived d(7, 9); d.func();
    cout << d.getX() << "\n";
    base *ptr = new derived(9, 7);
    ptr->func();
}
