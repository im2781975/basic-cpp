// C++ program to demonstrate if the value of
// of pure virtual destructor are provided
// then the program compiles & runs fine.
 
#include <iostream>
 
// Initialization of base class
class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};
Base::~Base() // Explicit destructor call
{
    std::cout << "Pure virtual destructor is called";
}
 
// Initialization of derived class
class Derived : public Base {
public:
    ~Derived() { std::cout << "~Derived() is executed\n"; }
};
 
int main()
{
    // Calling of derived member function
    Base* b = new Derived();
    delete b;
    return 0;
}
