#include <iostream>
using namespace std;
class Base {
public:
  /*  virtual ~Base() {
        cout << "~Base() is executed" << endl;
    }*/
    virtual~Base()=0;
};
// pure virtual destructor must be defined, even though it's declared as pure virtual. 
//destructors are always called when an object is destroyed, and a definition is required to ensure proper cleanup.
Base::~Base(){
    cout << "Pure virtual destructor is called";
} 
class Derived : public Base {
public:
    ~Derived() {
        cout << "~Derived() is executed" << endl;
    }
};
int main() {
    Base* b = new Derived();
    delete b;
    //When delete b is called, the destructor for Derived is invoked first,
    //followed by the destructor for Base. This is because the destructor in Base 
    //is virtual, ensuring that the destructor chain is followed correctly.
    return 0;
}
