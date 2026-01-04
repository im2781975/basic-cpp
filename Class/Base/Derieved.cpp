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
