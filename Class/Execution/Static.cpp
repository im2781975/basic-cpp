#include<bits/stdc++.h>
using namespace std;
class test{
    int x, y;
    public:
    test(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
    test &setx(int a){
        x = a;
        return *this;
    }
    test &sety(int b){
        y = b;
        return *this;
    }
    void print(){
        cout << "\nx: " << x << " y: " << y;
    }
};
class test{
    int x, y;
    public:
    test(int x = 0, int y = 0){}
    void setx(int a){
        x = a;
    }
    void sety(int b){
        y = b;
    }
    void print(){
        cout << "x: " << x << " y: " << y << "\n";
    }
};
class Test{
    int x, y;
    public:
    Test(int x = 0,int y = 0){
        this->x = x;
        this->y = y;
    }
    static void Func1(){
        cout << "Func1()";
    }
    static void Func2(){
        cout << "Func2()";
    }
};
int main(){
    test t(4, 6);
    t.print();
    t.setx(10).sety(20);
    t.print();
    
    test a;
    int x = 20;
    a.setx(20);
    a.print();
    //
    test t;
    t.setx(6);
    t.sety(9);
    t.print();
    //
    Test t;
    t.Func1();
    t.Func2();
}
