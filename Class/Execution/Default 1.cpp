// how default arguments & virtual function are used together
#include <iostream>
using namespace std;
class Base {
public:
    virtual void fun(int x = 0){
        cout << "Base::fun(), x = " << x << endl;
    }
};
//default argument will be print as base class
class Derived : public Base {
    public:
    virtual void fun(int x = 10) {
        cout << "Derived::fun(), x = " << x << endl;
    }
};
int main()
{
    Derived d1; 
    Base* bp = &d1;
    bp->fun(); 
    return 0; 
}
