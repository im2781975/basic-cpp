#include<bits/stdc++.h>
using namespace std;
class Base{
    public:
    void fun(){
        cout << "\nBase Func";
    }
    virtual void fun1(){
        cout << "\nBase-1 Func";
    }
    virtual void fun2(){
        cout << "\nBase-2 Func";
    }
    virtual void fun3(){
        cout << "\nBase-3 Func";
    }
};
class derieved:public Base{
    public:
    void fun(){
        cout << "\nDerieved";
    }
    void fun1(){
        cout << "\nDerieved-1";
    }
    void fun3(int x){
        cout << "\nDerieved-3";
    }
};
int main(){
    Base *bp;
    derieved d;
    bp = &d;
    // Early binding because fun() is non-virtual in base
    bp->fun();
    // Late binding (RTP)
    bp->fun1();
    bp->fun2();
    bp->fun3();
}
