#include<bits/stdc++.h>
using namespace std;
class base {
    public:
    int num;
    base(int x): num(x){}
    base *operator->() { return this; }
};
class parent{
    public:
    void func() { cout << "parent func"; }
};
class derived{
    public:
    void tion(){
        parent p; p.func();
    }
};
int main(){
    base b(8); cout << b.num << " ";
    base *ptr = &b; cout << ptr->num << " " << b->num << "\n";
    derived d; d.tion();
}
