//Run Time Type Identification(RTTI).
#include <iostream>
using namespace std;
class B {
public:
    virtual void Func() {}
};
class D : public B {};
//default arguments and virtual function are used together
class Base{
    public:
    virtual void Func(int x = 1){
        cout << "Base::Func(): " << x;
    }
};
class derieved:public Base{
    public:
    virtual void Func(int x){
        cout << "\nDerieved::Func(): " << x;
    }
};
int main() {
    // creates a pointer b to an object of class B but initializes it 
    //with an instance of class D. This is possible because of polymorphism;
    //you can point a base class pointer to a derived class object.
    B* b = new D;
    //to cast the base class pointer b to a derived class pointer d.
    D* d = dynamic_cast<D*>(b);
    //without virtual
    if (d != nullptr)
        cout << "works";
    else
        cout << "cannot cast B*  D*";
    delete b; 
    //
    Base *bp;
    derieved d;
    bp = &d;
    bp->Func();
    return 0;
}
