#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
    void fun_a()
    {
        cout << "A";
    }
};
class B
{
    public:
    void fun_b()
    {
        cout << "B";
    }
};
int main()
{
    B *b = new B();
    A *a = reinterpret_cast<A*>(b);
    a->fun_a();
}
