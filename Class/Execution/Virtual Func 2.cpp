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
class child:public base{
    public:
    void display(){
        cout << "Child Display Func\n";
    }
    void print(){
        cout << "Child Print Func\n";
    }
};
int main(){
    base *b;
    child c;
    c.display();
    c.print();
    
    b = &c;
    b ->base::display();
    b->print();
}
