#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    virtual void display(){
        cout << "Virtual Base Class Func\n";
    }
    void print(){
        cout << "Base Class Print\n";
    }
};
class derived:public base{
    public:
    void display(){
        cout << "Derived Display Func\n";
    }
    void print(){
        cout << "Derived Print Func\n";
    }
};
//access overridden function using pointer of Base type that 
//points to an object of Derived class
class parent{
    public:
    void print(){
        cout << "Base Class\n";
    }
};
class child:public parent{
    public:
    void print(){
        cout << "child class\n";
    }
};
int main(){
    base *b;
    derived c;
    c.display();
    c.print();
    b = &c;
    b ->base::display();
    b->print();
    
    child c, d;
    parent *ptr = &c;
    ptr->print();
    child::parent *p = &c;
    p->print();
    child *arr = &d;
    arr->print();
}
