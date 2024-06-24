#include <bits/stdc++.h>
using namespace std;
// A class that is derived from another class is called a subclass (also a derived class, extended class, or child class). 
//The class from which the subclass is derived is called a superclass (also a base class or a parent class).
class base{
    public:
    virtual void print(){
        cout << "Base Class\n";
    }
};
class Derieved:public base{
    public:
    void print(){
        cout << "Derieved Class\n";
    }
};
int main(){
    //Without Virtual it will print "Base Class"
    Derieved d;
    base &b = d;
    b.print();
}
