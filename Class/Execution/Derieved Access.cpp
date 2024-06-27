#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    void call(){
        print();
    }
    void print(){
        cout << "Base call\n";
    }
};
class Derieved:public base{
    public:
    void print(){
        cout << "Derieved call\n";
    }
};
//Local class
void func(){
    class test{
        public:
        static void method(){
            cout << "\nclass method";
        }
    };
    cout << "Yes\n";
    test::method();
    test t;
    t.method();
}
//Nested Class
class parent {
    int x;
    public:
    class child {
        int y;
        public:
        child(int val): y(val) {}
        int GetY() {
            return y;
        }
    };
    void fun(child *n) {
        cout << n->GetY();
    }
};
int main()
{
    base b;
    b.call();
    Derieved d;
    d.call();
    d.print();
    Derieved::base x;
    x.call();
    //
    func();
    //
    parent::child c(20);
    parent b;
    b.fun(&c);
}
