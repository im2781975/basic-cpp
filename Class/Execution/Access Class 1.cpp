// operators that can be overloaded
#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    int num;
    base(int i):num(i){}
    base *operator->(){
        return this;
    }
};
class parent{
    public:
    void fun(){
        cout << "Parent Func()";
    }
};
class derieved{
    public:
    void g(){
        parent b;
        b.fun();
    }
};
int main(){
    base b(5);
    cout << "b.num: " << b.num << "\n";
    base *ptr = &b;
    cout << "ptr->num: " << ptr->num << "\n";
    // Accessing num using -> operator
    cout << b->num << "\n";
    
    derieved d;
    d.g();
}
