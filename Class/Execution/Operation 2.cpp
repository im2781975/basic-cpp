#include <bits/stdc++.h>
using namespace std;
class A{
    int a, b, c;
    public:
    void add(int x, int y){
        a = x; b = y;
        cout << "Sum is: " << a + b << "\n";
    }
    void add(int x, int y, int z){
        a = x; b = y; c = z;
        cout << "Sum is: " << a + b + c << "\n";
    }
    virtual void print(){
        cout << "Class A\n";
    }
};
class B:public A{
    public:
    void print(){
        cout << "Class B\n";
    }
    void sum(int x, int y){
        add(x, y);
    }
};
class base{
    int a, b;
    public:
    int solve(int x){
        a = x;
        b = a/2;
        return b;
    }
    void print(){
        cout << a << " " << b;
    }
};
int main(){
    A a;
    a.add(6, 8, 9);
    a.print();
    B b;
    b.add(2, 7);
    b.sum(11, 19);
    b.print();
    // 
    int n; cin >> n;
    base x;
    x.solve(n);
    x.print();
}
