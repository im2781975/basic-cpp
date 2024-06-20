//A virtual function (also known as virtual methods) is a member function 
//that is declared within a base class and is re-defined (overridden) by a derived class
//it's a abstract class.
#include <iostream>
using namespace std;
class Base {
    public:
    int x;
    // any class inheriting from Base must provide an implementation for the function.
    //The Base class does not provide any implementation for this function.
    virtual void fun() = 0;
    //virtual void fun() {};
    int getX(){ 
        return x; 
    }
};
class Derived : public Base{
    int y;
    public:
    void fun() override{ 
        cout << "\nfun() called";
    }
};
int main(void)
{
    Derived d;
    d.x=5;
    cout<<d.getX();
    cout<<d.x;
    d.fun();
    return 0;
}
