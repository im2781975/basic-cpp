//successful dynamic casting and it returns value of type new_type
#include <iostream>
using namespace std;
class Base {
    virtual void print()
    {
        cout << "Base" ;
    }
};
class Derived1 : public Base {
    void print()
    {
        cout << "Derived1" << "\n";
    }
};
class Derived2 : public Base {
    void print()
    {
        cout << "Derived2" << "\n";
    }
};
int main()
{
    Derived1 d1;
    // Base class pointer holding
    // Derived1 Class object
    Base* bp = dynamic_cast<Base*>(&d1);
 
    // Dynamic_casting
    Derived1* dp2 = dynamic_cast<Derived1*>(bp);
    if (dp2 == nullptr)
        cout << "null" << "\n";
    else
        cout << "not null" << "\n";
    return 0;
}
