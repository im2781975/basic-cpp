#include <iostream>
using namespace std;
class A
{
public:
    void fun()
    {
        cout << "fun() called\n";
        delete this;
    }
};
int main()
{
    A *ptr = new A;
    ptr->fun();
    ptr = nullptr; // Make ptr nullptr to make sure that it's not used again.
    A a;
    a.fun();
    return 0;
}

